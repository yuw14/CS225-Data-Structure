#include "Node.h"

using namespace std;

Node *listIntersection(Node *first, Node *second) {
  // your code here
  Node *third=NULL;//I don't know how to initialize
  Node *tmpSecondStart=second;
  Node * tmpThird=third;
  while(first!=NULL){
    while(second!=NULL){
      if(second->data_==first->data_){
        Node* node=new Node();
        node->data_=second->data_;
        node->next_=NULL;
        if(third==NULL){
          third=node;
          third->data_=second->data_;
          third->next_=NULL;//How to idicate it's the first element in the new list
          tmpThird=third;
        }
        else{tmpThird->next_=node;
        tmpThird=tmpThird->next_;}
      }
      second=second->next_;
    }
    second=tmpSecondStart;
    first=first->next_;
  }
  return third;
  // return NULL;
}

Node::Node() {
    numNodes++;
}

Node::Node(Node &other) {
    this->data_ = other.data_;
    this->next_ = other.next_;
    numNodes++;
}

Node::~Node() {
    numNodes--;
}

int Node::numNodes = 0;
