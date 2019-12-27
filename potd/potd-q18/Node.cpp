#include "Node.h"

void mergeList(Node *first, Node *second) { 
  // your code here!
	// if(first==NULL || second==NULL){
	// 	return;
	// }
	// if(first->next_ == NULL){
	// 	first->next_=second;
	// 	return;
	// }
	if ((first==NULL)&&(second==NULL)){return;}
	if((first!=NULL)&&(second==NULL)){return;}
	if((first->next_==NULL)&&(second->next_!=NULL)){return;}
	Node* tmp1=first->next_;
	Node* tmp2=second->next_;
	second->next_=tmp1;
	first->next_=second;
	mergeList(tmp1,tmp2);
}

Node::Node() {
    numNodes++;
}

Node::Node(const Node &other) {
    this->data_ = other.data_;
    this->next_ = other.next_;
    numNodes++;
}

Node::~Node() {
    numNodes--;
}

int Node::numNodes = 0;
