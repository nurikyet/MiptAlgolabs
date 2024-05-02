CC = g++
CFLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal\
-Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum\
-Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy\
-Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers\
-Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing\
-Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

all: HeapInsertTester

HeapInsertTester: HeapInsertMain.o ../Heap.o ../BinHeapTester.o HeapInsertAlgo.o
	$(CC) $(CFLAGS) $^ -o $@

HeapInsertMain.o: HeapInsertMain.c
	$(CC) $(CFLAGS) -c $^ -o $@

../Heap.o: ../Heap.c
	$(CC) $(CFLAGS) -c $^ -o $@

../BinHeapTester.o: ../BinHeapTester.c
	$(CC) $(CFLAGS) -c $^ -o $@

HeapInsertAlgo.o: HeapInsertAlgo.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm *.o
