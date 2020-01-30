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

void polylinkedlist::mulPoly(polylinkedlist poly){
	//stub
}

void polylinkedlist::squPoly(){
	Node* temp=first;
	while(temp!=NULL){
		temp->expo=temp->expo*2;
		temp = temp->next;
	}
}


int main(int argc, char* argv[]){
	if(argc!=2){
		cerr<<argv[0]<< " Expects two arguements"<<endl;
	}
	polylinkedlist one;
	polylinkedlist two;
	string temp = "";
	int counter = 1;
	int numPolys =0;
	int mult = 0;
	string coef;
	cout<<argv[1][1]<<endl;
	/*
	for(int i = 1; i< argc; i++){
		if(argv[i] != "**" && argv[i] != "*" && numPolys ==0){
			if(counter%2==1){
				temp= argv[i];
				counter++;
			}
			else{
				cout<<temp<<endl;
				one.insert(stoi(temp),stoi(argv[i]));
				temp="";
			}
		}
		else if(numPolys==1 && argv[i] != "**" && numPolys == 1){
			if(counter%2==1){
				temp = argv[i];
				counter++;
			}
			else{
				two.insert(stoi(temp),stoi(argv[i]));
				temp="";
			}
		}
		else if(argv[i]=="**"){
			one.squPoly();
			one.readPoly();
			return 0;
		}
		else if(argv[i]=="*"){
			counter++;
			mult++;
		}
	}

*/

	return 0;
}


