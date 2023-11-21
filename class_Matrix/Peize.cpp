#include "Matrix.h"

bool Matrix::luDecomposition(Matrix& L, Matrix& U)
{
    if (n < m)
    {
        std::cout << "LU decomposition is not possible for the given matrix." << std::endl;
        return false;
    }

    Matrix lower;
    Matrix upper;

    lower.n = n, lower.m = m;
    upper.n = upper.m = m;

    lower.a.resize(n);
    for (int i = 0; i < n; ++i)
        lower.a[i].resize(m);

    upper.a.resize(m);
    for (int i = 0; i < m; ++i)
        upper.a[i].resize(m);

    // Decomposition
    for (int i = 0; i < m; i++)
    {
        // Upper Triangular
        for (int k = i; k < m; k++)
        {
            // Summation of L(i, j) * U(j, k)
            double sum = 0;
            for (int j = 0; j < i; j++)
                sum += (lower.a[i][j] * upper.a[j][k]);

            // Evaluating U(i, k)
            upper.a[i][k] = a[i][k] - sum;
        }

        // Lower Triangular
        for (int k = i; k < n; k++)
        {
            if (i == k)
                lower.a[i][i] = 1; // Diagonal as 1
            else
            {
                // Summation of L(k, j) * U(j, i)
                double sum = 0;
                for (int j = 0; j < i; j++)
                    sum += (lower.a[k][j] * upper.a[j][i]);

                // Evaluating L(k, i)
                lower.a[k][i] = (a[k][i] - sum) / upper.a[i][i];
            }
        }
    }

    // Printing the LU decomposition
    std::cout << "Lower Triangular Matrix (L):" << std::endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            std::cout << lower.a[i][j] << "\t";
        std::cout << std::endl;
    }

    std::cout << "Upper Triangular Matrix (U):" << std::endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++)
            std::cout << upper.a[i][j] << "\t";
        std::cout << std::endl;
    }

    L = lower;
    U = upper;
    return true;
}
