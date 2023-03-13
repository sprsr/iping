// iping.h: a header file for iping.c
#ifndef IPING_H // include guard to prevent multiple inclusion
#define IPING_H

// Standard Library Headers
#include <stdint.h>
#include <stdio.h>

// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>
// #include <sys/socket.h>
// #include <netinet/in.h>
// #include <arpa/inet.h>

// Constants
#ifndef IPV4
#define IPV4 1
#endif
#ifndef IPV6
#define IPV6 2
#endif
#ifndef TCP
#define TCP 1
#endif
#ifndef UDP
#define UDP 2
#endif

// Type Defs
typedef __uint128_t uint128_t;



//Some Useful Structures for Managing Traffic Generation
//////////////////////////////////////////////////////////////////////////
///   IPV4 Header Format
//    0                   1                   2                   3
//    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
//   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//   |Version|  IHL  |Type of Service|          Total Length         |
//   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//   |         Identification        |Flags|      Fragment Offset    |
//   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//   |  Time to Live |    Protocol   |         Header Checksum       |
//   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//   |                       Source Address                          |
//   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//   |                    Destination Address                        |
//   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//   |                    Options                    |    Padding    |
//   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//   For more information: Resources/RFC791.txt   
/////////////////////////////////////////////////////////////////////////
typedef struct ipv4_hdr {
    uint8_t ihl:4,version:4;
    uint8_t tos;
    uint16_t total_length;
    uint16_t id;
    uint16_t frag_off:13,flags:3;
    uint8_t ttl;
    uint8_t protocol;
    uint16_t checksum;
    uint32_t source_addr;
    uint32_t dest_addr;
    //Note that options and padding are not included in the ipv4_hdr struct
}ipv4_hdr;

//////////////////////////////////////////////////////////////////////////
//   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//   |Version| Traffic Class |           Flow Label                  |
//   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//   |         Payload Length        |  Next Header  |   Hop Limit   |
//   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//   |                                                               |
//   +                                                               +
//   |                                                               |
//   +                         Source Address                        +
//   |                                                               |
//   +                                                               +
//   |                                                               |
//   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//   |                                                               |
//   +                                                               +
//   |                                                               |
//   +                      Destination Address                      +
//   |                                                               |
//   +                                                               +
//   |                                                               |
//   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

//////////////////////////////////////////////////////////////////////////

typedef struct ipv6_hdr {
    uint32_t flow_label:20,traffic_class:8,version:4;
    uint16_t payload_length;
    uint8_t next_header;
    uint8_t hop_limit;
    uint128_t source_addr;
    uint128_t dest_addr;
    //Note that the ipv6_hdr struct does not include extension headers
};
//////////////////////////////////////////////////////////////////////////
//
//      User Data Protocol Header Format
//      0      7 8     15 16    23 24    31
//      +--------+--------+--------+--------+
//      |     Source      |   Destination   |
//      |      Port       |      Port       |
//      +--------+--------+--------+--------+
//      |                 |                 |
//      |     Length      |    Checksum     |
//      +--------+--------+--------+--------+
//
//      For more information: Resources/RFC768.txt
//////////////////////////////////////////////////////////////////////////
struct udp_hdr {
    uint16_t source_port;   // Destination Port.  Port of the sending process, may be assumed.  If not used, 0.
    uint16_t dest_port;     // Destination Port. Required. 
    uint16_t length;        // Length of this header + data
    uint16_t checksum;      // Checksum.  16 bit ones complement of the one's complement sum of a pseudo header + this header + data.
};


//////////////////////////////////////////////////////////////////////////
//    Transmission Control Protocol Header Format
//    0                   1                   2                   3
//    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
//   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//   |          Source Port          |       Destination Port        |
//   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//   |                        Sequence Number                        |
//   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//   |                    Acknowledgment Number                      |
//   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//   |  Data |       |C|E|U|A|P|R|S|F|                               |
//   | Offset| Rsrvd |W|C|R|C|S|S|Y|I|            Window             |
//   |       |       |R|E|G|K|H|T|N|N|                               |
//   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//   |           Checksum            |         Urgent Pointer        |
//   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//   |                           [Options]                           |
//   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//   |                                                               :
//   :                             Data                              :
//   :                                                               |
//   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//   For more information: Resources/RFC9293.txt
//////////////////////////////////////////////////////////////////////////
struct tcp_hdr {
    uint16_t source_port;    //Source Port
    uint16_t dest_port;
    uint32_t seq_number;
    uint32_t ack_number;
    uint8_t  rsrvd:4, d_off:4;
    uint8_t  flags;
    uint16_t window;
    uint16_t checksum;
    uint16_t urgentpointer;
    //Note that there may be aditional options for TCP Header.  
    //The tcp_hdr struct only contains base.
};
#endif /* IPING_H */
