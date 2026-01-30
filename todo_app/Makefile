CC=gcc
CFLAGS=-I src -I src/ui -I src/utils

SRCS=$(wildcard src/**/*.c)
OBJS=$(SRCS:.c=.o)
TARGET=build/main.exe

all: $(TARGET)
	.\$(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	del build\*.exe
