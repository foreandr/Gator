#include <iostream>
#include <filesystem>
#include <fstream>
#include "functions.h"
#include <deque>
#include <windows.h>   // WinApi header
/* Notes:
* C++ 17 +


*/
using namespace std;
using namespace std::filesystem;
void rscan2(path const& f);
int howManyLines(path const& f);
void printLines(vector<path> paths);
void run(vector<path> paths);
// Command line arguments
int main(int argc, char* argv[]) {
	std::cout << "Thanks for using Gator\n";
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
	};
	run(testpaths);


	




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
void printLines(vector<path> paths) {
	for (auto& value : paths) {
		cout << "Directory: " << value << " has [";
		int value1 = howManyLines(value);
		printf("\x1B[92m%d\033[0m", value1);
		cout << "] lines of code.\n" << endl;
	}
}
void run(vector<path> paths) {
	int helpAnswer = help();
	if (helpAnswer == 1) {
		printLines(paths);
		run(paths);
	}
	else if (helpAnswer == 2) {
		cout << "Chose 2";
		run(paths);
	}
	else if (helpAnswer == 0) {
		std::cout << "Thanks for using Gator\n";
		exit(1);
	}
}