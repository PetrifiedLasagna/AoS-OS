#ifndef CLIENT_NET_H
#define CLIENT_NET_H

#include <enet/enet.h>

#define TIME_CHECK 1

enum{
DtaPositionData,DtaOrientationData,DtaWorldUpdate,DtaInputData,DtaWeaponInput,DtaHitPacket,DtaGrenadePacket,DtaSetTool,DtaSetColor,DtaExistingPlayer,DtaShortPlayerData,DtaMoveObject,DtaCreatePlayer,DtaBlockAction,
DtaBlockLine,DtaStateData,DtaKillAction,DtaChatMessage,DtaMapStart,DtaMapChunk,DtaPlayerLeft,DtaTerritoryCapture,
DtaProgressBar,DtaIntelCapture,DtaIntelPickup,DtaIntelDrop,DtaRestock,DtaFogColor,DtaWeaponReload,DtaChangeTeam,DtaChangeWeapon
};

enum{
StatusNotConnected,StatusWaitingMapS,StatusWaitingMapC,StatusConnected
};

class CNet{
public:
    int netstatus;
    int init();
    ~CNet();
    int connect_host(char address[], int info);
    int disconnect_host(int info);
    int check_packet(BYTE **packet);
    int send_packet(BYTE *packet);
    int handle_packet(BYTE *pdata, ...);
private:
    char *tmpm;
    UINT32 currs;
    UINT32 msize;
    ENetHost *client;
    ENetPeer *host;
    ENetAddress host_address;
    ENetEvent event;

    int aos_to_ip(char address[]);
};

#endif // CLIENT_NET_H
