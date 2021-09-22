#include "myArray.h"
myArray::myArray(ifstream& f, int _size) :myArray(_size){
	load(f);
}

myArray::myArray(int _size):size(_size),p(0) {
	if (size) {
		arr = new long int[size];
	}
	else {
		arr = nullptr;
	}
}

myArray::myArray(const myArray& other) :size(other.size),p(other.p){
	if (size) {
		arr = new long int[size];
		memcpy(arr, other.arr, sizeof(long int) * size);
	}
	else {
		arr = nullptr;
	}
}

myArray::~myArray() {
	if (arr) {
		delete[]arr;
	}
}

void myArray::operator=(const myArray& other)
{
	if (this != &other) {
		size = other.size;
		p = other.p;

		if (arr) { delete[] arr; }

		arr = new long int[size];
		memcpy(arr, other.arr , sizeof(long int) * size);
	}
}

bool myArray::operator==(const myArray& other) const
{
	return ((size == other.size) && (arr == other.arr));
}

void myArray::load(ifstream& f) {

	char* line = new char[11];
	int num;
	int logSize=0;

	while (!f.eof()) {
		f.getline(line,11);
			
		arr[logSize] = stringToLongInt(line);
		
		logSize++;
		if (logSize > size) {
			throw wrongInputException();
		}
	}

	if (logSize < size) {
		throw wrongInputException();
	}
}

void myArray::save(ofstream& f) {

	for (int i = 0; i < size; i++) {
		f << arr[i] << endl;
	}
}

myArray myArray::cut(int begin, int end) {
	myArray res(end - begin + 1);

	memcpy(res.arr, arr + begin, sizeof(long int) * res.size);

	return res;

}

int& myArray::P() {
	return p;
}

int myArray::getSize()
{
	return size;
}

void myArray::swap(int& index1, int& index2){
	
	long int temp= arr[index1];
arr[index1] = arr[index2];
arr[index2] = temp;

	int indexTemp = index1;
	index1 = index2;
	index2 = indexTemp;
}
