#ifndef CASE_INSENSITIVE_H
#define CASE_INSENSITIVE_H
#include "case_insensitive.h"
#endif
#include <string>

int CaseInsensitive::compare(const std::string &lhs, const std::string &rhs){
	std::string lowerLhs = lhs;
	std::string lowerRhs = rhs;

	for (int i = 0; i < lowerLhs.size(); i++){
		lowerLhs[i] = tolower(lowerLhs[i]);
	}

	for (int i = 0; i < lowerRhs.size(); i++){
		lowerRhs[i] = tolower(lowerRhs[i]);
	}

	if (lowerLhs < lowerRhs){
		return -1;
	}
	else if (lowerLhs > lowerRhs){
		return 1;
	}
	else{
		return 0;
	}
}