/*
A program that detects whether an array is sorted or not, and if it is not sorted, sorts it.
*/

#include <iostream>;
#include <string>;
#include <cstdlib>;
#include <ctime>;

using namespace std;

void insertRandomNumbersIntoArray(int nums[], int size);
bool arrayIsSorted(int nums[], int size);
void sortArrayWithInsertionSort(int nums[], int size);
void arrayToString(int nums[], int size);

int main()
{
	srand(time(NULL));

	const int size = 100;
	int nums[size];
	insertRandomNumbersIntoArray(nums, size);

	cout << "Randomly generated array of numbers: " << endl;
	arrayToString(nums, size);

	if (!arrayIsSorted(nums, size))
	{
		sortArrayWithInsertionSort(nums, size);
	}

	cout << "\nArray sorted with insertion sort:" << endl;
	arrayToString(nums, size);

	cin.get();
}

void insertRandomNumbersIntoArray(int nums[], int size)
{
	for (int i = 0; i < size; i++)
	{
		nums[i] = rand() % 250;
	}
}

bool arrayIsSorted(int nums[], int size)
{
	bool isSorted = true;

	for (int i = 0; i < size; i++)
	{
		if (i != 0 && nums[i - 1] > nums[i]) //previous number is bigger than current number
		{
			isSorted = false;
			break;
		}
	}

	return isSorted;
}

void sortArrayWithInsertionSort(int nums[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int smallestNumLeftIndex = i;

		for (int j = i; j < size; j++)
		{
			if (nums[j] < nums[smallestNumLeftIndex])
			{
				smallestNumLeftIndex = j;
			}
		}

		int temp = nums[i];
		nums[i] = nums[smallestNumLeftIndex];
		nums[smallestNumLeftIndex] = temp;
	}
}

void arrayToString(int nums[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		cout << nums[i] << ", ";
	}

	cout << nums[size - 1] << endl;
}