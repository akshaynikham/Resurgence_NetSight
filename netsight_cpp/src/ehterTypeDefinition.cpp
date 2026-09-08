#include<cstdint>
#include<cstddef>
#include<iostream>
#include "ether_type_definition.hpp"

EtherTypeDefinition etherTypes[]{
    {0x0800, EtherType::IPv4, "IPv4"},
    {0x86DD, EtherType::IPv6, "IPv6"},
    {0x0806, EtherType::ARP,  "ARP"}
};

EtherType rawBytesToEtherType(std::uint16_t rawEtherType){

    size_t size = sizeof(etherTypes)/sizeof(etherTypes[0]);    
    for(int i=0; i<size; i++){
        if(etherTypes[i].rawvalue == rawEtherType){
            return etherTypes[i].type;
        }
    }
    return EtherType::UNKNOWN;
}

std::string etherTypeToDisplay(EtherType ethertype){

    size_t size = sizeof(etherTypes)/sizeof(etherTypes[0]);
    for(int i=0; i<size;i++){
        if(etherTypes[i].type == ethertype){
            return etherTypes[i].name;
        }
    }
    return "Unknown";
}