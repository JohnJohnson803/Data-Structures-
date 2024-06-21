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
			if(head==NULL)
			{
				std::cout << "Singly Linked List is already empyty. Can't delete." << std::endl;
			}

			else if(head!=NULL)
			{
				if(head->key == k)
				{
					head = head->next;
					std::cout << "Node UNLINKED with keys value : " << k << std::endl;
				}

				else{
					 Node* temp = NULL;
					 Node* prevPtr = head;;
					 Node* currentPtr = head->next;
					 while(currentPtr!=NULL)
					 {
						if(currentPtr->key==k)
						{
							temp = currentPtr;
							currentPtr = NULL;
						}
						else{
							prevPtr = prevPtr->next;
							currentPtr = currentPtr->next;
						}
						if(temp!=NULL)
						{
							prevPtr->next=temp->next;
							std::cout << "Node UNLINKED with keys value: " << k << std::endl;
						}
						else{
							std::cout << "Node Doesn't exist with key value : " << k << std::endl;
						}
					 }
				}
			}
		}
};

int main()
{
    

    return 0;
}
