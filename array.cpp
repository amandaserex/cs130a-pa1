//array.cpp 
#include <iostream>
#include <string>
#include <sstream>
#include "array.h"

using namespace std;

void polyArray::insert(int coef, int expo){
	while(coef>999999){
		coef=coef%1000000;
	}
	while(expo>9999){
		expo=expo%10000;
	}
	this->data[expo]=coef;
}

polyArray::polyArray(){
	for(int i=0; i<=9999; i++){
		data[i]=0;
	}
}

void polyArray::cleanUp(){
	for(int i=0;i<=9999;i++){
		data[i]=0;
	}
}

void polyArray::writePoly(){
	for(int i = 0; i<=9999; i++){
		if(data[i] !=0){
			cout<< data[i] << " " << i << " ";
		}
	}
	cout<<endl;
}

polyArray polyArray::addPoly(polyArray poly){
	polyArray answer;
	for(int i = 0; i<=9999; i++){
		if(this->data[i]!=0){
			answer.insert(this->data[i]+poly.data[i], i);
			poly.data[i]=0;
		}
	}
	for(int j=0;j<=9999;j++){
		if(poly.data[j]!= 0){
			answer.insert(poly.data[j],j);
		}
	}
	return answer;
}

polyArray polyArray::mulPoly(polyArray poly){
	polyArray answer;
	polyArray tempAnswer;
	int incTemp =0;
	for(int i = 0; i<=9999; i++){
		incTemp=0;
		if(this->data[i]!=0){
			for(int k=0;k<=9999;k++){
				if(poly.data[k]!= 0){
					tempAnswer.insert(this->data[i]*poly.data[k],i+k);
					incTemp++;
				}
			}
		}
		if(incTemp>0){
			answer = answer.addPoly(tempAnswer);
			tempAnswer.cleanUp();
		}
	}
	return answer;
}

polyArray polyArray::squPoly(){
	polyArray duplicate;
	for(int i =0; i<=9999; i++){
		duplicate.insert(this->data[i], i);
	}
	return (this->mulPoly(duplicate));
}	

int main(int argc, char* argv[]){
	if(argc!=2){
		cerr<<argv[0]<< " Expects two arguements"<<endl;
	}
	polyArray one;
	polyArray two;
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
			polyArray answer = one.squPoly();
			answer.writePoly();
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
		polyArray answer = one.mulPoly(two);
		answer.writePoly();
	}
	if(add>0){
		polyArray answer = one.addPoly(two);
		answer.writePoly();
	}
	return 0;
}
