#include "function.h"

int main()
{
	string file = nameOfFile();
	input(file);
	cout << "Entered text:\n" << endl;
	output(file);
	string newfile = nameOfFile();
	changeFile(file, newfile);
	cout << "Changed file:\n" << endl;
	output(newfile);
	return 0;
}