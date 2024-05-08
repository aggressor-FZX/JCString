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
// creates a char array with 7 memory
JCString::JCString(int size) 
{
	jcStrInitialize(size, 0);//initialize new memory, size is cap and zero end index

	//keeping track of objects	
	++currentCount;
	++createdCount;

	this->str_num = createdCount;
}

// Destructor
JCString::~JCString() 
{
	if (currentCount < 0) 
	{
		cout << "less than zero current"; 
	}

	if (this->str != nullptr)
	{
	
		cout << "deleted this string " << this->str << endl;
		cout << "ID " << this->str_num << endl;

		// Be free memory
		delete[] this->str;
		this->str = nullptr;

		//keeping track of objects	
		--currentCount;
	}
	else {
		cout << "double delete \n";
	}
}

// constructor for dumping arrays
JCString::JCString(const char* cstr)
{
	//while loop counts chars and stores int
	int numChars = 0;
	for (numChars; cstr[numChars] != '\0'; ++numChars);

	this->jcStrInitialize(numChars+2, numChars, cstr); // reserves memomory for chars

	//keeping track of objects	
	++createdCount;
	++currentCount;
	this->str_num = createdCount;
}
// Copy constructor another JCString
JCString::JCString(const JCString& jcstr) 
{
	//constructor passes to jcstr init, whic handles the allocating  memory
	this->jcStrInitialize(jcstr.cap, jcstr.end, jcstr.str); // reserves memomory 

	//keeping track of objects
	++currentCount;
	++createdCount;

	this->str_num = createdCount;

}
// Initializing all values with null. 
void JCString::charInitialize( const int capSize)
{
	for (int i = 0; i < capSize; ++i)
	{
		this->str[i] = '\0';
	}
	// This makes sure we always have a null at the end
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
char JCString::operator[](const int index) const 
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

		*this = inputWord; // Let copy assignment operator handle the resize 
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

JCString JCString::operator+(const JCString& rhsJCString)
{
	cout << " adding JCString operator called \n";

	// Temp jcstring gets deleted after assignment operator copies to left hand side var
	JCString comboString = appendCstr(this->str, rhsJCString.str);// Calls char dump constructor

	return comboString;

}

JCString JCString::operator+(const char* rhsChars)
{   
	cout << " adding char* operator called\n";

	// Temp jcstring gets deleted after assignment operator copies to left hand side var
	JCString comboString = appendCstr(this->str, rhsChars);// concatinates then Calls char dump constructor

	return comboString;

}
// Assignment to C_string
JCString& JCString::operator=(const char* strToCopy)
{
	if (this->str != strToCopy)
	{
		if (this->str != nullptr)
		{ 
			// if initialized clear old stuff
			delete[] this->str;
		}

		// count chars in string to copy
		int numChars = 0;
		for (numChars; strToCopy[numChars] != '\0'; ++numChars);

		//assemble internal char array
		jcStrInitialize(numChars+2, numChars, strToCopy);

	}

	return *this;
}
// Assignment to JCSting 
JCString& JCString::operator=(const JCString& strToCopy) 
{
	if(this != &strToCopy)
	{ 
		if (this->str != nullptr)
		{ 
			// if initialized clear old stuff
			delete[] this->str;
		}

		//assemble internal char array
		jcStrInitialize(strToCopy.cap, strToCopy.end, strToCopy.str);

	}

	return *this;
}
// Assembles internal char array
// Cap size must be known in advance
// Old stuff deleted before calling jcString init
void JCString::jcStrInitialize(const int capSize, const int end, const char* inString/* =nullptr' */)
{
	this->end = end;
	this->cap = capSize;
	this->str = new char[this->cap];

	//initializing all values with null.
	this->charInitialize(this->cap); //this makes sure we always have a null at the end
	
	if(inString != nullptr)
	{ 
		//for loop checks that we don't go over the cap
		for (int i = 0; i < this->cap && inString[i] != '\0'; ++i)
		{
			this->str[i] = inString[i];
		}
	}

}

//TO DO: JCString& operator+=(const char* rhC_str) const;	  
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

// STATIC FUNCTIONS
char* JCString::appendCstr(const char* str1, const char* str2)
{	
	int count1 = 0;
	int count2 = 0;
	//count elements
	for (count1; str1[count1] != '\0'; ++count1);
	for (count2; str2[count2] != '\0'; ++count2);

	char* outChar = new char[count1 + count2 + 1] ;// space for null terminal
	//fill new char []
	for (int i = 0; str1[i] != '\0'; ++i)
	{
		outChar[i] = str1[i];
	}
	for (int i = 0; str2[i] != '\0'; ++i)
	{
		outChar[count1 + i] = str2[i];
	}
	outChar[count1 + count2] = '\0';//terminate with null

	return outChar;
}

int JCString::getCurrentCount() 
{
	return currentCount;
}
int JCString::getCreatedCount() 
{
	return createdCount;
}
