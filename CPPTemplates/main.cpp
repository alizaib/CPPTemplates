#include <iostream>
#include "TemplatesAsPolicy.h"
#include "MyVector.cpp"
#include "MySpecializedVector.cpp"
#include "Complex.cpp"
#include <vector>
#include "MyArray.cpp"

using namespace std;

void MyVectorDemo();
void FuntionPointerDemo();
void ComplexDemo();
void MyArrayDemo();

int main() {
	//TemplatesAsPolicy t1;
	//MyVectorDemo();
	//FuntionPointerDemo();
	//ComplexDemo();
	MyArrayDemo();
}

void MyVectorDemo() {
	MyVector<int> nums(2);
	nums[0] = 23;
	nums[1] = 2;
	cout << nums[0] << endl << nums[1];

	MyVector<char*> names(3);
	/*names[0] = "Ali";
	names[1] = "Rehan";
	names[3] = "Neelam";*/
	names.insert("Ali", 0);
	names.insert("Rehan", 1);
	names.insert("Neelam", 2);

	for (int i = 0; i < 3; i++)
		cout << names[i] << endl;
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

void MyArrayDemo() {
	MyArray<int, 2> myArray;
	myArray[0] = 25;
	myArray[1] = 6;

	cout << myArray[0] << endl << myArray[1] << endl;

	MyArray<int, 2> myArray2;
	myArray2[0] = 1025;
	myArray2[1] = 602;

	cout << myArray2[0] << endl << myArray2[1];
}
