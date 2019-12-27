/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */

#include <utility>
#include <algorithm>
#include<cmath>

using namespace std;

template <int Dim>
bool KDTree<Dim>::smallerDimVal(const Point<Dim>& first,
                                const Point<Dim>& second, int curDim) const
{
    /**
     * @todo Implement this function!
     */

  if(first[curDim]>second[curDim]){
    return false;
  }
  else if(first[curDim]<second[curDim]){
    return true;
  }
  else{
    return first<second;
  }
}

template <int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim>& target,
                                const Point<Dim>& currentBest,
                                const Point<Dim>& potential) const
{
    /**
     * @todo Implement this function!
     */
     double currentBestDistance=0;
     double potentialDistance=0;
     for(int i=0;i<Dim;i++){
       currentBestDistance+=pow(currentBest[i]-target[i],2);
     }
     for(int j=0;j<Dim;j++){
       potentialDistance+=pow(potential[j]-target[j],2);
     }
     if(potentialDistance<currentBestDistance){
        return true;
      }
      else if(potentialDistance>currentBestDistance){
        return false;
      }
     else{return potential < currentBest;}
}

//definitely true
template <int Dim>
int KDTree<Dim>::partition(vector<Point<Dim>>& points, int left, int right, unsigned pivotIndex, int dimension)
{
  Point<Dim> pivotValue=points[pivotIndex];
  swap(points[pivotIndex],points[right]);
  int storeIndex=left;
  for(int i=left;i<right;i++){
    if(smallerDimVal(points[i],pivotValue,dimension)){
      swap(points[storeIndex],points[i]);
      storeIndex++;
      }
    }
  swap(points[right],points[storeIndex]);
  return storeIndex;
}

// could I use 0?
//kth index smallest
template<int Dim>
Point<Dim> KDTree<Dim>::quickSelect(vector<Point<Dim>>& points, int left, int right, int k, int dimension)
{
  if(left==right){
    return points[left];
  }
  int pivotIndex=k;
  pivotIndex=partition(points, left, right,pivotIndex,dimension);
  //k-1
  if(k==pivotIndex){
    return points[k];
  }
  else if(k<pivotIndex){
    return quickSelect(points, left, pivotIndex-1, k,dimension);
  }
  else{
    return quickSelect(points,pivotIndex+1,right,k,dimension);
  }
}

template<int Dim>
typename KDTree<Dim>::KDTreeNode* KDTree<Dim>::ctor(vector<Point<Dim>>& points, int dimension, unsigned left, unsigned right)
{
    //base case
    if(left<0||right>=points.size())
    return NULL;
    if(right<left){
      return NULL;
    }

    int median=(left+right)/2;
    KDTreeNode* root=new KDTreeNode(quickSelect(points,left,right,median,dimension%Dim));
    dimension++;
    size++;
    root->left=ctor(points,dimension%Dim,left,median-1  );
    root->right=ctor(points,dimension%Dim,median+1, right);
    return root;
}

template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints)
{
    /**
     * @todo Implement this function!
     */
     if(newPoints.empty()){
       root=NULL;
       size=0;
     }
     else{
       vector<Point<Dim>> points=newPoints;
       size=0;
       root=ctor(points,0,0,points.size()-1);
     }
}

template <int Dim>
typename KDTree<Dim>::KDTreeNode* KDTree<Dim>::copy(KDTreeNode* subRoot)
{
  if(subRoot==NULL){
    return NULL;
  }
  KDTreeNode* newRoot=new KDTreeNode(subRoot->point);
  newRoot->left=copy(subRoot->left);
  newRoot->right=copy(subRoot->right);
  return newRoot;
}

template<int Dim>
void KDTree<Dim>::deleteTree(KDTreeNode* subRoot)
{
  if(subRoot==NULL){
    return;
  }
  deleteTree(subRoot->left);
  deleteTree(subRoot->right);
  delete subRoot;
}

template <int Dim>
KDTree<Dim>::KDTree(const KDTree<Dim>& other) {
  /**
   * @todo Implement this function!
   */
   size=other.size;
   root=copy(other.root);

}

template <int Dim>
const KDTree<Dim>& KDTree<Dim>::operator=(const KDTree<Dim>& rhs) {
  /**
   * @todo Implement this function!
   */
   if((*this)!=rhs){
   deleteTree(this->root);
   size=0;
   root=copy(rhs.root);
   size=rhs.size;
    }
  return *this;
}

template <int Dim>
KDTree<Dim>::~KDTree() {
  /**
   * @todo Implement this function!
   */
   deleteTree(root);
   size=0;
}

template <int Dim>
void KDTree<Dim>::findHelper(KDTreeNode* curr_node, Point<Dim> &curr_best, const Point<Dim>& query,int dimension )const
{
  if(curr_node==NULL){
    return;
  }
  KDTreeNode* nextNode;
  KDTreeNode* otherNode;
  if(smallerDimVal(curr_node->point, query,dimension)){
    nextNode=curr_node->right;
    otherNode=curr_node->left;
  }
  else{
    nextNode=curr_node->left;
    otherNode=curr_node->right;
  }
  findHelper(nextNode,curr_best,query,(dimension+1)%Dim);
  if(shouldReplace(query,curr_best,curr_node->point)){
    curr_best=curr_node->point;
  }
  double radius=0;
  for(int i=0;i<Dim;i++){
    radius+=pow((query[i]-curr_best[i]),2);
  }
  double distance=pow((query[dimension]-curr_node->point[dimension]),2);
  if(radius>=distance){
    findHelper(otherNode,curr_best,query,(dimension+1)%Dim);
  }


}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
{
    /**
     * @todo Implement this function!
     */
     if(root==NULL){
       return Point<Dim>();
     }
     Point<Dim> curr_best=root->point;
     Point<Dim> target=query;
     findHelper(root,curr_best,target,0);
     return curr_best;

    // return Point<Dim>();
}
