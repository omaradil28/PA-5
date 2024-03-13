#pragma once

#include "PA5.h"

class Data {
public:
	Data();
	Data(int, int, int);
	Data(Data const & copy );

	~Data();

	int customerGet() const;
	void customerSet(int);

	int serviceGet() const;
	void serviceSet(int);

	int totalGet() const;
	void totalSet(int);


private:
	int customerNumber;
	int serviceTime;
	int totalTime;
};

std::ostream& operator << (std::ostream& lhs, const Data& rhs);
