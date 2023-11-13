CC = gcc
INCLUDE = $(%.h)
OBJ = $(%.o)

test: $(OBJ)
	$(CC) $^ -o $@

%.o: %.c $(INCLUDE)
	$(CC) -c $^ -o $@

clean:
	rm -f $(OBJ) test 