#include "heap.h"

Heap::Heap() {
    // heap from lecture slides
    int temp[] = {9, 8, 6, 2, 5, 1};
    this->N = 6;
    for (int i = 0; i < this->N; i++) {
        this->heap[i] = temp[i];
    }
    cout << "Inputed heap:" << endl;
    PrintHeap();

    // building the heap
    for (int i = N / 2 - 1; i >= 0; i--) {
        Heapify(this->heap, this->N, i);
    }
}

Heap::Heap(int input[], const int n) {
    for (int i = 0; i < n; i++) {
        this->heap[i] = input[i];
    }
    this->N = n;
    cout << "Inputed heap:" << endl;
    PrintHeap();

    // building the heap
    for (int i = N / 2 - 1; i >= 0; i--) {
        Heapify(this->heap, this->N, i);
    }
}

void Heap::Heapify(int A[], const int n, const int i) {
    int largest = i; // root
    int l = 2 * i + 1; // left child node
    int r = 2 * i + 2; // right child node

    if (l < n && A[l] > A[largest]) {
        largest = l;
    }

    if (r < n && A[r] > A[largest]) {
        largest = r;
    }

    if (largest != i) {
        Swap(A[i], A[largest]);
        Heapify(A, n, largest);
    }
}

void Heap::MakeHeap() {
    for (int i = (this->N / 2) - 1; i >= 0; i--) {
        Heapify(this->heap, this->N, i);
    }
}

void Heap::Swap(int& X, int& Y) {
    int temp = X;
    X = Y;
    Y = temp;
}

void Heap::DeleteRoot() {
    if (N <= 0) { // if the size is 0 --> root doesnt exist
        cout << "Heap is empty." << endl;
        return;
    } else { // else we can delete the root
        // root = last element and decrease heap size
        heap[0] = heap[N - 1];
        N--;
        // reconstruction of the heap
        Heapify(heap, N, 0);
    }
}

void Heap::HeapSort(int A[], const int n) {
    MakeHeap();
    for (int i = n - 1; i >= 0; i--) {
        Swap(A[0], A[i]);
        Heapify(A, i, 0);
    }
}

void Heap::HeapSort() {
    HeapSort(this->heap, this->N);
}

void Heap::PrintHeap() {
    cout << "parent\t\tleft child\tright child" << endl;
    for (int i = 0; i < this->N; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        cout << this->heap[i] << "\t\t";
        if (left < this->N) {
            cout << this->heap[left];
        } else {
            cout << "-";
        }
        cout << "\t\t";
        if (right < this->N) {
            cout << this->heap[right];
        } else {
            cout << "-";
        }
        cout << endl;
    }
    cout << "----------------------------------------------------" << endl;
}