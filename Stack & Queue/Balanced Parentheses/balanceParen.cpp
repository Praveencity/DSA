#include <iostream>
#include <string>
#include <stack>

bool balanceParan(std::string s)
{
    std::stack<char> st;
    int i = 0;
    int n = s.length();
    while (i < n)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty())
                return false;
            char ch = st.top();
            if (s[i] == ')' && ch == '(' || s[i] == '}' && ch == '{' || s[i] == ']' && ch == '[')
            {
                st.pop();
            }
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
    std::string s = "[[]{()}]";

    if (balanceParan(s))
        std::cout << "Balanced\n";
    else
        std::cout << "Not Balanced\n";

    return 0;
}