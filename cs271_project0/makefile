CXXFLAGS = -std=c++11

set: test_set.o
	g++ $(CXXFLAGS) -o set test_set.o

test_set.o: test_set.cpp set.h
	g++ $(CXXFLAGS) -c test_set.cpp


