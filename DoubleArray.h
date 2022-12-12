#pragma once
#include <iostream>
using namespace std;

/*
*@brief Класс "Массив действительных чисел"
*/
class DoubleArray
{
private:

	int m_size;
	double* array;

public:

	/*
	*@brief Удаление массива и обнуление размера передаваемого объекта
	*@param Объект класса "DoubleArray"
	*/
	void Delete(DoubleArray& obj);

	/*
	*@brief Конструктор
	*/
	DoubleArray();

	/*
	*@brief Конструктор с параметрами
	*@param Размер массива
	*@param Массив, состоящий из действительных чисел
	*/
	DoubleArray(int size_, double* array_);
	/*
	*@brief Деструктор
	*/
	~DoubleArray();
	/*
	*@brief Конструктор копирования
	*@param Объект класса "DoubleArray"
	*/
	DoubleArray(const DoubleArray& obj);
	/*
	*@brief Перегрузка оператора = для класса "DoubleArray"
	*@param Объект класса "DoubleArray"
	*@return Объект класса "DoubleArray"
	*/
	DoubleArray& operator=(const DoubleArray& obj);
	/*
	*@brief Перегрузка оператора + для класса "DoubleArray"
	*@param Действительное число
	*@return Объект класса "DoubleArray"
	*/
	DoubleArray operator+(const double number);
	/*
	*@brief Перегрузка оператора * для класса "DoubleArray"
	*@param Действительное число
	*@return Объект класса "DoubleArray"
	*/
	DoubleArray operator*(const double number);

	/*
	*@brief Перегрузка оператора - для класса "DoubleArray"
	*@param Действительное число
	*@return Объект класса "DoubleArray"
	*/
	DoubleArray operator-(const double number);

	/*
	*@brief Перегрузка оператора / для класса "DoubleArray"
	*@param Действительное число
	*@return Объект класса "DoubleArray"
	*/
	DoubleArray operator/(const double number);
	/*
	*@brief Проверяет, пустой ли массив
	*@return True или False
	*/
	bool Empty();
	/*
	*@brief Получение размера объекта класса "DoubleArray"
	*@return Натуральное число
	*/
	int Size();
	/*
	*@brief Перегрузка оператора [] для класса "DoubleArray"
	*@param Индекс элемента (Позиция)
	*@return Указатель на элемент в классе "DoubleArray"
	*/
	double& operator[](int index);
	/*
	*@brief Отчищение массива в объекте класса "DoubleArray"
	*/
	void Clear();
	/*
	*@brief Вставляет элемент на выбранную позицию
	*@param Натуральное число (Позиция)
	*@param Натуральное число (Элемент)
	*@return Объект класса "DoubleArray"
	*/
	DoubleArray Insert(int position, int element);

	/*
	*@brief Возвращает указатель на выбранный элемент
	*@param Индекс элемента (Позиция)
	*@return Указатель на элемент в классе "DoubleArray"
	*/
	double& At(int index);

	/*
	*@brief Возвращает указатель на первый элемент
	*@return Указатель на элемент в классе "DoubleArray"
	*/
	double& Front();

	/*
	*@brief Возвращает указатель на последний элемент
	*@return Указатель на элемент в классе "DoubleArray"
	*/
	double& Back();
};

