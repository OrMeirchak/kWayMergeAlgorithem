#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class wrongInputException : public exception {
private:
	const string MESSAGE = "wrong input";
public:
	const string what() {
		return MESSAGE;
	}
};

bool number(char ch);

int charToInt(char ch);

long int stringToLongInt(char* str);

int getFloor(float num);

int getCeiling(float num);