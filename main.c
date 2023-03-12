#include <stdio.h>
#include <string.h>
#include "iping.h"


int main(int argc, char *argv[]) {

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i],"--help") == 0) {
            printf("\nHelp Message!\n");      
        }
        if (strcmp(argv[i],"--l4") == 0) {
            printf("\nL4  Header\n");
            if (strcmp(argv[i+1], "udp") == 0) {
                printf("\nL4 will be UDP\n"); 
            }
        }
    }
   return 0;
}
