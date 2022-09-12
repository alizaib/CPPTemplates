#pragma once
#include<iostream>

template<typename T>
class MyVector {
private:
	int size;
	T* ptr;
	int index;
public:
	MyVector(int = 10);
	MyVector(const MyVector&);

	int getSize() const;

	int getIndex() const;
	void setIndex(int);


	//operators overload
	T& operator*();	
	T& operator [] (int index);
	bool operator !=(const MyVector<T>&);
	void operator = (const MyVector<T>&);
	MyVector<T>& operator ++();

	~MyVector();
};

template<typename T>
MyVector<T>::MyVector(int s) : ptr(0) {
	size = s;
	if (size != 0) {
		ptr = new T[size];
	}
	else {
		ptr = NULL;
	}
	index = 0;
}

template<typename T>
MyVector<T>::MyVector(const MyVector<T>& copy) : ptr(0) {
	size = copy.size;

	if (size != 0) {
		ptr = new T[size];

		for (int i = 0; i < size; i++)
			ptr[i] = copy.ptr[i];
	}
	else {
		ptr = NULL;
	}
	index = copy.index;
}

template<typename T>
int MyVector<T>::getSize() const {
	return size;
}

template<typename T>
int MyVector<T>::getIndex() const {
	return index;
}

template<typename T>
void MyVector<T>::setIndex(int i) {	
	index = i;
}

template<typename T>
T& MyVector<T>::operator*() {
	return ptr[index];
}

template<typename T>
T& MyVector<T>::operator [] (int index) {
	if (index < 0 || index >= size)
		exit(1);

	return ptr[index];
}

template<typename T>
bool MyVector<T>::operator!=(const MyVector<T>& v) {
	if (size != v.size || index != v.index)
		return true;

	for (int i = 0; i < size; i++)
		if (ptr[i] != v.ptr[i])
			return true;

	return false;
}

template<typename T>
void MyVector<T>::operator = (const MyVector<T>& copy){
	if (this == &copy)
		return;

	if (ptr != nullptr)
		delete[] ptr;

	size = copy.size;

	if (size != 0) {
		ptr = new T[size];

		for (int i = 0; i < size; i++)
			ptr[i] = copy.ptr[i];
	}
	else {
		ptr = NULL;
	}
	index = copy.index;
}

template<typename T>
MyVector<T>& MyVector<T>::operator ++() {
	if (index < size)
		++index;

	return *this;
}


template<typename T>
MyVector<T>::~MyVector<T>() {
	delete[] ptr;
	ptr = NULL;
}
