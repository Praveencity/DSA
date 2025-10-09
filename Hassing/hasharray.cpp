#include <bits/stdc++.h>
using namespace std;

const int N = 1e7+5; //const is must
int freqInt[N]; // Global : 1e7   Local : 1e5
int freqChar[27];
int freqAllChar[256];

int main()
{
    // FOR INTEGER USING ARRAY
    int arrInt[10] = {1,2,4,4,5,2,4,5,5};


    //PreCompute
    for(int i : arrInt)
    {
        freqInt[i]++;
    }

    
    int t1; cin >> t1;
    while(t1--)
    {
        int a; cin >> a;

        if(freqInt[a] == 0) 
            cout << a << " -> Not exist" << endl;
        else 
            cout << a << " -> " << freqInt[a] << endl;
    }

    cout << "-----------------------------------" << endl;

    //  FOR STRING USING ARRAY
    string s = "abhdbds";

    // FOR LOWERCASE ONLY
    for(char i : s)
    {
        freqChar[i - 97]++;
    }

    int t2; cin >> t2;
    while(t2--)
    {
        char a; cin >> a;

        if(freqChar[a - 97] == 0) 
            cout << a << " -> Not exist" << endl;
        else 
            cout << a << " -> " << freqChar[a - 97] << endl;
    }

    cout << "-----------------------------------" << endl;

    //FOR ALL CHARACTER
    string str = "aAVUcjns%^&&^*?>";

    for(char i : str)
    {
        freqAllChar[i]++;
    }
    
    int t3; cin >> t3;
    while(t3--)
    {
        char a; cin >> a;

        if(freqAllChar[a] == 0) 
            cout << a << " -> Not exist" << endl;
        else 
            cout << a << " -> " << freqAllChar[a] << endl;
    }
}