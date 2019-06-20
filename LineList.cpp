#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include "LineList.h"

/**
*Default Constructor to initialise head and tail
*/
LineList::LineList() {
	theSize = 0;
	const char* headstring{ "HeadNode" };
	const char* tailstring{ "TailNode" };
	const Line headNode{ Line{headstring} };
	const Line tailNode{ Line{tailstring} };
	head = new Node{ headNode, nullptr, nullptr };
	tail = new Node{ tailNode, nullptr, nullptr };
	head->next = tail;
	tail->prev = head;
}

/**
*Destructor to free memory
*/
LineList::~LineList() {
	while (!empty()) {
		pop_front();
	}
	delete head;
	delete tail;
	head = nullptr;
	tail = nullptr;
}

/**
*Copy Constructor
*@param rhs LineList object
*/
LineList::LineList(const LineList& rhs) {
	theSize = 0;
	const char* headstring{ "HeadNode" };
	const char* tailstring{ "TailNode" };
	const Line headNode{ Line{ headstring } };
	const Line tailNode{ Line{ tailstring } };
	head = new Node{ headNode, nullptr, nullptr };
	tail = new Node{ tailNode, nullptr, nullptr };
	head->next = tail;
	tail->prev = head;
	Node* temp{ rhs.head };
	while (temp->next = rhs.tail) {
		temp = temp->next;
		Line Temp = Line(temp->data);
		push_back(Temp);
		temp = temp->next;
	}
}

/**
*Assignment operator overload
*@param rhs LineList object
@return Line List
*/
const LineList& LineList::operator=(const LineList& rhs) {
	theSize = rhs.theSize;
	if (this == &rhs)
		return *this;
	while (!empty()) {
		pop_front();
	}
	Node* temp{ rhs.head };
	while (temp->next = rhs.tail) {
		temp = temp->next;
		Line Temp{ Line(temp->data) };
		push_back(Temp);
		temp = temp->next;
	}
	return *this;
}

/**
*function to push coming line object to front of Line List
*@param line Line object
*/
void LineList::push_front(const Line& line) {
	Node* temp{ new Node{ line,head,head->next } };
	head->next->prev = temp;
	head->next = temp;
	theSize++;
}

/**
*function to push line object at the end of Line List
*@param line Line object
*/
void LineList::push_back(const Line& line) {
	Node* temp{ new Node{ line,tail->prev,tail } };
	tail->prev->next = temp;
	tail->prev = temp;
	theSize++;
}

/**
*function to pop Line object from the front of Line List
*/
void LineList::pop_front() {
	if (empty() == true) {
		return;
	}
	Node* temp{ head->next->next };
	delete head->next;
	head->next = temp;
	temp->prev = head;
	theSize--;
}

/**
*function to pop Line object from the end of Line List
*/
void LineList::pop_back() {
	if (empty() == true) {
		return;
	}
	Node* temp{ tail->prev->prev };
	delete tail->prev;
	tail->prev = temp;
	temp->next = tail;
	theSize--;
}

/**
*This function return the size of Line List:Number of line in list
*@return theSize of Line-List
*/
int LineList::size() const {
	return theSize;
}

/**
*This function tests LineList is empty or not
*@return true(1) if Line List is empty otherwise false(0)
*/
bool LineList::empty() const {
	if (theSize == 0) {
		return true;
	}
	return false;
}

/**
*This function inserts Line in Line-list at position k
*@param line Line class object
*@param k position where user want to insert line
*/
void LineList::insert(const Line& line, int k) {
	if (k > theSize || k <= 0) {
		return;
	}
	int position{ 1 };
	Node* nodeAtPositionK{ head };
	while (nodeAtPositionK->next != tail) {
		nodeAtPositionK = nodeAtPositionK->next;
		if (position == k) {
			break;
		}
		position++;
	}
	Node* nodeToInsert{ new Node{ line,nodeAtPositionK->prev,nodeAtPositionK->prev->next } };
	nodeAtPositionK->prev->next = nodeToInsert;
	nodeAtPositionK->prev = nodeToInsert;
	theSize++;
}

/**
*functtion to remove the line at position k of Line-List
*@param k Line position which user want to remove from Line-List
*/
void LineList::remove(int k) {
	if (k > theSize || k <= 0) {
		return;
	}
	int position{ 1 };
	Node* nodeAtPositionK{ head };
	while (nodeAtPositionK->next != tail) {
		nodeAtPositionK = nodeAtPositionK->next;
		if (position == k) {
			break;
		}

		position++;
	}
	nodeAtPositionK->prev->next = nodeAtPositionK->next;
	nodeAtPositionK->next->prev = nodeAtPositionK->prev;
	delete nodeAtPositionK;
	nodeAtPositionK = nullptr;
	theSize--;
}

/**
*Function to get line at position k from Line-List
*@param k position Line which user want to get
*@return Line at position k
*/
Line LineList::get(int k) const {
	if (k > theSize || k <= 0) {
		return nullptr;
	}
	int position{ 1 };
	Node* nodeAtPositionK{ head };
	while (nodeAtPositionK->next != tail) {
		nodeAtPositionK = nodeAtPositionK->next;
		if (position == k) {
			break;
		}

		position++;
	}

	return nodeAtPositionK->data.cstr();
}

/**
*Constructor of Node class
*@param ln reference to Line object
*@prv pointer to previous node
*@nxt pointer to next node
*/
LineList::Node::Node(const Line& ln, Node* prv, Node* nxt) :data{ ln }, prev{ prv }, next{ nxt } {}

/**
*This function print Line-List
*/
void LineList::print() {
	cout << endl;
	cout << "********************************" << endl;
	int i{ 1 };
	Node* temp{ head };
	while (temp->next != tail) {
		temp = temp->next;
		cout << "(" << i << ")" << temp->data.cstr() << endl;
		i++;
	}
	cout << "********************************" << endl;
}

