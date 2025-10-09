#include <iostream>
#include <string>
#include <cctype>
#include <stack>

std::string prefix2Infix(std::string s)
{
    std::stack<std::string> infix;
    int n = s.length() - 1;
    while(n>=0)
    {
        if(isalnum(s[n])) infix.push(std::string(1,s[n]));
        else
        {
            std::string t1 = infix.top(); infix.pop();
            std::string t2 = infix.top(); infix.pop();
            infix.push("(" + t1 + std::string(1,s[n]) + t2 + ")");
        }
        n--;
    }
    return infix.top();
}

int main()
{
    std::string pre_exp = "*-A/BC-/AKL";
    std::cout << "Infix : " << prefix2Infix(pre_exp);
    return 0;
}