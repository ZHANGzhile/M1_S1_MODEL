CC = gcc
INCLUDE = $(%.h)
OBJ = LU_fac.o utils.o test.o

test: $(OBJ)
	$(CC) $^ -o $@ -lmpfr

%.o: %.c $(INCLUDE)
	$(CC) -c $^ -o $@

leaksMain:
	leaks -atExit -- ./main 

leaksTest:
	leaks -atExit -- ./test

clean:
	rm -f $(OBJ) test