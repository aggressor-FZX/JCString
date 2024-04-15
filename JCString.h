////
// Name: Jeff Calderon
// Section: 
// Class Name: JCString
//
// Description: HEADER FILE Just the Declerations and stuff
//  class do (not how it does it: for example, it uses loops)?  Blah
//  blah blah blah blah, blah blah blah blah blah blah blah blah!
////

#ifndef MYSTRING_H
#define MYSTRING_H

#include <istream>

using namespace std;

class JCString {     
public:
	JCString();						// default constructor
	JCString(const char* cstr);		// cstring constructor for dumping array

	int length();
	int capacity();

	char at(int index);
	bool read(istream& inputStrm);
	void write(ostream& outputStrm);

	bool lessThan(const JCString& argStr);
	bool greaterThan(const JCString& argStr);
	bool equals(const JCString& argStr);
	
	void setEqualTo(const JCString& argStr);
	const char* c_str();

	JCString returnLower() const;
	void makeLower();

private:
	char* str; // the array it is based off called str;
	int end; // the index of the last char
	int cap; // the max memory to use
	int JCScompareTo(const JCString& angStr);
};

#endif

