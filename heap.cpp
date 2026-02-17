// heap.cpp
// Lucas Zhou

#include "heap.h"
#include <iostream>
using std::cout;

// Builds a heap from the range [start, end) using the heapify algorithm
// Should run in O(n) time
Heap::Heap(std::vector<int>::iterator start, std::vector<int>::iterator end){
  vdata.assign(start, end); //go through and iterate through the vector
  int startingHeapIdx = getStartingPointHeapifyDown(vdata); //starting point
  for (int i = startingHeapIdx; i >= 0; i--) { //start from one before leaf index, iterate down to zero
    HeapifyDown(i); //do the heapify on every index i
  } 
}

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
  vdata.push_back(value); //push the value back into the vdata heap vector
  HeapifyUp(vdata.size() - 1); //start from the last element in the heap vector, go up
}

void Heap::HeapifyUp(int curr_idx) { //heapify up!
  while(curr_idx > 0) { //loops while current index is not the root
    int parent_idx = getParentIndex(curr_idx); //current index updates every time the while loop runs!
    if (vdata[curr_idx] < vdata[parent_idx]) { //if parent is greater
      int temp = vdata[curr_idx]; //set up current index for swap
      vdata[curr_idx] = vdata[parent_idx]; //update current value with parent's value
      vdata[parent_idx] = temp; //update parent value with current's value (as stored in temp
      curr_idx = parent_idx; //update the current index to parent! (so that you can move up the tree)
    } else { //current value greater than or equal to parent! (min heap property satisfied)
      break; //stop as soon as current is greater than or equal to parent!
    }
  }
}
  
// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
  if (vdata.empty()) { // empty vector?
    return; //exit, no need to pop
  }
  vdata[0] = vdata.back(); //update the root with the end
  vdata.pop_back(); //pop the end
  if (!vdata.empty()) { //removed root and still not empty?
    HeapifyDown(0); //heapify down from the root
  }
}

// Returns the minimum element in the heap
int Heap::top(){
  if (!vdata.empty()) { //check if vdata not empty
    return vdata[0]; //return first element of heap vector
  }
  throw std::runtime_error("Heap is empty"); //no root if empty
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  if (vdata.size() == 0) { //vector size is zero
    return true; //it's empty
  }
  return false; //not empty!
}

int Heap::getParentIndex(int i) { //parent index
  return (i-1) / 2; //index! 
}
int Heap::getLeftChildIndex(int i) { //left child index
  return 2*i + 1; //index!
}
int Heap::getRightChildIndex(int i) { //right child index
  return 2*i + 2; //index
}
int Heap::getStartingPointHeapifyDown(std::vector<int>& v) { //last node for heapify down
  return v.size()/2 - 1; //node before leaf
}
void Heap::HeapifyDown(int curr_idx) { //heapify helper (can use vdata)
  while(1) { //this algorithm repeats itself until the current index is smaller than the children
    int left = getLeftChildIndex(curr_idx); //get left child
    int right = getRightChildIndex(curr_idx); //get right child
    int smallest = curr_idx; //initialize smallest (in case there aren't any smaller than the parent!)
    if (left < vdata.size() && vdata[left] < vdata[smallest]) { //smaller child is the left, make sure it's below the parent
      smallest = left; //set smallest index to left
    }
    if (right < vdata.size() && vdata[right] < vdata[smallest]) { //if left child is already the smallest, find a smaller one in the right!
      smallest = right; //set smallest index to right
    }
    if (curr_idx == smallest) { //checkpoint: no need to move on! while loop done! parent is already smallest!
      return; //exit
    }
    int temp = vdata[curr_idx]; //store curr_idx data in temp (get ready to swap)
    vdata[curr_idx] = vdata[smallest]; //update current with smallest
    vdata[smallest] = temp; //update smallest with current
    curr_idx = smallest; //update current index with the smallest after swap!
  }
}

