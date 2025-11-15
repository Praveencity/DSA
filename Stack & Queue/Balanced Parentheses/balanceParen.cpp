#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool balanceParan(string s)
{
    stack<char> st;
    int i = 0;
    int n = s.length();
    while (i < n)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);
        else
        {
            if (st.empty())
                return false;
            char ch = st.top();
            if (s[i] == ')' && ch == '(' || s[i] == '}' && ch == '{' || s[i] == ']' && ch == '[')
                st.pop();
            else
                return false;
        }
        i++;
    }
    if (st.empty())
        return true;
    return false;
}

int main()
{
    string s = "[[]{()}]";

    if (balanceParan(s))
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";

    return 0;
}