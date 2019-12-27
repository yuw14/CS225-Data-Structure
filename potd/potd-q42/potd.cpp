#include <unordered_map>

using namespace std;

unordered_map<string, int> common_elems(unordered_map<string, int> &mapA,
                                        unordered_map<string, int> &mapB) {

    // your code here
    unordered_map<string,int> mapC;
    for(unordered_map<string,int>::iterator it1=mapA.begin();it1!=mapA.end();){
    	bool move=true;
    	for(unordered_map<string,int>::iterator it2=mapB.begin();it2!=mapB.end();){
    		if(it1->first==it2->first){
    			mapC[it1->first]=it1->second+it2->second;
    			it1=mapA.erase(it1);
    			it2=mapB.erase(it2);
    			move=false;
    		}
    		else{
    			it2++;
    		}
    	}
    	if(move==true){
    	it1++;
    	}	
    }
   
    return mapC;
    // return unordered_map<string, int>();
} 