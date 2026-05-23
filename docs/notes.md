***Project Name: Resurgence_NetSight***

Goal: Build a packet snipping tool >> Integrate with main project >> Build Strong Fundamentals >> Cybersecurity Mastery.

---

Socket():

The function is defined in the <sys/socket.h> header:

int socket(int domain, int type, int protocol);

- domain: Specifies the communication domain or protocol family.
- AF_INET: IPv4 Internet protocols.
- AF_INET6: IPv6 Internet protocols.
- AF_UNIX or AF_LOCAL: Local communication on the same host.

- type: Specifies the communication semantics (style).
- SOCK_STREAM: Provides reliable, two-way, connection-based byte streams (typically TCP).
- SOCK_DGRAM: Supports datagrams (connectionless, unreliable messages like UDP).
- SOCK_RAW: Provides raw network protocol access.

- protocol: Specifies a particular protocol to be used with the socket. 
- Normally, only a single protocol exists to support a particular socket type within a given protocol family, in which case protocol can be specified as 0


Sockets Connection Phases:

1. When app executes the socket() system call, we are telling the OS: "Hey, I'm going to need to do some networking soon. Set aside some RAM for me."The kernel sets up the blank memory buffers, creates the internal data structure, and gives a number (the File Descriptor, like 3).At this exact second, this socket has no IP address and no Port number assigned to it yet. It is just an empty, unconfigured container in the kernel's memory.

2. Once we take that blank socket container (File Descriptor 3) and actually connect it to the internet (using bind() or connect()), it fills up with real network data. To the rest of the internet, the socket is invisible unless it has three specific things:
    1. An IP Address: So packets know which computer to go to.
    2. A Port Number: So the computer knows which specific app gets the packets.
    3. A Protocol (TCP/UDP): So the network card knows how to format the packets. Therefore, a fully operational socket endpoint on a network is defined by that unique trio.

3. We pass an argument into socket() to tell the kernel what network universe this socket belongs to. 
This is the "Domain".
    1. If we choose AF_INET, you are telling the kernel: "Construct this socket's memory structure to understand 32-bit IPv4 addresses, because I plan to talk to the global internet."
    2. If we choose AF_UNIX, we are telling the kernel: "Don't worry about internet rules, IP addresses, or network cards. I am only using this to talk to another app on this exact same hard drive. Optimize the memory buffers for speed."


**Mapping Sockets to the OSI Model**

  OSI LAYER          DATA UNIT      WHAT HANDLES IT      SYSTEM CALLS / MECHANICS
 ────────────       ───────────    ─────────────────    ──────────────────────────────
  7. Application     Data           Your Application     Chrome / Python Code (`import socket`)
  6. Presentation    Data           Libraries / App      SSL/TLS Encryption, JSON parsing
  5. Session         Data           OS Kernel / API      socket(), bind(), listen(), accept()
 ─────────────────────────────────── SOCKET BOUNDARY ─────────────────────────────────────
  4. Transport       Segment        OS TCP/IP Stack      connect(), Send/Receive Buffers, Ports
  3. Network         Packet         OS TCP/IP Stack      IP Addresses, Routing Tables
  2. Data Link       Frame          Network Driver/NIC   MAC Addresses, Ethernet Frames (AF_PACKET)
  1. Physical        Bits           Physical Cables      Wi-Fi Radio Waves, Ethernet Copper Voltages


**sockaddr_in structure Layer3/4**

struct sockaddr_in {
    short int          sin_family;  // 2 Bytes: Address family (Always set to AF_INET)
    unsigned short int sin_port;    // 2 Bytes: Port number (Stored in Network Byte Order)
    struct in_addr     sin_addr;    // 4 Bytes: The IPv4 Address structure (see below)
    unsigned char      sin_zero[8]; // 8 Bytes: Pure padding (Filled with zeros to make it 16 bytes)
};

The Nested IP Address Structure:

struct in_addr {
    unsigned int s_addr;            // 4 Bytes: The raw 32-bit IPv4 address (e.g., 0x7F000001 for 127.0.0.1)
};


**sockaddr_ll structure Layer2**

struct sockaddr_ll {
    unsigned short sll_family;   // 2 Bytes: Address family (Always set to AF_PACKET)
    unsigned short sll_protocol; // 2 Bytes: Physical Protocol (EtherType, e.g., ETH_P_IP or ETH_P_ARP)
    int            sll_ifindex;  // 4 Bytes: Network Interface Index (The system ID for eth0, wlan0, etc.)
    unsigned short sll_hatype;   // 2 Bytes: Hardware Address Type (e.g., ARPHRD_ETHER for standard Ethernet)
    unsigned char  sll_pkttype;  // 1 Byte:  Packet Type (e.g., PACKET_HOST for us, PACKET_BROADCAST)
    unsigned char  sll_halen;    // 1 Byte:  Length of the physical MAC address (Always 6 bytes for Ethernet)
    unsigned char  sll_addr[8];  // 8 Bytes: The actual Physical MAC Address (Only 6 bytes used, 2 bytes padding)
};