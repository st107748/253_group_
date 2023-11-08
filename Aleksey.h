Matrix operator*(const Matrix& b);
Matrix operator^(const Matrix& b);
friend std::ostream& operator << (std::ostream& st, Matrix& a);
friend std::istream& operator >> (std::istream& st, Matrix& a);