CC = g++
EXE1 = main
LIB_SRC = calculator.cpp
LIB_OBJ = $(subst /,\,calculator.o)


EXEALL =$(EXE1)

all: $(EXEALL)


$(LIB_OBJ): $(LIB_SRC)
	$(CC) -c $< -o $@ 

$(EXE1): $(EXE1).cpp $(LIB_OBJ)
	$(CC) -o $@ $^

clean:
	del $(EXE1).exe
	del $(LIB_OBJ)
	