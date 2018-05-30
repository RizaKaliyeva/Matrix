#include "Matrix.h"

template<typename T>
matrix<T>::matrix()
{
	els = nullptr;
	cols = 0;
	rows = 0;
}

template<typename T> 
inline matrix<T>::matrix(size_t rows, size_t cols, T e)
{
	this->rows = rows;
	this->cols = cols;

	this->els = new T*[rows];
	for (int i = 0; i < rows; i++)
		this->els[i] = new T[cols];

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			this->els[i][j] = e;
}


template<typename T>
matrix<T>::matrix(T * arr, int rows)
{

}


template<typename T>
inline matrix<T>::matrix(const matrix & obj)
{
	this->rows = obj.rows;
	this->cols = obj.cols;
	this->els = new T*[rows];
	for (int i = 0; i < rows; i++)
		this->els[i] = new T[cols];

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			this->els[i][j] = obj.els[i][j];
}

template<typename T> 
matrix<T>::~matrix()
{
	for (int i = 0; i < rows; i++)
		delete[]els[i];
	delete[] els;
}

template<typename T>
istream & operator >> (istream & is, matrix<T>& a)
{
	for (int i = 0; i < a.rows; i++)
	{
		for (int j = 0; j < a.cols; j++)
			is >> a.els[i][j];
	}
	return is;
}

template<typename T> 
ostream & operator<<(ostream & os, matrix<T> a)
{
	for (int i = 0; i < a.rows; i++)
	{
		for (int j = 0; j < a.cols; j++)
			os << a.els[i][j] << "\t";
		os << endl;
	}
	return os;
}


template<typename T>
matrix<T> matrix<T>::operator=(const matrix<T> & obj)
{
	this->rows = obj.rows;
	this->cols = obj.cols;
	this->els = new T*[rows];
	for (int i = 0; i < rows; i++)
		this->els[i] = new T[cols];

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			this->els[i][j] = obj.els[i][j];
	return *this;
}

template<typename T>
matrix<T> matrix<T>::operator+(const matrix<T>& obj)
{
	matrix <T> tmp;

	if (this->rows > obj.rows)
		tmp.rows = this->rows;
	else tmp.rows = obj.rows;

	if (this->cols > obj.cols)
		tmp.cols = this->cols;
	else tmp.cols = obj.cols;

	tmp.els = new T*[tmp.rows];
	for (int i = 0; i < rows; i++)
		tmp.els[i] = new T[tmp.cols];

	for (int i = 0; i < tmp.rows; i++)
	{
		for (int j = 0; j < tmp.cols; j++)
		{
			tmp.els[i][j] = this->els[i][j] + obj.els[i][j];
		}
	}
	return tmp;
}

template<typename T>
matrix<T> matrix<T>::operator+(int a)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j <cols; j++)
			this->els[i][j] += a;
	return *this;
}

template<typename T>
matrix<T> matrix<T>::operator++()
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			this->els[i][j] += 1;
	return *this;
}

template<typename T>
matrix<T> matrix<T>::operator--()
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			this->els[i][j] -= 1;
	return *this;
}