#include <iostream>
#define SPACE 10 

class TreeNode{
	public:
		int value;
		TreeNode* left;
		TreeNode* right;
		
		TreeNode()
		{
			value = 0;
			left = NULL;
			right = NULL;
		}

		TreeNode(int v)
		{
			value = v; 
			left = NULL;
			right = NULL;
		}

};

class BST
{
	public:
		TreeNode* root;

		BST()
		{
			root = NULL;
		}

		bool isEmpty()
		{
			if(root == NULL)
				return true;
			else
				return false;
		}

		void insertNode(TreeNode* n)
		{
			if(root == NULL)
			{
				root = n;
				std::cout << "Value inserted as root node" << std::endl;
			}

			else{
					TreeNode* ptr = root;
					while(ptr != NULL)
					{
						if(n->value == ptr->value)
						{
							std::cout << "No Duplicates allowed in the tree. Insert another value for your Node" << std::endl;
							return;
						}
							//Check to see if inserted Node value is less than current Node value
						else if(n->value < ptr->value && ptr->left == NULL)
						{
							ptr->left = n;
							std::cout << "Node Appended" << std::endl;
							break;
						}

						else if(n->value < ptr->value)
						{
							ptr = ptr->left;
						}
							//Check to see if inserted Node value is greater than current Node value
						else if(n->value > ptr->value && ptr->right == NULL)
						{	
							ptr->right = n;
							std::cout << "Node Appended" << std::endl;
							break;
						}

						else if(n->value > ptr->value)
						{
							ptr = ptr->right;
						}
					}	
			}
		}

		void print2D(TreeNode* root, int space)
		{
			if(root == NULL)
				return;
			space += SPACE; //Increase distance between levels
			print2D(root->right, space);
			std::cout << std::endl;
			for(int i = SPACE; i < space; i++)
			{
				std::cout << " ";
			}
			std::cout << root->value <<"\n";
			print2D(root->left, space);
		}

		void printPreOrder(TreeNode* n)
		{
			if(n == NULL)
				return;
			std::cout << n->value << std::endl;
			printPreOrder(n->left);
			printPreOrder(n->right);
		}

		void printInOrder(TreeNode* n)
		{
			if(n == NULL)
				return;
			printInOrder(n->left);
			std::cout << n->value << " ";
			printInOrder(n->right);
		}

		void printPostOrder(TreeNode* n)
		{
			if(n == NULL)
				return;
			printPostOrder(n->left);
			printPostOrder(n->right);
			std::cout << n->value << " ";
		}

		void iterativeSearch(int value)
		{
			TreeNode* ptr = root;
			while(ptr != NULL)
			{
				if(ptr->value == value)
				{
					std::cout << "Node with value: " << value << " was found in the tree" << std::endl << std::endl;
					return;
				}

				else{
						if(value < ptr->value)
						{
							ptr = ptr->left;
						}

						else if(value > ptr->value)
						{
							ptr = ptr->right;
						}
				}
			}
			std::cout << "No Node with value of " << value << " exists within this Binary Tree" << std::endl << std::endl;
		}

		TreeNode* recursiveSearch(int value, TreeNode* ptr)
		{
			if(ptr == NULL)
				return ptr;

			if(ptr->value == value)
			{
				return ptr;
			}

			if(value < ptr->value)
				return recursiveSearch(value, ptr->left);
					
			else
				return recursiveSearch(value, ptr->right);	
	}

		int height(TreeNode* root)
		{
			if(root == NULL)
				return -1;

			int lh = height(root->left);
			int rh = height(root->right);
			if(lh > rh)
			{
				return lh + 1;
			}
			else{

				return rh + 1;
			}
		}
};

int main()
{
	BST obj;
	int option,value;
	do{
		std::cout << "1. Insert Node" << std::endl;
		std::cout << "2. Search Node" << std::endl;
		std::cout << "3. Delete Node" << std::endl;
		std::cout << "4. Print BST Values" << std::endl;
		std::cout << "5. Clear Screen" << std::endl;
		std::cout << "0. Exit Program" << std::endl << std::endl;
		std::cout << "What operation do you want to perform?" << std::endl;
		std::cout << "Select Option number. Enter 0 to exit: ";
		std::cin >> option;
		
		TreeNode* newNode = new TreeNode();


		switch(option)
		{
			case 0:
				break;
			case 1:
				std::cout << "INSERT" << std::endl;
				std::cout << "Enter the Value of tree node to insert in BST: ";
				std::cin >> value;
				newNode->value = value;
				obj.insertNode(newNode);
				std::cout << std::endl;
				break;
			case 2:
				std::cout << "SEARCH" << std::endl;
				std::cout << "Enter the value of the Node you wish to find: ";
				std::cin >> value;
				newNode = obj.recursiveSearch(value, obj.root);
				if(newNode == NULL)
				{
					std::cout << "There is No Node within this tree with the value: " << value << std::endl;
					break;
				}
				
				else{
				std::cout << newNode->value << std::endl;
				break;
				}
			case 3:
				std::cout << "DELETE" << std::endl;
				break;
			case 4:
				std::cout << "PRINT" << std::endl << std::endl;
				obj.printPostOrder(obj.root);
				std::cout << std::endl << std::endl;
				break;
			case 5:
				std::cout << "CLEAR" << std::endl;
				system("clear");
				break;
			default:
				std::cout << "Enter Proper Option" << std::endl;
				break;
		}


	}while(option != 0);

	return 0;
}
