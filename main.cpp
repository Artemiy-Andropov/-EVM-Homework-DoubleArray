#include <iostream>
#include "DoubleArray.h"
#include "Exception.h"
using namespace std;

int main()
{
	try
	{
		//
		DoubleArray test_1;

		DoubleArray test_2;

		cin >> test_2;

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

			cout << test_2 << endl;

			test_2.Resize(9);

			cout << test_2 << endl;

			test_2.Resize(4);

			cout << test_2 << endl;

			test_2 = test_1;

			cout << test_2 << endl;

			test_2.Erase(0, 4);

			cout << test_2 << endl;
		}
	}
	catch (ArrayException& exception_)
	{
		std::cerr << "An exception occurred at array (" << exception_.GetError() << ") " << "Error code: " << exception_.GetCodeError() << std::endl;
	}
	return 0;
}