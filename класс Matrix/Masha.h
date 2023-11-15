#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;
class Matrix
{

void Matrix::GetMatrix();
vector<double> Matrix::operator* (const vector<double>& v1);
Matrix Matrix::operator| (const Matrix& b);
double Matrix::MatrixNorm() const;
};