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
    std::string name = "123456789";
	int sum = 0;
	std::string temp = "";
	for(int i=0; i<9; i++)
	{	
		temp = (name[i]);
		sum += std::stoi(temp);
	}
	std::cout << sum << std::endl;
    return 0;
}
