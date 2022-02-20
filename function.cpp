#include <iostream>
#include <fstream>
#include <string>
#include "function.h"
using namespace std;
string nameOfFile()
{
	string fileName;
	cout << "enter name of the file:";
	cin >> fileName;
	return fileName;
}
void input(string name)
{
	string line;
	char simb;
	ofstream fileout;
	cout << "If you like to append your input, enter q. Otherwise enter w:";
	cin >> simb;
	if (simb == 'q')
		fileout.open(name, ios::app);
	if (simb == 'w')
		fileout.open(name);
	while (simb != 'w' && simb != 'q')
	{
		cout << "Enter correct letter:";
		cin >> simb;
	}
	cout << endl;
	cout << "Enter your text:\n End the line | press --> ENTER\n End the input | press --> Ctrl + X\n";
	cin.ignore();
	while (1) {
		string line;
		getline(cin, line, '\n');
		if (char(line[0]) == 24)
			break;
		fileout << line << endl;
	}
	fileout.close();

}

void changeFile(string name, string newname)
{
	string newtext;
	ifstream filein(name);
	char ch;
	if (!filein.is_open())
	{
		cout << "Can't open the file!\n";

	}
	else
	{
		while (filein.get(ch))
		{
			if (ch != '1' and ch != '0')
				newtext += ch;
			if (ch == '1')
				newtext += '0';
			if (ch == '0')
				newtext += '1';
		}
	}
	ofstream fileout(newname);
	fileout << newtext;
	filein.close();
	fileout.close();
}
void output(string name)
{
	ifstream file(name);
	string line;
	while (!file.eof())
	{
		getline(file, line);
		cout << line << endl;
	}
	file.close();
	cout << endl;
}