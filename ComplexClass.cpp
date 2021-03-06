// ComplexClass.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Header.h"
#include <iostream>
#include <cmath>

using namespace std;

template<class T>
double Complex<T>::real() const {
	return re;
}

template<class T>
double Complex<T>::imag() const {
	return im;
}

template<class T>
ostream& operator<< (ostream &out, const Complex<T> &c) {
	if (c.im > 0 && c.im != 1) {
		out << "(" << c.re << "+" << c.im << "i" << ")";
	}
	else if (c.im == 1) {
		out << "(" << c.re << "+i" << ")";
	}
	else if (c.im == -1) {
		out << "(" << c.re << "-i" << ")";
	}
	else
		out << "(" << c.re << c.im << "i" << ")";
	return out;
}

template<class T>
Complex<T> Complex<T>::operator+(const Complex<T> &c) {
	return Complex<T>(re + c.re, im + c.im);
}

template<class T>
Complex<T> Complex<T>::operator-(const Complex<T> &c) {
	return Complex<T>(re - c.re, im - c.im);
}

template<class T>
Complex<T> Complex<T>::operator*(const Complex<T> &c) {
	return Complex<T>(re * c.re - im * c.im, re * c.im + im * c.re);
}

template<class T>
Complex<T> Complex<T>::operator/(const Complex<T> &c) {
	Complex<T> temp;
	T r = c.re * c.re + c.im * c.im;
	temp.re = (re * c.re + im * c.im) / r;
	temp.im = (im * c.re - re * c.im) / r;
	return temp;
}

template<class T>
bool Complex<T>::operator==(const Complex<T> &c) {
	return re == c.re && im == c.im;
}

template<class T>
Complex<T> &Complex<T>::operator+=(const Complex<T> &c) {
	re += c.re;
	im += c.im;
	return *this;
}

template<class T>
Complex<T> &Complex<T>::operator-=(const Complex<T> &c) {
	re -= c.re;
	im -= c.im;
	return *this;
}

template<class T>
Complex<T> &Complex<T>::operator*=(const Complex<T> &c) {
	double temp = re * c.re - im * c.im;
	im = re * c.im + im * c.re;
	re = temp;
	return *this;
}

template<class T>
Complex<T> &Complex<T>::operator/=(const Complex<T> &c) {
	double q = c.im / c.re;
	double d = c.re + c.im*q;
	re = (re + im * q) / d;
	im = (im - re * q) / d;
	return *this;
}

template<class T>
Complex<T> &Complex<T>::operator++() {
	++re;
	return *this;
}

template<class T>
Complex<T> Complex<T>::operator++(int) {
	Complex<T> temp(*this);
	++re;
	return temp;
}

template<class T>
Complex<T> &Complex<T>::operator--() {
	--re;
	return *this;
}

template<class T>
Complex<T> Complex<T>::operator--(int) {
	Complex<T> temp(*this);
	--re;
	return temp;
}


int main() {
	Complex<double> a(3, -5);
	Complex<double> b(-1, 4);

	cout << "a = " << a << "; b =" << b << endl;
	cout << " a + b = " << a + b << endl;
	cout << " a - b = " << a - b << endl;
	cout << " a * b = " << a * b << endl;
	cout << " a / b = " << a / b << endl;
	cout << "sin(a) = " << sin(a) << endl;
	cout << "cos(a) = " << cos(a) << endl;
	cout << "tan(a) = " << tan(a) << endl;
	cout << "sinh(b) = " << sinh(b) << endl;
	cout << "cosh(b) = " << cosh(b) << endl;
	cout << "tanh(b) = " << tanh(b) << endl;
	cout << "exp(a) = " << exp(a) << endl;
	cout << "sqrt(b) = " << sqrt(b) << endl;
	cout << "log(a) = " << log(a) << endl;
	cout << " |a| = " << a.abs() << endl;
	cout << " |b| = " << b.abs() << endl;
	cout << "++a  = " << ++a << endl;
	cout << "a++  = " << a++ << endl;
	system("pause");
	return 0;
}


