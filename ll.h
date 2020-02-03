#ifndef LL_H
#define LL_H
#include <iostream>
#include <string>
using namespace std;

struct Node{
	int expo;
	int coef;
	Node* next;
	Node(int coefficent, int exponent){ 
		coef=coefficent;
		expo=exponent;
		next = NULL;
	}
};

class polylinkedlist{
	public:
		polylinkedlist();
		~polylinkedlist();
		void insert(int coefficent, int exponent);
		void writePoly();
		polylinkedlist addPoly(polylinkedlist poly);
		polylinkedlist mulPoly(polylinkedlist poly);
		polylinkedlist squPoly();//squares an entire polynomial
	private:
		Node* first;
		Node* last;
		
};


#endif
