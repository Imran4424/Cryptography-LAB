#include <iostream>
#include <string>
using namespace std;

typedef long long int lli;

int gcd(int a, int b) 
{ 
    int temp; 

    while (1) 
    { 
        temp = a % b; 
        if (temp == 0)
        {	
          return b; 
        } 
        a = b; 
        b = temp; 
    } 
} 


lli temp[200];

string PlaintextToCipher(string text, lli eKey, lli n)
{
	lli i = 0;

	string encrypt;

	while(i != text.length())
	{
		lli ascii = (int)text[i];

		ascii = ascii - 96;

		lli k = 1;

		for(lli j = 0; j < eKey; j++)
		{
			k = k * ascii;
			k = k % n;
		} 

		temp[i] = k;

		ascii = k + 96;

		encrypt += (char) ascii;

		i++;
	}

	return encrypt;
}

string CipherToPlaintext(string encrypt, lli dKey, lli n)
{
	lli i = 0;

	string decrypt;

	while(i != encrypt.length())
	{
		lli ascii = temp[i];

		lli k = 1;

		for(int j = 0; j < dKey; j++)
		{
			k = k * ascii;
			k = k % n;
		}

		ascii = k + 96;

		decrypt += (char) ascii;

		i++;
	}

	return decrypt;
}


int main(int argc, char const *argv[])
{
	lli p = 53, q = 59;

	lli n = p*q;

	lli phiN = (p-1)*(q-1);

	// encryption key;

	lli eKey = 2;

	while(eKey < phiN)
	{
		if( gcd(eKey, phiN) == 1)
		{
			break;
		}
		else
		{
			eKey++;
		}
	}

	// decryption key

	int k = 2;
	lli dKey = (1 + (k*phiN)) / eKey;

	string text = "Encrypt the plaintext message using RSA algorithm. Then perform the reverse operation to get original plaintext.";

	cout << "......................" <<endl;

	cout << "Plain Text: "<< text << endl << endl;

	string encrypt = PlaintextToCipher(text, eKey, n);

	cout <<"Cipher: " << encrypt << endl << endl;

	string decrypt = CipherToPlaintext(encrypt, dKey, n);

	cout << "Plain Text: "<< decrypt << endl;

	return 0;
}