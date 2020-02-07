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
		void clearll();
		void insert(int coefficent, int exponent);
		void writePoly();
		void addPoly(polylinkedlist& poly);
		void mulPoly(polylinkedlist& poly);
		void squPoly();//squares an entire polynomial
	private:
		Node* first;
		Node* last;
		
};


#endif
