import java.util.Scanner;
import java.util.Random;

class Lehman
{
	int MyPow(int base, int expo, int mod)
	{
		int result = base;

		for(int i = 1; i < expo; i++)
		{
			result = (result * base) % mod;
		}

		return result;
	}


	public static void main(String[] args) 
	{
		Scanner cin = new Scanner(System.in);
		Random rand = new Random();

		boolean status = true;

		int num;

		System.out.println("enter the number which you want to be tested");
		num = cin.nextInt();

		int times;

		System.out.println("How many times you want to repeat the test");
		times = cin.nextInt();
	

		for(int t = 1; t <= times; t++)
		{
			int randomNum = rand.nextInt(num - 1) + 1; 

			int expo = (num - 1) / 2;

			int result = new Lehman().MyPow(randomNum, expo, num);

			if (result % num != 1 && result % num != (num - 1)) 
			{
				System.out.println(num + " is definitely not prime");

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
			
			System.out.println(num + " has 1 - (1/(2^" + times + ")) probability of being prime");
		}

	}
}