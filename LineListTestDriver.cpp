#include<iostream>
#include<iomanip>
#include<fstream>
#include<cassert>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::string;

#include "Line.h"
#include "LineList.h"

/**
*Function Prototypes
*/
bool operator== (const LineList&, const LineList&);
bool operator!= (const LineList&, const LineList&);
bool operator== (const Line&, const Line&);
bool operator!= (const Line&, const Line&);
void load_linked_list(const char*, LineList&);
void test_linked_list_operations(LineList&);
void test_line_operations(Line&);

/**
*Main class which drives whole program
*/
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//to check memory leak
	const char* filename_a{ "input_a.txt" };
	const char* filename_b{ "input_b.txt" };

	LineList list_a{};
	load_linked_list(filename_a, list_a);      // load our first list list_a
	cout << "list_a loaded" << "\n";
	list_a.print();                           // print list_a

	test_linked_list_operations(list_a);      // manipulate lines in list_a
	cout << "\n" << "list_a rearranged" << "\n";
	list_a.print();                           // print manipulated list_a

	LineList list_b{};
	load_linked_list(filename_b, list_b);     // load our second list list_b
	cout << "list_b loaded" << "\n";
	list_b.print();
	assert(list_a == list_b);                 // test operator=
	cout << "assert(list_a == list_b) is successfull" << endl;
	cout << "\n**End of line list operation:**" << endl;
	cout << "********************************" << endl;

	Line line{ list_a.get(1) };					//get of line at first position of list_a
	test_line_operations(line);
	cout << "Done!" << endl;
	return 0;                                // report success
}

/**
*Loads the supplied line_list  with the lines of a given text file.
@param filename The name of the given text file.
@param line_list The LineList object to load.
*/
void load_linked_list(const char* filename, LineList& line_list)
{
	std::ifstream ifs(filename, std::ifstream::in);
	if (!ifs.is_open())
	{
		cout << "Unable to open file" << filename << endl;
		exit(0);
	}

	int lineno = 0;
	std::string line;
	while (getline(ifs, line)) // Read until end of file
	{
		++lineno;
		//cout << "(" << lineno << ") " << line << endl;
		const char* c_line = line.c_str(); // const makes this a safe idea.
		// Get a pointer to the c-string represented by the C++ string object
		// ONLY because Line's Ctor in the call below expects a char *
		line_list.push_back(Line(c_line));
		/*if (ifs.eof()) {
			break;
		}*/
	}
}

/**
*Tests oprations provided by a given LineList object.
*@param line_list The LineList object to use throughout the test.
*/
void test_linked_list_operations(LineList& line_list)
{

	if (line_list.empty()) return;								// test empty()
	cout << "**Operations on line_list a:**" << endl;
	int lastPos{ line_list.size() };								// size
	line_list.remove(lastPos);									// remove
	cout << "\nRemove last element of list_a:" << endl;
	line_list.print();
	if (line_list.empty()) return;								// empty

	line_list.remove(1);											// remove
	cout << "Remove 1 element from list:" << endl;
	line_list.print();
	if (line_list.empty()) return;								// empty

	Line lastline{ line_list.get(line_list.size()) };				// get, copy ctor
	line_list.pop_back();										// pop_back
	cout << "After performing pop_back " << endl;
	line_list.print();
	if (line_list.empty()) return;								// empty

	Line line1{ line_list.get(1) };								// get
	cout << "Line at position 1:" << line1.cstr() << endl;
	line_list.pop_front();										// pop_front()
	cout << "\nAfter pop_front from list:" << endl;
	line_list.print();
	if (line_list.empty()) return;								// empty

	line1 = line_list.get(1);									// get, operator=
	cout << "Line at position 1:" << line1.cstr() << endl;
	line_list.pop_front();										// pop_front();
	cout << "\nAfter pop_front from list:" << endl;
	line_list.print();
	line_list.push_front(lastline);								// push_front
	cout << "After push_front to list:" << endl;
	line_list.print();
	line_list.push_back(line1);								    // push_back
	cout << "After push_back to list:" << endl;
	line_list.print();
	cout << "After inserting on 3rd position:" << endl;
	if (line_list.size() >= 3)									// size
		line_list.insert(Line("Line  3"), 3);						// insert
	line_list.print();

	line_list.insert(Line("Welcome to C++"), 1);					 // insert
	cout << "After inserting on first position:" << endl;
	line_list.print();
	cout << "After push_back in the Line List:" << endl;
	line_list.push_back(Line("Have fun!"));						// push_back
	line_list.print();
}

/**
*Tests oprations provided by a given Line object.
@param line The Line object to use throughout the test.
*/
void test_line_operations(Line& line) {
	cout << "**Starting of Line operation**" << endl;
	cout << "\nOriginal Line:";
	cout << line.cstr() << endl;									//test cstr()
	if (line.empty())return;
	cout << "----------------------------" << endl;

	line.pop_back();											//test pop_back()
	cout << "After pop_back:";
	cout << line.cstr() << endl;
	if (line.empty())return;
	cout << "----------------------------" << endl;

	line.push_back('t');										//test push_back()
	cout << "After push_back:";
	cout << line.cstr() << endl;
	cout << "----------------------------" << endl;

	cout << "Line Length:" << line.length() << endl;            //test length()
	cout << "Line Capacity:" << line.capacity() << endl;		//test capacity()
	cout << "Is Line full(1 means true,0 means false):" << line.full() << endl;
	cout << "----------------------------" << endl;

	line.push_back('t');
	cout << "After push_back:";
	cout << line.cstr() << endl;
	cout << "----------------------------" << endl;

	cout << "Line Length:" << line.length() << endl;
	cout << "Line Capacity:" << line.capacity() << endl;
	cout << "Is Line full(1 means true,0 means false):" << line.full() << endl;
	cout << "\n**End of line operation and program**" << endl;
}

/**
*An overload for operator==. Considers two lists equal
*if they each have the same number of lines and same lines.
@param list1 The left hand side operand.
@param list2 The right hand side operand.
@return true or false based on comparision.
*/
bool operator== (const LineList& list1, const LineList& list2)
{
	if (list1.size() != list2.size()) return false;
	for (size_t i{ 1 }; i != list1.size(); ++i)
	{
		if (list1.get(i) != list2.get(i)) return false;
	}
	return true;
}

/**
*An oveload for operator!=. Considers two lines unequal
*if they are not equal.
@param line1 The left hand side operand.
@param line2 The right hand side operand.
@return true or false based on comparision.
*/
bool operator!=(const Line& line1, const Line& line2) {
	return!(line1 == line2);
}

/**
*An oveload for operator!=. Considers two lists unequal
*if they are not equal.
@param list1 The left hand side operand.
@param list2 The right hand side operand.
@return true or false based on comparision.
*/
bool operator!= (const LineList& list1, const LineList& list2)
{
	return !(list1 == list2);
}

/**
*An overload for operator==. Considers two line equal
*if they each have the same number of character and same characters.
@param line1 The left hand side operand.
@param line2 The right hand side operand.
@return true or false based on comparision.
*/
bool operator==(const Line& line1, const Line& line2) {
	if (line1.length() != line2.length()) return false;
	int result = strcmp(line1.cstr(), line2.cstr());
	if (result > 0) {
		return false;
	}
	else if (result < 0) {
		return false;
	}
	else {
		return true;
	}
}