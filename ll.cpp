//ll.cpp
#include "ll.h"
#include <iostream>
#include <sstream>
using namespace std;

polylinkedlist::polylinkedlist(){
	first=last=NULL;
}
		
polylinkedlist::~polylinkedlist(){
	Node* n=first;
	Node* p;
	while(n!=NULL){
		p=n->next;
		delete n;
		n=p;
	}
}

void polylinkedlist::clearll(){
	if(first=last=NULL){
		return;
	}
	Node* n=first;
	Node* p;
	while(n!=NULL){
		p=n->next;
		delete n;
		n=p;
	}
	first=last=NULL;
	
}

void polylinkedlist::insert(int coefficent,int exponent){
	while(coefficent>999999){
		coefficent=coefficent%1000000;
	}
	while(exponent>9999){
		exponent=exponent%10000;
	}
	if(first==NULL){
		first=last= new Node(coefficent, exponent);
	}
	else if(last && exponent>last->expo){
		last->next=new Node(coefficent,exponent);
		last=last->next;
	}
	else{
		Node* where = first;
		int node=0;
		while(where && exponent> where->expo){
			where=where->next;
			node++;
		}
		if(node==0){
			Node* newguy = new Node(coefficent,exponent);
			newguy->next= first;
			first=newguy;
		}
		else{
			where = first;
			for(int i =0; i<node; i++){
				where=where->next;
			}
			Node* tempNext = where->next;
			where->next= new Node(coefficent,exponent);
			where->next->next=tempNext;
		}
	}
}

void polylinkedlist::writePoly(){
	Node* checker = this->first;
	while(checker != NULL){
		cout<< checker->coef << " " <<checker->expo<<" ";
		checker = checker->next;
	}
	cout<<endl;
}

void polylinkedlist::addPoly(polylinkedlist& poly){
	Node* one = this->first;
	Node* two = poly.first;
	polylinkedlist answer;
	while(one != NULL && two!=NULL){
		if(two->expo > one->expo){
			answer.insert(one->coef, one->expo);
			one = one->next;
		}
		else if(two->expo == one->expo){
			answer.insert(one->coef + two->coef, one->expo);
			one = one->next;
			two = two->next;
		}
		else if(two->expo < one->expo){
			answer.insert(two->coef, two->expo);
			two = two -> next;
		}
	}
	if(one==NULL){
		while(two != NULL){
			answer.insert(two->coef, two->expo);
			two=two->next;
		}
	}
	if(two==NULL){
		while(one != NULL){
			answer.insert(one->coef, one->expo);
			one=one->next;
		}
	}
	this->clearll();
	Node* copier= answer.first;
	while(copier!= NULL){
		this->insert(copier->coef, copier->expo);
		copier = copier->next;
	}
	return;
}

void polylinkedlist::mulPoly(polylinkedlist& poly){
	Node* pointer = poly.first;
	Node* og = this->first;
	polylinkedlist realanswer;
	polylinkedlist tempanswer;
	while(pointer != NULL){
		while(og != NULL){
			tempanswer.insert(pointer->coef * og->coef, pointer->expo + og->expo);
			og = og->next;
		}
		og = this->first;
		realanswer.addPoly(tempanswer);
		pointer = pointer->next;
		tempanswer.clearll();
	}
	this->clearll();
	Node* copier= realanswer.first;
	while(copier!= NULL){
		this->insert(copier->coef, copier->expo);
		copier = copier->next;
	}	
	return;
}

void polylinkedlist::squPoly(){
	polylinkedlist duplicate;
	Node* og = this->first;
	while(og != NULL){
		duplicate.insert(og->coef, og->expo);
		og=og->next;
	}
	this->mulPoly(duplicate);
	return;
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
		one.mulPoly(two);
		one.writePoly();
	}
	
	if(add>0){
		one.addPoly(two);
		one.writePoly();
	}

	return 0;
}


