#ifndef TREE_CPP
#define TREE_CPP

#include "tree.h"

template <class T>
Tree<T>::Iterator::Iterator(Tree::Node *root) : curr_(root) {
	// TODO: your code here
	s.push(root);
}

template <class T>
typename Tree<T>::Iterator & Tree<T>::Iterator::operator++() {
	// TODO: your code here
	while (!s.empty()&&s.top()->data_%2!=0) {
		Node* temp1=s.top();
		s.pop();
		if(temp1->right_!=NULL){
			s.push(temp1->right_);
		}
		if(temp1->left_!=NULL){
			s.push(temp1->left_);
		}
	}
	Node* temp=s.top();
	s.pop();
	if(temp->right_!=NULL){
		s.push(temp->right_);
	}
	if(temp->left_!=NULL){
		s.push(temp->left_);
	}
	curr_=s.top();
	return *this;
}

template <class T>
T Tree<T>::Iterator::operator*() const {
	// TODO: your code here
	// return curr_->data_;
	return T(); // remove this line
}



/*******************
 ** PROVIDED CODE **
 *******************/
template <class T>
bool Tree<T>::Iterator::operator!=(const Tree<T>::Iterator &other) {
	return !(curr_ == other.curr_);
}

template <class T>
typename Tree<T>::Iterator Tree<T>::begin() {
	return Iterator(root_);
}

template <class T>
typename Tree<T>::Iterator Tree<T>::end() {
	return Iterator(NULL);
}

#endif
