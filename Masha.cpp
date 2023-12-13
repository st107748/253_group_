#include <iostream>
#include<set>
#include <vector>
using namespace std;
void mysort(set<int> s)
{
    int n;
   
    set<int>::iterator i;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;
        s.insert(k);
    }
    for (i = s.begin(); i != s.end(); ++i)
    {
        cout << *i << " ";
        
    }
    
}
template <class T, class T1>
void mysort2(set<T> s, set <T1> s1)
{
    int n;
    set<T1> s2;
    typename set<T>::iterator i;
    
    for (i = s1.begin(); i != s1.end(); ++i)
    
    {
        s2.insert(*i);
    }
    for (i = s.begin(); i != s.end(); ++i)
    
    {
        s2.insert(*i);
    }
    for (i = s2.begin(); i != s2.end(); ++i)
    {
        cout << *i << " ";
        
    }
    
}
 
 