#ifndef ARRAY_H
#define ARRAY_H

#include <string>
#include <iostream>
using namespace std;

class polyArray{
	public:
		void insert(int coef, int expo);
		polyArray();
		void cleanUp();
		void writePoly();
		polyArray addPoly(polyArray poly);
		polyArray mulPoly(polyArray poly);
		polyArray squPoly();	
	private:
		int data[10000];//max capacity is 9999
};

#endif
