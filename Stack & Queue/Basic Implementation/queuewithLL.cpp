#include <iostream>
#include <climits>

class Node
{
    public:
        int data;
        Node* next;
    public:
        Node(int data1 = 0,Node* next1 = nullptr)
        {
            data = data1;
            next = next1;
        }
};

class Queue
{
    public:
        Node* start = NULL;
        Node* end = NULL;
        int length = 0;

    public:
        void push(int);
        int front();
        int back();
        int pop();
        int size();
};

void Queue::push(int data)
{
    if(length == 0)
    {
        Node* temp = new Node(data);
        start = temp;
        end = temp;
        length++;
    }
    else
    {
        Node* temp = new Node(data);
        end->next = temp;
        end = temp;
        length++;
    }
}

int Queue::front()
{
    if(length == 0)
    {
        std::cout << "Queue is empty" << std::endl;
        return INT_MIN;
    }
    std::cout << "Front of Queue is : " << start->data << std::endl;
    return start->data;
}

int Queue::back()
{
    if(length == 0)
    {
        std::cout << "Queue is empty" << std::endl;
        return INT_MIN;
    }
    std::cout << "Back of Queue is : " << end->data << std::endl;
    return end->data;
}

int Queue::pop()
{
    if(length == 0)
    {
        std::cout << "Queue Underflow" << std::endl;
        return INT_MIN;
    }
    int delEle = start->data;
    Node* temp = start;
    start = start->next;
    length--;
    delete temp;
    if(length == 0) end = NULL;
    std::cout << "Pop element is : " << delEle << std::endl;
    return delEle;
}

int Queue::size()
{
    std::cout << "Size of queue is : " << length << std::endl;
    return length;
}

int main()
{
    Queue q;

    q.push(10);
    q.push(20);
    q.front();   // Should print 10
    q.back();    // Should print 20
    q.size();    // Should print 2

    q.pop();     // Should remove 10
    q.front();   // Should print 20
    q.size();    // Should print 1

    // Fill the queue to capacity
    for(int i = 0; i < 9; i++)
        q.push(i * 10);

    q.push(999); // Should trigger "Queue Overflow"

    // Empty the queue
    while(q.size() > 0)
        q.pop();

    // Trigger underflow
    q.pop();     // Should print "Queue Underflow"

    return 0;
}