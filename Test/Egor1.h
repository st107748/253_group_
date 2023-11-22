#include "templateMatrix.h"
Matrix<T> Matrix<T>::Trans()
{
	Matrix<T> B(m, n);//vector<double>
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			B.a[i][j] = a[j][i];
		}
	}
	return B;
}
Matrix<T> Matrix<T>::operator &(Matrix<T> B)
{
	if (m > B.m)
	{
		for (int i = 0; i < B.n; ++i)
		{
			B.a[i].resize(m);
		}
	}
	if (m < B.m)
	{
		for (int i = 0; i < n; ++i)
		{
			a[i].resize(B.m);
			m = B.m;
		}
	}

	Matrix<T> C(n + B.n, m);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			C.a[i][j] = a[i][j];
		}
	}
	for (int i = n; i < n + B.n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			C.a[i][j] = B.a[i - n][j];
		}
	}
	return C;
}
Matrix<T> Matrix<T>::RowChange(int i, int j)
{
	std::vector <double> v;
	v = a[i];
	std::vector <double> u;
	u = a[j];
	Matrix C(n, m);
	C.a.resize(n);
	for (int k = 0; k < n; ++k)
	{
		C.a[i].resize(m);
		if (k != i && k != j)
		{
			for (int s = 0; s < m; ++s)
			{
				C.a[k][s] = a[k][s];

			}

		}
		if (k == i)
		{
			for (int s = 0; s < m; ++s)
			{
				C.a[k][s] = u[s];
			}
		}
		if (k == j)
		{
			for (int s = 0; s < m; ++s)
			{
				C.a[k][s] = v[s];
			}
		}
	}
	return C;
}
#pragma once
