#include "potd.h"
#include <vector>

// Your code here!
double sum(vector<double>::iterator start, vector<double>::iterator end){
  double result=0;
  for(vector<double>::iterator it=start;it!=end;it++){
    result+= *it;
  }
  return result;
}

vector<double>::iterator max_iter(vector<double>::iterator start, vector<double>::iterator end){
  vector<double>::iterator max_iter=start;
  for(vector<double>::iterator it=start;it!=end;it++){
    if((*it)>(*max_iter)){
      max_iter=it;
    }
  }
  return max_iter;
}

void sort_vector(vector<double>::iterator start, vector<double>::iterator end){
    for(vector<double>::iterator it=start;it!=end;it++){
      vector<double>::iterator max_iterator=max_iter(it,end);
      double tmp=(*it);
      (*it)=(*max_iterator);
      (*max_iterator)=tmp;
    }
}
