/*
Multi-dimensional arrays with pointers

Written By: Stephen Merendino
Date: May 25, 2015

THis program implements a function that takes a vector and
sums all the values in the vector, no matter the type of numerical data
it holds.

Problem Source:
Learning with C++
Alex Alain
Chapter 29, Practice Problem 1 (page 339)

TODO:
-None
*/

#include <vector>
#include <iostream>

template <typename T>
T sum(std::vector<T> collection){
	T total = 0;
	for (std::vector<T>::iterator itr = collection.begin(), end = collection.end(); itr != end; itr++){
		total += *itr;
	}
	return total;
}

int main(){
	std::vector<int> ints{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::cout << sum(ints) << std::endl;

	std::vector<float> floats{ 1.5f, 2.2f, 3.9f, 4.8f, 5.1f, 6.6f, 7.0f, 8.4f, 9.9f, 10.25f };
	std::cout << sum(floats) << std::endl;

	std::vector<double> doubles{ 1.5, 2.2, 3.9, 4.8, 5.1, 6.6, 7.0, 8.4, 9.9, 10.25 };
	std::cout << sum(floats) << std::endl;

	std::cin.get();
}