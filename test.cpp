#include <iostream>

struct Complex 
{
    double re, im;
    double abs() const 
    { return sqrt(re * re + im * im); }
};

void f(const Complex& z)
{
    cout << z.abs();
}// OK!

// константный метод
// 1) не пытается менять поля объекта
// 2) ключевое слово const в конце заголовка

struct Complex {
    double re, im;
    double abs() const {
        re = re;
        return sqrt(re * re + im * im);
    }
};

struct Complex {
    double re, im;
    double abs() const {
        if (0 == 1) re = 0;
        return sqrt(re * re + im * im);
    }
};

int main() { 
  return 0;
}
