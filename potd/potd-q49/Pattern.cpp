#include "Pattern.h"
#include <string>
#include <iostream>
#include <vector>
#include <map>

bool wordPattern(std::string pattern, std::string str) {

    //write your code here
	std::vector<string> v;
	string currString="";
	for(auto c:str){
		if(c==' '){
			v.push_back(currString);
			currString="";
		}
		else{
			currString+=c;
		}
	}
	v.push_back(currString);

	if(pattern.length()!=v.size()){
		return false;
	}

    std::map<char, string> map1;
    std::map<string, char> map2;
    for(unsigned i=0;i<pattern.length();i++){
    	if(map1[pattern[i]]=="" && map2[v[i]]=='\0'){
    		map1[pattern[i]]=v[i];
    		map2[v[i]]=pattern[i];
    	}
    	else{
    		if(map1[pattern[i]]!=v[i]||map2[v[i]]!=pattern[i]){
    			return false;
    		}
    	}
    }
    return true;
}

