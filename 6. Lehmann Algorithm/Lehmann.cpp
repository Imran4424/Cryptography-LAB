#include <iostream>
#include <string>
#include <fstream>
using namespace std;

typedef unsigned long long int ulli;

ulli my_pow(ulli base, ulli expo, ulli mod)
{
	ulli result = base;

	for(ulli i = 1; i <= expo; i++)
	{
		result = (result * base) % mod;
	}

	return result;
}

int main(int argc, char const *argv[])
{
	ulli num;
	cout << "enter the number which you want to be tasted" << endl;
	cin >> num;


	ulli times;
	cout << "How many times you want to repeat the number" << endl;
	cin >> times;


	for(ulli t = 1; t <= times; t++)
	{
		ulli randomNum = rand() % (num-1) + 1;

		ulli expo = (num-1) / 2 ;

		ulli result = my_pow(randomNum, expo, num);

		
		
		if ( result % num != 1 && result % num != (num - 1))
		{
			cout << num << " is definitely not prime " << endl;

			break;
		}
	
	}


	return 0;
}

/*
	GMP - c++ library for big numbers
*/