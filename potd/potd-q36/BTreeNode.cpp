#include <vector>
#include "BTreeNode.h"


// std::vector<int> traverse(BTreeNode* root) {
//     // your code here
//     std::vector<int> v;
//     if(root->is_leaf_){
//     	for(unsigned i=0;i<root->elements_.size();i++){
//     	v.push_back(root->elements_[i]);}
//     	return v;
//     }
//     else{
//     	for(unsigned j=0;j<root->elements_.size();j++){
//     		return traverse(root->children_[j]);
//     		v.push_back(root->elements_[j]);
//     	}
//     	return traverse(root->children_.back());
//     }
//     // return v;
// }

void traverse(BTreeNode* root, std::vector<int> & answer){
    if(root->is_leaf_){
    	for(unsigned i=0;i<root->elements_.size();i++){
    	answer.push_back(root->elements_[i]);}
    	return ;
    }	
    else{
    	for(unsigned j=0;j<root->elements_.size();j++){
    		traverse(root->children_[j],answer);
    		answer.push_back(root->elements_[j]);
    	}
    	traverse(root->children_.back(),answer);
    }
}

std::vector<int> traverse(BTreeNode* root) {
    // your code here
    std::vector<int> v;
    traverse(root,v);
    return v;

}

