#include <bits/stdc++.h>
using namespace std;

/*
 * ===================================================================
 * Program: Infix to Prefix Conversion
 * Approach:
 * This program converts an infix expression to its equivalent prefix
 * expression using a direct, right-to-left scan. This is an
 * adaptation of the Shunting-yard algorithm.
 *
 * 1. It uses a stack of characters (std::stack<char>) for operators.
 * 2. It iterates through the infix string from RIGHT to LEFT.
 * 3. Operands (letters/numbers) are appended directly to the
 * 'prefix' string (which is being built in reverse).
 * 4. Parentheses logic is reversed:
 * - ')' is pushed onto the stack.
 * - '(' triggers a pop of all operators until ')' is found.
 * 5. Operator Precedence: The logic is modified for the reverse scan
 * to maintain correct associativity.
 * - For left-assoc. (*, /, +, -): Pop ops with *higher*
 * precedence.
 * - For right-assoc. (^): Pop ops with *equal* precedence
 * (a special case in this code).
 * 6. Final Step: The resulting 'prefix' string is reversed at the
 * end to get the correct final prefix order.
 * ===================================================================
 */

int priority(char ch)
{
    int pno = -1;
    if(ch == '^') pno = 3;
    else if(ch == '*' || ch == '/') pno = 2;
    else if(ch == '+' || ch == '-') pno = 1;
    return pno;
}

string infix2Prefix(string s)
{
    stack<char> st;
    string prefix;
    int n = s.length() - 1;
    while(0<=n)
    {
        if(isalnum(s[n]))
            prefix += s[n];
        else
        {
            if(s[n] == ')')
                st.push(s[n]);
            else if(s[n] == '(')
            {            // if input is wrong.
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
                {                       // <= Not here.
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

    reverse(prefix.begin(),prefix.end()); // O(N) & O(1) Time and Space Complexity
    return prefix;
}

int main()
{
    string expr = "a+b*(c^d-e)^(f+g*h)-i";
    string result = infix2Prefix(expr);
    cout << "Prefix: " << result << endl;
}