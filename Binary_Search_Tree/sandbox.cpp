#include <iostream>

class TreeNode{
	public:
		int key;
		TreeNode* left;
		TreeNode* right;

		TreeNode()
		{
			left = NULL;
			right = NULL;
		}

		TreeNode(int k)
		{
			left = NULL;
			right = NULL;
			key = k;
		}
};

class BST{
	public:
		TreeNode* root;

		BST()
		{
			root = NULL;
		}
		
		//Check to see if Tree is empty
		bool isEmpty()
		{
			if(root == NULL)
			{
				return true;
			}

			else{
					return false;
			}
		}

		//Create the insert Node function
		void insertNode(TreeNode* n)
		{
			if(root == NULL)
				root = n;

			else{
					TreeNode* ptr = root;
					while(ptr != NULL)
					{
						if(n->key == ptr->key)
						{
							std::cout << "No duplicates allowd in this tree. Insert a differen key value." << std::endl;
							return;
						}

						else if(n->key < ptr->key && ptr->left == NULL)
						{
							ptr->left = n;
							std::cout << "Left Node Appended" << std::endl;
							break;
						}

						else if(n->key < ptr->key)
						{
							ptr = ptr->left;
						}

						else if(n->key > ptr->key && ptr->right == NULL)
						{
							ptr->right = n;
							std::cout << "Right Node Appended" << std::endl;
							break;
						}

						else if(n->key > ptr->key)
						{
							ptr = ptr->right;
						}
					}

			}
		}

	



};

int main()
{

	return 0;
}
