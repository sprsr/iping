#include <stdio.h>
#include <string.h>
#include "iping.h"
#include "genframe.h"

int main(int argc, char *argv[]) {

    frame_op* options = init_frame_op();         

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i],"--help") == 0) {
            printf("\nHelp Message!\n");      
        }
        if (strcmp(argv[i],"--l3") == 0) {
            if (strcmp(argv[i+1], "ipv4") == 0) {
                options->typeL4 = IPV4;
                options->frame_length += 20;
            }
            else if (strcmp(argv[i+1], "ipv6") == 0) {
                options->typeL4 = IPV4;
                options->frame_length += 40;
            }
        }
        if (strcmp(argv[i],"--l4") == 0) {
            if (strcmp(argv[i+1], "tcp") == 0) {genframe(options);
                options->typeL3 = TCP;
                options->frame_length += 20;
            }
            else if (strcmp(argv[i+1], "udp")==0) {
                options->typeL4 = UDP;
                options->frame_length += 8;
            }
        }
        
    }
    genframe(options);
    return 0;
}
