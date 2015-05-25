#ifndef COMPARATOR_H
#define COMPARATOR_H
#include "comparator.h"
#endif
#include <string>

class CaseInsensitive : public Comparator{
public:
	~CaseInsensitive(){};
	virtual int compare(const std::string &lhs, const std::string &rhs);
};