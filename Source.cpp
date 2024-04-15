////
// Name: Jeff Calderon
// Class: CS132 
// Section: 33616 
// Program Name: JCString 
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
#include "JCString.h"
#include <iostream>

using namespace std;
// GLOBAL VARIABLES
char INPUT_FILE[] = "infile2.txt";
char OUTPUT_FILE[] = "outfile3.txt";

// Function prototypes 
vector<JCString> vectorSort(const vector<JCString>& wordVec);
void saveToFIle(const vector<JCString>& wordVec, char* fileName, int wordPerLin);

int main()
{ 
	vector<JCString> words(100);        // calls default constructor 100 times
	ifstream fin(INPUT_FILE);

	// READ
	if (fin.fail()) {
		system("pause");
		exit(1);
	}

	int wordCnt = 0;
	for (wordCnt; words[wordCnt].read(fin); ++wordCnt) {       // empty loop
	}

	words.resize(wordCnt);            //shrink vector to size used
	fin.close();
	
	// SORT
	vector<JCString> sortedVec = vectorSort(words);

	// SAVE TO FILE	
	int wordsPerLine = 6;
	saveToFIle(sortedVec, OUTPUT_FILE, wordsPerLine);
	
	return 0;

}
	
vector<JCString> vectorSort(const vector<JCString> &wordVec)
{
	bool notDone;
	int i = 0;
	vector<JCString> sortedVec = wordVec;

	do {
		notDone = false;
		for (i = 0; i < sortedVec.size()-1; i++) // up to the second to last elem 
		{



			//if the next one is less than it comes backwards
			if (!sortedVec.at(i).lessThan(sortedVec.at(i+1)))// will automaticaly check the last elem
			{
				JCString holder = sortedVec.at(i);
				sortedVec.at(i) = sortedVec.at(i + 1);
				sortedVec.at(i + 1) = holder;
				notDone = true; 
			}
		}

	} while (notDone);

	return sortedVec;
}

//saves a JCString vector to a file
void saveToFIle(const vector<JCString> &wordVec, char* fileName, int wordPerLin)
{
	ofstream outfile(fileName, ios::out); 
	if (!outfile)
	{
		cout << "ERROR READING FILE!!" << endl;
	}

	int line = 0;

	// left aligning and spacing
	outfile << left;
	outfile << setw(13);

	//writing out
	for (JCString str : wordVec)
	{
		str.write(outfile);
		line++;
		if (line % wordPerLin == 0)// 6 words per line
		{
			outfile << endl;
		}

	}

	outfile.close();

}


