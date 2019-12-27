#include "abstractsyntaxtree.h"
#include <string>

/**
 * Calculates the value from an AST (Abstract Syntax Tree). To parse numbers from strings, please use std::stod
 * @return A double representing the calculated value from the expression transformed into an AST
 */
double AbstractSyntaxTree::eval() const {
    // @TODO Your code goes here...
    return helperEval(this->getRoot());
    // return -1;
}

double AbstractSyntaxTree::helperEval(const Node* subRoot) const {
    if(subRoot==NULL){
      return -1;
    }
    if(subRoot->left==NULL&&subRoot->right==NULL){
      return std::stod(subRoot->elem);
    }
    else{
    if(subRoot->elem=="+"){
      return helperEval(subRoot->left)+helperEval(subRoot->right);
    }
    if(subRoot->elem=="-"){
      return helperEval(subRoot->left)-helperEval(subRoot->right);
    }
    if(subRoot->elem=="*"){
      return helperEval(subRoot->left)*helperEval(subRoot->right);
    }
    if(subRoot->elem=="/"){
      return helperEval(subRoot->left)/helperEval(subRoot->right);
    }
  }
  return -1;
}
