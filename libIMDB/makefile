CC=gcc
CFLAGS=-Wall -fPIC -I./include/private -I./include/public
LDFLAGS=-shared -lmsgpack-c
RM=rm -f
LIB_TARGET=libIMDB.so
TEST_TARGET=test-bin
LIB_SOURCES=$(wildcard src/*.c)
LIB_OBJECTS=$(LIB_SOURCES:.c=.o)
TEST_SOURCES=test.c

.PHONY: all clean debug build_and_clean test

all: build_and_clean

build_and_clean: $(LIB_TARGET)
	@$(MAKE) clean

$(LIB_TARGET): $(LIB_OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(LIB_OBJECTS)

debug: CFLAGS += -g
debug: LDFLAGS += -g
debug: $(LIB_TARGET)

test: CFLAGS += -g
test: debug
	$(CC) $(CFLAGS) -L. -lIMDB -o $(TEST_TARGET) $(TEST_SOURCES)
	@$(MAKE) clean

