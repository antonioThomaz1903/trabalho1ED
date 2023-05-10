all:
	gcc src/main.c -o main.exe
	./main.exe

windows:
	gcc src/main.c -o main.exe
	./main.exe

linux:
	gcc src/main.c -o main
	./main
	