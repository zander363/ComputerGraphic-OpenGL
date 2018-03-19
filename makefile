.PHONY:clean
#makefile test for final's hw
CC=gcc
CFLAGS=-lfreeglut -lopengl32 -lglu32
CFILES=$(wildcard *.cpp)
OBJS=$(CFILES:%c=%.o)
all:final
final:final.o
	$(CC) final.o $(CFLAGS) -o final
final.o:final.c
	$(CC) final.c ${CFLAGS} -c
clean:
	rm -f final.o
