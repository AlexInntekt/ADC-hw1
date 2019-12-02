OBJS = papyrus.cpp
CC = g++ -std=c++11
COMPILER_FLAGS = -Wall
OBJ_NAME = exe


all: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
