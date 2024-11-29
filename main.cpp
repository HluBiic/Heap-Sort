#include "heap.h"

/*
* This class demonstrates the functionality of the program by printing 4 forms of heap:
*	1. inputed heap,
*	2. initial heap (after heapify),
*	3. after deleting the root,
*	4. after sorting with heap sort algorithm.
*/

int main() {
    int A[] = { 15, 3, 27, 10, 6, 22, 13, 19, 8, 29 }; // example heap
	int n = 10;

    Heap heap(A, n);
	cout << "Initial heap:" << endl;
    heap.PrintHeap();

	cout << "Heap after deleting root:" << endl;
    heap.DeleteRoot();
    heap.PrintHeap();

	cout << "Sorted heap:" << endl;
    heap.HeapSort();
    heap.PrintHeap();

    return 0;
}