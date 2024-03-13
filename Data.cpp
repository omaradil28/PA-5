#include "Data.h"
//Constructors
Data::Data() {
	customerNumber = 0;
	serviceTime = 0;
	totalTime = 0;
}

Data::Data(int customer, int service, int total) {

	customerNumber = customer;
	serviceTime = service;
	totalTime = total;
}

//Copy Constructor
Data::Data(Data const& copy) {
	customerNumber = copy.customerGet();
	serviceTime = copy.serviceGet();
	totalTime = copy.totalGet();
}

//Destructor
Data::~Data() {}

//Setters
void Data::customerSet(int num) {
	customerNumber = num;
}

void Data::serviceSet(int num) {
	serviceTime = num;
}

void Data::totalSet(int num) {
	totalTime = num;
}

//Getters
int Data::customerGet() const {
	return customerNumber;
}


int Data::serviceGet() const {
	return serviceTime;
}

int Data::totalGet() const {
	return totalTime;
}

std::ostream& operator << (std::ostream& lhs, const Data& rhs) {
	lhs << '(' << rhs.customerGet() << ',' << rhs.serviceGet() << ',' << rhs.totalGet() << ')';
	return lhs;
}
