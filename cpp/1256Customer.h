#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer{
private:
	long arrive;
	int processtime;
public:
	Customer(){arrive = 0, processtime = 0;}
	void set(long when);
	long when() const{return arrive;}
	int ptime()const {return processtime;}
};
#endif