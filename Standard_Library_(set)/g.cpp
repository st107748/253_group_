#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <map>

using namespace std;

template <class T1>
T1 f(T1 x)
{
    return (x > 0) ? (x) : (-x);
}

 
int main()
{
    unordered_set<int> o;
    o.insert(-1), o.insert(1);
    
    return 0;
}
