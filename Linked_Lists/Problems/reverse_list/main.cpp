//In this program we will implement a linked list and reverse it

#include <iostream>

class Node{
	public:
		Node* next;
		int key;

		Node(){
			next = NULL;
			key = 0;
		}

		Node(int k)
		{
			next = NULL;
			key = k;
		}
};

class LinkedList{
	public:
		Node* head;

		LinkedList()
		{
			head = NULL;
		}

		Node* ifNodeExists(int k)
		{
			Node* ptr = head;

			if(ptr == NULL)
			{
				std::cout << "List is empty, there are no Nodes in this list\n";
				return nullptr; 
			}

			else{
					while(ptr != NULL)
					{
						if(ptr->key == k)	
						{	
							std::cout << "Node with Key: " << k << " has been located\n";
							break;
						}

						else{
								ptr = ptr->next;		
						}
					}
			}		
			
			return ptr;
		}

		void appendNode(Node* n)
		{
			if(head == NULL)
			{
				head = n;
			}

			else{
					//Check to see if Node with this particular key exists within the list
					if(ifNodeExists(n->key) != NULL)
					{
						std::cout << "Node with Key: " << n->key << " is already present within this list. Append with different Key value\n";
						return;
					}

					else{
							Node* ptr = head;
							while(ptr->next != NULL)
							{
								ptr = ptr->next;
							}

							ptr->next = n;
							std::cout << "Node Appended\n";
					}
			}
		}

		
		void reverseList()
		{
			Node* currPtr = head;
			if(currPtr == NULL)
			{
				std::cout << "There are no Nodes present in this list\n";
				return;
			}

			else{
					Node* prevPtr = NULL;
					Node* nextPtr;

					while(currPtr != NULL)
					{
						nextPtr = currPtr->next;
						currPtr->next = prevPtr;
						prevPtr = currPtr;
						currPtr = nextPtr;
					}

					head = prevPtr;
			}
		}

		void printList()
		{
			Node* ptr = head;
			while(ptr != NULL)
			{
				std::cout << ptr->key << " ";
				ptr = ptr->next;
			}

			std::cout << "\n";
		}	

};

int main()
{
	
	LinkedList l1;
	
	Node* node = new Node();
	node->key = 1;

	Node* node2 = new Node();
	node2->key = 2;

	Node* node3 = new Node();
	node3->key = 3;

	l1.appendNode(node);
	l1.appendNode(node2);
	l1.appendNode(node3);

	l1.printList();
	l1.reverseList();
	l1.printList();
	//l1.ifNodeExists(2);


	return 0;
}
