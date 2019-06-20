#include<iostream>
#include<cstring>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;
#include "Line.h"


/**
*Constructor to assign value to linePtr
*@param text pointor to incoming line
*/
Line::Line(const char* text) {
	if (!(text == nullptr)) {
		lineLength = strlen(text);
		lineCapacity = lineLength;
		int temp{ lineLength };
		temp = temp + 1;
		linePtr = new char[temp];
		strcpy(linePtr, text);
		linePtr[lineLength] = '\0';
	}
	else {
		return;
	}
}

/**
*Copy constructor
*@param text reference to a line
*/
Line::Line(const Line& text) {
	lineLength = text.length();
	lineCapacity = lineLength;
	int temp{ lineLength };
	temp = temp + 1;
	linePtr = new char[temp];
	strcpy(linePtr, text.cstr());
	linePtr[lineLength] = '\0';
}

/**
*Assignment operator
*@param rhs reference to line object
*@return pointer to the line
*/
const Line& Line::operator=(const Line& rhs) {
	if (this == &rhs) {
		return *this;
	}
	delete[] linePtr;
	lineLength = rhs.lineLength;
	lineCapacity = lineLength;
	int temp{ lineLength };
	temp = temp + 1;
	linePtr = new char[temp];
	strcpy(linePtr, rhs.cstr());
	return *this;
}

/**
*Destructor to clean memory
*/
Line:: ~Line() {
	delete[] linePtr;
	linePtr = nullptr;
}

/**
*Function to get line text from line object
*@return line text
*/
const char* Line::cstr() const {
	return this->linePtr;
}

/**
*function to give length of line
*@return length of line
*/
int Line::length() const {
	return lineLength;
}

/**
*Function to check line is empty or not
*@return true(1) and false(0) on the basis of empty or not
*/
bool Line::empty() const {
	if (linePtr[0] == '\0' || strlen(linePtr) == 0 || linePtr == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

/**
*Function to test line is full or not
*@return true(1) and false(0)
*/
bool Line::full() const {
	if (lineLength == lineCapacity) {
		return true;
	}
	else {
		return false;
	}
}

/**
*function to give capacity of line for number of character
*@return capacity of line
*/
int Line::capacity() const {
	return lineCapacity;
}

/**
*function to resize line capacity when line is full
*/
void Line::resize() {
	int temp{ lineCapacity };
	temp = temp * 2;
	lineCapacity = temp;
	char* tempstring{ new char[lineLength + 1] };
	strcpy(tempstring, linePtr);
	delete[] linePtr;
	linePtr = nullptr;
	linePtr = new char[lineCapacity + 1];
	strcpy(linePtr, tempstring);
	delete[] tempstring;
	tempstring = nullptr;

}

/**
*This function pushes or ammend the character to last of the line
*/
void Line::push_back(const char& ch) {
	if (full() == true) {
		resize();
	}
	linePtr[lineLength] = ch;
	linePtr[lineLength + 1] = '\0';
	lineLength = lineLength + 1;

}

/**
*This function will remove the character
*/
void Line::pop_back() {
	if (empty() == true) {
		return;
	}
	else {
		linePtr[lineLength - 1] = '\0';
		lineLength = lineLength - 1;
	}
}

/**
*Stream insertion operation overload
*@param out reference of ostream object
*@param line reference of line object
*@param reference to ostream object
*/
ostream& operator<<(ostream& out, const Line& line) {
	out << line.cstr();
	return out;
}

/**
*Stream extraction operator overload
*@param in reference to istream object
*@param line reference of line object
*@return reference to ostream object
*/
istream& operator>>(istream& in, Line& line) {
	in >> line.linePtr;
	return in;
}