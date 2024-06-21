/* 
    1. appendNode()
    2. prependNode()
    3. insertNodeAfter()
    4. deleteNodeByKey()
    5. updateNodeByKey()
    6. print()
*/
#include <iostream>

class Node{
    public:
	int key;
	int data;
	Node* next;
	
	Node()
	{
	    key=0;
	    data=0;
	    next=NULL;
	}

	Node(int k, int d)
	{
	    key = k;
	    data = d;
	}
};

class SinglyLinkedList{
    public:
	Node*  head;

	SinglyLinkedList()
	{
	    head=NULL;
	}

	SinglyLinkedList(Node* n)
	{
	    head = n;
	}

	//1. Check is Node exist using key value
	Node* nodeExists(int k)
	{
	    Node* temp = NULL;
	    Node* ptr = head;

	    while(ptr !=NULL)
	    {
		if(ptr->key == k)
		{
		    temp = ptr;
		}

		ptr = ptr->next;
	    }
	    return temp;
	}

	//2. Append a node to the list
	void appendNode(Node *n)
	{
	    //First check to see if that Node already exists
	    if(nodeExists(n->key) != NULL)
	    {
		std::cout << "Node already existss with key value : " << n->key << ". Append node with different Key value" << std::endl;
	    }

	    else{
		if(head == NULL)
		{
		    // If you create an object of SinglyLinkedList but have no nodes to which your head pointer points to. Then n will become the head pointer. 
		    head = n;
		    std::cout << "Node Appended" << std::endl;
		}

		else{
			Node* ptr = head;
			while(ptr->next != NULL)
			{
			    ptr = ptr->next;
			}
			ptr->next = n;
			std::cout << "Node Appended" << std::endl;
		}
	    }
	}

	//3. Prepend Node - Attach a node at the start 
	void prependNode(Node* n)
	{
	    // First check to see if Node already exist
	    if(nodeExists(n->key) != NULL)
		{
		    std::cout << "Node already exists with key value : " << n->key << ". Append another node with a different key value" << std::endl;
		}
		
		// Check to see if head node is storing the value of NULL
		else{	
			if(head == NULL)
			{
			    head = n;
			    std::cout << "Node prepended" << std::endl;
			}

			else{
			    n->next = head;
			    head = n;
			    std::cout << "Node prepended" << std::endl;
			}
		}
	    }

		//4. Insert Node after a particular node in the List
		void insertNodeAfter(int k, Node* n)
		{
			Node* ptr = nodeExists(k);
			if(ptr ==NULL)
			{
				std::cout << "No Node exists with key value: " << k << std::endl;
			}

			else{
					if(nodeExists(n->key) != NULL)
					{
						std::cout << "Node already exists with key value: " << n->key << ". Append another node with different Key value." << std::endl;
					}

					else{
						n->next = ptr->next;
						ptr->next = n;
						std::cout << "Node Inserted" << std::endl;
					}
			}
		}

		//5. Delete Node by unique key
		void deleteNodeByKey(int k)
		{
			//First check to see if list is empty
			if(head == NULL)
			{
				std::cout << "List is empty, there is nothing to delete." << std::endl;
			}

			else if(head != NULL)
			{
				if(head->key == k){
				head = head->next;
				std::cout << "Node deleted" << std::endl;
				}

				else{
					Node* temp = NULL;
					Node* currentPtr = head->next;
					Node* prePtr = head;
					while(currentPtr != NULL)
					{
						if(currentPtr->key == k)
						{
							temp = currentPtr;
						}

						else{
							prePtr = prePtr->next;
							currentPtr = currentPtr->next;
						}

						if(temp != NULL)
						{
							prePtr->next = temp->next;
							std::cout << "Node Unlinked with key value: " << k << std::endl;
						}
						else{
							std::cout << "Node doesn't exist with key value: " << k << std::endl;
						}
					}
				}
			}
		}

		//6. Update Node by key
		void updateNodeByKey(int k, int d)
		{
			Node* ptr = nodeExists(k);
			if(ptr == NULL)
			{
				std::cout << "Node with key: " << k << " does not exists. Try a different key" << std::endl;
			}

			else{
					ptr->data = d;
					std::cout << "Node with key: " << k << "has been updated with value: " << d << std::endl;
			}
		}

		void printEntireList()
		{
			//First check to see if there is anything in the List
			if(head == NULL)
			{
				std::cout << "Your list is empty and there is nothing to print" << std::endl;
			}

			else{
				Node* ptr = head;
				while(ptr != NULL)
				{
					std::cout << "Node with Key: " << ptr->key << " , Data: " << ptr->data << std::endl;
					ptr = ptr->next;
				}
			}
		}
};

int main()
{
    SinglyLinkedList s;
	int option;
	int key1,k1,data1;

	do{
		std::cout <<"\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << std::endl;
		std::cout << "1. appendNode()" << std::endl;
		std::cout << "2. prependNode()" << std::endl;
		std::cout << "3. insertNode()" << std::endl;
		std::cout << "4. deleteNodeByKey()" << std::endl;
		std::cout << "5. updateNodeByKey()" << std::endl;
		std::cout << "6. print()" << std::endl;
		std::cout << "7. Clear Screen" << std::endl << std::endl;

		std::cout << "Option: ";
		std::cin >> option;
		Node* n1 = new Node();

		switch(option)
		{
			case 0:
				break;
			case 1:
				std::cout << "Appended Node Operation \nEnter key & data of the Node to be Appended" << std::endl;
				std::cout << "Key: ";
				std::cin >> key1;
				std::cout << "Data: ";
				std::cin >> data1;
				n1->data = data1;
				n1->key = key1;
				s.appendNode(n1);
				break;

			case 2:
				std::cout << "Prepend Node Operation \nEnter key and data of the Node to be Prepended" << std::endl;
				std::cout << "Key: ";
				std::cin >> key1;
				std::cout << "Data: ";
				std::cin >> data1;
				n1->key = key1;
				n1->data = data1;
				s.prependNode(n1);
				break;

			case 3:
				std::cout << "Insert Node Operation\nEnter in the key you want this Node to be inserted after and the data associated with it" << std::endl;
				std::cout << "Key of the Node for which this Node will be inserted after: ";
				std::cin >> k1;
				std::cout << "Now enter in the information of the new Node that will be passed in." << std::endl;
				std::cout << "Key: ";
				std::cin >> key1;
				std::cout << "Data: ";
				std::cin >> data1;
				n1->key = key1;
				n1->data = data1;
				s.insertNodeAfter(k1, n1);
				break;

			case 4:
				std::cout << "Delete Node Operation\nEnter in the key of the Node you want to be deleted." << std::endl;
				std::cout << "Key: ";
				std::cin >> k1;
				s.deleteNodeByKey(k1);
				break;

			case 5:
				std::cout << "Update Node Operation\nEnter in the key of the Node you want to be updated." << std::endl;
				std::cout << "Key: ";
				std::cin >> k1;
				std::cout << "Enter in the updated information: ";
				std::cin >> data1;
				s.updateNodeByKey(k1,data1);
				break;

			case 6:
				std::cout << "Printing All Items in List" << std::endl << std::endl;
				s.printEntireList();
				break;
			
			case 7:
				system("clear");
				break;
			default:
				std::cout << "Enter Proper Option Number " << std::endl;
		}

	}while(option != 0);


    return 0;
}
