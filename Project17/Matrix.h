#pragma once
#include"Library.h"
template <typename T>
class matrix {
	T** els;
	size_t rows;
	size_t cols;

public:
	matrix();
	matrix(size_t rows, size_t cols, T e = 0);
	matrix(T*arr, int rows);
	matrix(const matrix &obj);
	~matrix();

	template<typename T>
	friend istream &operator >> (istream &is, matrix<T> & a);
	template<typename T>
	friend ostream &operator <<(ostream &os, matrix<T> a);

	matrix operator=(const matrix <T> &obj);
	matrix operator+(const matrix <T> &obj);
	matrix operator+(int a);
	matrix operator++();
	matrix operator--();
};