#include <vector>
#include "BTreeNode.h"


BTreeNode* find(BTreeNode* root, int key) {
    // Your Code Here
    if(root==NULL){
    	return NULL;
    }
    if(root->is_leaf_){ 
    	if(key<root->elements_[0]){
    		return NULL;
    	}
    	else{
    	for(unsigned j=0;j<root->elements_.size();j++){
    		if(key==root->elements_[j]){
    			return root;
    		}
    		else if(key<root->elements_[j]){
    			return NULL;
    		}
    	}
    	if(key>root->elements_.back()){
    		return NULL;
    	}
    	}
    }
    else{
    for(unsigned i=0;i<root->elements_.size();i++){
    	if(key==root->elements_[i]){
    		return root;
    	}
    	else if(key<root->elements_[i]){
    		return find(root->children_[i],key);
    	}
    }
    if(key>root->elements_.back()){
    	return find(root->children_.back(),key);
    }
	}
  // return NULL;
}
