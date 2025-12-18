#include <iostream>
#include <vector>

//Making a Node data type for linked list using class.
//Struct can also be use.
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


// Convert an array to linked list
Node* arrayToLinkedList(Node* head,std::vector<int> &nums)
{
    if(nums.size() == 0) return NULL;
    head = new Node(nums[0]);
    Node* mover = head;
    for(int i =1;i<nums.size();i++)
    {
        mover->next = new Node(nums[i]);
        mover = mover->next;
    }
    return head;
}


// Check the length of linked list
int lengthOfLinkedList(Node* head)
{
    if(head == NULL) return 0;
    int cnt = 0;
    Node* ptr = head;
    while(ptr)
    {
        cnt++;
        ptr = ptr->next;
    }
    return cnt;
}


// Function to check is element present in linked list
int checkIfPresent(Node* head,int val)
{
    Node* ptr = head;
    while(ptr)
    {
        if(ptr->data == val) return true;
        ptr = ptr->next;
    }
    return false;
}

// Remove element from start 
Node* removeHead(Node*head)
{
    Node* temp = head;
    head = head->next;
    delete temp; // To prevent from memory leak we have to free memory from heap.
    return head;
}


// Remove element from last 
Node* removeTail(Node*head)
{
    if(head == NULL || head->next == NULL) return NULL;
    Node* temp = head;
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    return head;
}

// Remove element from given index
Node* removeAtIndex(Node* head,int index)
{
    if(index < 0 || head == NULL) return head;
    if(index == 0)
    {
        head = removeHead(head);
        return head;
    }
    int count = 0;
    Node* prev = head;
    Node* temp = prev->next;
    while(temp)
    {
        count++;
        if(count == index) 
        {
            prev->next = temp->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
    
}

// Remove a given element
Node* removeElement(Node* head,int el)
{
    if(head->data == el)
    {
        head = removeHead(head);
        return head;
    }
    Node* prev = head;
    Node* temp = head->next;
    while(temp)
    {
        if(temp->data == el)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* insertAtFront(Node* head, int val)
{
    head = new Node(val,head);
    return head;
}

Node* insertAtLast(Node* head,int val)
{
    if(head == NULL) return new Node(val);
    Node* temp = head;
    while(temp->next) temp = temp->next;
    temp->next = new Node(val);
    return head;
}

Node* insertAtIndex(Node* head,int val,int index)
{
    if(head == NULL)
    {
        if(index == 0) return new Node(val);
        else return head;
    }
    if(index == 0) return new Node(val,head);
    Node* temp = head;
    int count = 1;
    while(temp)
    {
        if(count == index)
        {
            temp->next = new Node(val,temp->next);
            break;
        }
        temp = temp->next;
        count++;
    }
    return head;
}

Node* insertBeforeElement(Node* head,int val,int el)
{
    if(head == NULL)
    {
        if(head->data == el) return new Node(val);
        else return head;
    }
    if(head->data == el) return new Node(val,head);
    Node* temp = head;
    while(temp->next)
    {
        if(temp->next->data == el)
        {
            temp->next = new Node(val,temp->next);
            break;
        }
        temp = temp->next;
    }
    return head;
}

// Function for printing a linked list
void printLinkedList(Node* head)
{
    Node* temp = head;
    while(temp)
    {
        std::cout<< temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// Main function
int main()
{   
    std::vector<int> v = {2,4,45,23,12,43};

    // initializing head of a linked list
    Node* head = NULL;

    head = arrayToLinkedList(head,v);

    printLinkedList(head);
    
    //Finding the Length of a Linked List
    std::cout<< "Length of Linked List : " << lengthOfLinkedList(head) << std::endl;
    
    
    //Checking if the value is present in the linked list
    int val;
    std::cin >> val; // Taking the value val as an input
    std::string found = checkIfPresent(head,val) ? "Yes" : "No" ;
    std::cout << "Is " << val << " present in Linked List : " << found << std::endl;

    // Removing an element from Linked List
    
    head = removeHead(head);
    printLinkedList(head);

    head = removeTail(head);
    printLinkedList(head);

    head = removeAtIndex(head,2);
    printLinkedList(head);
    
    head = removeElement(head,45);
    printLinkedList(head);


    // Inserting an element in Linked List

    head = insertAtFront(head,42);
    printLinkedList(head);
    
    head = insertAtLast(head,6);
    printLinkedList(head);
    
    head = insertAtIndex(head,7,1);
    printLinkedList(head);
    
    head = insertBeforeElement(head,13,12);
    printLinkedList(head);


    return 0;
}