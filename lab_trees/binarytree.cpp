/**
 * @file binarytree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */
#include "TreeTraversals/InorderTraversal.h"
#include <iostream>
#include<vector>

/**
 * @return The height of the binary tree. Recall that the height of a binary
 *  tree is just the length of the longest path from the root to a leaf, and
 *  that the height of an empty tree is -1.
 */
template <typename T>
int BinaryTree<T>::height() const
{
    // Call recursive helper function on root
    return height(root);
}

/**
 * Private helper function for the public height function.
 * @param subRoot
 * @return The height of the subtree
 */
template <typename T>
int BinaryTree<T>::height(const Node* subRoot) const
{
    // Base case
    if (subRoot == NULL)
        return -1;

    // Recursive definition
    return 1 + std::max(height(subRoot->left), height(subRoot->right));
}

/**
 * Prints out the values of the nodes of a binary tree in order.
 * That is, everything to the left of a node will be printed out before that
 * node itself, and everything to the right of a node will be printed out after
 * that node.
 */
template <typename T>
void BinaryTree<T>::printLeftToRight() const
{
    // Call recursive helper function on the root
    printLeftToRight(root);

    // Finish the line
    std::cout << std::endl;
}

/**
 * Private helper function for the public printLeftToRight function.
 * @param subRoot
 */
template <typename T>
void BinaryTree<T>::printLeftToRight(const Node* subRoot) const
{
    // Base case - null node
    if (subRoot == NULL)
        return;

    // Print left subtree
    printLeftToRight(subRoot->left);

    // Print this node
    std::cout << subRoot->elem << ' ';

    // Print right subtree
    printLeftToRight(subRoot->right);
}

/**
 * Flips the tree over a vertical axis, modifying the tree itself
 *  (not creating a flipped copy).
 */
template <typename T>
void BinaryTree<T>::mirror()
{
    //your code here
    mirror(root);
}

template <typename T>
void BinaryTree<T>::mirror( Node * subRoot)
{
  if(subRoot==NULL){
    return;
  }
  Node* tmp=subRoot->right;
  subRoot->right=subRoot->left;
  subRoot->left=tmp;
  mirror(subRoot->left);
  mirror(subRoot->right);
}
/**
 * isOrdered() function iterative version
 * @return True if an in-order traversal of the tree would produce a
 *  nondecreasing list output values, and false otherwise. This is also the
 *  criterion for a binary tree to be a binary search tree.
 */
template <typename T>
bool BinaryTree<T>::isOrderedIterative() const
{
    // your code here
    InorderTraversal<int> tree(this->getRoot());
    int lastElement;
    int count=0;
    for(TreeTraversal<int>::Iterator it=tree.begin();it!=tree.end();++it){
      if(count==0){
        lastElement=(*it)->elem;
        count++;
      }
      else{
        if((*it)->elem<lastElement){return false;}
        else{
          lastElement=(*it)->elem;
          count++;
        }
      }
    }
    return true;
}

/**
 * isOrdered() function recursive version
 * @return True if an in-order traversal of the tree would produce a
 *  nondecreasing list output values, and false otherwise.   if(subRoot==NULL){
    return
  }This is also the
 *  criterion for a binary tree to be a binary search tree.
 */
template <typename T>
bool BinaryTree<T>::isOrderedRecursive() const
{
    // your code here
    return isOrderedHelper(root,INT_MIN,INT_MAX);
    // return false;
}

template <typename T>
bool BinaryTree<T>::isOrderedHelper(const Node * subRoot,int min,int max) const{
  bool result=true;
  if(subRoot==NULL){return true;}
  else{
  if(subRoot->elem>max){
    return false;
  }
  if(subRoot->elem<min){
    return false;
  }
  else{
    result=result&&isOrderedHelper(subRoot->left,min,subRoot->elem)&&isOrderedHelper(subRoot->right,subRoot->elem,max);
    return result;
    }
  }
}

/**
 * creates vectors of all the possible paths from the root of the tree to any leaf
 * node and adds it to another vector.
 * Path is, all sequences starting at the root node and continuing
 * downwards, ending at a leaf node. Paths ending in a left node should be
 * added before paths ending in a node further to the right.
 * @param paths vector of vectors that contains path of nodes
 */
template <typename T>
void BinaryTree<T>::getPaths(std::vector<std::vector<T>>& paths) const
{
    // your code here
    std::vector<T> v;
    helperGetPaths(paths,root,v);
}

template <typename T>
void BinaryTree<T>::helperGetPaths(std::vector<std::vector<T>>& paths,const Node * subRoot,std::vector<T> temp) const
{
    // your code here
    // std::vector<T> temp;
    if(subRoot==NULL){
      return;
    }
    if(subRoot->left==NULL&&subRoot->right==NULL){
      temp.push_back(subRoot->elem);
      paths.push_back(temp);
      return;
    }
    temp.push_back(subRoot->elem);
    helperGetPaths(paths,subRoot->left,temp);
    helperGetPaths(paths,subRoot->right,temp);

}


/**
 * Each node in a tree has a distance from the root node - the depth of that
 * node, or the number of edges along the path from that node to the root. This
 * function returns the sum of the distances of all nodes to the root node (the
 * sum of the depths of all the nodes). Your solution should take O(n) time,
 * where n is the number of nodes in the tree.
 * @return The sum of the distances of all nodes to the root
 */
template <typename T>
int BinaryTree<T>::sumDistances() const
{
    // your code here
    // return -1;
    return sumDistances(root,0);
}

template <typename T>
int BinaryTree<T>::sumDistances(const Node* subRoot,int height) const
{
    // your code here
    if(subRoot==NULL){return 0;}
    else{
      return height+sumDistances(subRoot->left,height+1)+sumDistances(subRoot->right,height+1);
    }
    // return -1;
}
