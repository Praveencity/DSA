#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

/*
 * ===================================================================
 * Program: Postfix to Prefix Conversion
 * Approach:
 * This program converts a postfix (Reverse Polish Notation)
 * expression to its equivalent prefix (Polish Notation) expression.
 *
 * 1. It uses a stack of strings (stack<string>).
 * 2. It iterates through the postfix string from LEFT to RIGHT.
 * 3. Operands (letters/numbers) are converted to strings and
 * pushed onto the stack.
 * 4. Operators pop the top two operands (op2, then op1),
 * combine them into a new prefix string: "operator + op1 + op2",
 * and push the new string back onto the stack.
 * 5. The final item on the stack is the complete prefix expression.
 * ===================================================================
 */

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