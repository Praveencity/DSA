#include <bits/stdc++.h>
using namespace std;

/*
 * ===================================================================
 * Program: Postfix to Infix Conversion
 * Approach:
 * This program converts a postfix (Reverse Polish Notation)
 * expression to its equivalent infix expression.
 *
 * 1. It uses a stack of strings (stack<string>).
 * 2. It iterates through the postfix string from left to right.
 * 3. Operands (letters/numbers) are converted to strings and
 * pushed onto the stack.
 * 4. Operators pop the top two operands (right, then left),
 * combine them into a new infix string like "(left+op+right)",
 * and push the new string back onto the stack.
 * 5. The final item on the stack is the complete, fully-
 * parenthesized infix expression.
 * ===================================================================
 */

string postfix2Infix(string s)
{
    stack<string> infix;
    int n = s.length();
    int i = 0;
    while(i<n)
    {
        if(isalnum(s[i]))
        {        //Converts char to string.
            infix.push(string(1, s[i])); 
        }
        else
        {
            string right = infix.top(); infix.pop();
            string left = infix.top(); infix.pop();
            infix.push("(" + left + string(1,s[i]) + right + ")");
        }
        i++;
    }
    return infix.top();
}

int main()
{
    string postfix = "ab+cd+*ef+gh+*+";
    cout << "Infix: " << postfix2Infix(postfix) << "\n";
}