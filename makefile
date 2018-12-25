OBJFILE = board.o data_struct.o AI.o
TARGET = Tic-Tac-Toe.out
GCC_FLAG = -g -Wall
all: $(OBJFILE)
	gcc $(GCC_FLAG) $(OBJFILE) -o $(TARGET)

test: $(OBJFILE) test.o
	gcc $(GCC_FLAG) $(OBJFILE) test.o -o test.exe
test.o : test.c
	gcc $(GCC_FLAG) -c -g ./test.c -o test.o

$(OBJFILE):%.o:%.c
	gcc $(GCC_FLAG) -c $< -o $@
clean:
	rm -f  $(OBJFILE) $(TARGET)
	rm -f test.o
