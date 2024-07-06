// Header for DOSEm

#include <stdio.h>
#include <windows.h>
#include <direct.h>

void gotodir(char dirc[256]){

    printf("\nGO TO DIRECTORY: ");
    fgets(dirc, 256, stdin);

    size_t len = strlen(dirc);
    if (len > 0 && dirc[len-1] == '\n') {
        dirc[len-1] = '\0';
    }

    if (_chdir(dirc) == 0) {
        printf("\nSuccessfully changed current directory to \"%s\"", dirc);
    } else {
        printf("\nERR1: Failed to change directory to \"%s\"", dirc);
    }
}

void exec(char dosprog[]){
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    si.dwFlags = STARTF_USESHOWWINDOW;
    si.wShowWindow = SW_SHOWNORMAL;

    ZeroMemory(&pi, sizeof(pi));

    // Create the command to run the program
    char commandexec[256];
    snprintf(commandexec, sizeof(commandexec), "cmd.exe /c start %s", dosprog);

    // Start the DOS program
    if (!CreateProcess(NULL, commandexec, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
    {
        printf("\nERR2: Failed to run %s\n", dosprog);
        return;
    }

    // Wait for the process to exit
    WaitForSingleObject(pi.hProcess, INFINITE);

    // Close process and thread handles
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    printf("\nRunning program: %s\n", dosprog);
    printf("Your windows version may not support this program. ");
    printf("See processor info (you may have 32-bit or 64-bit)\n");
}

void help(){
    printf("\nhelp - Shows a list of commands.");
    printf("\ngotodir - Changes current directory.");
    printf("\nclose - Closes the window.");
    printf("\nexec - Executes a DOS program.\n");
}
