CC=gcc
CFLAGS=-Wall -Wextra -pedantic -fPIC
LDFLAGS=-shared
LIBRARY=libserverserial.so
HEADER=serverserial.h
SOURCE=serverserial.c

EXAMPLE_DIR=../example_app

all: $(LIBRARY)
	cp -rf $(HEADER) $(LIBRARY) $(EXAMPLE_DIR)

$(LIBRARY): $(SOURCE) $(HEADER)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<

clean:
	rm -f $(LIBRARY)

.PHONY: all clean
