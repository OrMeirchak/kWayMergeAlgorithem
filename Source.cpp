#include "Header.h"

bool number(char ch) {
	if ((ch < '0') || (ch > '9')) {
		return false;
	}
	else {
		return true;
	}
}

int charToInt(char ch) {
	if (!number(ch)) {
		throw wrongInputException();
	}
	else {
		return ch - '0';
	}
}

long int stringToLongInt(char* str) {
	bool neg = false;
	int p = 0;
	int res = 0;

	if (str[p] == '-') {
		neg = true;
		p++;
	}
	while (str[p] != '\0') {
		res *= 10;
		res += charToInt(str[p]);
		p++;
	}
	if (neg) {
		res *= -1;
	}
	return res;
}

int getFloor(float num)
{
	int res = num;

	if (res > num) {
		res--;
	}
	return res;
}

int getCeiling(float num) {
	int res = num;
	if (res < num) {
		res++;
	}
	return res;
}