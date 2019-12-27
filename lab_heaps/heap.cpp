
/**
 * @file heap.cpp
 * Implementation of a heap class.
 */
 #include<math.h>

template <class T, class Compare>
size_t heap<T, Compare>::root() const
{
    // @TODO Update to return the index you are choosing to be your root.
    // return 0;
    return 1;
}

template <class T, class Compare>
size_t heap<T, Compare>::leftChild(size_t currentIdx) const
{
    // @TODO Update to return the index of the left child.
    return 2*currentIdx;
    // return 0;
}

template <class T, class Compare>
size_t heap<T, Compare>::rightChild(size_t currentIdx) const
{
    // @TODO Update to return the index of the right child.
    // return 0;
    return (2*currentIdx+1);

}

template <class T, class Compare>
size_t heap<T, Compare>::parent(size_t currentIdx) const
{
    // @TODO Update to return the index of the parent.
    // return 0;
    return currentIdx/2;
}

template <class T, class Compare>
bool heap<T, Compare>::hasAChild(size_t currentIdx) const
{
    // @TODO Update to return whether the given node has a child
    // return false;
    return (2*currentIdx)<(_elems.size());
}

template <class T, class Compare>
size_t heap<T, Compare>::maxPriorityChild(size_t currentIdx) const
{
    //assume has at least one child
    // @TODO Update to return the index of the child with highest priority
    ///   as defined by higherPriority()
    if(hasAChild(currentIdx)){
      if((2*currentIdx+1)==_elems.size()){
        return leftChild(currentIdx);
      }
      if(higherPriority(_elems[leftChild(currentIdx)],_elems[rightChild(currentIdx)])){
        return leftChild(currentIdx);
      }
      return rightChild(currentIdx);
    }
    return 0;

}

template <class T, class Compare>
void heap<T, Compare>::heapifyDown(size_t currentIdx)
{
    // @TODO Implement the heapifyDown algorithm.
    if(hasAChild(currentIdx)){
      size_t maxPriorityChildIndex=maxPriorityChild(currentIdx);
      if(higherPriority(_elems[maxPriorityChildIndex],_elems[currentIdx])){
        std::swap(_elems[maxPriorityChildIndex],_elems[currentIdx]);
        heapifyDown(maxPriorityChildIndex);
      }
    }
    // return;
}

template <class T, class Compare>
void heap<T, Compare>::heapifyUp(size_t currentIdx)
{
    if (currentIdx == root())
        return;
    size_t parentIdx = parent(currentIdx);
    if (higherPriority(_elems[currentIdx], _elems[parentIdx])) {
        std::swap(_elems[currentIdx], _elems[parentIdx]);
        heapifyUp(parentIdx);
    }
}

template <class T, class Compare>
heap<T, Compare>::heap()
{
    // @TODO Depending on your implementation, this function may or may
    ///   not need modifying
    _elems.push_back(T());
}

template <class T, class Compare>
heap<T, Compare>::heap(const std::vector<T>& elems)
{
    // @TODO Construct a heap using the buildHeap algorithm
    // _elems.resize(elems.size()+1);
    _elems.push_back(T());
    // if(!elems.empty()){
      for(size_t i=0;i<elems.size();i++){
        _elems.push_back(elems[i]);
      }
    // }
    for(size_t j=parent(_elems.size()-1);j>0;j--)
    {
      heapifyDown(j);
    }
}

template <class T, class Compare>
T heap<T, Compare>::pop()
{
    // @TODO Remove, and return, the element with highest priority
    if(empty()){
    return T();
    }
    // else if(_elems.size()==2){
    //   T temp=_elems[root()];
    //   _elems.pop_back();
    //   return temp;
    // }
    else{
      T minValue=_elems[root()];
      _elems[root()]=_elems[_elems.size()-1];
      // std::swap(_elems[root()],_elems[_elems.size()-1]);
      _elems.pop_back();
      heapifyDown(root());
      return minValue;
    }
}

template <class T, class Compare>
T heap<T, Compare>::peek() const
{
    // @TODO Return, but do not remove, the element with highest priority
    if(empty()){
    return T();
    }
    else{
      return _elems[root()];
    }
}

template <class T, class Compare>
void heap<T, Compare>::push(const T& elem)
{
    // @TODO Add elem to the heap
    _elems.push_back(elem);
    heapifyUp(_elems.size()-1);
}

template <class T, class Compare>
void heap<T, Compare>::updateElem(const size_t & idx, const T& elem)
{
    // @TODO In-place updates the value stored in the heap array at idx
    // Corrects the heap to remain as a valid heap even after update
    size_t index=(idx);
    if(index>(_elems.size()-1)){
      return;
    }
    else{
      T curr_=_elems[index];
      _elems[index]=elem;
      if(higherPriority(elem,curr_)){
        heapifyUp(index);
      }
      else{
        heapifyDown(index);
      }
    }
}


template <class T, class Compare>
bool heap<T, Compare>::empty() const
{
    // @TODO Determine if the heap is empty
    if(_elems.size()<=1){
      return true;
    }
    else{
      return false;
    }
    // return true;
}

template <class T, class Compare>
void heap<T, Compare>::getElems(std::vector<T> & heaped) const
{
    for (size_t i = root(); i < _elems.size(); i++) {
        heaped.push_back(_elems[i]);
    }
}
