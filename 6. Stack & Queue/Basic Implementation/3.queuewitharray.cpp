#include <iostream>
#include <climits>
using namespace std;

class Queue
{
    int array[10], start = -1, end = -1, length = 0, arrSz = 10;

public:
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
    if (length == arrSz)
    {
        cout << "Queue Overflow" << endl;
        return;
    }

    if (length == 0)
        start = end = 0;
    else
        end = (end + 1) % arrSz;

    array[end] = data;
    length++;
}

/**
 * @brief Gets the element at the front of the queue.
 * @return The front element, or INT_MIN if the queue is empty.
 */
int Queue::front()
{
    if (length == 0)
    {
        cout << "Queue is empty" << endl;
        return INT_MIN;
    }
    cout << "Front of Queue is : " << array[start] << endl;
    return array[start];
}

/**
 * @brief Gets the element at the back of the queue.
 * @return The back element, or INT_MIN if the queue is empty.
 */
int Queue::back()
{
    if (length == 0)
    {
        cout << "Queue is empty" << endl;
        return INT_MIN;
    }
    cout << "Back of Queue is : " << array[end] << endl;
    return array[end];
}

/**
 * @brief Removes and returns the element from the front of the queue.
 * @return The removed element, or INT_MIN if the queue is empty.
 */
int Queue::pop()
{
    if (length == 0)
    {
        cout << "Queue Underflow" << endl;
        return INT_MIN;
    }

    int delEle = array[start];

    if (start == end)
    {
        start = end = -1;
    }
    else
    {
        start = (start + 1) % arrSz;
    }

    cout << "Pop element is : " << delEle << endl;
    length--;
    return delEle;
}

/**
 * @brief Returns the current number of elements in the queue.
 * @return The length of the queue.
 */
int Queue::size()
{
    cout << "Length of Queue is : " << length << endl;
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
    q.front(); // Should print 20
    q.size();  // Should print 1

    // Fill the queue to capacity
    for (int i = 0; i < 9; i++)
        q.push(i * 10);

    q.push(999); // Should trigger "Queue Overflow"

    // Empty the queue
    while (q.size() > 0)
        q.pop();

    // Trigger underflow
    q.pop(); // Should print "Queue Underflow"

    return 0;
}