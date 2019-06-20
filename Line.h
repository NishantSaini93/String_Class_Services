/**
*The purpose of program are as following:
*To understand the use of pointers and references.
*Practice Array.
*Dynamic memory allocation and deallocation.
*Input file processing.
*Writing classes.
*/
#ifndef _Line_INCLUDED
#define _Line_INCLUDED

/**
*This class models a line of text,storing it in dynamically created array of characters.
*And provide simple operation on line.
*/
class Line {
private:
	char* linePtr{ nullptr };
	int lineLength{ 0 };
	int lineCapacity{ 0 };
public:
	Line() = default;
	Line(const char* text);
	Line(const Line&);
	const Line& operator=(const Line& rhs);
	virtual ~Line();
	const char* cstr() const;
	int length() const;
	bool empty() const;
	bool full() const;
	int capacity() const;
	void resize();
	void push_back(const char& ch);
	void pop_back();
	friend std::ostream& operator<<(std::ostream& out, const Line& line);
	friend std::istream& operator>>(std::istream& in, Line& line);

};
#endif