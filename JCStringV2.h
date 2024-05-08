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
	JCString(int size = DEFAULT_CAP);						 // default constructor
	JCString(const char* cstr);		 // cstring constructor for dumping array

	JCString(const JCString &jcstr); // Copy constructor another JCString

	~JCString(); // Destructor

	int length() const;
	int capacity() const;
	const char* c_str();

	//STATIC ACCESSORS
	static int getCurrentCount();
	static int getCreatedCount();

	// OPERATORS 
	JCString operator+(const JCString& rhsJCString); //adds another JCString object	
	JCString operator+(const char* rhsChars);		//adds more chars, adds char array
	JCString& operator=(const char* strToCopy);//copy assignment for string 
	JCString& operator=(const JCString& strToCopy); // Copy assignment JCSstinrg operator
	char operator[](const int index) const;					// Index operator 
	//istream& operator>>(istream& inputStrm, JCString& jcstr);
	friend istream& operator>>(istream& inputStrm, JCString& jcstr);// read in
	friend ostream& operator<<(ostream& inputStrm, const JCString& jcstr);		 // Write out using extractor

	// COMPARITOR FUNCTIONS FOR USE WITH LIKE OBJECTS
	bool operator<(const JCString& rhsJCString) const;	 // Less than operator
	bool operator>(const JCString& rhsJCString) const;	 // Greater than operator
	bool operator==(const JCString& rhsJCString) const;	 // Equal to than operator
	bool operator!=(const JCString& rhsJCString) const;	 // Not equal to than operator


	// MUTATOR FUNCTIONS
	void makeLower(); // The JCString becomes all lowercase 
	JCString& operator+=(const JCString& rhsJCString); //appends another JCString object	

	JCString returnLower() const; // returns a JCString copy in lowercase
private:
	char* str; // the array it is based off called str;
	int end; // the index of the last char
	int cap; // the max memory to use
	int JCScompareTo(const JCString& angStr) const;
	void charInitialize(const int capSize);
	void jcStrInitialize(const int capSize, const int end, const char* inString = nullptr);

	long int str_num;//string's id num

	// STATIC VARIABLES
	static const int DEFAULT_CAP = 7; // Default size of the array
	// STATIC FUNCTIONS
	static char* appendCstr(const  char* str1, const char* str2); // Appends two cstrings
	static int currentCount;
	static int createdCount;
	

};

#endif


