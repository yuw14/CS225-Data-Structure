/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 */

template <class T>
List<T>::List() {
  // @TODO: graded in MP3.1
    head_ = NULL;
    tail_ = NULL;
    length_=0;
}

/**
 * Returns a ListIterator with a position at the beginning of
 * the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::begin() const {
  // @TODO: graded in MP3.1
  return List<T>::ListIterator(head_);
}

/**
 * Returns a ListIterator one past the end of the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::end() const {
  // @TODO: graded in MP3.1
  return List<T>::ListIterator(NULL);
}


/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <typename T>
void List<T>::_destroy() {
  /// @todo Graded in MP3.1
  if(!(this->empty())){
    ListNode* curr=head_;
    ListNode* prev=NULL;
    while(curr!=NULL){
      prev=curr;
      ListNode* currNext=curr->next;
      delete curr;
      curr=currNext;
    }

  }
  head_=NULL;
  tail_=NULL;
  length_=0;
}

/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertFront(T const & ndata) {
  /// @todo Graded in MP3.1
  ListNode * newNode = new ListNode(ndata);
  newNode -> next = head_;
  newNode -> prev = NULL;

  if(head_==NULL){
    head_=newNode;
    tail_=newNode;
  }
  if (head_ != NULL) {
    // head_ -> prev = newNode;
    head_->prev=newNode;
    head_  = newNode;

  }
  // if (tail_ == NULL)
  // {
  //   tail_ = newNode;
  // }
  length_++;

}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertBack(const T & ndata) {
  /// @todo Graded in MP3.1
  ListNode * newNode = new ListNode(ndata);
  newNode->prev=tail_;
  newNode->next=NULL;
  if(tail_==NULL){
    head_=newNode;
    tail_=newNode;
  }
  if(tail_!=NULL){
    // std::cout<<(tail_==NULL)<<std::endl;
    tail_->next=newNode;
    tail_=newNode;
  }
  length_++;

}

/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List or ListNode objects!
 *
 * This function is also called by the public split() function located in
 * List-given.hpp
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <typename T>
typename List<T>::ListNode * List<T>::split(ListNode * start, int splitPoint) {
  /// @todo Graded in MP3.1
  if(splitPoint==0){
    return start;}

  ListNode * curr = start;

  for (int i = 0; i < splitPoint && curr != NULL; i++) {
    // if(i==(splitPoint)){
    //   curr->prev->next=NULL;
    //   curr->prev=NULL;
    //   return curr;
    // }


    curr = curr->next;
  }
  // return NULL;
  //
  if (curr != NULL) {
      curr->prev->next = NULL;
      curr->prev = NULL;
      return curr;
  }

  return NULL;


}

/**
 * Modifies the List using the waterfall algorithm.
 * Every other node (starting from the second one) is removed from the
 * List, but appended at the back, becoming the new tail. This continues
 * until the next thing to be removed is either the tail (**not necessarily
 * the original tail!**) or NULL.  You may **NOT** allocate new ListNodes.
 * Note that since the tail should be continuously updated, some nodes will
 * be moved more than once.
 */
template <typename T>
void List<T>::waterfall() {
  /// @todo Graded in MP3.1
  // if(head_==NULL){return;}
  // ListNode* curr=head_;
  // ListNode* tail=tail_;
  // if(curr==NULL){return;}
  // if(curr->next==NULL||curr->next==tail){
  //   return;
  // }
  // else{
  //   ListNode* tmp1=curr->next->next;
  //   ListNode* tmp2=curr->next;
  //   curr->next->next=NULL;
  //   curr->next->prev=tail;
  //   tail->next=tmp2;
  //   curr->next=tmp1;
  //   tmp1->prev=curr;
  //   curr=tmp1;
  //   tail=tmp2;
  //  return waterfall();
  // }
  ListNode* curr=head_;
  ListNode* tail=tail_;
  if(curr==NULL){return;}
  while(!(curr->next==NULL||curr->next==tail)){
    ListNode* tmp1=curr->next->next;
    ListNode* tmp2=curr->next;
    curr->next->next=NULL;
    curr->next->prev=tail;
    tail->next=tmp2;
    curr->next=tmp1;
    tmp1->prev=curr;
    curr=tmp1;
    tail=tmp2;
  }
  return;
}

/**
 * Reverses the current List.
 */
template <typename T>
void List<T>::reverse() {
  reverse(head_, tail_);
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
template <typename T>
void List<T>::reverse(ListNode *& startPoint, ListNode *& endPoint) {
  /// @todo Graded in MP3.2
  if(startPoint==endPoint){
    return;
  }
  ListNode* curr=startPoint;
  ListNode* e=endPoint;
  ListNode* s=startPoint;
  ListNode* ePN=endPoint->next;
  ListNode* sPP=startPoint->prev;

  while(curr!=ePN){
    ListNode *currNext=curr->next;
    curr->next=curr->prev;
    curr->prev=currNext;
    curr=currNext;
    }
    s->next=ePN;
    e->prev=sPP;
    endPoint=s;
    startPoint=e;
    if(sPP==NULL){
      head_=startPoint;
      head_->prev=NULL;
    }
    else{sPP->next=startPoint;}
    if(ePN==NULL){
      tail_=endPoint;
      tail_->next=NULL;
    }
    else{ePN->prev=endPoint;}
}

//   while(curr!=ePN){
//     ListNode *currNext=curr->next;
//     curr->next=curr->prev;
//     curr->prev=currNext;
//     curr=currNext;
//     }
//
//     f->next=ePN;
//     e->prev=sPP;
//     endPoint=f;
//     startPoint=e;
// }

/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <typename T>
void List<T>::reverseNth(int n) {
  /// @todo Graded in MP3.2
  if(this->size()<=n){
    this->reverse(head_,tail_);
    return;
  }
  ListNode* blockStart=head_;
  ListNode* blockEnd=NULL;
  ListNode* curr=blockStart;
  while(blockStart!=NULL){
    //judge if it is the last block
    curr=blockStart;
    for(int i=0;i<n;i++){
      if(curr->next==NULL){
        blockEnd=curr;
        break;
      }
      curr=curr->next;
    }
    if(blockEnd==NULL){
      ListNode* E=blockStart;
      for(int i=0;i<(n-1);i++){
        E=E->next;
      }
      ListNode* Enext=E->next;
      if(blockStart==head_){
        this->reverse(head_,E);
      }
      else{this->reverse(blockStart,E);}
      blockStart=Enext;
      blockEnd=NULL;
    }
    else{
      this->reverse(blockStart,tail_);
      return;
    }
  }
}


/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <typename T>
void List<T>::mergeWith(List<T> & otherList) {
    // set up the current list
    head_ = merge(head_, otherList.head_);
    tail_ = head_;

    // make sure there is a node in the new list
    if (tail_ != NULL) {
        while (tail_->next != NULL)
            tail_ = tail_->next;
    }
    length_ = length_ + otherList.length_;

    // empty out the parameter list
    otherList.head_ = NULL;
    otherList.tail_ = NULL;
    otherList.length_ = 0;
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <typename T>
typename List<T>::ListNode * List<T>::merge(ListNode * first, ListNode* second) {
  /// @todo Graded in MP3.2
  if(first==NULL&&second==NULL){
    return NULL;
  }
  if(first==NULL&&second!=NULL){
    return second;
  }
  if(first!=NULL&&second==NULL){
    return first;
  }
  else{
     ListNode* third=NULL;
    if(first->data<second->data){
      third=first;
      first=first->next;
    }
    else{
      third=second;
      second=second->next;
    }
    ListNode* tmp1=first;
    ListNode* tmp2=second;
    ListNode* tmp3=third;
    while (tmp1!=NULL&&tmp2!=NULL) {
      if(tmp1->data<tmp2->data){
        ListNode* tmp1Next=tmp1->next;
        tmp3->next=tmp1;
        tmp1->prev=tmp3;
        // tmp1->next=NULL;
        tmp1=tmp1Next;
        tmp3=tmp3->next;
      }
      else{
        ListNode* tmp2Next=tmp2->next;
        tmp3->next=tmp2;
        tmp2->prev=tmp3;
        // tmp2->next=NULL;
        tmp2=tmp2Next;
        tmp3=tmp3->next;
        }
      }
      if(tmp1==NULL&&tmp2!=NULL){
        tmp3->next=tmp2;
        tmp2->prev=tmp3;
      }
      if(tmp1!=NULL&&tmp2==NULL){
        tmp3->next=tmp1;
        tmp1->prev=tmp3;
      }
      return third;
    }
}

/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * Called by the public sort function in List-given.hpp
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <typename T>
typename List<T>::ListNode* List<T>::mergesort(ListNode * start, int chainLength) {
  /// @todo Graded in MP3.2
  if(start->next==NULL){
    return start;
  }
  ListNode* second=split(start,chainLength/2);
  return merge(mergesort(start,chainLength/2),mergesort(second,chainLength-chainLength/2));
  // return NULL;
}
