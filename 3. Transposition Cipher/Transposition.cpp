#include <iostream>
#include <string>
using namespace std;

string TextToCipher(string text, int width)
{
	string encrypt;

	int col = 0;
	
	int i = col;

	while( col < width )
	{
		encrypt += text[i];

		i += width

		if (i >= text.length())
		{
			i = ++col;
		}
	}

	return encrypt;
}


string CipherToText(string encrypt, int width)
{
	string dercypt;

	int row = 0;

	for(int i = 0, int j = row; i < encrypt.length(); i++)
	{
		dercypt[j] = encrypt[i];

		j += width;

		if (j >= encrypt.length())
		{
			j = ++row;
		}
	}
}


int main(int argc, char const *argv[])
{
	//string text = "DEPARTMENT OF COMPUTER SCIENCE AND TECHNOLOGY UNIVERSITY OF RAJSHAHI BANGLADESH";

	string text = "BANGLADESH IS BEAUTIFUL";

	cout<<"Plain text: "<< text << endl;

	string encrypt = TextToCipher(text, 5);

	cout<<"Encrypted text: "<< encrypt << endl;

	string dercypt = CipherToText(encrypt, 5);

	cout<< "Decypted text: "<< dercypt <<endl;

	return 0;
}