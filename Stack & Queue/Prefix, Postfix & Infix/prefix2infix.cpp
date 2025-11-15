#include <iostream>
#include <string>
#include <cctype>
#include <stack>
using namespace std;

/*
 * ===================================================================
 * Program: Prefix to Infix Conversion
 * Approach:
 * This program converts a prefix (Polish Notation) expression
 * to its equivalent infix expression.
 *
 * 1. It uses a stack of strings (stack<string>) to hold
 * operands and intermediate infix sub-expressions.
 * 2. It iterates through the prefix string from RIGHT to LEFT.
 * 3. Operands (letters/numbers) are converted to strings and
 * pushed onto the stack.
 * 4. Operators pop the top two operands (which, due to the
 * right-to-left scan, are the 'left' and then 'right' operands
 * for the infix expression).
 * - The first pop (t1) is the LEFT operand.
 * - The second pop (t2) is the RIGHT operand.
 * 5. A new string is formed: "(" + t1 + operator + t2 + ")"
 * (e.g., "(A+B)") and pushed back onto the stack.
 * 6. The final item on the stack is the complete, fully-
 * parenthesized infix expression.
 * ===================================================================
 */


string prefix2Infix(string s)
{
    stack<string> infix;
    int n = s.length() - 1;
    while(n>=0)
    {
        if(isalnum(s[n])) infix.push(string(1,s[n]));
        else
        {
            // First pop is the left operand
            string t1 = infix.top(); infix.pop();
            // Second pop is the right operand
            string t2 = infix.top(); infix.pop();
            // Combine as (left op right)
            infix.push("(" + t1 + string(1,s[n]) + t2 + ")");
        }
        n--;
    }
    return infix.top();
}

int main()
{
    string pre_exp = "*-A/BC-/AKL";
    cout << "Infix : " << prefix2Infix(pre_exp);
    return 0;
}