#include <stdio.h>

int prim(int n)
{
	/*
	n -> the number we check primality for
	return -> returns 1 if x is prime, 0 otherwise
	*/
	if (n < 2) return 0;
	if (n > 2 && n % 2 == 0) return 0;
	for (int d = 3; d * d <= n; d += 2)
		if (!(n % d))
			return 0;
	return 1;
}

int cmmdc(int a, int b)
{
	/*
	Function to compute greatest common divisor of two numbers
	a -> the first number
	b -> the second number
	returns the greatest common divisor (Euclidean division algorithm)
	*/
	while (b)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

void generateFirstNPrimeNumbers(int n)
{
	/*
	Function that generates first n prime numbers
	n -> the number of prime numbers we want to generate
	returns nothing
	*/
	int count = 0, x = 2;
	printf("The first n prime numbers are:\n");
	while (count <= n)
	{
		while (!prim(x))
			x++;
		printf("%d\n", x);
		count++;
		x++;
	}
}

void findLongestContiguousSubsequenceOfRelativelyPrimeNumbers(int n, int A[])
{
	/*
	Function that finds the longest contiguous subsequence of numbers that are relatively prime consecutively
	n -> the number of elements
	A -> the vector in which we look for
	returns nothing
	*/
	int currentLength = 0, maxLength = 0, start = 0, stop = 0;
		
	for (int i = 0; i < n; i++)
	{
		int last = i == 0 ? 0 : A[i - 1];

		if (cmmdc(A[i], last) == 1)
		{
			currentLength++;
			if (currentLength > maxLength)
			{
				maxLength = currentLength;
				start = i - maxLength + 1;
				stop = i;
			}
		}
		else
		{
			currentLength = 1;
		}
	}
	for (int i = start; i <= stop; i++)
		printf("%d ", A[i]);
	printf("\n");
}

void readFunction(int n, int A[])
{
	/*
	Function that reads the vector from option 1
	n -> the size of the vector
	A -> the vector
	returns nothing, everything is passed by refference
	*/
	for (int i = 0; i < n; i++)
	{
		printf("Element %d: ", i + 1);
		scanf("%d", &A[i]);
	}
}

void runMenu()
{
	/*
	Function that runs the menu
	*/
	int n = -1, A[10000] = { 0 };

	while (1)
	{
		printf("Welcome to my app. Made by Robert Beres 911/2.\n");
			printf("Menu:\n");
			printf("1. Read a vector from the keyboard\n");
			printf("2. Generate first n prime numbers\n");
			printf("3. Find longest contiguous sequence s.t. any two consecutive elements are relatively prime.\n");
			printf("4. Exit\n");

		int userInput = -1;
		printf("Your input: \n");
		scanf("%d", &userInput);
		

		if (userInput == 1)
		{
			printf("Enter n(size of array):\n");
			scanf("%d", &n);
			if (n > 0)
				readFunction(n, A);
			else
				printf("N must be greater than 0.\n");
		}
		else if (userInput == 2)
		{
			printf("Enter n:\n");
			scanf("%d", &n);
			if (n > 0)
				generateFirstNPrimeNumbers(n);
			else
				printf("N must be greater than 0.\n");
		}
		else if (userInput == 3)
			findLongestContiguousSubsequenceOfRelativelyPrimeNumbers(n, A);
		else if (userInput == 4)
			return;
	}
}

int main()
{
	runMenu();
	return 0;
}