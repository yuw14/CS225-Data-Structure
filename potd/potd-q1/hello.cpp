/* Your code here! */
#include<iostream>
#include"hello.h"
#include<string>
using namespace std;

int age=22;
string name="Wang Yu";
string hello(){
	string text;
	string s=to_string(age);
	text= "Hello world! My name is "+ name + " and I am "+ s +" years old.";
	return text;

}