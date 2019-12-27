#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;


vector<string> topThree(string filename) {
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
    string max_str="";
    int max_value=0;
    for(pair<string,int> c:map){
        if(c.second>max_value){
            max_str=c.first;
            max_value=c.second;
        }
    }
    ret.push_back(max_str);
    map.erase(max_str);
    max_str="";
    max_value=0;
    for(pair<string,int> c:map){
        if(c.second>max_value){
            max_str=c.first;
            max_value=c.second;
        }
    }
    ret.push_back(max_str);
    map.erase(max_str);  
    max_str="";
    max_value=0;
    for(pair<string,int> c:map){
        if(c.second>max_value){
            max_str=c.first;
            max_value=c.second;
        }
    }
    ret.push_back(max_str);  


    return ret;
}

