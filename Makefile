all:
	g++ -Wall RedBlackTree.cpp RedBlackTreeTests.cpp -o RBTest
run:
	./RBTest

try: all run



