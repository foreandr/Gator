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
void lookopen(path const& f);
int main() {
	path currentPath = "."; // Path object knows the right kind of string
	path canonicalpath = canonical(currentPath).string(); // path of current directory
	path parentPath = current_path().parent_path(); // Give me path to parent folder 
	
	if (!(exists(parentPath)))
		cout << "NOT OK  - file doesnt exists" << endl;
	
	path testpath = "C:/Users/Andre/source/repos/Investigator/Investigator/PathTester";
	lookopen(testpath);

}
void rscan2(path const& f) {
	cout << "\n\n Folder = " << absolute(f) << endl;
	// Use dot operation instead, also ranged for
	for (auto d : recursive_directory_iterator(f)) {
		cout << d.path().string() << (is_directory(d.status()) ? " [dir]" : "") <<
			" ext= " << d.path().extension().string() << endl;
	}
}
void lookopen(path const& f) {
	int count = 0;
	string myfilestring;
	ifstream myfile;
	for (auto d : recursive_directory_iterator(f)) {
		myfilestring = d.path().string(); 
		//cout << myfilestring << endl; // print out current file name FULL path
		
		myfile.open(myfilestring); 
		std::cout << myfile.rdbuf() << tab << count << endl;
		myfile.close();
		count += 1;
	}

	
}
