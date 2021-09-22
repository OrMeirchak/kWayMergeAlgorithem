#pragma once
#include "myArray.h"
class arrayOfArrayes {
private:
	myArray* arrOfArrayes;
	int size;

public:
	arrayOfArrayes(myArray &arr, int k);

	myArray& operator[](int index) {
		if ((index < 0) || (index >= size)) {
			throw outOfIndexExeption();
		}
		else {
			return arrOfArrayes[index];
		}
	}

	const myArray& operator[](int index) const {
		if ((index < 0) || (index >= size)) {
			throw outOfIndexExeption();
		}
		else {
			return arrOfArrayes[index];
		}
	}

	int getSize();

	//for debbuging
	friend ostream& operator<<(ostream& os, const arrayOfArrayes& arr){
		for (int i = 0; i < arr.size; i++) {
			os <<endl<< "arr: "<< i+1 <<endl<< arr[i] << endl;
		}
		return os;
	}
	//
};
