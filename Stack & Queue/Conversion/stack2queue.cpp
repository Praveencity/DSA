/*
--- How This Queue-from-Stacks Implementation Works ---

This code implements a Queue (FIFO - First-In, First-Out) using two
C++ Standard Library Stacks (LIFO - Last-In, First-Out). This method
is often called the "Amortized O(1) Pop" method.

Here's the logic:
1.  **s1 (Input Stack):** This stack acts as the "inbox". All `push`
    operations go directly to `s1`. This is a fast O(1) operation.
    The newest element (the "back" of the queue) is almost always `s1.top()`.

2.  **s2 (Output Stack):** This stack acts as the "outbox". All `pop`
    and `front` operations are served from `s2`.

3.  **The Transfer (Amortization):**
    -   When `front()` or `pop()` is called, it first checks if `s2` is empty.
    -   If `s2` is *not* empty, it means it already has the oldest element
        on top (from a previous transfer), so it just performs the `top()`
        or `pop()` operation directly. This is O(1).
    -   If `s2` *is* empty, it means all the elements are currently in `s1`
        (in LIFO order). The code then transfers *all* elements from `s1`
        to `s2`, one by one.
    -   Example: s1 = [10, 20, 30] (30 is top)
    -   Transfer: s2 = [30, 20, 10] (10 is top)
    -   This transfer (which is O(N)) reverses the order, placing the
      oldest element (10) at the top of `s2`, ready to be popped.
    -   Because each element is only moved once (from s1 to s2) and
      popped once (from s2), the *average* cost of `pop` and `front`
      over many operations is O(1), even though a single call
      can be O(N). This is called "amortized" O(1) time.

4.  **`back()` Logic:**
    -   The "back" of the queue is the last element added.
    -   If `s1` is *not* empty, the last element added is simply `s1.top()`. (O(1))
    -   If `s1` *is* empty (meaning all elements are in `s2`), the "back"
        element is at the *bottom* of `s2`. The code finds this by
        copying `s2` and popping until one element remains. (O(N))
*/

#include <iostream>
#include <stack> 
using namespace std;

// --- Queue Class ---
// Implements a Queue (FIFO) using two C++ STL stacks
class Queue
{
    stack<int> s1; // Input stack
    stack<int> s2; // Output stack

public:
    void push(int);
    int front();
    int back();
    void pop();
    int size();
};

/**
 * @brief Adds an element to the back of the queue (pushes to s1).
 * @param data The integer value to be added.
 * @note This is always a fast O(1) operation.
 */
void Queue::push(int data)
{
    s1.push(data);
}

/**
 * @brief Gets the element at the front of the queue.
 * @return The front element.
 * @note This is O(1) amortized. (Worst case O(N))
 */
int Queue::front()
{
    // If the output stack (s2) is empty,
    if (!s2.size())
    {
        // Transfer all elements from s1 to s2
        while (s1.size())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }
    // Now the front element is at the top of s2
    return s2.top();
}

/**
 * @brief Gets the element at the back of the queue.
 * @return The back element.
 * @note This is O(1) if s1 is not empty, but O(N) if s1 is empty.
 */
int Queue::back()
{
    // If s1 has elements, the last pushed item is the back.
    if (!s1.empty())
    {
        return s1.top();
    }

    // If s1 is empty, the back element is at the bottom of s2.
    // We copy s2 to find it without modifying s2.
    stack<int> temp = s2;
    while (temp.size() > 1)
    {
        temp.pop();
    }
    // The last remaining element is the back
    return temp.top();
}

/**
 * @brief Removes the element from the front of the queue.
 * @note This is O(1) amortized. (Worst case O(N))
 */
void Queue::pop()
{
    // If the output stack (s2) is empty,
    if (!s2.size())
    {
        // Transfer all elements from s1 to s2
        while (s1.size())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }
    // Now pop the front element from s2
    s2.pop();
}

/**
 * @brief Returns the total number of elements in the queue.
 * @return The total size.
 */
int Queue::size()
{
    // The total size is the sum of elements in both stacks
    return s1.size() + s2.size();
}

/**
 * @brief Main function to drive and test the Queue class.
 */
int main()
{
    Queue q;

    q.push(10); // s1: [10]
    q.push(20); // s1: [10, 20]
    q.push(30); // s1: [10, 20, 30]

    // front() triggers transfer:
    // s1: []
    // s2: [30, 20, 10]
    cout << "Front: " << q.front() << "\n"; // 10
    // back() checks s1 (empty), copies s2, finds bottom
    cout << "Back: " << q.back() << "\n"; // 30

    // pop() removes from s2
    // s2: [30, 20]
    q.pop();
    cout << "After pop:\n";
    cout << "Front: " << q.front() << "\n"; // 20
    cout << "Back: " << q.back() << "\n"; // 30

    // push(40) goes to s1
    // s1: [40]
    // s2: [30, 20]
    q.push(40);
    cout << "After pushing 40:\n";
    // front() is still s2.top()
    cout << "Front: " << q.front() << "\n"; // 20
    // back() checks s1 (not empty), returns s1.top()
    cout << "Back: " << q.back() << "\n"; // 40

    // size() is s1.size() + s2.size() (1 + 2)
    cout << "Size: " << q.size() << "\n"; // 3
    return 0;
}