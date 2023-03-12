// iping.h: a header file for iping.c
#ifndef IPING_H // include guard to prevent multiple inclusion
#define IPING_H

// Standard Library Headers
#include <stdint.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>
// #include <sys/socket.h>
// #include <netinet/in.h>
// #include <arpa/inet.h>

//Some Useful Structures for Managing Traffic Generation
/////////////////////////////////////////////////
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
//      For more information: RFC/rfc768.txt
/////////////////////////////////////////////////
struct udp_hdr {
    uint16_t source_port;   // Destination Port.  Port of the sending process, may be assumed.  If not used, 0.
    uint16_t dest_port;     // Destination Port. Required. 
    uint16_t length;        // Length of this header + data
    uint16_t checksum;      // Checksum.  16 bit ones complement of the one's complement sum of a pseudo header + this header + data.
};

//
#endif /* IPING_H */
