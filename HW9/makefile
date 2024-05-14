CXX = g++
FLAGS = -ggdb -Wall -c

OBJS = BST.o main.o
TARGET = BST

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

.cpp.o:
	$(CXX) $(FLAGS) -c $<

clean:
	rm -f $(TARGET) *.o
BST.o: BST.h
main.o: BST.h