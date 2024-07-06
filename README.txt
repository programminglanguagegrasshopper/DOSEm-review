DOSEm - A DOS programs emulator

This program is written in C and compiled in GCC (GNU C Compiler)
Also this DOS emulator only works on Windows.

Q&A:

Q1. If 'dosemh.h' is supposed to be the commands file, then why help and close commands work?
	A. They are accepted on dosemf.c, because 'close' would throw a error.

Q2. Why it throws a library error?
	A. If you don´t have the neccesary libraries, then go install MinGW.

Q3. When i run some DOS programs (like .COM or .EXE) it throws a global OS error, What do i do?
	E: Windows 10/7/8.1/8/7 may not support MS-DOS running from the terminal.
	A. Run DOSEm in 16-bit mode, or run it inside a Windows XP / Vista virtual machine. If none of these work,
	   then if you have a old PC, verify for it to be x32 or to have a 32-bit processor.

Q4. Does it support 2 formats or only one?
	A. It supports 2 file formats. EXE & COM.

Q5. When i compile and run the program, it throws a uncompatible error.
	E: This can happen on VS Code, VS Community or even GCC.
	A. If you have GCC, type this on the terminal:
			gcc -o dosem.exe dosemf.c
	   and then type:
			.\dosem.exe