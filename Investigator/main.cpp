#include <iostream>
#include <filesystem>
#include <fstream>
#include "functions.h"
/* Notes:
* C++ 17 +


*/
using namespace std;
using namespace std::filesystem;
void rscan2(path const& f);
int howManyLines(path const& f);
int main() {
	path currentPath = "."; // Path object knows the right kind of string
	path canonicalpath = canonical(currentPath).string(); // path of current directory
	path parentPath = current_path().parent_path(); // Give me path to parent folder 
	
	if (!(exists(parentPath)))
		cout << "NOT OK  - file doesnt exists" << endl;
	
	path testpath = "C:/Users/Andre/source/repos/Investigator/Investigator/PathTester";
	path testpath2 = "C:/Users/Andre/source";
	cout << howManyLines(testpath2);

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
