#include <iostream>
#include "TemplatesAsPolicy.h"
#include "MyVector.cpp"
#include "Complex.cpp"
#include <vector>

using namespace std;

void MyVectorDemo();
void FuntionPointerDemo();
void ComplexDemo();

int main() {
	//TemplatesAsPolicy t1;
	//MyVectorDemo();
	//FuntionPointerDemo();
	ComplexDemo();
}

void MyVectorDemo() {
	MyVector<int> nums(2);

	cout << nums[0];
}

void PrintValue(int value) { cout << value; }

void ForEach(vector<int>& values, void(*action)(int)) {
	for (int value : values)
		action(value);
}

void FuntionPointerDemo() {
	vector<int> values = { 1, 3, 5, 7, 9 };

	ForEach(values, PrintValue);
	cout << endl;
	ForEach(values, [](int value) { cout << "Value :" << value << endl; });
}

void ComplexDemo() {
	Complex<float> f(0, 0);
	Complex<double> d = f;
}
