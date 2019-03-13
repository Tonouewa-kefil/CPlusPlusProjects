word: main.o Linkedlist.o BinarySearchTree.o
	g++ main.o Linkedlist.o BinarySearchTree.o -o knight

main.o: main.cpp Linkedlist.h BinarySearchTree.o
	g++ -c main.cpp

Linkedlist.o: Linkedlist.cpp Linkedlist.h
	g++ -c Linkedlist.cpp
  
BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h Linkedlist.o
  g++ -c BinarySearchTree.cpp

clean:
	 rm *.o
	rm word

run:     word
	./word
