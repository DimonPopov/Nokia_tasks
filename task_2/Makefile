GCC = g++
FLASG = -std=c++17 -g -Wall
OBJ = main.o
OBJTEST = unitTests.o


.PHONY: all test clean


all: task2


task2: $(OBJ)
	$(GCC) $(FLAGS) $^ -o $@

main.o: main.cpp deleteASCIIchain.hpp
	$(GCC) $(FLAGS) -c $< -o $@



test: $(OBJTEST)
	$(GCC) $(FLASG) $^ -o $@

unitTests.o: $(TES)unitTests.cpp
	$(GCC) $(FLASG) -c -lboost_unit_test_framework $< -o $@



clean:
	rm *.o task2 test

