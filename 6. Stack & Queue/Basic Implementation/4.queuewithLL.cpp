#include <iostream>
#include <climits>
using namespace std;
// No 'using namespace std;' is used, so '' is used explicitly.

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

// --- Queue Class ---
// Implements a Queue (FIFO) data structure using a linked list
class Queue
{
public:
    Node *start = NULL; // Pointer to the front (head) of the queue
    Node *end = NULL;   // Pointer to the back (tail) of the queue
    int length = 0;   // Current number of elements in the queue

public:
    // Function declarations
    void push(int);
    int front();
    int back();
    int pop();
    int size();
};

/**
 * @brief Adds an element to the back of the queue.
 * @param data The integer value to be added.
 */
void Queue::push(int data)
{
    // Create a new node with the given data
    Node *temp = new Node(data);
    
    // 1. Handle the case for the first element
    if (length == 0) // or (start == NULL)
    {
        // If the queue is empty, the new node is both the start and end
        start = temp;
        end = temp;
    }
    // 2. Handle all other cases
    else
    {
        // Link the current last node (end) to the new node
        end->next = temp;
        // Update the 'end' pointer to be the new node
        end = temp;
    }
    // Increment the count of elements
    length++;
}

/**
 * @brief Gets the element at the front of the queue.
 * @return The front element, or INT_MIN if the queue is empty.
 */
int Queue::front()
{
    // Check if the queue is empty
    if (length == 0)
    {
        cout << "Queue is empty" << endl;
        return INT_MIN; // Return error value
    }
    // If not empty, print and return the data from the 'start' node
    cout << "Front of Queue is : " << start->data << endl;
    return start->data;
}

/**
 * @brief Gets the element at the back of the queue.
 * @return The back element, or INT_MIN if the queue is empty.
 */
int Queue::back()
{
    // Check if the queue is empty
    if (length == 0)
    {
        cout << "Queue is empty" << endl;
        return INT_MIN; // Return error value
    }
    // If not empty, print and return the data from the 'end' node
    cout << "Back of Queue is : " << end->data << endl;
    return end->data;
}

/**
 * @brief Removes and returns the element from the front of the queue.
 * @return The removed element, or INT_MIN if the queue is empty.
 */
int Queue::pop()
{
    // 1. Check for Queue Underflow
    if (length == 0)
    {
        cout << "Queue Underflow" << endl;
        return INT_MIN;
    }

    // 2. Store the data to be returned
    int delEle = start->data;
    // 3. Create a temporary pointer to the node to be deleted
    Node *temp = start;
    // 4. Move the 'start' pointer to the next node in the list
    start = start->next;
    // 5. Decrement the length
    length--;
    
    // 6. Delete the old front node to prevent memory leaks
    delete temp;

    // 7. If popping the last element, 'end' must be set to NULL
    if (length == 0)
    {
        end = NULL;
    }

    // 8. Print and return the deleted element's data
    cout << "Pop element is : " << delEle << endl;
    return delEle;
}

/**
 * @brief Returns the current number of elements in the queue.
 * @return The length of the queue.
 */
int Queue::size()
{
    cout << "Size of queue is : " << length << endl;
    return length;
}

/**
 * @brief Main function to drive and test the Queue class.
 */
int main()
{
    Queue q;

    q.push(10);
    q.push(20);
    q.front(); // Should print 10
    q.back();  // Should print 20
    q.size();  // Should print 2

    q.pop();   // Should remove 10
    q.front(); // Should print 2