CC = gcc
CFLAGS = -Wall -Werror -g
LDFlags = -Wall -Werror -g

.PHONY: all 
all: testNAC

testNAC: testNAC.o NAC.o
testNAC.o: testNAC.c NAC.h
NAC.o: NAC.c NAC.h

.PHONY: clean 
clean: 
	-rm -f runTests testNAC.o NAC.o