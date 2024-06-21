#include <iostream>
        
class Node
{
public:
    int Value;
    Node *Next;
};

void printList(Node *head)
{
    Node *current = head;
    Node *nextPtr = NULL;
    int value = head->Value;
    bool endOfList = false;

    while (endOfList == false)
    {
        std::cout << current->Value << std::endl;
        if (current->Next == NULL)
        {
            endOfList = true;
        }
        nextPtr = current->Next;
        current = nextPtr;
    }
}

void insertAtTheFront(Node **head, int newValue)
{
    // 1. Prepare a newNode
    Node *newNode = new Node();
    newNode->Value = newValue;
    // 2. newNode will now point to current head
    newNode->Next = *head;
    // 3. Move head of the list to point to the newNode
    *head = newNode;
}

void insertAtTheEnd(Node **head, int newValue)
{
    // 1. Prepare a newNode
    Node *newNode = new Node();
    newNode->Value = newValue;
    newNode->Next = NULL;

    // 2. If Linked List is empty, newNode will be a head node
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    // 3. Find the last node
    Node *last = *head;
    while (last->Next != NULL)
    {
        last = last->Next;
    }

    last->Next = newNode;
}

void insertAfterGivenNode(Node** head, int Key, int newValue)
{
    //Create a new node
    Node* newNode = new Node();
    newNode->Value = newValue;

    //Find an arbitrary node given a specific key
    Node* n = *head;
    while(n->Value != Key)
    {
        n = n->Next;
    }

    newNode->Next = n->Next;
    n->Next = newNode;  

}

int main()
{
    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();

    head->Value = 1;
    head->Next = second;

    second->Value = 2;
    second->Next = third;

    third->Value = 3;
    third->Next = NULL;

    insertAtTheFront(&head, -1);
    insertAtTheEnd(&head, 4);
    insertAtTheEnd(&head, 5);
    insertAfterGivenNode(&head, 4, 0);
    printList(head);
}