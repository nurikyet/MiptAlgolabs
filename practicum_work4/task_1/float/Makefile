CC = g++
CFLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal\
-Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum\
-Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy\
-Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers\
-Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing\
-Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

all: FloatHash

FloatHash: FloatMain.o FloatSolver.o FloatHashFunctions.o
	$(CC) $(CFLAGS) $^ -o $@

FloatMain.o: FloatMain.c
	$(CC) $(CFLAGS) -c $^ -o $@

FloatSolver.o: FloatSolver.c
	$(CC) $(CFLAGS) -c $^ -o $@

FloatHashFunctions.o: FloatHashFunctions.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm *.o
