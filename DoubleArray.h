#pragma once
#include <iostream>
using namespace std;

/*
*@brief ����� "������ �������������� �����"
*/
class DoubleArray
{
private:

	int m_size;
	double* array;

public:

	/*
	*@brief �������� ������� � ��������� ������� ������������� �������
	*@param ������ ������ "DoubleArray"
	*/
	void Delete(DoubleArray& obj);

	/*
	*@brief �����������
	*/
	DoubleArray();

	/*
	*@brief ����������� � �����������
	*@param ������ �������
	*@param ������, ��������� �� �������������� �����
	*/
	DoubleArray(int size_, double* array_);
	/*
	*@brief ����������
	*/
	~DoubleArray();
	/*
	*@brief ����������� �����������
	*@param ������ ������ "DoubleArray"
	*/
	DoubleArray(const DoubleArray& obj);
	/*
	*@brief ���������� ��������� = ��� ������ "DoubleArray"
	*@param ������ ������ "DoubleArray"
	*@return ������ ������ "DoubleArray"
	*/
	DoubleArray& operator=(const DoubleArray& obj);
	/*
	*@brief ���������� ��������� + ��� ������ "DoubleArray"
	*@param �������������� �����
	*@return ������ ������ "DoubleArray"
	*/
	DoubleArray operator+(const double number);
	/*
	*@brief ���������� ��������� * ��� ������ "DoubleArray"
	*@param �������������� �����
	*@return ������ ������ "DoubleArray"
	*/
	DoubleArray operator*(const double number);

	/*
	*@brief ���������� ��������� - ��� ������ "DoubleArray"
	*@param �������������� �����
	*@return ������ ������ "DoubleArray"
	*/
	DoubleArray operator-(const double number);

	/*
	*@brief ���������� ��������� / ��� ������ "DoubleArray"
	*@param �������������� �����
	*@return ������ ������ "DoubleArray"
	*/
	DoubleArray operator/(const double number);
	/*
	*@brief ���������, ������ �� ������
	*@return True ��� False
	*/
	bool Empty();
	/*
	*@brief ��������� ������� ������� ������ "DoubleArray"
	*@return ����������� �����
	*/
	int Size();
	/*
	*@brief ���������� ��������� [] ��� ������ "DoubleArray"
	*@param ������ �������� (�������)
	*@return ��������� �� ������� � ������ "DoubleArray"
	*/
	double& operator[](int index);
	/*
	*@brief ��������� ������� � ������� ������ "DoubleArray"
	*/
	void Clear();
	/*
	*@brief ��������� ������� �� ��������� �������
	*@param ����������� ����� (�������)
	*@param ����������� ����� (�������)
	*@return ������ ������ "DoubleArray"
	*/
	DoubleArray Insert(int position, int element);

	/*
	*@brief ���������� ��������� �� ��������� �������
	*@param ������ �������� (�������)
	*@return ��������� �� ������� � ������ "DoubleArray"
	*/
	double& At(int index);

	/*
	*@brief ���������� ��������� �� ������ �������
	*@return ��������� �� ������� � ������ "DoubleArray"
	*/
	double& Front();

	/*
	*@brief ���������� ��������� �� ��������� �������
	*@return ��������� �� ������� � ������ "DoubleArray"
	*/
	double& Back();
};

