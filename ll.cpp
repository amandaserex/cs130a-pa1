//ll.cpp
#include "ll.h"
#include <iostream>
#include <sstream>
using namespace std;

polylinkedlist::polylinkedlist(){
	first=last=NULL;
}
		
polylinkedlist::~polylinkedlist(){
	//stub	
}

void polylinkedlist::insert(int coefficent,int exponent){
	if(first==NULL){
		first=last= new Node(coefficent, exponent);
	}
	else{
		last->next=new Node(coefficent,exponent);
		last=last->next;
	}
}

void polylinkedlist::writePoly(){
	Node* checker = this->first;
	while(checker != NULL){
		cout<< checker->coef << " " <<checker->expo;
		checker = checker->next;
	}
	cout<<endl;
}

polylinkedlist polylinkedlist::addPoly(polylinkedlist poly){
	//stub
	cout<<"called Add"<<endl;
	return poly;
}
polylinkedlist polylinkedlist::mulPoly(polylinkedlist poly){
	//stub
	cout<<"called multiply"<<endl;
	return poly;
}

polylinkedlist polylinkedlist::squPoly(){
	polylinkedlist duplicate;
	cout<<"called squared"<<endl;
	//stub
	return duplicate;
}


int main(int argc, char* argv[]){
	if(argc!=2){
		cerr<<argv[0]<< " Expects two arguements"<<endl;
	}
	polylinkedlist one;
	polylinkedlist two;
	string coefTemp = "";
	int counter = 1;
	int numPolys = 1;
	int mult= 0;
	int add = 0;
	string num;
	stringstream ss;
	ss<< argv[1];
	while(getline(ss,num,' ')){
		if(num != "**" && num != "*" && num!= "+" ){
			if(counter%2==1){
				coefTemp=num;
				counter++;
			}
			else if(numPolys==1){
				one.insert(stoi(coefTemp),stoi(num));
				coefTemp="";
				counter++;
			}
			else{
				two.insert(stoi(coefTemp),stoi(num)); 
				coefTemp="";
				counter++;
			}

		}
		else if(num== "**"){
			one.squPoly();
			one.writePoly();
		}
		else if(num == "*"){
			numPolys++;
			mult++;
		}
		else if(num== "+"){
			numPolys++;
			add++;
		}
	}

	if(mult>0){
		polylinkedlist answer = one.mulPoly(two);
		answer.writePoly();
	}
	if(add>0){
		polylinkedlist answer = one.addPoly(two);
		answer.writePoly();
	}

	return 0;
}


