CC = g++
CFLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal\
-Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum\
-Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy\
-Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers\
-Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing\
-Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

all: StackArrayRes

StackArrayRes.exe: ArrayMain.o StackArray.o ArrayTester.o
	$(CC) $^ -o $@

ArrayMain.o: ArrayMain.c
	$(CC) $(CFLAGS) -c $^ -o $@

StackArray.o: StackArray.c
	$(CC) $(CFLAGS) -c $^ -o $@

ArrayTester.o: ArrayTester.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm *.o
