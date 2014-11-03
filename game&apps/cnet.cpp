#include <enet/enet.h>
#include <zlib/zlib.h>
#include "sysmain.h"
#include "voxlap5.h"
#include "cnet.h"

#pragma comment(lib, "enet.lib")
#pragma comment(lib, "zdll.lib")

#define MAP_CHUNK 65536

int CNet::init(){
    netstatus=StatusNotConnected;
    msize = currs = 0;
    client=NULL;
    host=NULL;
    host_address.host=NULL;
    host_address.port=0;
    if(enet_initialize()!=0){
        MessageBox(ghwnd, "Enet failed to initialize!", "ERROR", MB_OK);
        return 1;
    }
    client = enet_host_create(NULL, 1, 1, 100000, 100000);

    if(client==NULL){
        MessageBox(ghwnd, "Enet failed to create client", "ERROR", MB_OK);
        return 2;
    }
    if(enet_host_compress_with_range_coder(client)!=0){
        MessageBox(ghwnd, "Enet failed to enable range coding", "ERROR", MB_OK);
        return 3;
    }
    return 0;
}

CNet::~CNet(){
    if(host!=NULL)disconnect_host(0);
    if(client!=NULL)enet_host_destroy(client);
    enet_deinitialize();
}

int CNet::connect_host(char address[], int info){
    ENetEvent event;
    if (strpbrk(address, "aos://")!=NULL){
        int ret = aos_to_ip(address);
        if(ret==1){
            MessageBox(ghwnd, "Failed to set host address", "ERROR", MB_OK);
            return 1;
        }else if(ret==2){
            MessageBox(ghwnd, "Incorrect server version", "ERROR", MB_OK);
            return 2;
        }
    }else{
        MessageBox(ghwnd, "Incorrect address, use an AoS address", "ERROR", MB_OK);
        return 2;
    }

    host = enet_host_connect(client, &host_address, 1, info);
    if(host==NULL){
        MessageBox(ghwnd, "Failed to connect to host. Does not exist?", "ERROR", MB_OK);
        return 3;
    }

    if(enet_host_service(client, &event, 7000) && event.type==ENET_EVENT_TYPE_CONNECT){
        netstatus=StatusWaitingMapC;
        return 0;
    }
    MessageBox(ghwnd, "Failed to establish connection with host", "ERROR", MB_OK);
    return 4;
}

int CNet::disconnect_host(int info){
    if(host!=NULL && netstatus!=StatusNotConnected){
        netstatus=StatusNotConnected;
        enet_peer_disconnect(host, info);
        ENetEvent event;
        while(enet_host_service(client, &event, 2500)>0){
            switch(event.type){
                case ENET_EVENT_TYPE_RECEIVE:
                    enet_packet_destroy(event.packet);
                    break;
                case ENET_EVENT_TYPE_DISCONNECT:
                    enet_peer_reset(host);
                    host=NULL;
            }
        }
    }else if(host!=NULL && netstatus==StatusNotConnected){
        enet_peer_reset(host);
        host=NULL;
    }
    return 0;
}

int CNet::check_packet(pckdata *packet){
    int pckt;
    ENetEvent event;
    if(netstatus==StatusNotConnected)return 3;
    if(netstatus==StatusConnected){pckt=10;}else{pckt=0;}
    if(enet_host_service(client, &event, pckt)>0){
        switch(event.type){
            case ENET_EVENT_TYPE_DISCONNECT:
                MessageBox(ghwnd, "You were disconnected from the host", "", MB_OK);
                return 2;
                break;

            case ENET_EVENT_TYPE_RECEIVE:
                packet->length = event.packet->dataLength-1;
                packet->type = event.packet->data[0];
                packet->data = (BYTE*) malloc(packet->length);
                memcpy(packet->data, &event.packet->data[1], packet->length);
                enet_packet_destroy(event.packet);
                break;
        }
    }else{
        return 1;
    }
    return 0;
}

int CNet::send_packet(pckdata packet){
    return 0;
}

int CNet::handle_packet(pckdata pdata, ...){

    if(netstatus==StatusNotConnected){
        MessageBox(ghwnd, "checked for packet before connected", "ERROR", MB_OK);
        return 5;
    }else if(netstatus==StatusWaitingMapC){

        if(pdata.type==DtaMapStart){
            msize = currs = 0;
            msize = pdata.data[0] | pdata.data[1]<<8 | pdata.data[2]<<16 | pdata.data[3]<<24;
            tmpm = (char*) malloc(msize);
            mapt = 30;
            return 0;

        }else if(pdata.type==DtaMapChunk){
            memcpy(&tmpm[currs], pdata.data, pdata.length);
            currs+=pdata.length;
            if(currs==msize || mapt<=0){
                if(map_pump()){
                    MessageBox(ghwnd, "failed to inflate map data", "ERROR", MB_OK);
                    return 3;

                }else{
                    netstatus=StatusConnected;
                }
                MessageBox(ghwnd, "pump done", "", MB_OK);
            }
            return 0;

        } else if(pdata.type != DtaWorldUpdate &&
                    pdata.type != DtaExistingPlayer &&
                    pdata.type != DtaCreatePlayer){
            if(map_pump()){
                MessageBox(ghwnd, "failed to inflate map data", "ERROR", MB_OK);
                return 3;
            }else{
                netstatus=StatusConnected;
            }
            MessageBox(ghwnd, "pump done", "", MB_OK);
        }
        mapt--;
    }
    return 0;
}

int CNet::map_pump(){
    MessageBox(ghwnd, "decompressing", "", MB_OK);

    int ret;
    unsigned int offs = 0;
    unsigned int have;
    z_stream strm;
    char out[MAP_CHUNK];
    char mapbuff[VSID*VSID];

    strm.zalloc = Z_NULL;
    strm.zfree = Z_NULL;
    strm.opaque = Z_NULL;
    strm.avail_in = 0;
    strm.next_in = Z_NULL;
    ret = inflateInit(&strm);
    if (ret != Z_OK)
        return 1;

    do {
        if(msize-offs>MAP_CHUNK){strm.avail_in=MAP_CHUNK;}else strm.avail_in=msize-offs;
        if (strm.avail_in == 0)
            break;

        do {
            strm.avail_out = MAP_CHUNK;
            strm.next_out = (Bytef*)out;
            ret = inflate(&strm, Z_NO_FLUSH);
            if(ret==Z_STREAM_ERROR){
                MessageBox(ghwnd, "Zlib was unable to inflate the map data", "", MB_OK);
                return 2;
            }
            switch (ret) {
            case Z_NEED_DICT:
                ret = Z_DATA_ERROR;
            case Z_DATA_ERROR:
            case Z_MEM_ERROR:
                (void)inflateEnd(&strm);
                return 3;
            }
            have = MAP_CHUNK - strm.avail_out;
            memcpy(mapbuff+offs, out, have);
            offs+=have;
        } while (strm.avail_out == 0);

    } while (ret != Z_STREAM_END);

    inflateEnd(&strm);

    setspans((vspans*)mapbuff, VSID*VSID, (0,0,0), 0);

    return 0;
}

int CNet::aos_to_ip(char address[]){
    char *buff = address+6;
    char aos[11];
    long ip;
    char ipa[16];
    char port[6];
    char ver[5];

    strncpy(aos, buff, strcspn(buff, ":"));
    buff = strchr(buff, ':')+1;
    strncpy(port, buff, strcspn(buff, ":"));
    buff = strchr(buff, ':')+1;
    strncpy(ver, buff, strcspn(buff, ":"));
    ip = atol(aos);

    wsprintf(ipa, "%d.%d.%d.%d",
             ip&0x000000ff,
             (ip>>8)&0x0000ff,
             (ip>>16)&0x00ff,
             ip>>24);

    if(enet_address_set_host(&host_address, ipa)!=0){
        return 1;
    }else if(strpbrk(ver, "0.75")==NULL)return 2;
    host_address.port = atoi(port);

    return 0;

}

#if 0
#include <stdio.h>
#include <conio.h>
#include <enet/enet.h>

int main(){

    if(enet_initialize() != 0){
        printf("failed to initialize enet\n");
        return 1;
    }

    ENetHost *client;

    client = enet_host_create(NULL, //client host
                              1, //maximum connections
                              1, //number of channels
                              57600 / 8, //any incoming bandwidth
                              14400 / 8); //any outgoing bandwidth

    if(client==NULL){
        printf("failed to create client\n");
        return 2;
    }

    ENetAddress address;
    enet_address_set_host(&address, "localhost");
    address.port=1234;

    ENetPeer * host = enet_host_connect(client, &address, 0, 0);

    if(host==NULL){
        printf("no host exist\n");
        return 3;
    }

    ENetEvent event;
    if(enet_host_service(client, &event, 10000) && event.type==ENET_EVENT_TYPE_CONNECT){
        printf("connected to host\n");
        printf("press escape to quit\n");

        int msgl=0;
        char message[25];
        while(1){
            enet_host_service(client, &event, 250);
            if(event.type==ENET_EVENT_TYPE_DISCONNECT){
                printf("\nyou were disconnected from the host\n");
                break;
            }
            char res=0;
            if(kbhit()){
                res=getch();
                if(res>0x1f && res<0x7f && msgl<24){
                    message[msgl]=res;
                    msgl++;
                    message[msgl]='\0';
                    printf("%c", res);
                }
            }
            if(res==0x1b){ //quit
                enet_peer_disconnect(host, 0);
                while(enet_host_service(client, &event, 3000) > 0){
                    switch(event.type){

                    case ENET_EVENT_TYPE_RECEIVE:
                        enet_packet_destroy(event.packet);
                        break;

                    case ENET_EVENT_TYPE_DISCONNECT:
                        printf("\ndisconnected succesfully\n");
                        break;
                    }
                }
                break;
            }else if(res==0xd){
                ENetPacket *packet = enet_packet_create(message, msgl+1, ENET_PACKET_FLAG_RELIABLE);
                enet_peer_send(host, 0, packet);
                enet_host_flush(client);
                msgl=0;
                printf("\n");
            }
        }
    } else {
        printf("could not find host\n");
        enet_peer_reset(host);
    }

    enet_host_destroy(client);
    enet_deinitialize();
    return 0;
}

#endif // 0
