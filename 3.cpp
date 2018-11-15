#include <iostream>
#include <string>
using namespace std;

string TextToCipher(string text)
{
    for(int i = 0; i < text.size(); i++)
    {
        int previous_position = i;

        while(text[i] != ' ' && text[i] != '\0')
        {
            i++;
        }

        int space_position = i;

        cout << previous_position <<" "<< space_position<<endl;

        for(int j = previous_position; j < space_position; j++)
        {
            for(int k = space_position - 1; k >= previous_position; k--)
            {
                char temp = text[j];
                text[j] = text[k];
                text[k] = temp;
            }
        }
    }

    return text;
}

string CipherToText(string encrypt)
{
    for (int i = 0; i < encrypt.size(); i++)
    {
        int previous_position = i;

        while (encrypt[i] != ' ' && encrypt[i] != '\0')
        {
            i++;
        }

        int space_position = i;

        //cout << previous_position << " " << space_position << endl;

        for (int j = previous_position; j < space_position; j++)
        {
            for (int k = space_position - 1; k >= previous_position; k--)
            {
                char temp = encrypt[j];
                encrypt[j] = encrypt[k];
                encrypt[k] = temp;
            }
        }
    }

    return encrypt;
}

main(int argc, char const *argv[])
{
    //string text = "DEPARTMENT OF COMPUTER SCIENCE AND TECHNOLOGY UNIVERSITY OF RAJSHAHI BANGLADESH";

    string text = "BANGLADESH IS BEAUTIFUL";

    cout<<"Plain text: "<< text << endl;

    string encrypt = TextToCipher(text);

    cout<<"Encrypted text: "<< encrypt << endl;

    string dercypt = CipherToText(encrypt);

    cout<< "Decypted text: "<< dercypt <<endl;

    return 0;
}
