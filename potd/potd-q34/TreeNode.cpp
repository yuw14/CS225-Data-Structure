#include "TreeNode.h"

TreeNode::RotationType balanceTree(TreeNode*& subroot) {
	// Your code here
	int b1=getHeight(subroot->right_)-getHeight(subroot->left_);
	if(b1==2){
		int b2=getHeight(subroot->right_->right_)-getHeight(subroot->right_->left_);
		if(b2==1){
			return TreeNode::left;
		}
		else{
			return TreeNode::rightLeft;
		}
	}
	if(b1==-2){
		int b3=getHeight(subroot->left_->right_)-getHeight(subroot->left_->left_);		
		if(b3==-1){
			return TreeNode::right;
		}
		else{
			return TreeNode::leftRight;
		}
	}	
  return TreeNode::right;
}
