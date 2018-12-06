/*
    Suppose you are given a line tof text as a plaintext , find out the corresponding Caesar Cipher(i.e. character three to the right modulo 
    26). Then perform the reverse operation to get original plaintext
*/

#include <iostream>
#include <string>
using namespace std;


string PlaintextToCipher(string text)
{
    for(int i = 0; i < text.size(); i++)
    {
        //cout<<"In loop"<<endl;
        
        if ((text [i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z')) 
        {
             //cout<<"In If"<<endl;

            if (text [i] >= 'A' && text[i] <= 'Z') 
            {
                //cout<<(int) text[i]<<" text "<<text[i]<<endl;

                int code = ((int) text[i] + 3);

                //cout<<code<<" code "<<(char)code<<endl;

                code = code - (int) 'A';

                
                if ((code - 26) >= 0) 
                {
                    code = code - 26;    
                }
                
                code = code + (int) 'A';

                text[i] = (char) code;
            }

            
            if (text[i] >= 'a' && text[i] <= 'z') 
            {
                int code = (int) text[i] + 3;

                code = code - (int) 'a';

                
                if ((code - 26) >= 0) 
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
    for(int i = 0;i < encrypt.size(); i++)
    {
        if ((encrypt [i] >= 'A' && encrypt[i] <= 'Z') || (encrypt[i] >= 'a' && encrypt[i] <= 'z')) 
        {
            
            if (encrypt [i] >= 'A' && encrypt[i] <= 'Z') 
            {
                int code = (int) encrypt[i] - 3;

                code = code - (int) 'A';

                
                if (code < 0) 
                {
                    code = code + 26;    
                }
                
                code = code + (int) 'A';

                encrypt[i] = (char) code;
            }

            
            if (encrypt[i] >= 'a' && encrypt[i] <= 'z') 
            {
                int code = (int) encrypt[i] - 3;

                code = code - (int) 'a';

                
                if (code < 0) 
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
