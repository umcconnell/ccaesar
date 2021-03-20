# Basic config
IDIR =include/
CC=gcc
CFLAGS=-I$(IDIR) -Wall -Wextra -pedantic -std=c99 -O3

# Object files
ODIR=src
_OBJ = main.o caesar.o cli.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

# Libraries
LDIR =../lib
LIBS= 

# Dependencies
_DEPS = caesar.h cli.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

# Make object files (%.o) from their corresponding source files (%.c) including
# their dependencies ($(DEPS))
$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# Make the main executable and clean up afterwards
ccaesar: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
	make clean

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 

# Tests (make -B test)
# Required dependencies: valgrind (https://www.valgrind.org/)
test1:
	cat test/test.txt | ./ccaesar -s 7 | diff test/test-expected.txt -

test2:
	cat test/test2.txt | ./ccaesar -s 26 | diff test/test2.txt -

test3:
	cat test/test2.txt | ./ccaesar -s 11 | ./ccaesar -s -11 | diff test/test2.txt -

test4:
	cat test/test2.txt | valgrind ./ccaesar -s 11 -n -c >/dev/null

test: ccaesar
	make test1
	make test2
	make test3
	make test4


# Benchmark (make -B bench)
# Required dependencies: hyperfine (https://github.com/sharkdp/hyperfine)
bench: ccaesar
	hyperfine --warmup 3 'cat test/test2.txt | ./ccaesar -s 7 -c'