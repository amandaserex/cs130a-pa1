#ifndef ARRAY_H
#define ARRAY_H

#include <string>
#include <iostream>
using namespace std;

class polyArray{
	public:
		void insert(int num);
		polyArray();
		~polyArray();
		void readPoly();
		void writePoly();
		void mulPoly(polyArray poly);
		void squPoly();	
	private:
		int data[10000];//max capacity is 9999
};

#endif
