#include "genframe.h"

frame_op* init_frame_op() {
    frame_op* obj = malloc(sizeof(struct frame_op));
    obj->frame_length = 0;
    obj->typeL3 = 0;
    obj->typeL4 = 0;
    return obj;
}

void genframe(frame_op* options) {

    switch (options->typeL3) {
        case IPV4:    
            printf("\nGenerating IPV4 Header\n");
            gen_ipv4_hdr(options); 
        break;
        case IPV6:
            printf("\nGenerating IPV6 Header\n");
    }
    switch (options->typeL4) {
        case TCP:
            printf("\nGenerating TCP Header\n");
        break;
        case UDP:
            printf("\nGenerating UDP Header\n");
        break;
    }
    
}

void gen_ipv4_hdr(frame_op* options) {
    ipv4_hdr* header = malloc(sizeof(struct ipv4_hdr));
    
    header->version      = 4;
    header->ihl          = 5;
    header->tos          = 0;
    header->total_length = options->frame_length;
    header->id           = rand();
    header->flags        = 0;
    header->frag_off     = 0;
    header->ttl          = 255;
    switch (options->typeL4) {
        case (TCP):
            header->protocol = 6;
        break;
        case (UDP):
            header->protocol = 17;
        break;
        default:
            header->protocol = 0;
        break;
    }
    header->checksum = 0;
    header->source_addr = rand();
    header->dest_addr   = rand();

    header->checksum = ipv4_checksum(header);
}

uint16_t ipv4_checksum(ipv4_hdr* header) {
    return 0;
}
