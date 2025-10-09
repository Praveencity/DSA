#include <iostream>
#include <string>
#include <stack>
#include <cctype>


std::string post2Pre(std::string s)
{
    std::stack<std::string> pre;
    int i = 0;
    int n = s.length();
    while(i<n)
    {   
        if(isalnum(s[i])) pre.push(std::string(1,s[i]));
        else
        {
            std::string t1 = pre.top(); pre.pop();
            std::string t2 = pre.top(); pre.pop();
            pre.push(std::string(1,s[i]) + t2 + t1);
        }
        i++;
    }
    return pre.top();
}

int main()
{
    std::string post_exp = "ABC/-AK/L-*";
    std::cout << "Prefix : " << post2Pre(post_exp);
    return 0;
}