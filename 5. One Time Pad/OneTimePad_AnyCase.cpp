/*
    You are supplied a file of large non-repeating set of truly random key letter. Your job is to encrypt the plaintext using 
    ONE TIME PAD technique. Then perform the reverse operation to get the original plaintext
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string PlaintextToCipher(string text)
{
    ifstream read_key;
    string key;

    read_key.open("key.txt");

    if(read_key.is_open())
    {
        string line;

        while(read_key)
        {
            getline(read_key, line);
        }

        key = line;

        read_key.close();
    }

    int i,j;

    for(i = 0, j=0; i < text.size() && j < key.size(); i++, j++)
    {
        
        if ((text [i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z')) 
        {

            if (text [i] >= 'A' && text[i] <= 'Z') 
            {

                int code = (int) (text[i] + key[j]);

                code = code - (int) 'A';

                
                while ((code - 26) >= 0) 
                {
                    code = code - 26;    
                }
                
                code = code + (int) 'A';

                text[i] = (char) code;
            }

            
            if (text[i] >= 'a' && text[i] <= 'z') 
            {
                int code = (int) (text[i] + key[j]);

                code = code - (int) 'a';

                
                while ((code - 26) >= 0) 
                {
                    code = code - 26;    
                }
                
                code = code + (int) 'a';

                text[i] = (char) code;
            }
            
        }
        
    }

    return text;
}


string CipherToPlaintext(string encrypt)
{
    ifstream read_key;
    string key;

    read_key.open("key.txt");

    if(read_key.is_open())
    {
        string line;

        while(read_key)
        {
            getline(read_key, line);
        }

        key = line;

        read_key.close();
    }

    int i,j;

    for(i = 0, j=0; i < encrypt.size() && j < key.size(); i++, j++)
    {
        if ((encrypt [i] >= 'A' && encrypt[i] <= 'Z') || (encrypt[i] >= 'a' && encrypt[i] <= 'z')) 
        {
            
            if (encrypt [i] >= 'A' && encrypt[i] <= 'Z') 
            {
                int code = (int) (encrypt[i] - key[j]);

                code = code - (int) 'A';

                
                while (code < 0) 
                {
                    code = code + 26;    
                }
                
                code = code + (int) 'A';

                encrypt[i] = (char) code;
            }

            
            if (encrypt[i] >= 'a' && encrypt[i] <= 'z') 
            {
                int code = (int) (encrypt[i] - key[j]);

                code = code - (int) 'a';

                
                while (code < 0) 
                {
                    code = code + 26;    
                }
                
                code = code + (int) 'a';

                encrypt[i] = (char) code;
            }
        }
    }

    return encrypt;
}


int main(int argc, char const *argv[])
{
    string text;

    getline(cin, text);

    cout<<"......................"<<endl;

    cout<<"Plain Text: "<<text<<endl<<endl;

    string encrypt = PlaintextToCipher(text);

    cout<<"Cipher: "<<encrypt<<endl<<endl;

    string decrypt = CipherToPlaintext(encrypt);

    cout<<"Plain Text: "<<decrypt<<endl;

    return 0;
}
