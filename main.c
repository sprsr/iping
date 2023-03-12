#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i],"--help") == 0) {
            printf("\nHelp Message!\n");      
        }

        printf("\n%s\n", argv[i]);
    }
   return 0;
}
