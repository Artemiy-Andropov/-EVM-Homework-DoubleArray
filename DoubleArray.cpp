#include <iostream>
#include "DoubleArray.h"
#include "Exception.h"
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
	if (index >= m_size || index < 0)
		throw ArrayException("Error. Invalid input. This position is not in the array.");
	else
		return array[index];
}

ostream& operator<<(ostream& out, const DoubleArray& obj)
{
	if (obj.m_size == 0)
		return out;
	for (int i = 0; i < obj.m_size; i++)
		out << obj.array[i] << " ";
	return out;
}

istream& operator>>(istream& in, DoubleArray& obj)
{
	try
	{
		while (in.peek() == ' ')
			in.ignore();

		if (in.peek() != '[')
			throw ArrayException("Invalid first character. Here it was expected '[' .");
		else
			in.ignore();

		if (in.peek() == ']')
		{
			in.ignore();
			if (!obj.Empty())
				delete[]obj.array;
			obj.m_size = 0;
			obj.array = nullptr;
			return in;
		}

		int size = 100;
		double* array_ = new double[size];
		int count = 0;

		while (true)
		{
			double data;
			in >> data;
			if (in.fail())
			{
				delete[]array_;
				throw ArrayException("Invalid character. Here a real number was expected.");
			}
			array_[count] = data;
			count++;
			if (count == size) //На случай, если пользователь ввел больше 100 элементов
			{
				size *= 3;
				double* copy = new double[count];
				for (int i = 0; i < count; i++)
					copy[i] = array_[i];
				delete[]array_;
				array_ = new double[size];
				for (int i = 0; i < count; i++)
					array_[i] = copy[i];
				delete[]copy;
			}

			if (in.peek() == ']')
			{
				in.ignore();
				obj.m_size = count;
				if (!obj.Empty())
					delete[]obj.array;
				obj.array = new double[count];
				for (int i = 0; i < count; i++)
					obj.array[i] = array_[i];
				delete[]array_;
				return in;
			}
			if (in.peek() != ',')
			{
				delete[]array_;
				throw ArrayException("Invalid character.Here it was expected ',' ");
			}
			else
				in.ignore();
		}
	}
	catch (ArrayException& exception_)
	{
		std::cerr << "An exception occurred at array ( " << exception_.GetError() << " )" << std::endl;
		in.setstate(ios::failbit);
		return in;
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
		throw ArrayException("Error. Invalid input. This position is not in the array.");
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
	if (index >= m_size || index < 0)
		throw ArrayException("Error. Invalid input. This position is not in the array.");
	else
		return array[index];
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
	if (end < start)
		throw ArrayException("Error. The parameters are set incorrectly.");
	if (start < 0)
		start = 0;
	if (end >= m_size)
		end = m_size;
	int size = m_size - ((end - start) + 1);
	if (size == 0)
	{
		m_size = 0;
		delete[]array;
		array = nullptr;
		return;
	}
	double* copy = new double[size];
	int count = 0;
	for (int i = 0; i < m_size; i++)
	{
		if (i >= start && i <= end)
			continue;
		copy[count] = array[i];
		count++;
	}
	delete[]array;
	array = new double[size];
	m_size = size;
	for (int i = 0; i < size; i++)
		array[i] = copy[i];
	delete[]copy;
}