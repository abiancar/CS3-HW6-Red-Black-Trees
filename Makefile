all:
	g++ -g -Wall -std=c++11 RedBlackTree.cpp RedBlackTreeTests.cpp -o RBTest
run:
	./RBTest

try: all run



