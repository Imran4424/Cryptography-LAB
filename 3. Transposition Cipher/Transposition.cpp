#include <iostream>
#include <string>
using namespace std;

string TextToCipher(string text, int width)
{
	string encrypt;

	int col = 1;

	


}


string CipherToText(string encrypt)
{

}


int main(int argc, char const *argv[])
{
	//string text = "DEPARTMENT OF COMPUTER SCIENCE AND TECHNOLOGY UNIVERSITY OF RAJSHAHI BANGLADESH";

	string text = "BANGLADESH IS BEAUTIFUL";

	cout<<"Plain text: "<< text << endl;

	string encrypt = TextToCipher(text, 5);

	cout<<"Encrypted text: "<< encrypt << endl;

	string dercypt = CipherToText(encrypt);

	cout<< "Decypted text: "<< dercypt <<endl;

	return 0;
}