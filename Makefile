INCDIR=inc
SRCDIR=src
OUTDIR=out
BINDIR=bin

CC=g++

.PHONY: all clean generate check

all: generate check
generate: $(OUTDIR)/generate.out
check: $(OUTDIR)/check.out


# remove all output files

clean:
	@find bin -type f -exec rm -f {} +
	@find out -name '*.out' -type f -exec rm -f {} +


# build integer-generation files

$(OUTDIR)/generate.out: generate.cpp args gen
	$(CC) -I$(INCDIR) -L$(BINDIR) -largs -lgen -o $@ $<


# build uniqueness-checking files

$(OUTDIR)/check.out: check.cpp bst
	$(CC) -I$(INCDIR) -L$(BINDIR) -lbst -o $@ $<


# argument-parsing library (written by me)

args: $(BINDIR)/libargs.so

$(BINDIR)/libargs.so: $(SRCDIR)/args.cpp
	$(CC) -I$(INCDIR) -c -o $@ $<


# integer-generating library (written by me)

gen: $(BINDIR)/libgen.so

$(BINDIR)/libgen.so: $(SRCDIR)/generator.cpp
	$(CC) -I$(INCDIR) -c -o $@ $<


# binary search tree library (written by me)

bst: $(BINDIR)/libbst.so

$(BINDIR)/libbst.so: $(SRCDIR)/bst.cpp
	$(CC) -I$(INCDIR) -c -o $@ $<
