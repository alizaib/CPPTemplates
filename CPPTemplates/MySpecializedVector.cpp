#pragma once
#include "MyVector.cpp"

template<>
class MyVector<char*> {
private:
	int size;
	char **ptr;
public:
	MyVector(int s) {
		size = s;
		if (size != 0) {
			ptr = new char* [size];
			for (int i = 0; i < size; i++)
				ptr[i] = 0;
		}
		else
			ptr = 0;
	}

	MyVector(const MyVector<char*>& copy) {
		size = copy.getSize();
		if (size == 0) {
			ptr = 0;
			return;
		}
		ptr = new char* [size];
		for (int i = 0; i < size; i++)
			if (copy.ptr[i] != 0) {
				size_t destLength = strlen(copy.ptr[i]) + 1;				
				strcpy_s(ptr[i], destLength, copy.ptr[i]);
			}
			else
				ptr[i] = 0;
	}

	~MyVector() {
		for (int i = 0; i < size; i++)
			delete[] ptr[i];
		delete[] ptr;
	}

	MyVector<char*> operator =(const MyVector<char*>& rhs) {
		if (this == &rhs)
			return *this;

		for (int i = 0; i < size; i++) {
			delete[] ptr[i];
			ptr[i] = 0;
		}

		delete[] ptr;

		size = rhs.getSize();
		if (size == 0) {
			ptr = 0;
			return *this;
		}

		for (int i = 0; i < size; i++) {
			if (ptr[i] != 0) {
				strcpy_s(ptr[i], strlen(rhs.ptr[i] + 1), rhs.ptr[i]);
			}
			else {
				ptr[i] = 0;
			}
		}
		return *this;
	}

	int getSize() const {
		return size;
	}

	
	char*& operator[](int index) {
		if (index < 0 || index >= size) {
			exit(1);
		}		
		return ptr[index];
	}

	//TODO: find this out
	//cannot convert from 'char *' to 'const char *&
	/*const char*& operator[](int index) {
		if (index < 0 || index >= size) {
			exit(1);
		}
		return ptr[index];
	}*/

	void insert(const char* str, int i) {
		delete[] ptr[i];
		if (strlen(str) != 0) {
			size_t len = strlen(str) + 1;
			ptr[i] = new char[len];
			strcpy_s(ptr[i], len, str);
		}
		else {
			ptr[i] = 0;
		}
	}
};

//TODO: moving defintions of these classes give compile error

//MyVector<char*>::~MyVector() {
//	for (int i = 0; i < size; i++)
//		delete[] ptr[i];
//	delete[] ptr;
//}

//MyVector<char*>::MyVector(int s) {
//	size = s;
//	if (size != 0) {
//		ptr = new char* [size];
//		for (int i = 0; i < size; i++)
//			ptr[i] = 0;
//	}
//	else
//		ptr = 0;
//}
