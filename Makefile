run: BinarySearchTree.o main.o 
	g++ BinarySearchTree.o main.o  -o run

BinarySearchTree.o: BinarySearchTree.cpp
	g++ -c BinarySearchTree.cpp BinarySearchTree.h

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o run