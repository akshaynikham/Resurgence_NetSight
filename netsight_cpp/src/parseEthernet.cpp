#include <iostream>
#include <cstddef>
#include <cstdint>
#include "parse_status.hpp"
#include "ethernet_info.hpp"
#include "ether_type_definition.hpp"


bool hasEthernetHeader(unsigned char* packet_start, unsigned char* packet_end )
    {
    
        std::size_t available_bytes = packet_end - packet_start;
        std::cout << "Available Bytes: " << static_cast<int>(available_bytes) << '\n';

        return available_bytes >= 14;
    }

// EtherType interpretEtherType(std::uint16_t rawEtherType){
//     switch (rawEtherType)
//     {
//     case 0x0800:
//         return EtherType::IPv4;
    
//     case 0x86DD:
//         return EtherType::IPv6;

//     case 0x0806:
//         return EtherType::ARP;
        
//     default:
//         return EtherType::UNKNOWN;
//     }
// }

// std::string etherTypeToString(EtherType type){
//     switch (type)
//     {
//     case EtherType::IPv4:
//         return "IPv4";

//     case EtherType::IPv6:
//         return "IPv6";

//     case EtherType::ARP:
//         return "ARP";

//     default:
//         return "unknown";
//     }
// }

EthernetInfo parseEthernet(unsigned char* packet_start, unsigned char* packet_end)
{
    EthernetInfo ethernet_info{};

    if(hasEthernetHeader(packet_start,packet_end))
    {
        ethernet_info.rawEtherType = ((*(packet_start + 12) << 8) | *(packet_start + 13) );
        // std::cout << "rawBytes: " << ethernet_info.rawEtherType << '\n';
        // ethernet_info.ethertype  = interpretEtherType(ethernet_info.rawEtherType);
        ethernet_info.ethertype = rawBytesToEtherType(ethernet_info.rawEtherType);
        // std::cout << "EtherType: " << etherTypeToString(ethernet_info.ethertype);
        ethernet_info.parsestatus = ParseStatus::Parsed;
    }else{
        ethernet_info.parsestatus = ParseStatus::Truncated;
    }

    return ethernet_info;

}