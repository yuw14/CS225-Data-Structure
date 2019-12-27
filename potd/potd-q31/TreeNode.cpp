#include "TreeNode.h"
#include <cstdlib>
#include <cstddef>
#include"math.h"


int getHeight(TreeNode* root){
	if(root==NULL){return -1;}
	if(root->left_==NULL&&root->right_==NULL){
		return 0;
	}
	if(root->left_==NULL){
		return 1+getHeight(root->right_);
	}
	if(root->right_==NULL){
		return 1+getHeight(root->left_);
	}
	else{
		return 1+fmax(getHeight(root->left_),getHeight(root->right_));
	}
}

bool isHeightBalanced(TreeNode* root) {
  // your code here
	// bool result=true;
	int b;
	if(root==NULL){
		return true;
	}
	if(root->left_==NULL&&root->right_==NULL){
		return true;
	}
	else{
		b=abs(getHeight(root->right_)-getHeight(root->left_));
		return (b<=1)&&isHeightBalanced(root->left_)&&isHeightBalanced(root->right_);
	}
  // return false;
}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}

