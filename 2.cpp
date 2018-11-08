/**
 * 
*/

#include <iostream>
#include <string>
using namespace std;

string PlainTextToCipther(string text)
{
    for(int i = 0; i < text.size(); i++)
    {
        for(int j=i; j < i+2 ; j++)
        {

        }

        i = i+2;
    }
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