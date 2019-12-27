#include "TreeNode.h"
#include<algorithm>
#include<queue>

int getHeight(TreeNode* root){
	if(root==NULL){
		return -1;
	}
	else{
		return 1+std::max(getHeight(root->left_),getHeight(root->right_));
	}
}

TreeNode* findLastUnbalanced(TreeNode* root) {
  // your code here

	std::queue<TreeNode*> q;
	q.push(root);
	TreeNode* result=NULL;
	while(!q.empty()){
		TreeNode* curr=q.front();
		q.pop();
		int b=getHeight(curr->right_)-getHeight(curr->left_);
		if(b>1||b<-1){
			result=curr;
		}
		if(curr->left_!=NULL){
			q.push(curr->left_);
		}
		if(curr->right_!=NULL){
			q.push(curr->right_);
		}
	}
	return result;

  return NULL;
}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}

