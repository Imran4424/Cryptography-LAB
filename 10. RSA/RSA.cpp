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

	string encrypt = PlaintextToCipher(text, eKey);

	cout <<"Cipher: " << encrypt << endl << endl;

	string decrypt = CipherToPlaintext(encrypt, dKey);

	cout << "Plain Text: "<< decrypt << endl;

	return 0;
}