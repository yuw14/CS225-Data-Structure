#include "Friend.h"
#include <vector>
using namespace std;
int find(int x, std::vector<int>& parents) {
   // your code
	if(parents[x]<0){return x;}
	else{return find(parents[x],parents);}
}

int findCircleNum(std::vector<std::vector<int>>& M) {
    // your code
  	std::vector<int> disJointSet;
  	for(size_t i=0;i<M.size();i++){
  		disJointSet.push_back(-1);
  	}
  	for(size_t i=0;i<M.size();i++){
  		for(size_t j=0;j<M.size();j++){
  			if(i!=j && M[i][j]==1 && disJointSet[i]!=j){
  				disJointSet[j]=i;
  			}
  		}
  	}
  	int count=0;
  	for(auto e:disJointSet){
  		if(e<0){
  			count++;
  		}
  	}
  	return count;
}
