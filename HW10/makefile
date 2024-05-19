CXX = g++
FLAGS = -ggdb -Wall -c

OBJS = functionsforhw10.o main.o
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

.cpp.o:
	$(CXX) $(FLAGS) -c $<

clean:
	rm -f $(TARGET) *.o
functionsforhw10.o: functionsforhw10.h
main.o: functionsforhw10.h