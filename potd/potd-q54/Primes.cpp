#include <vector>
#include "Primes.h"

std::vector<int> *genPrimes(int M) {
    std::vector<int> *v = new std::vector<int>();
    std::vector<int> *t = new std::vector<int>(M);
    int i=0;
    int nextPrime = 2;

    for(i=0; i<M; i++)
        (*t)[i] = 1;

    (*t)[0]=0;
    (*t)[1]=0;

    v->push_back(2);

    while (nextPrime < M) {
        for(i=nextPrime*nextPrime;
                i < M;
                i+=nextPrime)
            (*t)[i] = 0;
        for(++nextPrime; nextPrime<M; nextPrime++)
            if ((*t)[nextPrime] == 1) {
                v->push_back(nextPrime);
                break;
            }
    }

    delete t;
    return v;
}

bool couldStartFromThisPrime(int primeIndex, std::vector<int> *primes,int num){
  while (num>0) {
    num-=(*primes)[primeIndex];
    primeIndex++;
  }
  if(num==0){return 1;}
  else {return 0;}
}

int numSequences(std::vector<int> *primes, int num) {

    // your code here
    int count=0;
    int i=0;
    while((*primes)[i]<=num){
      bool b=couldStartFromThisPrime(i,primes,num);
      if(b==1){count++;}
      i++;
    }
    // code to quell compiler complaints.  Delete it.
    // return num + (*primes)[1];
    return count;
}
