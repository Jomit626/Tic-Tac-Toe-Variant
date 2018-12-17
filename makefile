OBJFILE = board.o
TARGET = Tic-Tac-Toe.out

all: $(OBJFILE)
	gcc $(OBJFILE) -o $(TARGET)

test: $(OBJFILE) test.o
	gcc $(OBJFILE) test.o -o test.out
test.o : test.c
	gcc -c -g ./test.c -o test.o

$(OBJFILE):%.o:%.c
	gcc -c $< -o $@
