#include "iping.h"
#include <stdio.h>
#include <stdlib.h>
#include "genframe.h"

frame_op* init_frame_op() {
    frame_op* obj = malloc(sizeof(struct frame_op));
    obj->typeL3 = 0;
    obj->typeL4 = 0;
    return obj;
}

void genframe(frame_op* options) {

    switch (options->typeL3) {
        case IPV4:    
            printf("\nGenerating IPV4 Header\n");
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
