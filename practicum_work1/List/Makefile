CC = g++
CFLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal\
-Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum\
-Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy\
-Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers\
-Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing\
-Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

all: StackListRes.exe

StackListRes.exe: ListMain.o StackList.o ListTester.o
	$(CC) $^ -o $@

ListMain.o: ListMain.c
	$(CC) $(CFLAGS) -c $^ -o $@

StackList.o: StackList.c
	$(CC) $(CFLAGS) -c $^ -o $@

ListTester.o: ListTester.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm *.o
