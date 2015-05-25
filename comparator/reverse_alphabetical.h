#ifndef COMPARATOR_H
#define COMPARATOR_H
#include "comparator.h"
#endif
#include <string>

class ReverseAlphabetical : public Comparator{
	public:
		~ReverseAlphabetical(){};
		virtual int compare(const std::string &lhs, const std::string &rhs);
};