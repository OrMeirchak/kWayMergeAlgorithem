#pragma once
#include "margeWithHeap.h"

class kWayMergeAlgorithem {

private:
	void regularMerge(myArray& arr,arrayOfArrayes& arrOfArrayes);
	void quickSort(myArray& arr, int begin, int end);
	int partition(myArray& arr, const int begin, const int end);

public:
	void operator()(myArray& arr, int k);

};