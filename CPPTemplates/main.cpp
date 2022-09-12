#include <iostream>
#include "TemplatesAsPolicy.h"
#include "MyVector.cpp"
#include "MySpecializedVector.cpp"
#include "Complex.cpp"
#include <vector>
#include "MyArray.cpp"

using namespace std;

template<typename P, typename T>
P myFind(P& start, P& beyond, const T& x) {	
	while (start != beyond && *start != x)
		++start;

	return start;
}

void MyVectorDemo();
void FuntionPointerDemo();
void ComplexDemo();
void MyArrayDemo();

int main() {
	//TemplatesAsPolicy t1;
	MyVectorDemo();
	//FuntionPointerDemo();
	//ComplexDemo();
	//MyArrayDemo();
}

void MyVectorDemo() {
	/*MyVector<int> nums(2);
	nums[0] = 23;
	nums[1] = 2;
	cout << nums[0] << endl << nums[1];*/

	/*MyVector<char*> names(3);*/
	/*names[0] = "Ali";
	names[1] = "Rehan";
	names[3] = "Neelam";*/
	/*names.insert("Ali", 0);
	names.insert("Rehan", 1);
	names.insert("Neelam", 2);

	for (int i = 0; i < 3; i++)
		cout << names[i] << endl;*/

	MyVector<int> iv(3);
	iv[0] = 10;
	iv[1] = 20;
	iv[2] = 30;

	MyVector<int> beyond(iv), found(3);
	beyond.setIndex(iv.getSize());
	
	found = myFind(iv, beyond, 20);
	cout << "Index: " << found.getIndex();


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

	MyArray<> myArray2;
	myArray2[0] = 1025;
	myArray2[1] = 602;
	myArray2[7] = 777;

	//myArray and myArray2 are of different types for the compiler

	cout << myArray2[0] << endl << myArray2[1] << endl << myArray2[7];
}
