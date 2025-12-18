#include <iostream>
#include <string>
#include <stack>
using namespace std;
/*
 * ===================================================================
 * Program: Infix to Postfix Conversion (Shunting-yard Algorithm)
 * Approach:
 * This program converts an infix expression to its equivalent postfix
 * (Reverse Polish Notation) expression.
 *
 * 1. It uses a stack of characters (std::stack<char>) to hold
 * operators and parentheses.
 * 
 * 2. It iterates through the infix string from LEFT to RIGHT.
 * 
 * 3. Operands (letters/numbers) are appended directly to the
 * 'postfix' string.
 * 
 * 4. '(' is pushed onto the stack.
 * 
 * 5. ')' triggers a pop of all operators from the stack (appending
 * them to 'postfix') until '(' is found, which is then popped
 * and discarded.
 * 
 * 6. Operator Precedence:
 * - For Left-Associative (*, /, +, -): Pop ops from the stack
 * that have GREATER THAN OR EQUAL precedence to the current op.
 * - For Right-Associative (^): Pop ops from the stack that
 * have strictly GREATER precedence (this code implements
 * this by only pushing if the top is not >=, i.e., <).
 * 
 * 7. After the loop, any remaining operators on the stack are
 * popped and appended to the 'postfix' string.
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

string infix2Postfix(string s)
{
    stack<char> st;
    string postfix;
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
            else if(s[i] == '^')
            {
                while(!st.empty() && priority(s[i]) < priority(st.top()) )
                {
                    postfix += st.top();
                    st.pop();
                }
                st.push(s[i]);
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
    string expr = "a+b*(c^d-e)^(f+g*h)-i";
    string result = infix2Postfix(expr);
    cout << "Postfix: " << result << endl;
}