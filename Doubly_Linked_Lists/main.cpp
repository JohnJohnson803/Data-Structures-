#include <iostream>

class Node{
	public:
		int data;
		int key;
		Node* next;
		Node* previous;

		Node()
		{
			key=0;
			data=0;
			next=NULL;
			previous=NULL;
		}

		Node(int k, int d)
		{
			key = k;
			data = d;
			next = NULL;
			previous = NULL;
		}
};


class DoublyLinkedList{
	public:
		Node* head;

		DoublyLinkedList()
		{
			head=NULL;
		}

		DoublyLinkedList(Node* n)
		{
			head = n;
		}

		// 1. Check if node exists using key value
		Node* checkIfNodeExists(int k)
		{
			Node* temp = NULL;
			Node* ptr = head;
			while(ptr != NULL)
			{
				if(ptr->key == k)
				{
					temp = ptr;
					break;
				}
				ptr = ptr->next;
			}	

			return temp;
		}

		//2. Append a node to the list
		void appendNode(Node* n)
		{
			//First check to see if Node with appended Node's Key exists in lists already
			if(checkIfNodeExists(n->key) != NULL)
			{
				std::cout << "Node with Key: " << n->key << " already exists within the list. Append a Node with a different Key"					<< std::endl;
			}

			else{
				if(head == NULL)
				{
					head = n;
					std::cout << "Node Appended as Head Node" << std::endl;
				}

				else{
					Node* ptr = head;
					while(ptr->next != NULL)
					{
						ptr = ptr->next;
					}

					ptr->next = n;
					n->previous = ptr;
					std::cout << "Node Appended" << std::endl;
				}
		
			}
		}

		//3. Prepend Node to the list
		void prependNode(Node* n)
		{
			//First check to see if Node being prepended key is already in the list
			if(checkIfNodeExists(n->key) != NULL)
			{
				std::cout << "Node with Key: " << n->key << "is already in the list. Append a Node with a different key"						 << std::endl;
			}

			else{
				if(head == NULL)
				{
					head = n;
					std::cout << "Node Prepended" << std::endl;
				}

				else{
					head->previous = n;
					n->next = head;
					head = n; 
					std::cout << "Node Prepended" << std::endl;
				}
			}
		}

		void insertNodeAfter(int k,Node* n)
		{
			//First check to see if Node you want to insert after even exists
			Node* ptr = checkIfNodeExists(k);

			if(ptr == NULL)
			{
				std::cout << "Node with Key: " << k << " does not exists in this list. Please Select another Node to insert after." << std::endl;
			}
			
			else{	
					//Check to see if Node you want to insert has a key already found in the list.
					if(checkIfNodeExists(n->key) != NULL)
					{
						std::cout << "Node you want to insert already has a matching Key in the List. Please choose a different Value for you Key." << std::endl;
					}

					else
					{

						// Check to see if Node to be inserted is at the end of the List
						if(ptr->next == NULL)
						{
							ptr->next = n;
							n->previous = ptr;
						}

						else{
							ptr->next->previous = n;
							n->next = ptr->next;
							n->previous = ptr;
							ptr->next = n;
						}
					}
			}
		}

		//Deleting A Node From a List
		void deleteNodeFromList(int k)
		{
			//First check to see if Node to be deleted exists in the list.
			Node* ptr = checkIfNodeExists(k);
			if(ptr == NULL)
			{
				std::cout << "The key you entered in does not belong to a node in this list. Please select another Node to be deleted. " << std::endl;
			}

			else{
					//Check to see if Node to be deleted is at the end of the list
					if(ptr->next == NULL)
					{
						ptr->previous->next = NULL;
						std::cout << "Last Node deleted from the list" << std::endl;
					}

					//Check to see if Node to be delete is at the head Node
					else if(head->key == k)
					{
						head = head->next;
						std::cout << "Node Deleted" << std::endl;
					}
					else{
						ptr->previous->next = ptr->next;
						ptr->next->previous = ptr->previous;
					}
			}
		}

		void updateNodeByKey(int k, int d)
		{
			Node* ptr = checkIfNodeExists(k);
			if(ptr == NULL)
			{
				std::cout << "The Key which you provided does not belong to a Node in this List. Please enter a different Key." << std::endl;
			}

			else{
				ptr->data = d;
				std::cout << "Node updated with Data: " << d << std::endl;
			}
		}

		void printEntireList()
		{
			//First check if list is empty
			if(head == NULL)
			{
				std::cout << "List is empty therefore there is nothing to print" << std::endl;
			}

			else{
					Node* ptr = head;
					while(ptr != NULL)
					{
						std::cout << "Key: " << ptr->key << "\nData: " << ptr->data << std::endl;
						ptr = ptr->next;
					}
			}
		}
};


int main()
{
	Node johnathan(1,1997);
	DoublyLinkedList list;
	list.appendNode(&johnathan);
	list.printEntireList();	
	


	return 0;
}
