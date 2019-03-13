knight: main.o Linkedlist.o
	g++ main.o Linkedlist.o -o knight

main.o: main.cpp Linkedlist.h 
	g++ -c main.cpp

Linkedlist.o: Linkedlist.cpp Linkedlist.h
	g++ -c Linkedlist.cpp
  
clean:
	 rm *.o
	rm knight

run:     knight
	./knight
