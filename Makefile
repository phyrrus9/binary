CC=gcc
AR=ar
CFLAGS=
SRC=functions_control.c functions_data.c functions_search.c
INC=node.h functions.h binary.h tree.h
OBJ=control.o data.o search.o
OUT=binary.a
all: $(OUT)
$(OUT): $(OBJ)
	$(AR) rcs $(OUT) $(OBJ)
control.o: $(SRC) $(INC)
	$(CC) $(CFLAGS) -c -o control.o functions_control.c
data.o: $(SRC) $(INC)
	$(CC) $(CFLAGS) -c -o data.o functions_data.c
search.o: $(SRC) $(INC)
	$(CC) $(CFLAGS) -c -o search.o functions_search.c
clean:
	rm -f $(OBJ)
	rm -f $(OUT)
