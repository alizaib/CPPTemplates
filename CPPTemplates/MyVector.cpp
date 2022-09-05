#pragma once
#include<iostream>

template<typename T>
class MyVector {
private:
	int size;
	T* ptr;
public:
	MyVector(int = 10);
	MyVector(const MyVector&);

	int getSize() const;

	//operators overload
	MyVector operator = (const MyVector&);
	T& operator [] (int index);

	~MyVector();
};

template<typename T>
MyVector<T>::MyVector(int s) {
	size = s;
	if (size != 0) {
		ptr = new T[size];
	}
	else {
		ptr = NULL;
	}
}

template<typename T>
MyVector<T>::MyVector(const MyVector<T>& copy) {
	//this = copy;

	//TODO: Verify the above line
	size = copy.getSize();

	if (size != 0) {
		ptr = new T[size];
		for (int i = 0; i < size; i++)
			ptr[i] = copy.ptr[i];
	}
	else {
		ptr = NULL;
	}

}

template<typename T>
int MyVector<T>::getSize() const {
	return size;
}

template<typename T>
MyVector<T> MyVector<T>::operator = (const MyVector& right) {
	if (this != right) {
		delete[] ptr;
		size = right.getSize();

		if (size != 0) {
			ptr = new T[size];
			for (int i = 0; i < size; i++)
				ptr[i] = right.ptr[i];
		}
		else {
			ptr = NULL;
		}
	}
}

template<typename T>
T& MyVector<T>::operator [] (int index) {
	if (index < 0 || index >= size)
		exit(1);

	return ptr[index];
}

template<typename T>
MyVector<T>::~MyVector<T>() {
	delete[] ptr;
	ptr = NULL;
}
