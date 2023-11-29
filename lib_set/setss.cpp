#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

template <class T>
vector<vector<T> > subsets(unordered_set <T> S)
{
    vector<vector<T> > res;
    vector <T> Vs;
    for (auto i : S)
    {
        Vs.push_back(i);
    }
    int n = S.size();

    for (int i = 0; i < (1 << n); ++i)
    {
        cout<< "hey" << endl;
        vector <T> subs;
        subs.clear();
        for (int j = n - 1; j >= 0; --j)
        {
            if ((i >> j) & 1)
            {
                subs.push_back(Vs[j]);
            }
        }
        res.push_back(subs);
    }
    return res;
}
int main(int argc, char **argv)
{
    unordered_set <int> A;
    A.insert(1);
    A.insert(2);
    A.insert(3);
    vector <vector <int> > AA;
    AA = subsets(A);
    for (vector <int> aa : AA)
    {
        cout << "set: ";
        for (auto a: aa)
        {
            cout << a << " ";
        }
        cout << endl;

    }
    return 0;
}
