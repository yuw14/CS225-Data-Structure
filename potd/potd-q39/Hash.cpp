#include <vector>
#include <string>
#include "Hash.h"

using namespace std;

int hashFunction(string s, int M) {
   // Your Code Here
	int sum=0;
	for(unsigned long i=0;i<s.length();i++){
		sum+=s[i];
	}
	if(sum>=M){
		sum=sum%M;
	}
	return sum;
   //hash function to sum up the ASCII characters of the letters of the string
 }

int countCollisions (int M, vector<string> inputs) {
	int collisions = 0;
	// Your Code Here
	vector<bool> v(M);
	for(int i=0;i<M;i++){
		v[i]=false;
	}
	for(unsigned long j=0;j<inputs.size();j++){
		int hash=hashFunction(inputs[j],M);
		if(v[hash]==false){
			v[hash]=true;
		}
		else{
			collisions++;
		}
	}
	return collisions;
}
