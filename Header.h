#pragma once
#include <iostream>
#include <cmath>
#define PI       3.1415
#define PI_2     1.571

using namespace std;

template<class T>
class Complex {
	T re, im;

	template <class M>
	friend ostream & operator<< (ostream &, const Complex<M> &);

	inline friend Complex sin(const Complex &c) {
		if (c.im == 0)
			return Complex(sin(c.re), 0);
		return Complex(sin(c.re)*cosh(c.im), cos(c.re)*sinh(c.im));
	}

	inline friend Complex cos(const Complex &c) {
		if (c.im == 0)
			return Complex(cos(c.re), 0);
		return Complex(cos(c.re)*cosh(c.im), -sinh(c.im)*sin(c.re));
	}

	inline friend Complex tan(const Complex &c) {
		if (c.im == 0)
			return Complex(tan(c.re), 0);
		T tn = tan(c.re);
		T tnh = tanh(c.im);
		T d = 1 / (1 + tn * tn*tnh*tnh);
		return Complex(tn*(1 - tnh * tnh)*d, tnh*(1 + tn * tn)*d);
	}

	inline friend Complex sinh(const Complex &c) {
		if (c.im == 0)
			return Complex(sinh(c.re), 0);
		return Complex(sinh(c.re)*cos(c.im), cosh(c.re)*sin(c.im));
	}

	inline friend Complex cosh(const Complex &c) {
		if (c.im == 0)
			return Complex(cosh(c.re), 0);
		return Complex(cosh(c.re)*cos(c.im), sin(c.im)*sinh(c.re));
	}

	inline friend Complex tanh(const Complex &c) {
		if (c.im == 0)
			return Complex(tanh(c.re), 0);
		T tnh = tanh(c.re);
		T tn = tan(c.im);
		T d = 1 / (1 + tnh * tnh*tn*tn);
		return Complex(tnh*(1 + tn * tn)*d, tn*(1 - tnh * tnh)*d);
	}

	inline friend Complex exp(const Complex &c) {
		if (c.im == 0)
			return Complex(exp(c.re), 0);
		T e = exp(c.re);
		return Complex(e*cos(c.im), e*sin(c.im));
	}

	inline friend Complex log(const Complex &c) {
		if (c.im == 0)
			return Complex(log(c.re), 0);
		return Complex(log(c.re*c.re + c.im*c.im) / 2, (c.im>0 ? (PI_2) : (-PI_2)) - atan(c.re / c.im));
	}

	inline friend Complex sqrt(const Complex &c) {
		if (c.im == 0)
			return Complex(sqrt(c.re), 0);
		T n = sqrt(c.re*c.re + c.im*c.im);
		return Complex(sqrt((n + c.re) / 2), (c.im<0 ? -sqrt((n - c.re) / 2) : sqrt((n - c.re) / 2)));
	}

public:
	Complex() {};
	Complex(T r) { re = r; im = 0; }
	Complex(T r, T i) { re = r; im = i; }
	Complex(const Complex<T> &c) { re = c.re; im = c.im; }
	~Complex() {}
	T abs() { return sqrt(re * re + im * im); }
	double real() const;
	double imag() const;
	Complex<T> operator+(const Complex<T> &c);
	Complex<T> operator-(const Complex<T> &c);
	Complex<T> operator*(const Complex<T> &c);
	Complex<T> operator/(const Complex<T> &c);
	bool operator==(const Complex<T> &c);
	Complex<T> &operator+=(const Complex<T> &c);
	Complex<T> &operator-=(const Complex<T> &c);
	Complex<T> &operator*=(const Complex<T> &c);
	Complex<T> &operator/=(const Complex<T> &c);
	Complex<T> &operator++();
	Complex<T> operator++(int);
	Complex<T> &operator--();
	Complex<T> operator--(int);

};
