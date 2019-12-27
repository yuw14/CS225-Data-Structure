#include "Node.h"
#include<iostream>
/** Create a new node and add it to the list, while keeping the list sorted.
*/
Node *insertSorted(Node *first, int data) {
    // your code here
    //Node node;
    Node* node=new Node();
    node->next_=NULL;
    node->data_=data;  

    if(first==NULL){
        first=node;
        return first;
        }
     if(first->data_>data){

        node->next_=first;
        first=node;
        return first;
        }   
    Node* tmpFirst=first;
    while(tmpFirst!=NULL){
        if(tmpFirst->data_==data){
            delete node;
            return first;
        }
        else if(tmpFirst->next_==NULL){
            tmpFirst->next_=node;
            return first;
        }
        else if((tmpFirst->next_->data_)>data){
            node->next_=tmpFirst->next_;
            tmpFirst->next_=node;
            return first;
        }        
        else {tmpFirst=tmpFirst->next_;}

    }
    

    return NULL;
}

/** Creates a new list (containing new nodes, allocated on the heap)
	that contains the set union of the values in both lists.
*/
Node *listUnion(Node *first, Node *second) {
    Node *out = NULL;
    // Node* head=new Node(out); how to??

    while (first != NULL) {
        //iterate by first
        Node * nextFirst=first->next_;
        // your code here
        // hint: call insertSorted and update l1

        out=insertSorted(out,first->data_);
        first=nextFirst;}
    

    while (second != NULL) {
        // your code here
        Node * nextSecond=second->next_;
 
        out=insertSorted(out,second->data_);
        second=nextSecond;}

    

    return out;
        // return head; 
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
