////
// Name: Jeff Calderon
// Section: CS132 33616
// Class Name: JCString
// Program Name: JCString Class Implementation
// 
// Description: Constructor takes no args or entire char array
// Member functions use comparisons between ASCII Values 
// in the letters of the words in the JCString internal array
// to sort, compare words and return weather arg word is 
// greater or smaller. 
////

#include "JCStringV2.h"
#include <iostream>



// Static Variables 
int JCString::currentCount = 0;
int JCString::createdCount = 0;


// initialzer with basic values
// creates a char array with 20 memory
JCString::JCString() 
{
	this->cap = 7; //size of memory
	this->end = 0;//index of the end of the string
	this->str = new char[cap]; // reserves memomory for 7 chars
	this->charInitialize(this->cap);
	this->str[end] = '\0'; // terminates the char array at 0

	//keeping track of objects	
	this->str_num = createdCount;
	++currentCount;
	++createdCount;

	cout << "created a JCStrin with cap of " << cap << endl;
	cout << " created " << currentCount << " JCstrings " << endl;
	cout << " created ID " << this->str_num << endl;
}

// Destructor
JCString::~JCString() 
{
	if (this->str != nullptr)
	{
	
		cout << "deleted this string " << this->str << endl;
		cout << "ID " << this->str_num << endl;

		//keeping track of objects	
		--currentCount;
		if (currentCount < 0) { cout << "less than zero current"; }
		// Be free memory
		delete[] this->str;
		this->str = nullptr;
	}
	else {
		cout << "double delete \n";
	}
}

// constructor for dumping arrays
JCString::JCString(const char* cstr) 
{	
	//while loop counts chars and stores int 
	for (this->end = 0; cstr[this->end] != '\0'; ++this->end);
		
	if (this->cap+1 > this->end) 	//increases the cap
	{

		delete[] this->str;
		this->cap = this->end + 7;
		
		
	}

	std::cout << "dump array cap " << this->cap << " word: " << cstr << endl;
	
	this->str = new char[this->cap]; // creates char arr a holding array
	this->charInitialize(this->cap);

	// fills a char array stores in the variable
	for (int i = 0; i < this->end; ++i) {
		this->str[i] = cstr[i];
	}
	this->str[end] != '\0';

	//keeping track of objects	
	this->str_num = createdCount;
	++createdCount;
	++currentCount;

}
// Copy constructor another JCString
JCString::JCString(const JCString& jcstr) 
{
	this->cap = 7;
	this->end = 0;
	//index of the end of the string
	std::cout << "copy constructor cap " << this->cap << " word: ";

	for (int i = 0; i < jcstr.length(); i++)
	{
		cout << jcstr[i];
	}
	std::cout << endl;

	for (this->end = 0; jcstr.str[this->end] != '\0'; ++this->end) 
	{
	}

	if (this->end+1 > cap) 	//increases the cap
	{
		std::cout << jcstr.str << " is big\n";
		std::cout << " the cap is " << this->cap << endl;
		this->cap = this->end + 7;
		std::cout << "now the cap is " << this->cap << endl;
		std::cout << "end is " << this->end << endl;
		
	}
	this->str = new char[this->cap];
	this->charInitialize(this->cap);

	for (int i = 0; jcstr[i] != '\0'; i++)
	{
		this->str[i] = jcstr[i];
	}
	this->str[end] != '\0';
	this->str_num = createdCount;
	++createdCount;
	++currentCount;
}
void JCString::charInitialize( const int capSize)
{
	//initializing all values with null. 
	for (int i = 0; i < capSize; ++i)
	{
		this->str[i] = '\0';
	}
		//this makes sure we always have a null at the end
		// avoids accessing un allocated memory one hopes
		// adds the terminate char last char
	this->str[end] != '\0';
	
	
}

int JCString::length() const 
{
	return this->end;
}

int JCString::capacity() const 
{
	return this->cap;
}

//returns individual letter at index argument
char JCString::operator[](int& index) const 
{
	
	if (index >= 0 && index < this->end) {
		return this->str[index];
	}
	else {
		return '\0';				
	}
}

// reads in the word with the extractor operator ">>"
istream& JCString::operator>>(istream& inputStrm) 
{
	char inputWord[ 100 ];
	if (inputStrm >> inputWord) {  
		for (this->end = 0; inputWord[this->end] != '\0'; ++(this->end));//Loop counts letters finds end
		this->cap = this->end + 20;						
		
		for (int i = 0; i <= this->end; ++i) 
		{
			this->str[i] = inputWord[i];
		}
	}
	return inputStrm;
}

//write out char string to stream with insertion
ostream& JCString::operator<<(ostream& outputStrm)  
{

	outputStrm << this->str;
	return outputStrm;
}

bool JCString::operator<(const JCString& argStr) const 
{
	if (this->JCScompareTo(argStr) == -1)
	{
		return true;
	}
		
	return false;			
}

//defined in terms of the string compare function
bool JCString::operator>(const JCString& argStr) const 
{
	if (this->JCScompareTo(argStr) == 1)
	{
		return true;
	}
		
	return false;			
}

//defined in terms of the string compare function
bool JCString::operator==(const JCString& argStr) const 
{
	if (this->JCScompareTo(argStr) == 0)
	{
		return true;
	}
	return false;			
}

// defined in terms of the == operator
bool JCString::operator!=(const JCString& argStr) const 
{
	return !(this->operator==(argStr));
}


// compares char for char, returns 1 if this-> string is larger ascii value than argument jcstring
// returns -1 if this-> string is lesser ascii value
// returns 0 if this-> string is same ascii value
int JCString::JCScompareTo(const JCString& angStr) const
{
	
		int len = 0;
		int count = 0;
		int result = 0;

		// dummie char stirngs
		JCString thisString(this->str);

		// lower case logic for when we implement that later
		// uncomment when ready
		// TODO: write a method which makes this->str lowercase
		//JCString str2 = angStr.returnLower();
		//str1.makeLower();

		JCString str2(angStr.str);
		// make sure we iter through to the shortest char string
		if (thisString.length() < str2.length())
		{
			len = thisString.length();
		}
		else
		{
			len = str2.length();
		}
		// compares char for char, returns 1 if this-> string is larger

		while (count < len)
		{
			if(thisString.str[count] > str2.str[count])
			{
				//str1 is greater or comes later return 1
				result = 1;
				count = len; // effectivly breaks

			}
			else if (thisString.str[count] < str2.str[count])
			{
				result = -1;
				count = len; // effectivly breaks
			}
			//then they must be the same char , if one is terminated here it comes first (is smaller)
			// if the char arr is shorter than the other but equal otherwise
			// the shorter one wins by defult
			else if (thisString.str[count+1] == '\0')
			{
				result = -1;	//compare string is larger 
				count = len;
				
			}
			else if (str2.str[count+1] == '\0')
			{
				result = 1;		//this string is larger, compare string comes first 
				count = len;
			}	

			count++;
		}
		return result;//return 0 if equal
}

JCString& JCString::operator=(const JCString& strToCopy) 
{
	std::cout << "= operator cap " << this->cap << " word: " << strToCopy.str << endl;
	if(this != &strToCopy)
	{ 
		delete[] this->str;
		this->end = strToCopy.end;
		this->cap = this->end + 7;
		this->str = new char[this->cap];
		this->charInitialize(this->cap);

		for (int i = 0; i < end; ++i) 
		{
			this->str[i] = strToCopy.str[i];
		}
	}
	return *this;
}

const char* JCString::c_str() {
	return this->str;
}

//  modifies the JCString such that it is all lower case
void JCString::makeLower()
{
	for (int i = 0; i <= this->end; i++)
	{
		if (this->str[i] < 91 || this->str[i] > 64)
		{
			this->str[i] += 32;
		}
	}
}
// returns an new instance of the JCString that is lower case
JCString JCString::returnLower() const
{
	JCString returnString(this->str);
	returnString.makeLower();
	return returnString;
}
// Static functions
int JCString::getCurrentCount() 
{
	return currentCount;
}
int JCString::getCreatedCount() 
{
	return createdCount;
}
