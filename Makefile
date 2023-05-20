all:
	gcc src\kdtree.c tests\testKdtree.c -o main.exe
	main.exe

linux:
	gcc src\kdtree.c tests\testKdtree.c -o main
	./main

debug:
	gcc -g src\kdtree.c tests\testKdtree.c -o main
	gdb main