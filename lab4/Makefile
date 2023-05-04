all: createThreads parallel1 parallel2 parallel3

createThreads: createThreads.c
	gcc createThreads.c -std=c99 -lpthread -Wno-implicit-function-declaration -o createThreads

parallel1: parallel1.c
	gcc parallel1.c -std=c99 -lpthread -Wno-implicit-function-declaration -o parallel1

parallel2: parallel2.c
	gcc parallel2.c -std=c99 -lpthread -Wno-implicit-function-declaration -o parallel2

parallel3: parallel3.c
	gcc parallel3.c -std=c99 -lpthread -Wno-implicit-function-declaration -o parallel3
