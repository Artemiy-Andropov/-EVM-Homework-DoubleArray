#include <iostream>
#include "DoubleArray.h"
using namespace std;

void DoubleArray::Delete(DoubleArray& obj)
{
	if (obj.array != nullptr)
		delete[] obj.array;
	obj.m_size = 0;
}
DoubleArray::DoubleArray()
{
	m_size = 0;
	array = nullptr;
}
DoubleArray::DoubleArray(int size_, double* array_)
{
	if (size_ <= 0)
	{
		array = nullptr;
		return;
	}

	m_size = size_;
	array = new double[m_size];

	for (int i = 0; i < m_size; ++i)
		array[i] = array_[i];
}
DoubleArray::~DoubleArray()
{
	Delete(*this);
}
DoubleArray::DoubleArray(const DoubleArray& obj)
{
	if (obj.m_size == 0)
	{
		array = nullptr;
		m_size = 0;
		return;
	}
	
	m_size = obj.m_size;
	array = new double[m_size];

	for (int i = 0; i < m_size; ++i)
		array[i] = obj.array[i];
}

DoubleArray &DoubleArray::operator=(const DoubleArray& obj)
{
	if (obj.m_size == 0)
	{
		array = nullptr;
		m_size = 0;
		return *this;
	}
	delete[]array;
	m_size = obj.m_size;
	array = new double[m_size];

	for (int i = 0; i < m_size; ++i)
		array[i] = obj.array[i];
	return *this;
}

DoubleArray DoubleArray::operator+(const double number) 
{
	for (int i = 0; i < m_size; ++i)
		array[i] += number;
	return *this;
}
DoubleArray DoubleArray::operator*(const double number)
{
	for (int i = 0; i < m_size; ++i)
		array[i] *= number;
	return *this;
}
DoubleArray DoubleArray::operator-(const double number)
{
	for (int i = 0; i < m_size; ++i)
		array[i] -= number;
	return *this;
}
DoubleArray DoubleArray::operator/(const double number)
{
	for (int i = 0; i < m_size; ++i)
		array[i] /= number;
	return *this;
}

bool DoubleArray::Empty()
{
	return (m_size == 0);
}
int DoubleArray::Size()
{
	return(m_size);
}

double& DoubleArray::operator[](int index)
{
	try
	{
		if (index >= m_size)
			throw 1;
		else
			return array[index];
	}
	catch(int)
	{
		cout << "Error. There is no element at this index" << endl;
	}
}

void DoubleArray::Clear()
{
	if (array != nullptr)
	{
		for (int i = 0; i < m_size; ++i)
			array[i] = 0;
	}
}

DoubleArray DoubleArray::Insert(int position, double element)
{
	if (position >= m_size || position < 0)
	{
		cout << "Error. There is no element at this index" << endl;

		return *this;
	}
	else
	{
		double* copy = new double[m_size];
		for (int i = 0; i < m_size; i++)
			copy[i] = array[i];
		delete[]array;
		m_size++;
		array = new double[m_size];
		int i = 0;
		for (; i < position; i++)
			array[i] = copy[i];
		array[position] = element;
		for (; i < m_size-1; i++)
			array[i+1] = copy[i];
		delete[]copy;
		return *this;
	}
}

double& DoubleArray::At(int index)
{
	try
	{
		if (index >= m_size)
			throw 1;
		else
			return array[index];
	}
	catch (int)
	{
		cout << "Error. There is no element at this index" << endl;
	}
}

double& DoubleArray::Front()
{
	return array[0];
}

double& DoubleArray::Back()
{
	return array[m_size-1];
}

void DoubleArray::Push_Back(double element)
{
	m_size++;
	double* copy = new double[m_size];
	for (int i = 0; i < m_size - 1; i++)
		copy[i] = array[i];
	delete[]array;
	array = new double[m_size];
	for (int i = 0; i < m_size - 1; i++)
		array[i] = copy[i];
	array[m_size - 1] = element;
	delete[]copy;
}

void DoubleArray::Resize(int size)
{
	if (size == m_size)
		return;
	if (size < 0)
	{
		cout << "Error. The entered size is less than 0. The array will be deleted." << endl;
		if(array != nullptr)
			delete[]array;
		m_size = 0;
		array = nullptr;
		return;
	}

	double* copy = new double[m_size];

	if (size > m_size)
	{
		for (int i = 0; i < m_size; i++)
			copy[i] = array[i];
		delete[]array;
		array = new double[size];
		for (int i = 0; i < size; i++)
		{
			if (i >= m_size)
				array[i] = 0;
			else
				array[i] = copy[i];
		}
		m_size = size;
	}
	else
	{
		for (int i = 0; i < size; i++)
			copy[i] = array[i];
		delete[]array;
		m_size = size;
		array = new double[size];
		for (int i = 0; i < size; i++)
			array[i] = copy[i];
	}
	delete[]copy;
}

void DoubleArray::Erase(int start, int end)
{
	try
	{
		if (end < start)
			throw 1;
		if (start < 0)
			throw 1;
		if (end >= m_size)
			throw 1;
		int size = m_size - ((end - start) + 1);
		if (size == 0)
		{
			m_size = 0;
			delete[]array;
		}
		double* copy = new double[size];
		for (int i = 0; i < m_size; i++)
		{
			if (i >= start && i <= end)
				continue;
			copy[i] = array[i];
		}
		delete[]array;
		array = new double[size];
	}
	catch(int)
	{
		cout << "Error. The parameters are set incorrectly." << endl;
		return;
	}
}
