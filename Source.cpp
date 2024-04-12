/**
if arg1 < arg2 returns a negative number
if arg1 > arg2 returns a positive number
if arg1 == arg2 returns zero
*/

////
// Name: Nancy Programmer
// Section: A, B, or S
// Program Name: MYString Tester
//
// Description: A brief description of the program.  What does the
//  program do (not how it does it: for example, it uses loops)?  Does
//  the program get input?  What kind?  What information is output
//  from the program and to where (screen or file)
////

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "JCString.h"
#include <iostream>

using namespace std;
vector<JCString> vectorSort(const vector<JCString>& wordVec);

int main()
{ // This is a vector of Jeff Strings we need to implement
	vector<JCString> words(100);        // calls default constructor 100 times
	ifstream fin("infile2.txt");

	// READ
	if (fin.fail()) {
		cout << "Couldn't open infile2.txt" << endl;
		system("pause");
		exit(1);
	}

	int wordCnt = 0;
	for (wordCnt; words[wordCnt].read(fin); ++wordCnt) {       // empty loop
		//cout << words[wordCnt].c_str() << '\t';      // for verifying input
	}
	words.resize(wordCnt);            //shrink vector to size used

	// SORT
	vector<JCString> sortedVec = vectorSort(words);
	for (JCString str : sortedVec)
	{
		ofstream outfile("outfile1.txt");
		if (!outfile)
		{
			cout << "Error Opening File" << endl;
			return 1;
		}
		str.write(outfile);
	}
	
	
	


}
	
vector<JCString> vectorSort(const vector<JCString> &wordVec)
{
	bool notDone = false;
	int i = 0;
	vector<JCString> sortedVec = wordVec;

	do {
		notDone = false;
		for (i = 0; i < sortedVec.size() - 1; i++)
		{
			//greater means it comes later in the alphabet to sort things
			// we put greater ones futher up futher in the vector
			if ( sortedVec.at(i + 1).lessThan(sortedVec.at(i)) ) 
			{
				JCString holder = sortedVec.at(i);
				sortedVec[i] = sortedVec[i + 1];
				sortedVec[i + 1] = holder;
				notDone = true;
			}
		}

	} while (notDone);

	return sortedVec;
}
		


		// OUTPUT to the outfile.txt

