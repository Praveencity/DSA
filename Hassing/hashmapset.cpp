#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<int,int> m;
    vector<int> v = {1,1,3,5,4,6,3,4};

    for(auto &i:v)
    {
        m[i]++;
    }

    int t; cin >> t;
    while(t--)
    {
        int x; cin >> x;
        if(m.find(x) != m.end()) 
            cout << x << " -> " << m[x] << endl;
        else 
            cout << x << " -> Not Exists" << endl;
    }

    cout << "---------------------------------------------" << endl;

    unordered_set<char> s;
    string str = "Thisisme";

    for(auto &i:str) s.insert(i);

    int t2; cin >> t2;
    while(t2--)
    {
        char ch; cin >> ch;
        if(s.find(ch) != s.end())  //Average case O(1)
            cout << "It Exists" << endl;
        else
            cout << "Not Exists" << endl;
    }
}