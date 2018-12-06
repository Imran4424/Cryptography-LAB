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

    read_key.open("key.txt");
    


    for(int i = 0; i < text.size(); i++)
    {
        
        if ((text [i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z')) 
        {

            if (text [i] >= 'A' && text[i] <= 'Z') 
            {

                int code = ((int) text[i] + 3);

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


int main(int argc, char const *argv[])
{
    

    return 0;
}
