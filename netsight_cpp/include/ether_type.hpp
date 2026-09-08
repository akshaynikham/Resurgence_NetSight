#pragma once

enum class EtherType {
    IPv4 = 0x0800,
    IPv6 = 0x86DD,
    ARP = 0x0806,
    UNKNOWN = 0
};