#include "MinHeap.h"

vector<int> lastLevel(MinHeap & heap)
{
        // Your code here
	unsigned int idx=1;
	while((2*idx)<heap.elements.size()){
		idx=2*idx;
	}
	std::vector<int> v;
	for(unsigned int i=idx;i<heap.elements.size();i++){
		v.push_back(heap.elements[i]);
	}
	return v;
}


// #include "MinHeap.h"


// vector<int> lastLevel(MinHeap & heap) {
// 	unsigned int idx = 0;
// 	while ( (heap.elements.size() - 1) > (idx * 2 + 1) )
// 	{
// 		idx = idx * 2 + 1;
// 	}
// 	vector<int> v;
// 	for (unsigned int i = idx + 1; i < heap.elements.size(); i++) 
// 	{
// 		v.push_back(heap.elements[i]);
// 	}
// 	return v;
// }