//ll.cpp
#include "ll.h"
#include <iostream>
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

void polylinkedlist::readPoly(){
	//stub
}

void polylinkedlist::writePoly(){
	//stub
}

polylinkedlist polylinkedlist::addPoly(polylinkedlist poly){
	//stub
	return poly;
}
polylinkedlist polylinkedlist::mulPoly(polylinkedlist poly){
	//stub
	return poly;
}

polylinkedlist polylinkedlist::squPoly(){
	polylinkedlist duplicate;

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
	string expTemp = "";
	int counter = 1;
	int numPolys = 1;
	int mult= 0;
	int add = 0;
	for(int i = 1; i< argc; i++){//length needs to be corrected
		if(argv[1][i] == " "){
			if(argv[1][i-1]=="*" || argv[1][i] =="+"){
				//does nothing just skips iteration
			}
			else if(counter%2==1){
				counter++;
			}
			else if(numPolys==1){
				one.insert(stoi(coefTemp),stoi(expTemp));
				coefTemp="";
				expTemp="";
				counter++;
			}
			else{
				two.insert(stoi(coefTemp),stoi(expTemp)); 
				coefTemp="";
				expTemp="";
				counter++;
			}

		}
		else if(argv[1][i] != "*" && argv[1][i] !="+"){
			if(counter%2==1){
				coefTemp= coefTemp + argv[1][i];
			}
			else{
				expTemp = expTemp + argv[1][i];
			}
		}
		else if(argv[1][i]=="*" && argv[1][i+1]=="*"){
			one.squPoly();
			one.readPoly();
			return 0;
		}
		else if(argv[1][i]=="*"){
			numPolys++;
			mult++;
		}
		else if(argv[1][i]=="+"){
			numPolys++;
			add++;
		}
	}

	if(mult>0){
		polylinkedlist answer = one.mulPoly(two);
		answer.readPoly();
	}
	if(add>0){
		polylinkedlist answer = one.addPoly(two);
		answer.readPoly();
	}


	return 0;
}


