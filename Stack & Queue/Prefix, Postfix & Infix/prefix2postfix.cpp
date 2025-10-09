#include <iostream>
#include <stack>
#include <string>
#include <cctype>

std::string pre2Post(std::string s)
{
    std::stack<std::string> post;
    int n = s.length() - 1;
    while(n>=0)
    {
        if(isalnum(s[n])) post.push(std::string(1,s[n]));
        else
        {
            std::string t1 = post.top(); post.pop();
            std::string t2 = post.top(); post.pop();
            post.push(t1 + t2 + std::string(1,s[n]));
        }
        n--;
    }
    return post.top();
} 

int main()
{
    std::string pre_exp = "*-A/BC-/AKL";
    std::cout << "Postfix : " << pre2Post(pre_exp);
    return 0;
}