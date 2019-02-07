import java.util.*;

class Diffie_Hellman
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter modulo(p)");
		int p=sc.nextInt();
		System.out.println("Enter primitive root of "+p);
		int g=sc.nextInt();
		System.out.println("Choose 1st secret no(Alice)");
		int a=sc.nextInt();
		System.out.println("Choose 2nd secret no(BOB)");
		int b=sc.nextInt();
		
		int A = (int)Math.pow(g,a)%p;
		int B = (int)Math.pow(g,b)%p;
		
		int S_A = (int)Math.pow(B,a)%p;
		int S_B =(int)Math.pow(A,b)%p;	
		
		if(S_A==S_B)
		{
			System.out.println("ALice and Bob can communicate with each other!!!");
			System.out.println("They share a secret no = "+S_A);			
		}
		
		else
		{
			System.out.println("ALice and Bob cannot communicate with each other!!!");
		}
	}	
}

/*
Algorithm
Step 1 : Choose two prime numbers g(primitive root of p) and p.

Step 2 :  Alice selects a secret no(a) and computes ga mod p , let’s call it A. Alice sends A to Bob.

Step 3 : Bob selects a secret no(b) and computes gb mod p, let’s call it B. Bob sends B to Alice.

Step 4 : Alice computes S_A = Ba mod p

Step 5 : Bob computes S_B = Ab mod p

Step 6 : If S_A=S_B then Alice and Bob can agree for future communication.
*/