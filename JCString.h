////
// Name: Jeff Calderon
// Class Name: CS131
// Section:  33616
// Program JCString V2
// Description: HEADER FILE  Declerations 
// Shows memeber functions of the JCString class 
// Shows user how to use constructors and methods
// 
////

#ifndef JCSTRING_H
#define JCSTRING_H

#include <istream>

using namespace std;

class JCString 
{     
public:
	JCString();						// default constructor
	JCString(const char* cstr);		// cstring constructor for dumping array
	//Copy constructor another JCString
	JCString(const JCString &mstr);
	// Destructor
	~JCString();

	int length();
	int capacity();

	char at(int index);
	bool read(istream& inputStrm);
	void write(ostream& outputStrm);

	// Comparitor functions for use with like objects
	bool lessThan(const JCString& argStr);
	bool greaterThan(const JCString& argStr);
	bool equals(const JCString& argStr);

	void setEqualTo(const JCString& argStr);
	char* c_str() const;

	JCString returnLower() const; // returns a JCString copy in lowercase
	void makeLower(); // The JCString becomes all lowercase 

	

private:
	char* str; // the array it is based off called str;
	int end; // the index of the last char
	int cap; // the max memory to use
	int JCScompareTo(const JCString& angStr);
};

#endif

