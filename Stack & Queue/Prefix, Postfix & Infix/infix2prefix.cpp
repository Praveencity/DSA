#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>

int priority(char ch)
{
    int pno = -1;
    if(ch == '^') pno = 3;
    else if(ch == '*' || ch == '/') pno = 2;
    else if(ch == '+' || ch == '-') pno = 1;
    return pno;
}

std::string infix2Prefix(std::string s)
{
    std::stack<char> st;
    std::string prefix;
    int n = s.length() - 1;
    while(0<=n)
    {
        if(isalnum(s[n]))
        {
            prefix += s[n];
        }
        else
        {
            if(s[n] == ')')
            {
                st.push(s[n]);
            }
            else if(s[n] == '(')
            {
                    // if input is wrong.
                while(!st.empty() && st.top() != ')')
                {
                    prefix += st.top();
                    st.pop();
                }
                if(!st.empty()) st.pop();
            }
            else
            {
                if(s[n] == '^') // For right-associative operators (^) 	a ^ b ^ c → a ^ (b ^ c)

                {
                   while(!st.empty() && priority(s[n]) == priority(st.top()))
                    {
                        prefix += st.top();
                        st.pop();
                    } 
                }
                else
                {
                                                     // <= Not here.
                    while(!st.empty() && priority(s[n]) < priority(st.top()))
                    {
                        prefix += st.top();
                        st.pop();
                    }
                }                             
                st.push(s[n]);
            }
        }
        n--;
    }
    while(!st.empty())
    {
        prefix += st.top();
        st.pop();
    }

    std::reverse(prefix.begin(),prefix.end()); // O(N) & O(1) Time and Space Complexity
    return prefix;
}

int main()
{
    std::string expr = "a+b*(c^d-e)^(f+g*h)-i";
    std::string result = infix2Prefix(expr);
    std::cout << "Prefix: " << result << std::endl;
}