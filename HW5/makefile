CXX = g++
FLAGS = -ggdb -Wall -c

OBJS = stack.o main.o
TARGET = stack

all: $(TARGET) 

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

.cpp.o:
	$(CXX) $(FLAGS) -c $<

.PHONY: clean
clean:
	rm -f $(TARGET) *.o

stack.o: stack.h
main.o: stack.h
