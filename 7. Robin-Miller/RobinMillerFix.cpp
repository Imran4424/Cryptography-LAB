#include <iostream>
#include <string>
#include <fstream>
using namespace std;

typedef unsigned long long int ulli;

ulli MyPow(ulli base, ulli pow)
{
	ulli result = 1;

	for (int i = 1; i <= pow; ++i)
	{
		result *= base;
	}

	//cout << "I am here" << endl;

	return result;
}

ulli MyPowEx(ulli base, ulli expo, ulli mod)
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
	ulli num;
	cout << "enter the number which you want to be tasted" << endl;
	cin >> num;


	// finding b and m

	ulli b = 1, m;

	ulli dividor = MyPow(2, b);

	while((num - 1) % dividor == 0)
	{
		b++;

		dividor = MyPow(2,b);

		//cout << "I am here 2" << endl;
	}

	b--;

	dividor = MyPow(2,b);

	m = (num - 1) / dividor;


	// chosing a 

	ulli randomA = rand() % (num-1) + 1;


	ulli bInitial = MyPowEx(randomA, m, num);

	if(bInitial == 1 || bInitial == num-1)
	{
		cout << num << " is probably prime" << endl;
	}
	else
	{
		ulli bIterative = bInitial;

		for(int j = 1 ; j <= b ; j++)
		{
			bIterative = MyPowEx(bIterative, 2, num);

			if (bIterative == num - 1)
			{
				break;
			}
		}

		if (bIterative != num - 1)
		{
			cout << num << " is not prime" << endl;
		}
		else if(bIterative == num - 1)
		{
			cout << num << " is probably prime" << endl;
		}
	}

	

	return 0;
}