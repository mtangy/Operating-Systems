#
# This is a makefile for the DLX OS projects.
#

CC = gcc-dlx
AS = dlxasm
CFLAGS = -mtraps -O3

#INCS = $(wildcard *.h)
#SRCS = $(wildcard *.c)
#OBJS = $(addsuffix .o, $(basename $(wildcard *.c))) \
#       $(addsuffix .o, $(basename $(wildcard *.s)))
INCS = dlxos.h traps.h filesys.h memory.h misc.h process.h queue.h \
        syscall.h share_memory.h
SRCS = filesys.c memory.c misc.c process.c queue.c traps.c sysproc.c 
OBJS = $(addsuffix .o, $(basename $(SRCS)))

all: os.dlx.obj userprog interactiveProcess

os.dlx.obj: os.dlx
	$(AS) -i _osinit -l os.lst os.dlx
	mv os.dlx.obj ../execs

os.dlx: $(OBJS) dlxos.o trap_random.o osend.o share_memory.o synch.o
	$(CC) -mtraps -O3 dlxos.o trap_random.o share_memory.o synch.o $(OBJS) osend.o -o os.dlx

share_memory.o: share_memory.api
	cp share_memory.api share_memory.o

synch.o: synch.bin
	cp synch.bin synch.o

osend.o: osend.s
	$(CC) -c osend.s

trap_random.o: trap_random.s
	$(CC) -c trap_random.s

dlxos.o: dlxos.s
	$(CC) -c dlxos.s

usertraps.o: usertraps.s
	$(CC) -c usertraps.s

userprog : userprog.o usertraps.o misc.o
	$(CC) -mtraps -O3 userprog.o usertraps.o misc.o -o userprog.dlx
	$(AS) -l userprog.lst userprog.dlx
	mv userprog.dlx.obj ../execs

interactiveProcess : interactiveProcess.o usertraps.o misc.o
	$(CC) -mtraps -O3 interactiveProcess.o usertraps.o misc.o -o interactiveProcess.dlx
	$(AS) -l interactiveProcess.lst interactiveProcess.dlx
	mv interactiveProcess.dlx.obj ../execs


Makefile.depend: depend

depend: $(SRCS) $(INCS)
	$(CC) -MM $(SRCS) > Makefile.depend

clean:
	/bin/rm -f *.o *.dlx *.lst ../execs/*.obj Makefile.depend ../execs/vm

include Makefile.depend
