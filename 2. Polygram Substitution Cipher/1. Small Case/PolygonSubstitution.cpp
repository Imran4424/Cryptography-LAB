#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <algorithm>
using namespace std;

string PlaintextToCipher(string text)
{
	replace(text.begin(), text.end(), ' ', '_');

	map <string, string> encryptDictionary;

	ifstream readFile;

	string msg, cipher;

	readFile.open("dictionary.txt");

	if (readFile.is_open())
	{
		while(readFile >> msg >> cipher)
		{
			encryptDictionary[msg] = cipher;
		}

		readFile.close();
	}
	else
	{
		cout << "can not open the file" << endl;
	}

	string block;
	int startPos = 0;

	for(int i = 0; i < text.length(); i++)
	{
		block += text[i];

		if(block.length() == 3)
		{
			block = encryptDictionary[block];

			int x,y;

			for(x = startPos, y = 0; y < 3 ; y++, x++)
			{
				text[x] = block[y];
			}

			startPos = x;

			block.clear();
		}
	}

	return text;
}

string CipherToPlaintext(string encrypt)
{


	map <string, string> decryptDictionary;

	ifstream readFile;

	string msg, cipher;

	readFile.open("dictionary.txt");

	if (readFile.is_open())
	{
		while(readFile >> msg >> cipher)
		{
			decryptDictionary[cipher] = msg;
		}

		readFile.close();
	}
	else
	{
		cout << "can not open the file" << endl;
	}

	string block;
	int startPos = 0;


	for(int i = 0; i < encrypt.length(); i++)
	{
		block += encrypt[i];

		if(block.length() == 3)
		{
			block = decryptDictionary[block];

			int x,y;

			for(x = startPos, y = 0; y < 3 ; y++, x++)
			{
				encrypt[x] = block[y];
			}

			startPos = x;

			block.clear();
		}
	}

	replace(encrypt.begin(), encrypt.end(), '_', ' ');
	
	return encrypt;
}


int main(int argc, char const *argv[])
{
	string text;

	//getline(cin, text);

	text = "i love to play games";

	cout << "......................" <<endl;

	cout << "Plain Text: "<< text << endl << endl;

	string encrypt = PlaintextToCipher(text);

	cout <<"Cipher: " << encrypt << endl << endl;

	string decrypt = CipherToPlaintext(encrypt);

	cout << "Plain Text: "<< decrypt << endl;


	return 0;
}