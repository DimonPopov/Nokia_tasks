GCC = g++
FLASG = -std=c++17 -g -Wall
OBJ = main.o
OBJTEST = unitTests.o


.PHONY: all test clean


all: task1



task1: $(OBJ)
	$(GCC) $(FLAGS) $^ -o $@

main.o: main.cpp mergeList.hpp
	$(GCC) $(FLAGS) -c $< -o $@



test: $(OBJTEST)
	$(GCC) $(FLASG) $^ -o $@

unitTests.o: $(TES)unitTests.cpp
	$(GCC) $(FLASG) -c -lboost_unit_test_framework $< -o $@



clean:
	rm *.o task1 test

