All: array linkedlist

array: array.cpp array.h
	g++ -o array.out array.cpp

linkedlist: ll.cpp ll.h
	g++ -o linkedlist.out ll.cpp

clean:
	bin/rm -f array linkedlist *.o
