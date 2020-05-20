CC := g++
CFLAGS := -Wall -g
TARGET := main

SRCS := $(wildcard src/*.cpp)
OBJS := $(patsubst obj/%.cpp,obj/%.o,$(SRCS))

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) -o $@ $^
%.o: %.cpp
	$(CC) $(CFLAGS) -c $<
clean:
	rm -rf $(TARGET) *.o