CC = gcc
CFLAGS = -I. -W -Wall
LIBS = -lm `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0`
DEPS = $(wildcard *.h)
SRC = $(wildcard *.c)
OBJ= $(SRC:.c=.o)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

app: $(OBJ)
	gcc -o app $(SRC) -I. $(LIBS)
	
