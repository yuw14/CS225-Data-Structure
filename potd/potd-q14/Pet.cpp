// Pet.cpp
#include"Pet.h"
#include<string>
using namespace std;

// void Pet::setFood(string nu_food){
// 	food_=
// }
void Pet::setName(string nu_name){
	name_=nu_name;
}
string Pet::getName(){
	return name_;
}
void Pet::setOwnerName(string nu_ownername){
	owner_name_=nu_ownername;
}
string Pet::getOwnerName(){
	return owner_name_;
}
string Pet::print(){
	string answer="My name is "+name_;
	return answer;
}
Pet::Pet():Animal(){
	name_="Fluffy";
	owner_name_="Cinda";
}

Pet::Pet(string type, string food, string name, string ownername):Animal(type,food){
	name_=name;
	owner_name_=ownername;	
}
