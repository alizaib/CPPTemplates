#pragma once
template<typename T>
class Complex {
private:
	T real, img;
public:
	Complex(T r, T i);

	Complex(const Complex<T>&);

	template<typename U>
	Complex(const Complex<U>& c);
};

template<typename T>
Complex<T>::Complex(T r, T i) : real(r), img(i) {}

template<typename T>
Complex<T>::Complex(const Complex<T>& c) : real(c.real), img(c.img) {}

template<typename T>
template<typename U>
Complex<T>::Complex(const Complex<U>& c) : real(c.real), img(c.img) {}
