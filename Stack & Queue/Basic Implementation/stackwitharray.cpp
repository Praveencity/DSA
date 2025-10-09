#include <iostream>
#include <climits>

class Stack
{
    int array[10],Top = -1;
    public:
        void push(int);
        int top();
        int pop();
        int size();
};

void Stack::push(int data)
{
    if(Top>=9)
        std::cout << "Stack Overflow" << std::endl;
    else
        array[++Top] = data;
}

int Stack::top()
{
    if(Top == -1)
    {
        std::cout << "Stack is empty" << std::endl;
        return INT_MIN;
    }
    std::cout << "Stack Top Element : " << array[Top] << std::endl;
    return array[Top];
}

int Stack::pop()
{
    if(Top == -1)
    {
        std::cout << "Stack underflow" << std::endl;
        return INT_MIN;
    }
    std::cout << "Stack Pop Element : " << array[Top] << std::endl;
    return array[Top--];
}

int Stack::size() {
    std::cout << "Size of Stack : " << Top+1 << std::endl;
    return Top+1;
}

int main()
{
    Stack s;

    s.push(19);
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