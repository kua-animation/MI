CC = gcc
CFLAGS =

SRC_DIRS = src lib
SRCS = $(wildcard $(addsuffix /*.c, $(SRC_DIRS)))
OBJS = $(SRCS:.c=.o)
TARGET = program

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

