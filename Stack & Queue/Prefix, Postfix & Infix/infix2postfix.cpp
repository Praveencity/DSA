#include <iostream>
#include <string>
#include <stack>

int priority(char ch)
{
    int pno = -1;
    if(ch == '^') pno = 3;
    else if(ch == '*' || ch == '/') pno = 2;
    else if(ch == '+' || ch == '-') pno = 1;
    return pno;
}

std::string infix2Postfix(std::string s)
{
    std::stack<char> st;
    std::string postfix;
    int n = s.length();
    int i = 0;
    while(i<n)
    {
            // Can use isalnum(s[i]) here using file <cctype> 
        if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z' || s[i]>='0' && s[i]<='9')
        {
            postfix += s[i];
        }
        else
        {
            if(s[i] == '(')
            {
                 st.push(s[i]);
            }
            else if(s[i] == ')')
            {
                    // if input is wrong
                while(!st.empty() && st.top() != '(')
                {
                    postfix += st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                while(!st.empty() && priority(s[i]) <= priority(st.top()) )
                {
                    postfix += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        i++;
    }

    while(!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main()
{
    std::string expr = "a+b*(c^d-e)^(f+g*h)-i";
    std::string result = infix2Postfix(expr);
    std::cout << "Postfix: " << result << std::endl;
}