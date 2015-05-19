/*
Factorization Prime Finder

Written By: Stephen Merendino
Date: May 6, 2015

Design a program that finds all numbers from 1 to 1000 whose prime factors,
when added together, sum up to a prime number (for example, 12
has prime factors of 2, 2, and 3, which sum to 7, which is prime).
Implement the code for that algorithm.

Problem Source: 
Learning with C++
Alex Alain
Chapter 9, Practice Problem 3 (page 111)

TODO:
-None
*/

#include <iostream>;
#include <string>;

using namespace std;

int sumFactors(int num);
bool isPrime(int num);
void printNumWithFactors(int num);

int main()
{
	cout << "Finding all numbers from 1 to 1000 whose prime factors, when added together, sum up to a prime number." << endl;
	cout << "..........." << endl;

	for (int i = 1; i <= 1000; i++)
	{
		if (isPrime(sumFactors(i)))
		{
			printNumWithFactors(i);
		}
	}

	cin.get();
}

int sumFactors(int num)
{
	int factorTotal = 0;

	if (num == 1)
	{
		return 1;
	}

	if (isPrime(num))
	{
		return num + 1;
	}

	while (num != 1)
	{
		int factor = 2;

		while (factor <= num)
		{
			if (num % factor == 0) //check if number is divisible by current factor
			{
				factorTotal += factor;
				num = num / factor; //divide num so we can find the next factor
				continue; //break out of inner loop so we can reset the factor and find the next one
			}

			factor++;
		}
	}

	return factorTotal;
}

bool isPrime(int num)
{
	bool prime = true;
	int factor = 2;

	while (factor < num)
	{
		if ((num % factor == 0) && (factor < num)) //not prime
		{
			prime = false;
			break;
		}

		factor++;
	}

	return prime;
}

void printNumWithFactors(int num)
{
	int originalNum = num;

	if (isPrime(num))
	{
		cout << num << " has factors 1";
	}
	else
	{
		cout << num << " has factors";
	}

	while (num != 1)
	{
		int factor = 2;

		while (factor <= num)
		{
			if (num % factor == 0) //check if number is divisible by current factor
			{
				cout << ' ' << factor; //add factor onto total
				num = num / factor; //divide num so we can find the next factor
				continue; //break out of inner loop so we can reset the factor and find the next one
			}

			factor++;
		}
	}

	cout << " totaling up to " << sumFactors(originalNum) << " which is a prime number.";

	cout << endl;
}