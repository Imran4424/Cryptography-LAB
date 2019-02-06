#include <iostream>
#include <string>
#include <fstream>
using namespace std;

typedef unsigned long long int ulli;

ulli MyPow(ulli base, ulli expo, ulli mod)
{
	ulli result = base;

	for(ulli i = 1; i < expo; i++)
	{
		result = (result * base) % mod;
	}

	return result;
}

int main(int argc, char const *argv[])
{
	bool status = true;

	ulli num;
	cout << "enter the number which you want to be tasted" << endl;
	cin >> num;


	ulli times;
	cout << "How many times you want to repeat the test" << endl;
	cin >> times;


	for(ulli t = 1; t <= times; t++)
	{
		ulli randomNum = rand() % (num-1) + 1;

		ulli expo = (num-1) / 2 ;

		ulli result = MyPow(randomNum, expo, num);

		
		
		if ( result % num != 1 && result % num != (num - 1))
		{
			cout << num << " is definitely not prime " << endl;
			
			status = false;

			break;
		}
		else
		{
			status = true;
		}
			
	}

	
	if (status) 
	{
		
		cout << num << " has 1 - 1/(2^" << times << " probability of being prime " << endl;
	}
	


	return 0;
}

/*
	GMP - c++ library for big numbers
*/