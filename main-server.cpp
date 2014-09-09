#include <stdio.h>
#include <conio.h>
#include <enet/enet.h>

int main(){

    if(enet_initialize() != 0){
        printf("failed to initialize enet\n");
        return 1;
    }

    ENetAddress address;
    ENetHost *server;

    address.host = ENET_HOST_ANY;
    address.port = 1234;

    server = enet_host_create(&address,
                              32, //maximum clients
                              1, //number of communication channels
                              0, //any incoming bandwidth
                              0); //any outgoing bandwidth

    if(server==NULL){
        printf("failed to create server\n");
        return 2;
    }

    ENetEvent event;
    printf("press escape to quit\n");

    while(1){
        enet_host_service(server, &event, 1000);
        switch(event.type){
        case ENET_EVENT_TYPE_CONNECT:
            printf("A new client has connected: %x\n",
                   event.peer->address.host);
                   event.peer->data=(char*)event.peer->address.host;
            break;

        case ENET_EVENT_TYPE_RECEIVE:
            printf("Message from %x: %s\n",
                   event.peer->data,
                   event.packet->data);
            enet_packet_destroy(event.packet);
            break;

        case ENET_EVENT_TYPE_DISCONNECT:
            printf("Client %x disconnected\n",
                   (unsigned int)event.peer->data);
            event.peer->data=NULL;
            break;
        }

        if(kbhit())
            if(getch()==0x1b)
                break;

    }

    enet_host_destroy(server);
    enet_deinitialize();
    printf("server shutdown\n");
    return 0;
}
