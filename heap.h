#pragma once
#include <iostream>

using namespace std;

class Heap {
private:
    int N = 10;
    int heap[10];

    // construction of the heap
    void Heapify(int A[], const int n, const int i);
    // sorting with heap sort algorithm
    void HeapSort(int A[], const int n);

public:
    Heap();
    Heap(int input[], const int n);

    // method to call the Heapify function from outside without parameters
    void MakeHeap();
    // swaping 2 given elements
    void Swap(int& X, int& Y);
    // deleting max element (root) from the heap + its reconstruction
    void DeleteRoot();
    // method to call the HeapSort function from outside without parameters
    void HeapSort();
    // prints the heap to the console
    void PrintHeap();
};