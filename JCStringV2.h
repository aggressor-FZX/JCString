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

#ifndef JCSTRINGV2_H
#define JCSTRINGV2_H

#include <istream>

using namespace std;

class JCString 
{     
public:
	JCString();						// default constructor
	JCString(const char* cstr);		// cstring constructor for dumping array

	// Copy constructor another JCString
	JCString(const JCString &jcstr);

	// Destructor
	~JCString();

	int length();
	int capacity();

	//Static Accessors
	static int getCurrentCount();
	static int getCreatedCount();

	// Operators 
	JCString& operator=(const JCString& strToCopy); // Copy assignment operator
	//JCString& operator+(const JCString& strToCopy); // Appends another JCString 
	char operator[](int& index);					// Index operator 
	istream& operator>>(istream& inputStrm);		// Read in using extractor
	ostream& operator<<(ostream& inputStrm);		 // Write out using extractor

	// Comparitor functions for use with like objects
	bool operator<(const JCString& rhsJCString);	 // Less than operator
	bool operator>(const JCString& rhsJCString);	 // Greater than operator
	bool operator==(const JCString& rhsJCString);	 // Equal to than operator

	const char* c_str();

	JCString returnLower() const; // returns a JCString copy in lowercase
	void makeLower(); // The JCString becomes all lowercase 

private:
	char* str; // the array it is based off called str;
	int end; // the index of the last char
	int cap; // the max memory to use
	int JCScompareTo(const JCString& angStr);

	// Static 
	static int currentCount;
	static int createdCount;

};

#endif

