CC=gcc
CFLAGS=-Wall -Wextra -pedantic
LDFLAGS=-L. -lserverserial

APP_NAME=test
SOURCE=main.c

all: $(APP_NAME)

$(APP_NAME): $(SOURCE) $(LIBRARY)
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

clean:
	rm -f $(APP_NAME)

.PHONY: all clean
