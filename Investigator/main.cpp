#include <iostream>
#include <filesystem>
#include <fstream>
#include "functions.h"
#include <deque>
/* Notes:
* C++ 17 +


*/
using namespace std;
using namespace std::filesystem;
void rscan2(path const& f);
int howManyLines(path const& f);

// Command line arguments
int main(int argc, char* argv[]) {
	int argCount = argc;
	deque <string> args(argv + 1, argv + argc);
	if (args.empty())
	{
		cout << "Error: No commandline arguments detected - showing help" << endl;
		// Show help = true
	}
	else {
		// cout << "Commandline arguments detected" << endl;
	}
	vector<path> testpaths;
	
	for (auto &value : args) {
		//cout << value << endl;
		testpaths.push_back(value);
	}
	testpaths.push_back("C:/Users/Andre/source/repos/Investigator/Investigator/PathTester");
	testpaths.push_back("C:/Users/Andre/source");

	for (auto &value : testpaths) {
		cout << howManyLines(value) << endl;
	}




}
void rscan2(path const& f) {
	cout << "\n\n Folder = " << absolute(f) << endl;
	// Use dot operation instead, also ranged for
	for (auto d : recursive_directory_iterator(f)) {
		cout << d.path().string() << (is_directory(d.status()) ? " [dir]" : "") <<
			" ext= " << d.path().extension().string() << endl;
	}
}
int howManyLines(path const& f) {
	int count = 0;
	string myfilestring;
	ifstream myfile;
	
	int numLines = 0;

	for (auto d : recursive_directory_iterator(f)) {
		myfilestring = d.path().string(); 
		//cout << myfilestring << endl; // print out current file name FULL path
		

		// OG
		ifstream myfile(myfilestring);
		
		string currentString;
		while (getline(myfile, currentString)) {
			// Output the text from the file
			numLines += 1;
			//cout << currentString;
		}
		
		//currentString = myfile.rdbuf();
		//std::cout << myfile.rdbuf() << tab << count << endl;
		myfile.close();
		count += 1;
	}
	return numLines;
}
