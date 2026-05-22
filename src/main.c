#include <sys/socket.h>
#include <net/ethernet.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <netpacket/packet.h>

int main(){

    int sock = socket( AF_INET, SOCK_RAW, htons(ETH_P_ALL));

    if(sock >=0){
        printf("Success! %d\n", sock);
    }else{
        printf("failed!");
    }
}