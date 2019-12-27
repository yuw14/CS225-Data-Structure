#include "TreeNode.h"

#include <cstddef>
#include <iostream>
using namespace std;

TreeNode::TreeNode() : left_(NULL), right_(NULL) { }

int TreeNode::getHeight() {
	if(left_==NULL&&right_==NULL){
		return 0;
	}
	if(left_==NULL&&right_!=NULL){
		return 1+right_->getHeight();
	}
	if(left_!=NULL&&right_==NULL){
		return 1+left_->getHeight();
	}
	return 1+max(left_->getHeight(),right_->getHeight());	
  // return -1;
}
