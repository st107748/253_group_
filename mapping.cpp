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

template <class T1>
bool check(unordered_set<T1> opr)
{
    map <T1, T1> M;
    M.clear();
    for (auto t : opr)
    {

        if (M.find(f(t)) == M.end())
        {
            M[f(t)] = t;
        }
        else
        {
            if (M[f(t)] != t)
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    unordered_set<int> o;
    o.insert(-1), o.insert(1);
    cout << check(o) << endl;
    return 0;
}
