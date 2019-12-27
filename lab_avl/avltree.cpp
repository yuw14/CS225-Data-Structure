/**
 * @file avltree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */
#include"math.h"
#include <algorithm>
using namespace std;
template <class K, class V>
V AVLTree<K, V>::find(const K& key) const
{
    return find(root, key);
}

template <class K, class V>
V AVLTree<K, V>::find(Node* subtree, const K& key) const
{
    if (subtree == NULL)
        return V();
    else if (key == subtree->key)
        return subtree->value;
    else {
        if (key < subtree->key)
            return find(subtree->left, key);
        else
            return find(subtree->right, key);
    }
}

template <class K, class V>
void AVLTree<K, V>::rotateLeft(Node*& t)
{
    functionCalls.push_back("rotateLeft"); // Stores the rotation name (don't remove this)
    // your code here
    Node* newRoot=t->right;
    t->right=newRoot->left;
    newRoot->left=t;
    t->height=getHeight(t);
    newRoot->height=getHeight(newRoot);
    t=newRoot;
}

template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node*& t)
{
    functionCalls.push_back("rotateLeftRight"); // Stores the rotation name (don't remove this)
    // Implemented for you:
    rotateLeft(t->left);
    rotateRight(t);
}

template <class K, class V>
void AVLTree<K, V>::rotateRight(Node*& t)
{
    functionCalls.push_back("rotateRight"); // Stores the rotation name (don't remove this)
    // your code here
    Node* newRoot=t->left;
    t->left=newRoot->right;
    newRoot->right=t;
    t->height=getHeight(t);
    newRoot->height=getHeight(newRoot);
    t=newRoot;
}

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node*& t)
{
    functionCalls.push_back("rotateRightLeft"); // Stores the rotation name (don't remove this)
    // your code here
    rotateRight(t->right);
    rotateLeft(t);
}

template <class K, class V>
int AVLTree<K, V>::getHeight(Node* subRoot){
  if(subRoot==NULL){
    return -1;
  }
  else{
    return 1+max(getHeight(subRoot->left),getHeight(subRoot->right));
  }

}

template <class K, class V>
void AVLTree<K, V>::rebalance(Node*& subtree)
{
    // your code here
    if(subtree==NULL){
      return;
    }
    int b1=getHeight(subtree->right)-getHeight(subtree->left);
    if(b1==2){
      int b2=getHeight(subtree->right->right)-getHeight(subtree->right->left);
      if(b2==1){
        rotateLeft(subtree);
      }
      else(rotateRightLeft(subtree));
    }
    if(b1==-2){
      int b3=getHeight(subtree->left->right)-getHeight(subtree->left->left);
      if(b3==-1){
        rotateRight(subtree);
      }
      else{rotateLeftRight(subtree);}
    }
}

template <class K, class V>
void AVLTree<K, V>::insert(const K & key, const V & value)
{
    insert(root, key, value);
}

template <class K, class V>
void AVLTree<K, V>::insert(Node*& subtree, const K& key, const V& value)
{
    // your code here
    if(subtree==NULL){
      subtree=new Node(key,value);
    }
    if(subtree->key==key){
      subtree->value=value;
    }
    else if(key<subtree->key){
      insert(subtree->left,key,value);
    }
    else if(key>subtree->key){
      insert(subtree->right,key,value);
    }
    rebalance(subtree);
}

template <class K, class V>
void AVLTree<K, V>::remove(const K& key)
{
    remove(root, key);
}

template <class K, class V>
void AVLTree<K, V>::remove(Node*& subtree, const K& key)
{
    if (subtree == NULL)
        return;

    if (key < subtree->key) {
        // your code here
        remove(subtree->left,key);
    } else if (key > subtree->key) {
        // your code here
        remove(subtree->right,key);
    } else {
        if (subtree->left == NULL && subtree->right == NULL) {
            /* no-child remove */
            // your code here
            Node* temp=subtree;
            subtree=NULL;
            delete temp;
            // return;
        } else if (subtree->left != NULL && subtree->right != NULL) {
            /* two-child remove */
            // your code here
            Node* IOP=subtree;
            IOP=subtree->left;
            while(IOP->right!=NULL){
              IOP=IOP->right;
            }
            swap(IOP,subtree);
            remove(subtree->left,key);
        } else {
            /* one-child remove */
            // your code here
            Node* temp=subtree;
            if(temp->left!=NULL){
              subtree=temp->left;
            }
            else{
              subtree=temp->right;
            }
            delete temp;
        }
        // your code here
    }
    rebalance(subtree);

}
