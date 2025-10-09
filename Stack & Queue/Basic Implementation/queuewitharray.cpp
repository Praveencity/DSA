#include <iostream>
#include <climits>

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

void Queue::push(int data)
{
    if(length == arrSz)
    {
        std::cout << "Queue Overflow" << std::endl;
        return;
    }
    if(length == 0)
        start = end = 0;
    else
        end = (end+1)%arrSz;

    array[end] = data;
    length++;
}

int Queue::front()
{
    if(length == 0)
    {
        std::cout << "Queue is empty" << std::endl;
        return INT_MIN;
    }
    std::cout << "Front of Queue is : " << array[start] << std::endl;
    return array[start];
}

int Queue::back()
{
    if(length == 0)
    {
        std::cout << "Queue is empty" << std::endl;
        return INT_MIN;
    }
    std::cout << "Back of Queue is : " << array[end] << std::endl;
    return array[end];
}

int Queue::pop()
{
    if(length == 0)
    {
        std::cout << "Queue Underflow" << std::endl;
        return INT_MIN;
    }
    int delEle = array[start];  
    if(start == end) 
        start = end = -1;
    else 
        start = (start+1)%arrSz;

    std::cout << "Pop element is : " << delEle << std::endl;
    length--;
    return delEle;
}

int Queue::size()
{
    std::cout << "Length of Queue is : " << length << std::endl;
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