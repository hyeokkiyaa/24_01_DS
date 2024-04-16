CXX = g++
FLAGS = -ggdb -Wall -c

OBJS = calculator.o stack.o stack2.o main.o 
TARGET = calculator

all: $(TARGET) 

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@

.cpp.o:
	$(CXX) $(FLAGS) -c $<

.PHONY: clean
clean:
	rm -f $(TARGET) *.o

calculator.o: calculator.h
stack.o: stack.h
stack2.o: stack2.h
main.o: stack.h
