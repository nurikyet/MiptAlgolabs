CC = g++
CFLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal\
-Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum\
-Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy\
-Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers\
-Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing\
-Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

all: Tester.exe

Tester.exe: Tester.o 1/BubbleSort.o 1/InsertionSort.o 1/SelectionSort.o 1/ShellSort.o 2/HeapSort.o 3/MergeIterativeSort.o \
3/MergeRecursiveSort.o 4/FlagQsort.o 4/HoaraQsort.o 4/LomutoQsort.o 4/OneBranchHoaraQsort.o 5/Median3RandQsort.o \
5/MedianQsort.o 5/RandMedianQsort.o 5/RandQsort.o 6/IntroQSort.o 6/IntroShellSort.o 6/IntroShelllSort.o 8/LSD.o 8/MSD.o
	$(CC) $(CFLAGS) $^ -o $@

Tester.o: Tester.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

1/BubbleSort.o: 1/BubbleSort.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

1/InsertionSort.o: 1/InsertionSort.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

1/SelectionSort.o: 1/SelectionSort.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

1/ShellSort.o: 1/ShellSort.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

2/HeapSort.o: 2/HeapSort.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

3/MergeIterativeSort.o: 3/MergeIterativeSort.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

3/MergeRecursiveSort.o: 3/MergeRecursiveSort.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

4/FlagQsort.o: 4/FlagQsort.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

4/HoaraQsort.o: 4/HoaraQsort.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

4/LomutoQsort.o: 4/LomutoQsort.cpp
	$(CC) $(CFLAGS) -c $^ -o $@	

4/OneBranchHoaraQsort.o: 4/OneBranchHoaraQsort.cpp
	$(CC) $(CFLAGS) -c $^ -o $@	

5/Median3RandQsort.o: 5/Median3RandQsort.cpp
	$(CC) $(CFLAGS) -c $^ -o $@	

5/MedianQsort.o:  5/MedianQsort.cpp
	$(CC) $(CFLAGS) -c $^ -o $@	

5/RandMedianQsort.o: 5/RandMedianQsort.cpp
	$(CC) $(CFLAGS) -c $^ -o $@	

5/RandQsort.o: 5/RandQsort.cpp
	$(CC) $(CFLAGS) -c $^ -o $@	

6/IntroQSort.o: 6/IntroQSort.cpp
	$(CC) $(CFLAGS) -c $^ -o $@	

6/IntroShellSort.o: 6/IntroShellSort.cpp
	$(CC) $(CFLAGS) -c $^ -o $@	

6/IntroShelllSort.o: 6/IntroShelllSort.cpp
	$(CC) $(CFLAGS) -c $^ -o $@	

8/LSD.o: 8/LSD.cpp
	$(CC) $(CFLAGS) -c $^ -o $@	

8/MSD.o: 8/MSD.cpp
	$(CC) $(CFLAGS) -c $^ -o $@	

clean:
	rm *.o
