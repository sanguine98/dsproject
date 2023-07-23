SRC:= $(wildcard *.c)
OBJ:= $(patsubst %.c, %.o, $(SRC))
a.out: $(OBJ)
	gcc -o $@ $(OBJ) -Wall

clean :
	rm *.o *.out
