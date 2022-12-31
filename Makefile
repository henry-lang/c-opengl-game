SRC = $(shell find src -name '*.c')
UNAME_S = $(shell uname -s)
OBJ = $(SRC:.c=.o)
NAME = game

CC = clang
MAKE = make

CFLAGS = -std=c11 -O2 -g -Wall -Wextra -Wpedantic -Wstrict-aliasing
CFLAGS += -Wno-pointer-arith -Wno-newline-eof -Wno-unused-parameter -Wno-gnu-statement-expression
CFLAGS += -Wno-gnu-compound-literal-initializer -Wno-gnu-zero-variadic-macro-arguments
CFLAGS += -Ilib/glad/include/ -Ilib/glfw/include -fbracket-depth=1024
LDFLAGS = lib/glad/src/glad.o lib/glfw/src/libglfw3.a -lm

ifeq ($(UNAME_S), Darwin)
	LDFLAGS += -framework OpenGL -framework IOKit -framework CoreVideo -framework Cocoa
endif

ifeq ($(UNAME_S), Linux)
	LDFLAGS += -ldl -lpthread
endif

ifneq (,$(findstring NT,$(UNAME_S)))
	GLFW_CMAKE_FLAGS = -DCMAKE_C_COMPILER=$(shell which $(CC)).exe -G "MinGW Makefiles"
	LDFLAGS += -mwindows
	MAKE = mingw32-make
endif

.PHONY: all

all: clean libs build

libs:
	cd lib/glfw && cmake $(GLFW_CMAKE_FLAGS) . && $(MAKE)
	cd lib/glad && $(CC) -o src/glad.o -Iinclude -c src/glad.c

build: $(OBJ)
	$(CC) -o $(NAME) $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf $(OBJ) $(NAME)
