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
