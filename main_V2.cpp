////
// Name: Jeff Calderon
// Class: CS132 
// Section: 33616 
// Program JCString V2
//
// Description: This is a class that turns char arrays into a string class
// called JCString. This programs reads in a file and creates JCStrings
// from the text in the file. The JCStrings are stored in vector. 
// A method of the JCString class is called  which compares itself
// to other objects of the same class. This is used to alphabatize the 
// vector of JCStrings. Then this is outputted to a file
// NOTE: as of now Capitials Leter will always come before lower case
// as ASCII numbers are used to compare
////

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "JCStringV2.h"
#include <iostream>
using namespace std;

// GLOBAL VARIABLES
const char INPUT_FILE[] = "infile3.txt";
const char OUTPUT_FILE[] = "outfile5.txt";
const int WORD_LENGTH = 5;
const int WORDS_PER_LINE = 1;


// Function prototypes 
vector<JCString> vectorSort(const vector<JCString>& wordVec);
void saveToFIle(const vector<JCString>& wordVec, const char* fileName, int wordPerLin);

void jcprint(JCString& jcstr);
void printJCstrVector(const vector<JCString>& wordvec);

int main()
{ 
	vector<JCString> words;
	ifstream fileInput(INPUT_FILE);			

	// READ FILE
	if (fileInput.fail()) {
		cout << "ERROR READING FILE";
		exit(1);
	}

	// Loop reads in each words into JCString object iters thru jcstring vector

	int wordCnt = 0;
	JCString fileString;// single jcstring to read in file data
	JCString pushString; //jcstring  to collect concatinated string
	
	do {
		//if mult of 5 and jcstring has stuff
		if (wordCnt % WORD_LENGTH == 0 && pushString.c_str()[0] != '\0') 
		{
			//then push into vector
			words.push_back(pushString);
			pushString = "";
		}
		fileInput >> fileString;
		pushString += fileString;
		cout << "pushString: " << pushString << endl;
		cout << "fileString: " << fileString << endl;
		
		if (fileInput.eof())
		{
			words.push_back(pushString);
		}
		++wordCnt;
	} while (!fileInput.eof());
	vector<JCString> sortedVec = vectorSort(words);
	
	// SAVE TO FILE	
	saveToFIle(sortedVec, OUTPUT_FILE, WORDS_PER_LINE);
	cout << wordCnt << endl;
	
	return 0;

}

// A bubble sort variant uses JCString comparison method "lessThan"	
vector<JCString> vectorSort(const vector<JCString> &wordVec)
{
	cout << "in SORT \n";
	bool notDone;
	int i = 0;
	
	vector<JCString> sortedVec = wordVec;

	do {
		notDone = false;
		for (i = 0; i < sortedVec.size()-1; i++) // up to the second to last elem 
		{

			//if the next one is less than it moves to the current one
			//current one becomes the next
			if (sortedVec.at(i) > sortedVec.at(i + 1))// i+1, will automaticaly check the last elem
			{	
				//swap the values
				JCString holder = sortedVec.at(i); //hold the current one
				sortedVec.at(i) = sortedVec.at(i + 1);
				jcprint(holder);
				cout << endl;
				sortedVec.at(i + 1) = holder;// make current i the i + 1

				notDone = true; 
			}
		}

	} while (notDone);

	return sortedVec;
}
void printJCstrVector(const vector<JCString>& wordvec)
{
	for (JCString str : wordvec)
	{
		jcprint(str);
	}
}
void jcprint( JCString &jcstr)
{
	for(int i = 0; i < jcstr.length(); ++i)
	{
		cout << jcstr[i];
	}
}

//saves a JCString vector to a file
void saveToFIle(const vector<JCString> &wordVec, const char* fileName, int wordPerLin)
{
	ofstream outfile(fileName, ios::out); 
	if (!outfile)
	{
		cout << "ERROR READING FILE" << endl;
	}

	int line = 0;

	for (const JCString str : wordVec)
	{
		// left aligning and spaced 
		outfile << left << setw(13) << str << " " << str.length() << ":" << str.capacity();
		
		line++;

		// words per line before carriage return 
		if (line % wordPerLin == 0)
		{
			outfile << endl;
		}
	}

	outfile.close();

}


