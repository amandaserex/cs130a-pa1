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
		cout<< checker->coef << " " <<checker->expo<<" ";
		checker = checker->next;
	}
	cout<<endl;
}

polylinkedlist polylinkedlist::addPoly(polylinkedlist poly){
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

	return answer;
}

polylinkedlist polylinkedlist::mulPoly(polylinkedlist poly){
	//stub
	return poly;
}

polylinkedlist polylinkedlist::squPoly(){
	polylinkedlist duplicate;
	Node* og = this->first;
	while(og != NULL){
		duplicate.insert(og->coef, og->expo);
		og=og->next;
	}
	return this->mulPoly(duplicate);;
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


