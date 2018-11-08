/**
 * 
*/

#include <iostream>
#include <string>
using namespace std;

char EncryptCharacter(char flag, int shift)
{
    if ((flag >= 'A' && flag <= 'Z') || (flag >= 'a' && flag <= 'z'))
    {

        if (flag >= 'A' && flag <= 'Z')
        {

            int code = (int)flag + shift;

            code = code - (int)'A';

            if ((code - 26) >= 0)
            {
                code = code - 26;
            }

            code = code + (int)'A';

            flag = (char)code;
        }

        if (flag >= 'a' && flag <= 'z')
        {
            int code = (int)flag + shift;

            code = code - (int)'a';

            if ((code - 26) >= 0)
            {
                code = code - 26;
            }

            code = code + (int)'a';

            flag = (char)code;
        }
    }

    return flag;
}


string PlainTextToCipther(string text)
{
    for(int i = 0; i < text.size(); i = i+3)
    {
    
        /**
         * if there is single character left 5
        */
        if(i+1 >= text.size())
        {
            text[i] = EncryptCharacter(text[i],5);

        }
        else if(i+2 >= text.size())
        {
            /**
             * if there is two character left 7 11
            */
            text[i] = EncryptCharacter(text[i], 7);

            text[i+1] = EncryptCharacter(text[i+1], 11);
        }
        else if((text[i] <= text[i+1]) && (text[i+1] <= text[i+2]))
        {
            /**
             * increasing order 2 11 3
            */
            text[i] = EncryptCharacter(text[i], 2);

            text[i+1] = EncryptCharacter(text[i+1], 11);
            
            text[i+2] = EncryptCharacter(text[i+2], 3);

        }
        else if ((text[i] >= text[i + 1]) && (text[i + 1] >= text[i + 2]))
        {
            /**
             * decreasing order 5 4 6 
            */
            text[i] = EncryptCharacter(text[i], 5);

            text[i + 1] = EncryptCharacter(text[i + 1], 4);

            text[i + 2] = EncryptCharacter(text[i + 2], 6);
        }
        else if ((text[i] > text[i + 1]) && (text[i + 1] < text[i + 2]))
        {
            /**
             * B S B  11 16 5 
            */
            text[i] = EncryptCharacter(text[i], 11);

            text[i + 1] = EncryptCharacter(text[i + 1], 16);

            text[i + 2] = EncryptCharacter(text[i + 2], 5);
        }
        else if ((text[i] < text[i + 1]) && (text[i + 1] > text[i + 2]))
        {
            /**
             * S B S  18 3 10 
            */
            text[i] = EncryptCharacter(text[i], 18);

            text[i + 1] = EncryptCharacter(text[i + 1], 3);

            text[i + 2] = EncryptCharacter(text[i + 2], 10);
        }

    }// i loop
}

string CiptherToPlainText(string encrypt)
{
    for (int i = 0; i < encrypt.size(); i = i+3)
    {
        for (int j = i; j < i + 3; j++)
        {

        }
    }
}

main(int argc, char const *argv[])
{
   string text;

   getline(cin,text); 

    return 0;
}