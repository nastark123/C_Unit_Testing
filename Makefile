CC=gcc

INCDIR=./include

SRCDIR=./src
SRC=$(wildcard $(SRCDIR)/*.c)
BUILD=$(SRCDIR)/build
OBJ=$(patsubst $(SRCDIR)/%.c, $(BUILD)/%.o, $(SRC))

TARGETDIR=./out

CFLAGS=-I$(INCDIR) -Wall -O0
COFLAGS=-c
# use in future if need to link libs
# LFLAGS

all: unit-test


rebuild: clean all


unit-test: directories $(OBJ)
	$(CC) $(BUILD)/*.o -o $(TARGETDIR)/test


directories:
	@echo Creating directories...
	mkdir -p $(TARGETDIR)
	mkdir -p $(BUILD)
	@echo Directories created


clean:
	rm -f $(TARGETDIR)/*
	rm -f $(BUILD)/*.o


$(OBJ): $(BUILD)/%.o: $(SRCDIR)/%.c
	@echo Compiling utils object $@...
	$(CC) $(CFLAGS) $(COFLAGS) -o $@ $<
	@echo Done
