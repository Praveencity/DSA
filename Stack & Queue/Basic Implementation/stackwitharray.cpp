#include <iostream>
#include <climits>
using namespace std;

// --- Stack Class ---
// Implements a Stack (LIFO) data structure using a fixed-size array
class Stack
{
    int array[10], Top = -1; // 'Top' tracks the index of the top-most element

public:
    void push(int);
    int top();
    int pop();
    int size();
};

/**
 * @brief Adds an element to the top of the stack.
 * @param data The integer value to be added.
 */
void Stack::push(int data)
{
    // Check for Stack Overflow (index 9 is the last valid position)
    if (Top >= 9)
        cout << "Stack Overflow" << endl;
    else
        // Pre-increment 'Top', then assign data to that new index
        array[++Top] = data;
}

/**
 * @brief Gets the element at the top of the stack without removing it.
 * @return The top element, or INT_MIN if the stack is empty.
 */
int Stack::top()
{
    // Check if the stack is empty
    if (Top == -1)
    {
        cout << "Stack is empty" << endl;
        return INT_MIN;
    }
    // Print and return the element at the 'Top' index
    cout << "Stack Top Element : " << array[Top] << endl;
    return array[Top];
}

/**
 * @brief Removes and returns the element from the top of the stack.
 * @return The removed element, or INT_MIN if the stack is empty.
 */
int Stack::pop()
{
    // Check for Stack Underflow
    if (Top == -1)
    {
        cout << "Stack underflow" << endl;
        return INT_MIN;
    }
    // Print the top element
    cout << "Stack Pop Element : " << array[Top] << endl;
    // Return the element at 'Top', and *then* decrement 'Top'
    return array[Top--];
}

/**
 * @brief Returns the current number of elements in the stack.
 * @return The size of the stack.
 */
int Stack::size()
{
    // The size is 'Top' index + 1 (since 'Top' is 0-based)
    cout << "Size of Stack : " << Top + 1 << endl;
    return Top + 1;
}

/**
 * @brief Main function to drive and test the Stack class.
 */
int main()
{
    Stack s;

    s.push(19);
    s.push(20);
    s.top();  // Should print 20
    s.size(); // Should print 2

    s.pop();  // Should remove 20
    s.top();  // Should print 19 (Note: Your comment said 10, but it should be 19)
    s.size(); // Should print 1
    s.pop();  // Removes 19

    // Trigger overflow
    // Fill all 10 spots (indices 0 through 9)
    for (int i = 0; i < 10; i++)
        s.push(i);
    
    s.push(100); // Should print "Stack Overflow"

    // Empty the stack
    while (s.size() > 0)
        s.pop();

    // Trigger underflow
    s.pop(); // Should print "Stack Underflow"

    return 0;
}