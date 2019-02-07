#include <iostream>
#include <string>
#include <fstream>
using namespace std;

typedef unsigned long long int ulli;

ulli MyPow(ulli base, ulli pow)
{
	result = 1;

	for (int i = 1; i <= pow; ++i)
	{
		result *= base;
	}

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
	bool status = true;

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
	}

	b--;

	dividor = MyPow(2,b);

	m = (num - 1) / dividor;


	// chosing a 

	ulli randomA = rand() (num-1) + 1;


	bInitial = MyPowEx(randomA, m, num);

	if (bInitial == 1 || bInitial == -1)
	{
		
	}


	return 0;
}