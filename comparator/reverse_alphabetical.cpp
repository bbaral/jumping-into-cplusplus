#ifndef REVERSE_ALPHABETICAL_H
#define REVERSE_ALPHABETICAL_H
#include "reverse_alphabetical.h"
#endif
#include <string>

int ReverseAlphabetical::compare(const std::string &lhs, const std::string &rhs){
	if (lhs > rhs){
		return -1;
	}
	else if (lhs < rhs){
		return 1;
	}
	else{
		return 0;
	}
}