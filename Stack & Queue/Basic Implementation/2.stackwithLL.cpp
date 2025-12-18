#include <iostream>
#include <climits>
using namespace std;

// --- Node Class ---
// Represents a single node in the linked list
class Node
{
public:
    int data;
    Node *next;

public:
    /**
     * @brief Constructor for the Node class.
     * @param data1 The integer value to be stored in the node.
     * @param next1 Pointer to the next node in the list.
     */
    Node(int data1 = 0, Node *next1 = nullptr)
    {
        data = data1;
        next = next1;
    }
};

// --- Stack Class ---
// Implements a Stack (LIFO) data structure using a linked list
class Stack
{
public:
    Node *Top = NULL; // Pointer to the top-most node in the stack
    int length = 0;   // Current number of elements in the stack

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
    // 1. Create a new node.
    // 2. Set its 'next' to point to the current 'Top'.
    // 3. Set its 'data' to the provided data.
    Node *temp = new Node(data, Top);

    // 4. Update the 'Top' pointer to be this new node.
    Top = temp;

    // 5. Increment the length.
    length++;
}

/**
 * @brief Gets the element at the top of the stack without removing it.
 * @return The top element, or INT_MIN if the stack is empty.
 */
int Stack::top()
{
    // Check if 'Top' is NULL (if the stack is empty)
    if (!Top)
    {
        cout << "Stack is empty" << endl;
        return INT_MIN;
    }
    // Print and return the data from the 'Top' node
    cout << "Stack top is : " << Top->data << endl;
    return Top->data;
}

/**
 * @brief Removes and returns the element from the top of the stack.
 * @return The removed element, or INT_MIN if the stack is empty.
 */
int Stack::pop()
{
    // 1. Check for Stack Underflow
    if (!Top)
    {
        cout << "Stack Underflow" << endl;
        return INT_MIN;
    }

    // 2. Store the data from the 'Top' node to return later
    int delEle = Top->data;
    // 3. Create a temporary pointer to the current 'Top' node
    Node *temp = Top;
    // 4. Move the 'Top' pointer to the *next* node in the list
    Top = Top->next;
    
    // 5. Delete the old 'Top' node to prevent memory leaks
    delete temp;
    
    // 6. Print, decrement length, and return the data
    cout << "Pop element is : " << delEle << endl;
    length--;
    return delEle;
}

/**
 * @brief Returns the current number of elements in the stack.
 * @return The size of the stack.
 */
int Stack::size()
{
    cout << "Length of Stack is : " << length << endl;
    return length;
}

/**
 * @brief Main function to drive and test the Stack class.
 */
int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.top();  // Should print 20
    s.size(); // Should print 2

    s.pop();  // Should remove 20
    s.top();  // Should print 10
    s.size(); // Should print 1
    s.pop();  // Should remove 10

    // This implementation (linked list) doesn't have a fixed size.
    // It will only "overflow" if the system runs out of memory.
    for (int i = 0; i < 10; i++)
        s.push(i);
    
    s.push(100); // This will NOT print "Stack Overflow"

    // Empty the stack
    while (s.size() > 0)
        s.pop();

    // Trigger underflow
    s.pop(); // Should print "Stack Underflow"

    return 0;
}