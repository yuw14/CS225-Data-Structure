#include"potd.h"
// Your code here
#include<string>
// #include<iostream>

string getFortune(const string &s){
	if(s.length()%5==0){
		return "You will get A+";
	}
	if(s.length()%5==1){
		return "You will get a job";
	}
	if(s.length()%5==2){
		return "You will have a sexy girl friend";
	}
	if(s.length()%5==3){
		return "You will become very strong and nice in shape";
	}	
	if(s.length()%5==4){
		return "You will have regular sex life from now on";
	}
	else{return "Everything will be fine!!";}				
}

