// Pet.h
#pragma once
#include<string>
#include"Animal.h"
using namespace std;
class Pet:public Animal{
public:
	// void setFood(string nu_food);
	// string getFood();
	void setName(string nu_name);
	string getName();
	void setOwnerName(string nu_ownername);
	string getOwnerName();
	string print();
	Pet();
	Pet(string typeAnimal, string typeFood, string name, string ownername);

private:
	string name_;
	string owner_name_;


};