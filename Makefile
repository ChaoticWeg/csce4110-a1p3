INCDIR=inc
SRCDIR=src
OUTDIR=out
BINDIR=bin
RUNDIR=run

CC=g++

.PHONY: all clean generate check sorts quicksort countingsort

all: generate check quicksort 
generate: $(OUTDIR)/generate.out
check: $(OUTDIR)/check.out

sorts: quicksort countingsort
quicksort: $(OUTDIR)/sort/quicksort.out
countingsort: $(OUTDIR)/sort/countingsort.out


# remove all output files

clean:
	@find bin -type f -exec rm -f {} +
	@find out -name '*.out' -type f -exec rm -f {} +


# build integer-generation files

$(OUTDIR)/generate.out: $(RUNDIR)/generate.cpp args gen
	$(CC) -I$(INCDIR) -L$(BINDIR) -largs -lgen -o $@ $<


# build uniqueness-checking files

$(OUTDIR)/check.out: $(RUNDIR)/check.cpp bst
	$(CC) -I$(INCDIR) -L$(BINDIR) -lbst -o $@ $<


# quicksort algorithm

$(OUTDIR)/sort/quicksort.out: $(SRCDIR)/sort/quicksort.cpp
	$(CC) -I$(INCDIR) -o $@ $<


# counting-sort algorithm

$(OUTDIR)/sort/countingsort.out: $(SRCDIR)/sort/countingsort.cpp
	$(CC) -I$(INCDIR) -o $@ $<


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
