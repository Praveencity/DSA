#include <bits/stdc++.h>

class Node
{
    public:
        int data;
        Node* next;
        Node* prev;
    public:
        Node(int data1 = 0, Node* next1= nullptr, Node* prev1 = nullptr)
        {
            data = data1;
            next = next1;
            prev= prev1;
        }
};


// Deletion Function

Node* deleteHead(Node* head)
{
    if(head == NULL || head->next == NULL) return NULL;

    Node* temp = head;
    head = head->next;

    head->prev = nullptr;
    temp->next = nullptr; // Optional

    delete temp;
    return head;
}

Node* deleteTail(Node* head)
{
    if(head == NULL || head->next == NULL) return NULL;

    Node* tail = head;

    while(tail->next) tail = tail->next;

    tail->prev->next = nullptr;
    tail->prev = nullptr; // Optional

    delete tail;
    return head;
}

Node* deleteAtIndex(Node* head, int index)
{
    if(head == NULL) return NULL;
    if(index == 0) return deleteHead(head);

    Node* delNode = head->next;
    int count = 1;
    while(delNode)
    {
        if(count == index)
        {
            delNode->prev->next = delNode->next;
            if(delNode->next) delNode->next->prev = delNode->prev;
            delete delNode;
            break;
        }
        delNode = delNode->next;
        count++;
    }
    return head;
}

Node* deleteElement(Node* head, int el)
{
    if(head == NULL) return NULL;
    if(head->data == el) return deleteHead(head);
    Node* delNode = head->next;
    while(delNode)
    {
        if(delNode->data == el)
        {
            delNode->prev->next = delNode->next;
            if(delNode->next) delNode->next->prev = delNode->prev;
            delete delNode;
            break;
        }
        delNode = delNode->next;
    }
    return head;
}

Node* insertHead(Node* head,int value)
{
    if(head == NULL) return new Node(value);
    Node* temp = new Node(value,head,nullptr);
    head->prev = temp;
    return temp;
}

Node* insertTail(Node* head,int value)
{
    if(head == NULL) return new Node(value);
    Node* temp = head;
    while(temp->next) temp = temp->next;
    temp->next = new Node(value,nullptr,temp);
    return head;
}

Node* insertAtIndex(Node* head,int value,int index)
{
    if(head == NULL && index == 0) return new Node(value);
    if(index == 0) return insertHead(head,value);
    Node* temp = head->next;
    int count = 1;
    while(temp)
    {
        if(index == count)
        {
            Node* newNode = new Node(value,temp,temp->prev);
            temp->prev->next = newNode;
            temp->prev = newNode;
            return head;
        }
        temp = temp->next;
        count++;
    }

    if(count == index) return insertTail(head,value);

    return head;
}

Node* insertBeforeElement(Node* head,int value, int el)
{
    if(head == NULL) return NULL;
    if(head->data == el) return insertHead(head,value);
    Node* temp = head->next;
    while(temp)
    {
        if(temp->data == el)
        {
            Node* newNode = new Node(value,temp,temp->prev);
            temp->prev->next = newNode;
            temp->prev = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}

Node* convertTo2DLL(std::vector<int> &nums)
{
    if(nums.empty()) return nullptr;
    Node* head = new Node(nums[0]);
    Node* ptr = head;
    for(int i = 1; i<nums.size();i++)
    {
        ptr->next = new Node(nums[i],nullptr,ptr);
        ptr = ptr->next;
    }
    return head;
}



void print2DLinkedList(Node* head)
{
    while(head)
    {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> arr ={2,4,45,23,12,43};
    Node* head = convertTo2DLL(arr);

    print2DLinkedList(head);

    // Deletion from 2D Linked List

    head = deleteHead(head);
    print2DLinkedList(head);

    head = deleteTail(head);
    print2DLinkedList(head);
    
    head = deleteAtIndex(head,1);
    print2DLinkedList(head);

    head = deleteElement(head,23);
    print2DLinkedList(head);


    // Insertion in 2D Linked List

    head = insertHead(head,20);
    print2DLinkedList(head);

    head = insertTail(head,56);
    print2DLinkedList(head);

    head = insertAtIndex(head,67,3);
    print2DLinkedList(head);

    head = insertBeforeElement(head,90,67);
    print2DLinkedList(head);

    return 0;
}