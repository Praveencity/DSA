/*
--- How This Stack-from-Queue Implementation Works ---

This code implements a Stack (LIFO - Last-In, First-Out) using a single 
C++ Standard Library Queue (FIFO - First-In, First-Out).

The key idea is to make the `push` operation "costly" (O(N) time)
to maintain the LIFO order, while `pop` and `top` remain fast (O(1) time).

Here's the logic for `push(data)`:
1.  Get the current size of the queue (let's say 'n').
2.  Add the new 'data' to the back of the queue. The queue now has n+1 elements,
    with the new one at the very end.
3.  Rotate the queue 'n' times:
    - Take the element from the front.
    - Push it to the back.
4.  This process moves all 'n' of the *original* elements from the front
    to the back, placing them *after* the new element.
5.  The result is that the new element is now at the front of the queue.

Since the newest element is always at the front of the queue,
`top()` (which reads the front) and `pop()` (which removes the front)
now behave exactly like a stack.
*/

#include <iostream>
#include <queue>
#include <climits>
using namespace std;

// --- Stack Class ---
// Implements a Stack (LIFO) using a single C++ STL queue
class Stack
{
    queue<int> q; 
public:
    void push(int);
    int top();
    void pop();
    int size();
    bool empty();
};

/**
 * @brief Adds an element to the top of the stack.
 * @param data The integer value to be added.
 * @note This is the "costly" operation (O(N)).
 */
void Stack::push(int data)
{
    // 1. Get the current size *before* adding the new element
    int length = q.size();

    // 2. Add the new data to the back of the queue
    q.push(data);

    // 3. Rotate the queue 'length' times
    // This moves all the old elements to the back, behind the new element
    while (length--)
    {
        // 3a. Take the front (oldest) element
        // 3b. Push it to the back
        q.push(q.front());
        // 3c. Remove it from the front
        q.pop();
    }
}

/**
 * @brief Gets the element at the top of the stack.
 * @return The top element, or -1 if the stack is empty.
 * @note This is a fast operation (O(1)).
 */
int Stack::top()
{
    if (q.empty())
    {
        cout << "Error: Stack is empty" << endl;
        return -1; // Return an error code
    }
    // The "top" of the stack is now at the "front" of the queue
    return q.front();
}

/**
 * @brief Removes the element from the top of the stack.
 * @note This is a fast operation (O(1)).
 */
void Stack::pop()
{
    if (q.empty())
    {
        cout << "Error: Cannot pop from empty stack" << endl;
        return;
    }
    // Just remove the front element from the queue
    q.pop();
}

/**
 * @brief Returns the current number of elements in the stack.
 * @return The size of the stack.
 */
int Stack::size()
{
    return q.size();
}

/**
 * @brief Checks if the stack is empty.
 * @return True if the stack is empty, false otherwise.
 */
bool Stack::empty()
{
    return q.empty();
}

/**
 * @brief Main function to drive and test the Stack class.
 */
int main()
{
    Stack s;
    s.push(10); // Queue: [10]
    s.push(20); // Queue: [20, 10] (10 is rotated)
    s.push(30); // Queue: [30, 20, 10] (20, 10 are rotated)

    cout << "Top: " << s.top() << endl; // Should print 30
    s.pop();                           // Removes 30. Queue: [20, 10]

    cout << "Top after pop: " << s.top() << endl; // Should print 20
    cout << "Size: " << s.size() << endl;         // Should print 2

    s.pop(); // Removes 20. Queue: [10]
    s.pop(); // Removes 10. Queue: []
    s.pop(); // Triggers "Error: Cannot pop from empty stack"

    return 0;
}