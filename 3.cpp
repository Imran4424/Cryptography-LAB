#include <iostream>
#include <string>
using namespace std;

string TextToCipher(string text)
{
    for(int i = 0; i < text.size(); i++)
    {
        int previous_position = i;

        while(text[i] != ' ')
        {
            i++;
        }

        int space_position = i;

        for(int j = previous_position; j < space_position; j++)
        {
            for(int k = space_position - 1; k >= previous_position; k--)
            {
                char temp = text[j];
                text[j] = text[k];
                tex[k] = temp;
            }
        }

    }

    return text;
}

main(int argc, char const *argv[])
{
    string text = "DEPARTMENT OF COMPUTER SCIENCE AND TECHNOLOGY UNIVERSITY OF RAJSHAHI BANGLADESH";

    cout<<"Plain text: "<< text << endl;

    string encrypt = TextToCipher(text);

    cout<<"Encrypted text: "<< encrypt << endl;
    
    return 0;
}
