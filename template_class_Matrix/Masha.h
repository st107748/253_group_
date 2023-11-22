
 
vector<T> operator* (const vector<T>& v1);
     
 
Matrix operator| (const Matrix& b);
    
 
T MatrixNorm() const;
    
 
};

template<class T>
vector<T> Matrix<T>::operator* (const vector<T>& v1)
    {
        if (this->m != v1.size())
        {
            cout << "error";
            return v1;
        }
 
        else
        {
            vector<T> v2(this->n);
            for (int i = 0; i < this->n; ++i)
            {
                for (int j = 0; j < this->m; ++j)
                {
                    v2[i] += this->a[i][j] * v1[j];
                }
            }
            return v2;
        }
 
    }
    Matrix Matrix<T>::operator| (const Matrix& b)
    {
        Matrix c;
        T h;
        T k;
        h = max(this->n, b.n);
 
        k = this->m + b.m;
        c.n = h;
        c.m = k;
        c.a.resize(h);
        for (int i = 0; i < h; ++i)
        {
            c.a[i].resize(k);
        }
 
        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < k; ++j)
            {
                if (i < this->n && j < this->m)
                {
                    c.a[i][j] = this->a[i][j];
                }
                if (i >= this->n && j < this->m)
                {
                    c.a[i][j] = 0;
                }
                if (i < b.n && j >= this->m)
                {
                    c.a[i][j] = b.a[i][j - this->m];
                }
                if (i > b.n && j >= this->m)
                {
                    c.a[i][j] = 0;
                }
            }
        }
        return c;
    }
T Matrix<T>::MatrixNorm() const
    {
 
        T max = -1;
 
        for (int i = 0; i < n; ++i)
        {
            T ti = 0;
            for (int j = 0; j < m; ++j)
            {
 
                ti += abs(this->a[i][j]);
 
            }
            if (max < ti)
            {
                max = ti;
            }
        }
        return max;
 
    }
