#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

/*
 * ===================================================================
 * Program: Prefix to Postfix Conversion
 * Approach:
 * This program converts a prefix (Polish Notation) expression
 * to its equivalent postfix (Reverse Polish Notation) expression.
 *
 * 1. It uses a stack of strings (std::stack<string>).
 * 2. It iterates through the prefix string from RIGHT to LEFT.
 * 3. Operands (letters/numbers) are converted to strings and
 * pushed onto the stack.
 * 4. Operators pop the top two operands (op1, then op2),
 * combine them into a new postfix string: "op1 + op2 + operator",
 * and push the new string back onto the stack.
 * 5. The final item on the stack is the complete postfix expression.
 * ===================================================================
 */

string pre2Post(string s)
{
    stack<string> post;
    int n = s.length() - 1;
    while(n>=0)
    {
        if(isalnum(s[n])) post.push(string(1,s[n]));
        else
        {
            string t1 = post.top(); post.pop();
            string t2 = post.top(); post.pop();
            post.push(t1 + t2 + string(1,s[n]));
        }
        n--;
    }
    return post.top();
} 

int main()
{
    string pre_exp = "*-A/BC-/AKL";
    cout << "Postfix : " << pre2Post(pre_exp);
    return 0;
}