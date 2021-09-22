#pragma once
#include <cstring>
#include "Header.h"
using namespace std;

class outOfIndexExeption :public exception {};

class myArray {
private:
	long int* arr;
	int size;
	int p;

public:
	myArray(ifstream& f, int _size);
	myArray(int _size=0);
	myArray(const myArray&);
	~myArray();

	void load(ifstream& f);
	void save(ofstream& f);

	void operator=(const myArray& other);

	bool operator==(const myArray& other) const;

	myArray cut(int begin, int end);

	void swap(int& index1, int& index2);

	int& P();

	int getSize();

	long int& operator[](int index) {
		if ((index < 0) || (index >= size)) {
			throw outOfIndexExeption();
		}
		else {
			return arr[index];
		}
	}

	const long int& operator[](int index) const {
		if ((index < 0) || (index >= size)) {
			throw outOfIndexExeption();
		}
		else {
			return arr[index];
		}
	}


	//for debbuging
	friend ostream& operator<<(ostream& os, const myArray& arr)
	{

		for (int i = 0; i < arr.size; i++){
			os << '['<< i << ']' << arr[i] << endl;
		}

		return os;
	}
	//
};
