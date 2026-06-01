#include <sys/socket.h>
#include <net/ethernet.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <linux/if_packet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <unistd.h>


int main(){

    int sock_fd = socket( AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));

    if(sock_fd >=0){
        printf("Success! %d\n", sock_fd);
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

    struct sockaddr_ll sll;

    sll.sll_family = AF_PACKET;
    sll.sll_protocol = htons(ETH_P_ALL);
    sll.sll_ifindex = index;

    if(bind(sock_fd, (struct sockaddr *)&sll, sizeof(sll)) < 0){
        perror("failed to bind");
    }else{
        printf("bind succeeded\n");
    }


    close(sock_fd);

    
    return 0;
}