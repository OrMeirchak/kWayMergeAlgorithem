#pragma once
#include <iostream>
#include "arrayOfArrayes.h"
using namespace std;

class emptyHeapException : public exception {};

class noMemoryException : public exception {};

struct element {
	long int priority;
	myArray* arr;

	element() :element(0, nullptr) {}
	element(long int _priority, myArray* _data) :priority(_priority), arr(_data) {}
	element(int _priority, myArray* _data) :priority(_priority), arr(_data) {}
};

class heap{
private:
	element *data;
	int maxSize;
	int heapSize;

	static int getLeft(int node) {
		return (2 * node + 1);
	}
	static int getRight(int node) {
		return (2 * node + 2);
	}
	static int getParent(int node) {
		return (node - 1) / 2;
	}

	void fixHeap(int node);

public:
	heap(int max);
	~heap();
	element min();
	element deleteMin();
	void insert(element item);
	void swap(int index1, int index2);

	void static margeWithHeap(myArray& res, arrayOfArrayes& arrayOfArrayes) {

		heap Heap(arrayOfArrayes.getSize());

		for (int i = 0; i < arrayOfArrayes.getSize(); i++){

			element newElement(arrayOfArrayes[i][0], &arrayOfArrayes[i]);
			Heap.insert(newElement);
		}

		for (int i = 0; i < res.getSize(); i++) {
			res[i] = Heap.min().priority;

			myArray& arr = *(Heap.min().arr);

			int& p = arr.P();

			p++;

			try {
				Heap.data[0].priority = arr[p];
			}
			catch (outOfIndexExeption &e) {
				Heap.deleteMin();
			}
			Heap.fixHeap(0);
		}
	}

	//for debbuging
	friend ostream& operator<<(ostream& os, const heap& Heap)
	{
		os << " Heap : " << endl;
		for (int i = 0; i < Heap.heapSize; i++) {
			os << '[' << i << ']' << Heap.data[i].priority << endl;
		}
		os << endl;

		return os;
	}
	//
};
