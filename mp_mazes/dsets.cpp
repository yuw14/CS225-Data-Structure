/* Your code here! */
#include "dsets.h"
using std::vector;

void DisjointSets::addelements(int  num)
{
  for(int i=0;i<num;i++)
  {
    upTrees.push_back(-1);
  }
}

int DisjointSets::find(int  elem)
{
  if(upTrees[elem]<0) {return elem;}
  else{
    int root=find(upTrees[elem]);
    upTrees[elem]=root;
    return root;
    // upTrees[elem]=find(upTrees[elem]);
    // return upTrees[elem];
  }
}

void DisjointSets::setunion(int  a, int  b)
{
  int rootA=find(a);
  int rootB=find(b);
  if(rootA==rootB){return;}
  if(upTrees[rootA]>upTrees[rootB]){
    upTrees[rootB]+=upTrees[rootA];
    upTrees[rootA]=rootB;
  }
  else{
    upTrees[rootA]+=upTrees[rootB];
    upTrees[rootB]=rootA;
  }
}

int DisjointSets::size(int  elem)
{
  int root=find(elem);
  return (-1)*upTrees[root];
}
