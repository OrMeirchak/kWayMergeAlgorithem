#define CRT_SECURE_NO_WARNINGS
#include "kWayMergeAlgorithem.h"


int main(void) {
	int size;
	int k;
	string inFileName;
	string outFileName;


	cin >> size;
	cin >> k;
	cin >> inFileName;
	cin >> outFileName;



	ifstream inFile(inFileName);

	if (!inFile) {
		cout << "wrong input" << endl;
}

	ofstream outFile(outFileName);

	if (!outFile) {
		cout << "wrong input" << endl;
	}


	try {
		myArray arr(inFile, size);

		kWayMergeAlgorithem sort;

       sort(arr, k);

	   arr.save(outFile);
	}
	catch (wrongInputException& e) {
	cout << e.what();
}
	inFile.close();
	outFile.close();
}