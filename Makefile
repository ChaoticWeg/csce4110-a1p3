INCDIR=inc
SRCDIR=src
OUTDIR=out
BINDIR=bin

CC=g++

.PHONY: all generate clean

all: generate
generate: $(OUTDIR)/generate.out

clean:
	@find bin -type f -exec rm -f {} +
	@find out -name '*.out' -type f -exec rm -f {} +

%.o: CFLAGS=-c

$(OUTDIR)/generate.out: generate.cpp args gen
	$(CC) -I$(INCDIR) -L$(BINDIR) -largs -lgen -o $@ $<

args: $(BINDIR)/libargs.so

$(BINDIR)/libargs.so: $(SRCDIR)/args.cpp
	$(CC) -I$(INCDIR) -c -o $@ $<

gen: $(BINDIR)/libgen.so

$(BINDIR)/libgen.so: $(SRCDIR)/generator.cpp
	$(CC) -I$(INCDIR) -c -o $@ $<
