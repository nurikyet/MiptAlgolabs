CC = g++
CFLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal\
-Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum\
-Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy\
-Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers\
-Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing\
-Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

all: Tester.exe

Tester.exe: Tester.o 1/BubbleSort.o 1/InsertionSort.o 1/SelectionSort.o 1/ShellSort.o 2/HeapSort.o 3/MergeIterativeSort.o \
3/MergeRecursiveSort.o 4/FlagQsort.o 4/HoaraQsort.o 4/LomutoQsort.o 4/OneBranchHoaraQsort.o 5/CommonQsort.o 5/Median3RandQsort.o \
5/MedianQsort.o 5/RandMedianQsort.o 5/RandQsort.o 6/IntroQSort.o 6/IntroShellSort.o 6/IntroShelllSort.o 8/LSD.o 8/MSD.o
	$(CC) $(CFLAGS) $^ -o $@

Tester.o: Tester.c
	$(CC) $(CFLAGS) -c $^ -o $@

1/BubbleSort.o: 1/BubbleSort.c
	$(CC) $(CFLAGS) -c $^ -o $@

1/InsertionSort.o: 1/InsertionSort.c
	$(CC) $(CFLAGS) -c $^ -o $@

1/SelectionSort.o: 1/SelectionSort.c
	$(CC) $(CFLAGS) -c $^ -o $@

1/ShellSort.o: 1/ShellSort.c
	$(CC) $(CFLAGS) -c $^ -o $@

2/HeapSort.o: 2/HeapSort.c
	$(CC) $(CFLAGS) -c $^ -o $@

3/MergeIterativeSort.o: 3/MergeIterativeSort.c
	$(CC) $(CFLAGS) -c $^ -o $@

3/MergeRecursiveSort.o: 3/MergeRecursiveSort.c
	$(CC) $(CFLAGS) -c $^ -o $@

4/FlagQsort.o: 4/FlagQsort.c
	$(CC) $(CFLAGS) -c $^ -o $@

4/HoaraQsort.o: 4/HoaraQsort.c
	$(CC) $(CFLAGS) -c $^ -o $@

4/LomutoQsort.o: 4/LomutoQsort.c
	$(CC) $(CFLAGS) -c $^ -o $@	

4/OneBranchHoaraQsort.o: 4/OneBranchHoaraQsort.c
	$(CC) $(CFLAGS) -c $^ -o $@	

5/CommonQsort.o: 5/CommonQsort.c
	$(CC) $(CFLAGS) -c $^ -o $@	

5/Median3RandQsort.o: 5/Median3RandQsort.c
	$(CC) $(CFLAGS) -c $^ -o $@	

5/MedianQsort.o:  5/MedianQsort.c
	$(CC) $(CFLAGS) -c $^ -o $@	

5/RandMedianQsort.o: 5/RandMedianQsort.c
	$(CC) $(CFLAGS) -c $^ -o $@	

5/RandQsort.o: 5/RandQsort.c
	$(CC) $(CFLAGS) -c $^ -o $@	

6/IntroQSort.o: 6/IntroQSort.c
	$(CC) $(CFLAGS) -c $^ -o $@	

6/IntroShellSort.o: 6/IntroShellSort.c
	$(CC) $(CFLAGS) -c $^ -o $@	

6/IntroShelllSort.o: 6/IntroShelllSort.c
	$(CC) $(CFLAGS) -c $^ -o $@	

8/LSD.o: 8/LSD.c
	$(CC) $(CFLAGS) -c $^ -o $@	

8/MSD.o: 8/MSD.c
	$(CC) $(CFLAGS) -c $^ -o $@	

clean:
	rm *.o
