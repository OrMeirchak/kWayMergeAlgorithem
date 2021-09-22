#include "arrayOfArrayes.h"

arrayOfArrayes::arrayOfArrayes(myArray& _arr, int k):size(k) {
	arrOfArrayes = new myArray[k];

	int n = _arr.getSize();

	float newSize = (float)n / (float)k;

	int floor = getFloor(newSize);

	int ceiling = getCeiling(newSize);

	int NumberOfFloorSizeArrayes = ceiling * k - n;

	int NumberOfCeilingSizeArrayes = k - NumberOfFloorSizeArrayes;

	int arrayOfArrayesIndex=0;
	int arrayIndex = 0;


	for (int i = 0; i < NumberOfFloorSizeArrayes; i++, arrayIndex+=floor, arrayOfArrayesIndex++)	{

		arrOfArrayes[arrayOfArrayesIndex] = _arr.cut(arrayIndex, arrayIndex + floor - 1);
	}

	for (int i = 0; i < NumberOfCeilingSizeArrayes; i++, arrayIndex += ceiling, arrayOfArrayesIndex++) {

		arrOfArrayes[arrayOfArrayesIndex] = _arr.cut(arrayIndex, arrayIndex + ceiling - 1);
	}


}

int arrayOfArrayes::getSize()
{
	return size;
}
