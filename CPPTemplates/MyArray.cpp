#pragma once
template<typename T, int arrSize>
class MyArray {
private:
	const int _arrSize;
	T items[arrSize];
public:
	MyArray() : _arrSize(arrSize) {}

	T& operator [](int i) {		
		return items[i];
	}
};