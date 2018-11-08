/**
 * 
*/

#include <iostream>
#include <string>
using namespace std;

string PlainTextToCipther(string text)
{
    for(int i = 0; i < text.size(); i = i+3)
    {
        for(int j = i; j < i+3 ; j++)
        {
            /**
             * if there is single character left
            */
            if(j+1 >= text.size())
            {
                if ((text[j] >= 'A' && text[j] <= 'Z') || (text[j] >= 'a' && text[j] <= 'z'))
                {

                    if (text[j] >= 'A' && text[j] <= 'Z')
                    {

                        int code = (int)text[j] + 5;

                        code = code - (int)'A';

                        if ((code - 26) >= 0)
                        {
                            code = code - 26;
                        }

                        code = code + (int)'A';

                        text[j] = (char)code;
                    }

                    if (text[j] >= 'a' && text[j] <= 'z')
                    {
                        int code = (int)text[j] + 5;

                        code = code - (int)'a';

                        if ((code - 26) >= 0)
                        {
                            code = code - 26;
                        }

                        code = code + (int)'a';

                        text[j] = (char)code;
                    }
                }
            }

            /**
             * if there is two character left
            */
           
            if()

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