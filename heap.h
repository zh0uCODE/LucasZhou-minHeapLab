// heap.h
// Binary heap tree header file for CS 24 lab
// Diba Mirza

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>

class Heap{

 public:
    Heap() {}  // default constructor
    Heap(std::vector<int>::iterator start, std::vector<int>::iterator end); // build a heap from a range using heapify
    void push(int value);     // insert value; //duplicates are allowed
    void pop(); // delete the min element
    int top();
    bool empty();

 private:
    std::vector<int> vdata; //store the binary heap tree as a dynamic array
    int getParentIndex(int i); //get parent index helper
    int getLeftChildIndex(int i); //get left child index helper
    int getRightChildIndex(int i); //get right child index helper
    int getStartingPointHeapifyDown(std::vector<int>&v); //get node before leaf
    void HeapifyDown(int i); //heapify down function
    void HeapifyUp(int curr_idx);
};

#endif
