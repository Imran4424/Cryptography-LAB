import java.util.Scanner;

class Lehman
{
	int my_pow(int base, int expo, int mod)
	{
		int result = base;

		for(int i = 1; i <= expo; i++)
		{
			result = (result * base) % mod;
		}

		return result;
	}


	public static void main(String[] args) 
	{
		Scanner cin = new Scanner(System.in);

		
	}
}