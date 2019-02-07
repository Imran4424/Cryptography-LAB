#include <iostream>
#include <string>
#include <map>
#include <fstream>
using namespace std;

string PlaintextToCipher(string text)
{
	map <string, string> encryptDictionary;

	ifstream readFile;

	readFile.open("dictionary.txt");

	if (readFile.is_open())
	{
		

		readFile.close();
	}
	else
	{
		cout << "can not open the file" << endl;
	}
}


int main(int argc, char const *argv[])
{
	string text;

	getline(cin, text);

	cout << "......................" <<endl;

	cout << "Plain Text: "<< text << endl << endl;

	string encrypt = PlaintextToCipher(text);

	cout <<"Cipher: " << encrypt << endl << endl;

	string decrypt = CipherToPlaintext(encrypt);

	cout << "Plain Text: "<< decrypt << endl;


	return 0;
}