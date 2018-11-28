CC=g++
FLAGS=-Wall -Werror -pedantic -O1 --std=c++11
C_FLAG=-c
DEBUG=-g
LUA_PATH=/home/cabox/lua-5.3.5/src
INCLUDE=-I $(LUA_PATH) \
	-L $(LUA_PATH)
LUA_FLAGS=-llua -ldl -lm

all: Test Debug

Debug: Timer.o main.o
	$(CC) $(FLAGS) $(DEBUG) \
		main.o -o $@ \
		$(INCLUDE) \
		$(LUA_FLAGS)

Test: Timer.o main.o
	$(CC) $(FLAGS) \
		Timer.o main.o -o $@ \
		$(INCLUDE) \
		$(LUA_FLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) $(C_FLAG) \
		main.cpp -o $@ \
		$(INCLUDE) \
		$(LUA_FLAGS)
		
Timer.o: Timer.h Timer.cpp
	$(CC) $(FLAGS) $(C_FLAG) \
		Timer.cpp -o $@ \
		$(INCLUDE) \
		$(LUA_FLAGS)

clean:
	rm -v *.o Test Debug

.PHONY: clean all