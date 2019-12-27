#include "Swiftcipher.h"
#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

/* Swift Cipher: Frequency of words in a file corresponds to its location in the decrypted sentence */
string decipherer(string filename) {
    string line;
    ifstream infile (filename);
    vector<string> ret;
    map<string, int> map;
    if (infile.is_open()) {
        while (getline(infile, line)) {
            // do things
            map[line]++;
        }
    }
    infile.close();
    ret.resize(map.size());
    for(auto c:map){
    	ret[c.second-1]=c.first;
    }
    string result="";
    for(auto b:ret){
    	result+=b;
    	result+=" ";
    }
    result.pop_back();


	return result;
}
