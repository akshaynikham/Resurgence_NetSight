#include <iostream>
#include <cstddef>
#include <cstdint>
#include "packet_info.hpp"
#include "ether_type.hpp"
#include "ethernet_info.hpp"
#include "parse_status.hpp"
#include "parseEnumStatus.hpp"
#include "ether_type_definition.hpp"
#include "parseEnumStatus.hpp"
void greet();
EthernetInfo parseEthernet();
std::string etherTypeToDisplay();
std::string parseEnumStatusToString();


std::string protocolToString(Protocol protocol)
{
    switch (protocol)
    {
        case Protocol::TCP:
            return "TCP";

        case Protocol::UDP:
            return "UDP";

        case Protocol::ICMP:
            return "ICMP";

        default:
            return "Unknown";
    }
}

std::string etherTypeToString(EtherType type){
    switch (type)
    {
    case EtherType::IPv4:
        return "IPv4";

    case EtherType::IPv6:
        return "IPv6";

    case EtherType::ARP:
        return "ARP";

    default:
        return "unknown";
    }
}

bool hasEthernetHeaders(unsigned char* packet_start, unsigned char* packet_end ){
    
    std::size_t available_bytes = packet_end - packet_start;
    std::cout << "Available Bytes: " << static_cast<int>(available_bytes) << '\n';

    return available_bytes >= 14;
}

EtherType interpretEtherType(std::uint16_t rawEtherType){

    switch (rawEtherType)
    {
    case 0x0800:
        return EtherType::IPv4;
    
    case 0x86DD:
        return EtherType::IPv6;

    case 0x0806:
        return EtherType::ARP;
        
    default:
        return EtherType::UNKNOWN;
    }
}

int main()
{

    std::cout << "NetSight v0.1\n";
    std::cout << "Packet parser intializing....\n";
    greet();

    PacketInfo packet{};
    packet.protocol = Protocol::TCP;

    std::cout << "packetLength:" << packet.packetLength << '\n' ;
    std::cout << "EtherType:" << packet.EtherType << '\n' ;
    std::cout << "ip_version:" << packet.ip_version << '\n' ;
    std::cout << "protocol:" << protocolToString(packet.protocol) << '\n' ;

    unsigned char packets[20];
    packets[12] = 0x09;
    packets[13] = 0x90;

    // std::cout << static_cast<const void*>(packets) << '\n';
    // std::cout << static_cast<const void*>(packets + 1) << '\n';
    // std::cout << static_cast<const void*>(packets + 14) << '\n';
    // std::cout << static_cast<int>(*(packets + 14)) << '\n';
    // std::uint16_t ethertype = ((packets[12] << 8) | packets[13]);
    // std::cout << ethertype << '\n';

    unsigned char* packet_start = packets;
    unsigned char* packet_end = packets + 20;
    
    // unsigned char available_bytes = packet_end - packet_start;
    // std::cout << "Available Bytes: " << static_cast<int>(available_bytes) << '\n';
    bool etherHeaderPresent = hasEthernetHeaders(packet_start,packet_end);

    std::cout << "Ehternet header present: " << etherHeaderPresent << '\n';

    if(etherHeaderPresent){
        std::uint16_t ethertype = ((packets[12] << 8) | packets[13]);
        std::cout << "ethertype: " << ethertype << '\n';
        EtherType type = interpretEtherType(ethertype);
        std::cout << "EtherType: " << etherTypeToString(type) << '\n';
    }
    
    // std::cout << EtherType::IPv4 << '\n';
    // EtherType type = EtherType::IPv4;

    // std::cout << "EtherType: " << etherTypeToString(type) << '\n';

    EthernetInfo etherInfo = parseEthernet(packet_start, packet_end);
    std::cout << "RawBytes: " << etherInfo.rawEtherType << '\n';
    std::cout << "EtherType: " << etherTypeToDisplay(etherInfo.ethertype)  << '\n';
    std::cout << "ParseStatus: " << parseEnumStatusToString(etherInfo.parsestatus) << '\n';

    

}