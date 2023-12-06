#include <iostream>
#include <set>
#include <vector>

void MySort (std::vector <int> v)
{
    std::set <int> s;
    std::vector <int>::iterator i;
    for (i = v.begin(); i != v.end(); ++i)
    {
        int n = *i;
        s.insert(n);
    }
    std::set <int>::iterator j;
    for (j = s.begin(); j != s.end(); ++j)
    {
        std::cout << *j << std::endl;
    }
}
template <class T1, class T2>
std::set<T1> Difference(std::set <T1> s1, std::set <T2> s2)
{
    std::set <T1> s3;
    typename std::set<T1>::iterator i;
    for (i = s1.begin(); i!= s1.end(); ++i)
    {
        if(!s2.count(*i))
        {
            s3.insert(*i);
        }
    }
    return s3;
}
std::set <int> ALS()
{
    int r; 
    std::set <int> S, u;
    int n;
    while (std::cin >> n)
    {
        r = u.size();
        u.insert(n);
        if (r == u.size())
        {
            S.insert(n);
        }
    }
    return S;
}

int main()
{
    std::vector<int> v {1, 3, 3, 2, 6, 6, 5};
    MySort(v);
    std::set <int> s1 {1, 2, 3};
    std::set <int> s2 {1, 2, 5};
 std::cout <<   Difference(s1,s2).size();
 std::set<int>::iterator i;
 std::set <int> s;
 s = ALS();
 for (i = s.begin(); i != s.end(); ++i)
    {
        std::cout << *i << std::endl;
    }
 
    return 0;
}
