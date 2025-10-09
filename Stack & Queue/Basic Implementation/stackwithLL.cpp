#include <iostream>
#include <climits>

class Node
{
    public:
        int data;
        Node* next;
    public:
        Node(int data1 = 0, Node* next1 = nullptr)
        {
            data = data1;
            next = next1;
        }
};

class Stack
{
    public:
        Node* Top = NULL;
        int length = 0;
    public:
        void push(int);
        int top();
        int pop();
        int size();
};

void Stack::push(int data)
{
    Node* temp = new Node(data,Top);
    Top = temp;
    length++;
}

int Stack::top()
{
    if(!Top)
    {
        std::cout << "Stack is empty" << std::endl;
        return INT_MIN;
    }
    std::cout << "Stack top is : " << Top->data << std::endl;
    return Top->data;  
}

int Stack::pop()
{
    if(!Top)
    {
        std::cout << "Stack Underflow" << std::endl;
        return INT_MIN;
    }
    int delEle = Top->data;
    Node* temp = Top;
    Top = Top->next;
    delete temp;
    std::cout << "Pop element is : " << delEle << std::endl;
    length--;
    return delEle;
}

int Stack::size() 
{
    std::cout << "Length of Stack is : " << length << std::endl;
    return length;
}

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.top();     // Should print 20
    s.size();    // Should print 2

    s.pop();     // Should remove 20
    s.top();     // Should print 10
    s.size();    // Should print 1
    s.pop();

    // Trigger overflow
    for(int i = 0; i < 10; i++) s.push(i);
    s.push(100);  // Should print "Stack Overflow"

    // Empty the stack
    while(s.size() > 0) s.pop();

    // Trigger underflow
    s.pop();  // Should print "Stack Underflow"

    return 0;
}