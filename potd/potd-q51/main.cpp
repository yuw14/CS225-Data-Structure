#include "potd.h"
#include <vector>
#include <iostream>
using namespace std;

int main() {
	// test your code here!
	vector<string> result=topThree("in1.txt");
	for(auto c:result){
		cout<<c<<endl;
	}
	return 0;
}
