/**
*The purpose of program are as following:
*To understand the use of pointers and references.
*Practice Array.
*Dynamic memory allocation and deallocation.
*Input file processing.
*Writing classes.
*/
#ifndef _LineList_INCLUDED
#define _LineList_INCLUDED
#include "Line.h"
/**
*Class that implement the services for a List of Lines(Line-List) and operations on it.
*/
class LineList {
private:
	int theSize;
	/**
	*Class which facilitates the services to make node.
	*/
	class Node {
	public:
		Line data;
		Node* prev;
		Node* next;
		Node(const Line& ln, Node* prv, Node* nxt);
	};
private:
	Node* head;
	Node* tail;
public:
	LineList();
	virtual ~LineList();
	LineList(const LineList& rhs);
	const LineList& operator=(const LineList& rhs);
	void push_front(const Line& line);
	void push_back(const Line& line);
	void pop_front();
	void pop_back();
	int size() const;
	bool empty() const;
	void insert(const Line& line, int k);
	void remove(int k);
	Line get(int k) const;
	void print();
};
#endif