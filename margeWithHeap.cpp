#include <iostream>
#include "margeWithHeap.h"
using namespace std;

heap::heap(int max) {
	data = new element[max];

	maxSize = max;

	heapSize = 0;
}

heap::~heap() {
	delete[] data;
}

element heap::min() {
	return data[0];
}

element heap::deleteMin() {
	if (heapSize < 1){
		throw emptyHeapException();
	}
	else {
		element min = data[0];
		heapSize--;
		data[0] = data[heapSize];
		fixHeap(0);
		return min;
	}
}

void heap::insert(element item) {
	if (heapSize == maxSize) {
		throw noMemoryException();
}
	int i = heapSize;
	heapSize++;

	while ((i > 0) && (data[getParent(i)].priority > item.priority)){
		data[i] = data[getParent(i)];
	i = getParent(i);
}
data[i] = item;
}

void heap::fixHeap(int node) {
	int min;
	int left = getLeft(node);
	int right = getRight(node);


	if ((left < heapSize) && (data[left].priority < data[node].priority)) {
		min = left;
	}
	else {
		min = node;
	}

	if ((right < heapSize) && (data[right].priority < data[min].priority)) {
		min = right;
	}

    if (min != node) {
		swap(node, min);
		fixHeap(min);
	}
}

void heap::swap(int index1, int index2) {
	element temp = data[index1];
	data[index1] = data[index2];
	data[index2] = temp;
}