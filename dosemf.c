#include <stdio.h>
#include <windows.h>
#include <direct.h>
#include "dosemh.h"

int main(){

    char dirc[256];
    char command[256];

    printf("DOSEm v1.0\n");
    printf("Type \"help\" for a list of commands.\n");

    while (1) {
        printf("\n>>> ");
        fgets(command, 256, stdin);

        size_t len = strlen(command);
        if (len > 0 && command[len-1] == '\n') {
            command[len-1] = '\0';
        }

        if (strcmp(command, "gotodir") == 0) {
            gotodir(dirc);
        } else if (strcmp(command, "exec") == 0) {
            char dosprog[256];
            printf("\nEnter MS-DOS program name to run: ");
            fgets(dosprog, 256, stdin);

            len = strlen(dosprog);
            if (len > 0 && dosprog[len-1] == '\n') {
                dosprog[len-1] = '\0';
            }

            exec(dosprog);
        
        } else if(strcmp(command, "help") == 0){
            help();

        } else if (strcmp(command, "close") == 0) {
            break;
        } else {
            printf("Invalid command or too much parameters.");
        }

    }

    return 0;
}