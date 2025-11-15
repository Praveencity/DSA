#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

string post2Pre(string s)
{
    stack<string> pre;
    int i = 0;
    int n = s.length();
    while(i<n)
    {   
        if(isalnum(s[i])) pre.push(string(1,s[i]));
        else
        {
            string t1 = pre.top(); pre.pop();
            string t2 = pre.top(); pre.pop();
            pre.push(string(1,s[i]) + t2 + t1);
        }
        i++;
    }
    return pre.top();
}

int main()
{
    string post_exp = "ABC/-AK/L-*";
    cout << "Prefix : " << post2Pre(post_exp);
    return 0;
}