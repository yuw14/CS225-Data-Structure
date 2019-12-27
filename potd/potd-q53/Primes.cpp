#include <vector>
#include "Primes.h"
#include <math.h>
using namespace std;
std::vector<int> *genPrimes(int M) {
    std::vector<int> *v = new std::vector<int>();
    // your code here
    bool A[M];
    for(int i=0;i<=M;i++){
    	A[i]=true;
    }
    for(int i=2;i<=int(floor(sqrt(M)));i++){
    	if(A[i]==true){
    		int count=0;
    		for(int j=i*i;j<=M;j=i*i+count*i){
    			A[j]=false;
    			count++;
    		}
    	}
    }


    for(int i=2;i<=M;i++){
    	if(A[i]==true){
    		v->push_back(i);
    	}
    }
    return v;
}

