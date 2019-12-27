#include "Node.h"

using namespace std;

Node *listSymmetricDifference(Node *first, Node *second) {
  // your code here
  // Node *third=NULL;
  // Node* secondStart=second;
  // Node* currThird=third;
  // Node* tmpThird=third;
  // while(first!=NULL){
  //   while(second!=NULL){
  //     //check if there is already a second->data_ in third
  //     currThird=third;
  //     while(currThird!=NULL){
  //       if(second->data_==currThird->data_){break;}
  //       else{currThird=currThird->next_;}
  //     }
  //     if(currThird!=NULL){second=second->next_;continue;}
  //     else{
  //       if(second->data_==first->data_){continue;}
  //       else{second=second->next_;continue;}
  //     }
  //     if(second==NULL){
  //     Node* node=new Node();
  //     node->data_=second->data_;
  //     node->next_=NULL;
  //     if(third==NULL){
  //       third=node;
  //       tmpThird=third;
  //     }
  //     else{tmpThird->next_=node;
  //     tmpThird=tmpThird->next_;}
  //     }
  //   }
  //   second=secondStart;
  //   first=first->next_;
  // }
  // return third;
  // return NULL;
  Node *third=NULL;
  Node* secondStart=second;
  Node* tmpThird=third;
  while(first!=NULL){
    while(second!=NULL){
      if(second->data_==first->data_){break;}
      else{second=second->next_;}
    }
    //do insertion
    if(second==NULL){
    Node* node=new Node();
    node->data_=first->data_;
    node->next_=NULL;
    if(third==NULL){
      third=node;
      tmpThird=third;
    }
    else{tmpThird->next_=node;
    tmpThird=tmpThird->next_;}
    }
    second=secondStart;
    first=first->next_;
  }
  return third;
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
