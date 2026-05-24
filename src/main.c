#include <sys/socket.h>
#include <net/ethernet.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <netpacket/packet.h>
#include <net/if.h>

int main(){

    int sock = socket( AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));

    if(sock >=0){
        printf("Success! %d\n", sock);
    }else{
        perror("Socket creation failed");
        return 1;
    }

    const char *name = "enp0s3";
    unsigned int index = if_nametoindex(name);

    if(index == 0){
        perror("if_nametoindex failed:");
    }
    else{
        printf("Interface %s has index %u\n", name, index);
    }

    close(sock);

    
    return 0;
}