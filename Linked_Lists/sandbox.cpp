#include <iostream>

class Node{
public:
    int value;
    Node* next;
};

void newNode(Node** head, int newValue)
{
    
    Node* newNode = new Node(); //Created a new node object 
    newNode->value = newValue;  // set the value of my new node object 
    newNode->next = *head;      // set my newNode to point towards the head in my main function as it has the old value
    *head = newNode;            // Now I need to make head equal to my newNode as it has the most up to date value

}

int main()
{
    Node* head = new Node();
    head->value = 1;

    Node* second = new Node();
    second->value = 2;

    head->next = second;
    second->next = NULL;

    newNode(&head, -1);
    std::cout << head->value << std::endl;


    return 0;
}