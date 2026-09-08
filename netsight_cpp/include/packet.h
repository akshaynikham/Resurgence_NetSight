#pragma once
#include <vector>
#include <cstddef>

class Packet
{
private:
    std::vector<unsigned char> rawBytes;

public:
    Packet(std::vector<unsigned char>&& rawBytes);
    
    unsigned char* getRawBytes() const;
    std::size_t  getPacketSize() const;
};


