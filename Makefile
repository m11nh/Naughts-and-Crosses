CC = gcc
CFLAGS = -Wall -Werror -g
LDFlags = -Wall -Werror -g

.PHONY: all 
all: NACrun

NACrun: NACrun.o NAC.o NACview.o
NACrun.o: NACview.o NAC.o NACview.h
NACview.o: NACview.c NAC.o NAC.h
NAC.o: NAC.c NAC.h

testNAC: testNAC.o NAC.o
testNAC.o: testNAC.c NAC.h
NAC.o: NAC.c NAC.h

.PHONY: clean 
clean: 
	-rm -f runTests testNAC.o NAC.o NACview.o NACrun.o