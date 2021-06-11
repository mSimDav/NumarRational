#pragma once

#include<iostream>
#include<fstream>
using namespace std;

class Rational {
	int numarator, numitor;
	
public:
	Rational(int = 0, int = 1);
	Rational(const Rational&);
	~Rational();

	int cmmdc(int, int);
	void simplifica();

	friend Rational operator+ (const Rational& r1, const Rational& r2);
	friend Rational operator- (const Rational& r1, const Rational& r2);
	friend Rational operator* (const Rational& r1, const Rational& r2);
	friend Rational operator/ (const Rational& r1, const Rational& r2);


	Rational operator+(const Rational);
	Rational operator-(const Rational);
	Rational operator*(const Rational);
	Rational operator/(const Rational);


	Rational operator-();
	Rational operator!(); 
	Rational& operator=(const Rational& r);
	friend ostream& operator<<(ostream& out, Rational&);
	friend istream& operator>>(istream& in, Rational&);
	operator float()const {
		return numarator / (float)numitor;
	}
	explicit Rational(float f) {
		numarator = f;
		numitor = 1;
	}
};
