/*
Write a function that builds a two-dimensional multiplication table with arbitrary sizes for the two dimensions
*/

#include <iostream>

using namespace std;

int main()
{
	int numRows;
	int numCols;

	cout << "How many rows should the table have? ";
	cin >> numRows;

	cout << endl;

	cout << "How many columns should the table have? ";
	cin >> numCols;

	//initialize the array of int pointers
	int **p_p_rows = new int*[numRows];

	//set each int pointer to point to an array of ints
	for (int i = 0; i < numRows; i++)
	{
		p_p_rows[i] = new int[numCols];
	}

	//fill each value with its multiple
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numCols; j++)
		{
			p_p_rows[i][j] = (i + 1) * (j + 1);
		}
	}

	//print each value
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numCols; j++)
		{
			cout << p_p_rows[i][j] << '\t';
		}

		cout << endl;
	}

	//free each row back to the heap
	for (int i = 0; i < numRows; i++)
	{
		delete p_p_rows[i];
	}

	//free the list of pointers back to the heap
	delete p_p_rows;

	cin.ignore();
	cin.get();
}