#pragma once

#include <iostream>
#include <vector>  

using namespace std;

template <class T>
class Matrix;  // объ€вление шаблонного класса  Matrix,
// потребовалось дл€ функций operator << и operator >>,
// не €вл€ющимис€ методами


template <class T>
std::ostream& operator << (std::ostream& st, Matrix<T>& a);

template <class T>
std::istream& operator >> (std::istream& st, Matrix<T>& a);


template <class T>
class Matrix
{
private:
	int n; // number of rows
	int m; // number of columns  
	vector <vector<T>> a;

public:

	Matrix(int n_ = 0, int m_ = 0) : n(n_), m(m_),
		a(n_, vector<double>(m_, 0)) {}

	T& operator () (int i, int j);
	Matrix<T> operator*(const Matrix<T>& b);
	Matrix<T> operator^(const Matrix<T>& b);

	Matrix<T> Trans();
	Matrix<T> operator &(Matrix<T> B);
	Matrix<T> RowChange(int i, int j);

	vector<T> operator* (const vector<T>& v1);
	Matrix<T> operator| (const Matrix<T>& b);
	double MatrixNorm() const;

	bool luDecomposition(Matrix<T>& L, Matrix<T>& U);


	friend std::ostream& operator << <>(std::ostream& st, Matrix<T>& a);
	// operator << -- шаблонна€ функци€ 
	friend std::istream& operator >> <>(std::istream& st, Matrix<T>& a);

};