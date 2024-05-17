CC = g++
CFLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal\
-Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum\
-Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy\
-Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers\
-Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing\
-Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

all: OpenHash

OpenHash: Common.o Main.o Tester.o 
	$(CC) $(CFLAGS) $^ -o $@

Common.o: Common.с
	$(CC) $(CFLAGS) -c $^ -o $@

Main.o: Main.с
	$(CC) $(CFLAGS) -c $^ -o $@

Tester.o: Tester.с
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm *.o
