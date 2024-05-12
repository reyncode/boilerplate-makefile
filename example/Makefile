NAME := example

CC := gcc
CFLAGS := -std=c99
WARNINGS := -Wall -Wextra
OPT_FLAGS := -O2
DEBUG_FLAGS := -g

BIN_DIR := bin
SRC_DIR := src
OBJ_DIR := obj

# 3rd party dependencies
# PACKAGE = `pkg-config --cflags --libs my-dependency`
# LIBS = `pkg-config --libs my-dependency`

# create the path to the binary
BINARY := $(BIN_DIR)/$(NAME)

# collect all files in SRC_DIR that end with c
SRCS := $(wildcard $(SRC_DIR)/*.c)

# substitute all discovered c files with .o extension for linking
OBJS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Default build - with debug info
.PHONY: all
all: CFLAGS += $(DEBUG_FLAGS)
all: prep $(BINARY)

# Release build - optimized for release
.PHONY: release
release: CFLAGS += $(OPT_FLAGS)
release: prep $(BINARY)

$(BINARY): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(WARNINGS) -c -o $@ $^ $(PACKAGE)

.PHONY: prep
prep:
	@mkdir -p $(BIN_DIR) 
	@mkdir -p $(OBJ_DIR)

.PHONY: clean
clean:
	@echo "Cleaning up"
	@rm -rf $(BIN_DIR) $(OBJ_DIR)

.PHONY: vars
vars:
	@printf "\
	NAME: \"$(NAME)\"\n\
	BIN_DIR: \"$(BIN_DIR)\"\n\
	SRC_DIR: \"$(SRC_DIR)\"\n\
	OBJ_DIR: \"$(OBJ_DIR)\"\n\
	PACKAGE: \"$(PACKAGE)\"\n\
	LIBS: \"$(LIBS)\"\n\
	BINARY: \"$(BINARY)\"\n\
	SRCS: \"$(SRCS)\"\n\
	OBJS: \"$(OBJS)\"\n\
	CC: \"$(CC)\"\n\
	CFLAGS: \"$(CFLAGS)\"\n\
	WARNINGS: \"$(WARNINGS)\"\n\
	OPT_FLAGS: \"$(OPT_FLAGS)\"\n\
	DEBUG_FLAGS: \"$(DEBUG_FLAGS)\"\n"

.PHONY: help
help:
	@printf "\
	Usage: make target\n\
	\n\
	targets:\n\
	  all             Compile the binary using the debug configuration (default target)\n\
	  release         Compile the binary using the release optimizations\n\
	  clean           Clean the bin and object directories\n\
	  vars       	  Show the variables set in this Makefile\n\
	  help            Show this help info\n\
	\n"
