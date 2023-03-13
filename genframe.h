#include "iping.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct frame_op {
    int frame_length;
    int typeL3;
    int typeL4;
}frame_op;
frame_op* init_frame_op();
void genframe(frame_op* options);
void gen_ipv4_hdr(frame_op* options);
uint16_t ipv4_checksum(ipv4_hdr* header);
