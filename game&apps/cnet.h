#ifndef CLIENT_NET_H
#define CLIENT_NET_H

#include <enet/enet.h>

#define TIME_CHECK 1

struct pckdata{
    int type;
    int length;
    BYTE *data;
};

enum{
DtaPositionData,DtaOrientationData,DtaWorldUpdate,DtaInputData,DtaWeaponInput,DtaHitPacket,DtaGrenadePacket,DtaSetTool,DtaSetColor,DtaExistingPlayer,DtaShortPlayerData,DtaMoveObject,DtaCreatePlayer,DtaBlockAction,
DtaBlockLine,DtaStateData,DtaKillAction,DtaChatMessage,DtaMapStart,DtaMapChunk,DtaPlayerLeft,DtaTerritoryCapture,
DtaProgressBar,DtaIntelCapture,DtaIntelPickup,DtaIntelDrop,DtaRestock,DtaFogColor,DtaWeaponReload,DtaChangeTeam,DtaChangeWeapon
};

enum{
StatusNotConnected,StatusWaitingMapC,StatusConnected
};

class CNet{
public:
    unsigned long int currs;
    unsigned int msize;
    int netstatus;
    int init();
    ~CNet();
    int connect_host(char address[], int info);
    int disconnect_host(int info);
    int check_packet(pckdata *packet);
    int send_packet(pckdata packet);
    int handle_packet(pckdata packet, ...);
private:
    unsigned int mapt;
    char *tmpm;
    ENetHost *client;
    ENetPeer *host;
    ENetAddress host_address;

    int map_pump();
    int aos_to_ip(char address[]);
};

#endif // CLIENT_NET_H
