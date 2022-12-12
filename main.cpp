#include <iostream>
#include "DoubleArray.h"
using namespace std;

int main()
{
	DoubleArray test_1;

	double* array;
	array = new double[5];

	for (int i = 0; i < 5; ++i)
		cin >> array[i];

	DoubleArray test_2(5, array);

	test_1 = test_2;

	if (!test_2.Empty())
	{
		test_2 = test_2 + 4;

		test_2 = test_2 * 2;

		test_2 = test_2 - 2;

		test_2 = test_2 / 2;

		cout << test_2.Size() << endl;

		double test = test_2[3];

		cout << test << endl;

		test_2.Clear();

		test_2 = test_2.Insert(2, 10);

		cout << test_2[2] << endl;

		test_2.At(0) += 3;

		cout << test_2.At(3) << endl;

		cout << test_2.Front() << endl;

		cout << test_2.Back() << endl;

		test_2.Push_Back(7.4);

		for (int i = 0; i < test_2.Size(); i++)
			cout << test_2[i] << " ";

		cout << endl;

		test_2.Resize(9);

		for (int i = 0; i < test_2.Size(); i++)
			cout << test_2[i] << " ";

		cout << endl;

		test_2.Resize(4);

		for (int i = 0; i < test_2.Size(); i++)
			cout << test_2[i] << " ";

		cout << endl;

		test_2 = test_1;

		for (int i = 0; i < test_2.Size(); i++)
			cout << test_2[i] << " ";

		cout << endl;

		if(array != nullptr)
			delete[]array;
	}

	return 0;
}
