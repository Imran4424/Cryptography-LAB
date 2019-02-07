#include <iostream>
#include <string>
using namespace std;

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