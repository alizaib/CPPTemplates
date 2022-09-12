#pragma once
// non-type generic parameter, both type and non-type generic parameter can take default values
template<typename T = int, int arrSize = 10>
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