#pragma once
#include <iostream>

using namespace std;

template<typename T> class fraction
{
private:
	T numerator;
	T denominator;
	friend ostream& operator<<(ostream &, const fraction<T> &);
	friend istream& operator>>(istream &, fraction<T> &);
public:
	fraction();
	fraction(T n, T d);
	~fraction();

	fraction operator+(const fraction&);
	fraction operator-(const fraction&);
	fraction operator*(const fraction&);
	fraction operator/(const fraction&); // a + b 
	fraction& operator=(const fraction&);
	operator double();
};

// fraction.cpp

template<typename T> fraction<T>::fraction()
{
	this->numerator = 1;
	this->denominator = 1;
}

template<typename T> fraction<T>::fraction(T n, T d)
{
	if (!d) this->denominator = 1;
	else this->denominator = d;
	this->numerator = n;
	
}

template<typename T> fraction<T>::~fraction()
{
}

template<typename T> fraction<T> fraction<T>::operator+(const fraction &st)
{
	if (denominator == st.denominator) return fraction(numerator + st.numerator, denominator);
	else return fraction(numerator*st.denominator + st.numerator*denominator, denominator*st.denominator);
}

template<typename T> fraction<T> fraction<T>::operator-(const fraction &st)
{
	if (denominator == st.denominator) return fraction(numerator - st.numerator, denominator);
	else return fraction(numerator*st.denominator - st.numerator*denominator, denominator*st.denominator);
}

template<typename T> fraction<T> fraction<T>::operator*(const fraction &st)
{
	return fraction(numerator*st.numerator, denominator*st.denominator);
}

template<typename T> fraction<T> fraction<T>::operator/(const fraction &st)
{
	return fraction(numerator*st.denominator, denominator*st.numerator);
}

template<typename T> fraction<T>& fraction<T>::operator=(const fraction &st)
{
	numerator = st->numerator;
	denominator = st->denominator;
	return *this;
}

template<typename T> fraction<T>::operator double()
{
	if (denominator == 0) return 0;
	return (numerator / denominator);
}

template<typename T> ostream& operator<<(ostream &out, const fraction<T> &st)
{
	out << "[" << st.numerator << "/" << st.denominator << "]";
	return out;
}

template<typename T> istream& operator>>(istream &in, fraction<T> &fr)
{
	in >> fr.numerator >> fr.denominator;
	return in;
}
