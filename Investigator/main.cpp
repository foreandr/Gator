#include <iostream>
#include <filesystem>
#include <fstream>
#include "functions.h"
#include <deque>
#include <windows.h>   // WinApi header
/* Notes:
* C++ 17 +
* When using automatic command arguments, cannot put in wrong file
*/
using namespace std;
using namespace std::filesystem;

void searchFileFor(path const& f, string wantedString);
void rscan2(path const& f);
int howManyLines(path const& f);
void printLines(vector<path> paths);
void run(vector<path> paths);
int howManyLetter(path const& f, char ascii);
// Command line arguments
int main(int argc, char* argv[]) {
	printIntroText();
	vector<path> testpaths;
	
	//cout << argv[1]; // Look for path file
	
	path path;
	while (true) {	
		//cin >> path; // PUT BACK
		path = argv[1];
		if (exists(path)){
			cout << "All OK  - file exists" << endl;
			break;
		}
		else {

			cout << "Invalid Input or file Doesn't exist\n";
			printIntroText();
		}
	}
	testpaths.push_back(path);
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
int howManyLetter(path const& f, char asciiEntered) {
	int count = 0;
	string myfilestring;
	ifstream myfile;

	int numchar = 0;

	for (auto d : recursive_directory_iterator(f)) {
		myfilestring = d.path().string();
		ifstream myfile(myfilestring);
		string currentString;
		char c;
		while (myfile.get(c)) {
			if (c == asciiEntered) {
				numchar++;
			}
		}
		myfile.close();
	}
	return numchar;
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
	//int helpAnswer = help(); // Switch back after
	int helpAnswer = 3;
	if (helpAnswer == 1) {
		printLines(paths);
		run(paths);
	}
	else if (helpAnswer == 2) {
		char wantedChar;
		cout << "Wanted Ascii Chracter:\n";
		cin >> wantedChar;
		for (auto value : paths) {
			cout << "\nDirectory: " << value << " has [";
			int value1 = howManyLetter(value, wantedChar);
			printf("\x1B[92m%d\033[0m", value1);
			cout << "] instances of of [";
			printf("\x1B[92m%c\033[0m", wantedChar);
			cout << "]" << endl;
		}
		run(paths);
	}
	else if (helpAnswer == 3) {
		cout << "You picked 3\n";
		// looking for a particular text string related to connection
		for (auto value : paths) { 
			searchFileFor(value, "not connected"); // Change input to be like 2 after
		}
		

		//run(paths);
	}
	else if (helpAnswer == 0) {
		std::cout << "Thanks for using Gator\n";
		exit(1);
	}
}
void searchFileFor(path const& files, string wantedString) {
	
	ifstream inFile;
	string currentString;

	vector<string> vecOfWantedSearch;
	int lineNumber = 0;
	bool foundNothing = true;

	for (auto file : recursive_directory_iterator(files)) {
		lineNumber = 0; // Reset after each new file
		inFile.open(file);
		while (inFile >> currentString) {
			lineNumber++;
			if (currentString.find(wantedString) != string::npos) {
				cout << file << " " << wantedString << " " << lineNumber << '\n';
				foundNothing = false;
			}
			//cout << file << " " <<  currentString << endl;
		}
		inFile.close();
	}
	if (foundNothing == true) {
		cout << "We were not able to find: " << wantedString << "";
		printf("\x1B[92m%s\033[0m", wantedString);
	}
	//cout << "Wanted String: " << wantedString;
}
