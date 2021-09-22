#include "kWayMergeAlgorithem.h"

void kWayMergeAlgorithem::operator()(myArray& arr, int k) {
	if (k <= 0) {
		throw wrongInputException();
	}
    else if(k > arr.getSize()) {
		quickSort(arr,0,arr.getSize()-1);
	}
	else {
		arrayOfArrayes arrOfArrayes(arr, k);

		for (int i = 0; i < k; i++){
			kWayMergeAlgorithem recursion;
			recursion(arrOfArrayes[i], k);
		}

		if (k == 2) {
			regularMerge(arr, arrOfArrayes);
		}
			heap::margeWithHeap(arr, arrOfArrayes);
		}
	}

void kWayMergeAlgorithem::quickSort(myArray &arr, int begin, int end)
{
	if (begin < end){
		int pivot = partition(arr, begin, end);

		quickSort(arr, begin, pivot - 1); 
		quickSort(arr, pivot + 1, end); 
	}
}

int kWayMergeAlgorithem::partition(myArray& arr, const int begin, const int end) {
int pivot = begin;
	int p = end;

	while (p != pivot) {
		while ((p > pivot) && (arr[p] >= arr[pivot])) {
			p--;
		}

  		if (p != pivot) {
			arr.swap(p, pivot);

		}
		while (p < pivot && arr[p] < arr[pivot]) {
			p++;
		}

		if (p != pivot) {
			arr.swap(p, pivot);
		}
	}
	return pivot;
}

void kWayMergeAlgorithem::regularMerge(myArray& arr,arrayOfArrayes& arrOfArrayes)
{
    int read0 = 0;
    int read1 = 0;
    int write = 0;

    while (read0 < arrOfArrayes[0].getSize() && read1 < arrOfArrayes[0].getSize()) {
        if (arrOfArrayes[0][read0] <= arrOfArrayes[1][read1]) {
            arr[write] = arrOfArrayes[0][read0];
            read0++;
        }
        else {
            arr[write] = arrOfArrayes[1][read1];
            read1++;
        }
        write++;
    }

 
    while (read0 < arrOfArrayes[0].getSize()) {
        arr[write] = arrOfArrayes[0][read0];
        write++;
        read0++;
    }

   
    while (read1 < arrOfArrayes[1].getSize()) {
		arr[write] = arrOfArrayes[1][read1];
		write++;
		read1++;
    }
}
