#include"Matrix.h"

Matrix::Matrix operator*(const Matrix& b)
{
    if (this->m != b.n)
    {
        std::cout << "multiplication error";
        return *this;
    }
    
    
    else 
    
    {
        Matrix c;
    c.n = this->n;
    c.m = b.m;
    c.a.resize(n);
    for (int i = 0; i <= n - 1; ++i)
    {
        c.a[i].resize(b.m);
    }
        double q = 0;
        for (int i = 0; i <= this->n - 1; ++i)
        {
            for (int j = 0; j <= b.m - 1; ++j)
            {
                for (int k = 0; k <= this->m - 1; ++k)
                {
                    q += this->a[i][k] * b.a[k][j];
                }
                c.a[i][j] = q;
                q = 0;
            }
        }
        return c;
    }
} 

Matrix::Matrix operator^(const Matrix& b)
{
    Matrix c;
    c.n = this->n + b.n;
    c.m = this->m + b.m;
    c.a.resize(this->n + b.n);
    for (int i = 0; i <= this->n + b.n - 1; ++i)
    {
        c.a[i].resize(b.m + this->m);
    }
    for (int i = 0; i <= this->n - 1; ++i)
    {
        for (int j = 0; j <= this->m - 1; ++j)
        {
            c.a[i][j] = this->a[i][j];
        }
    }
    for (int i = this->n; i <= this->n + b.n - 1; ++i)
    {
        for (int j = this->m; j <= this->m + b.m - 1; ++j)
        {
            c.a[i][j] = b.a[i - this->n][j - this->m];
        }
    }
    return c;
}

std::ostream& operator << (std::ostream& st, Matrix& a)
{
    st << std::endl;
    for (int i = 0; i <= a.n - 1; ++i)
    {
        for (int j = 0; j <= a.m - 1; ++j)
        {
            st << a.a[i][j] << " ";
        }
        st << std::endl;
    }
    return st;
}

std::istream& operator >> (std::istream& st, Matrix& a)
{
    st >> a.n >> a.m;
    std::vector<std::vector<double>> b (a.n);
    for (int i = 0; i <= a.n - 1; ++i)
    {
        b[i].resize(a.m);
        for (int j = 0; j <= a.m - 1; ++j)
        {
            double k;
            st >> k;
            b[i][j] = k;
        }
    }
    a.a = b;
    return st;  
}
