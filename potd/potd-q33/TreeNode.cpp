#include "TreeNode.h"
#include <algorithm>


void rightRotate(TreeNode* root) {

    // Your code here
    TreeNode* newRoot=root->left_;
    TreeNode* ancenstor=root->parent_;
    TreeNode* naughty=newRoot->right_;
    newRoot->right_=root;
    root->parent_=newRoot;
    if(ancenstor==NULL){
    	newRoot->parent_=NULL;
    }
    else{
    	newRoot->parent_=ancenstor;
    	ancenstor->left_=newRoot;
    }
    if(naughty==NULL){
    	root->left_=NULL;
    }
    else{
    	root->left_=naughty;
    	naughty->parent_=root;
    }

}


void leftRotate(TreeNode* root) {

    // your code here
    TreeNode* newRoot=root->right_;
    TreeNode* ancenstor=root->parent_;
    TreeNode* naughty=newRoot->left_;
    newRoot->left_=root;
    root->parent_=newRoot;
    if(ancenstor==NULL){
    	newRoot->parent_=NULL;
    }
    else{
    	newRoot->parent_=ancenstor;
    	ancenstor->right_=newRoot;
    }
    if(naughty==NULL){
    	root->right_=NULL;
    }
    else{
    	root->right_=naughty;
    	naughty->parent_=root;
    }
}



void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}

