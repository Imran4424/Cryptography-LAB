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
        for(int j = i; j < i+3 ; j++)
        {
            /**
             * if there is single character left 5
            */
            if(j+1 >= text.size())
            {
                text[j] = EncryptCharacter(text[j],5);

                j = j+3;
                continue;
            }

            /**
             * if there is two character left 7 11
            */

            if(j+2 >= text.size())
            {
                text[j] = EncryptCharacter(text[j], 7);

                text[j+1] = EncryptCharacter(text[j+1], 11);

                j = j+3;
                continue;
            }

            /**
             * increasing order 2 11 3
            */

            if((text[j] <= text[j+1]) && (text[j+1] <= text[j+2]))
            {
                text[j] = EncryptCharacter(text[j], 2);

                text[j+1] = EncryptCharacter(text[j+1], 11);
                
                text[j+2] = EncryptCharacter(text[j+2], 3);
            }

        }// j loop
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