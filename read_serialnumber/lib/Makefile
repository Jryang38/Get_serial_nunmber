CC=gcc
CFLAGS=-Wall -Wextra -pedantic -fPIC
LDFLAGS=-shared
LIBRARY=libserverserial.so
SOURCE=serverserial.c

all: $(LIBRARY)

$(LIBRARY): $(SOURCE)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<

clean:
	rm -f $(LIBRARY)

.PHONY: all clean
