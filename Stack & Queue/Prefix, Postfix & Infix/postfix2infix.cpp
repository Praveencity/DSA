#include <iostream>
#include <string>
#include <stack>
#include <cctype>

std::string postfix2Infix(std::string s)
{
    std::stack<std::string> infix;
    int n = s.length();
    int i = 0;
    while(i<n)
    {
        if(isalnum(s[i]))
        {
                    //Converts char to string.
            infix.push(std::string(1, s[i])); 
        }
        else
        {
            std::string right = infix.top(); infix.pop();
            std::string left = infix.top(); infix.pop();
            infix.push("(" + left + std::string(1,s[i]) + right + ")");
        }
        i++;
    }
    return infix.top();
}

int main()
{
    std::string postfix = "ab+cd+*ef+gh+*+";
    std::cout << "Infix: " << postfix2Infix(postfix) << "\n";
}