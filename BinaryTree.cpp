/**
 *	Author: Caleb A. Payton
 *
 *	Binary search tree.
 *	Uses recursion to build tree
 *
 */

#include <iostream>

using namespace std;

class binaryTree
{
	private:
		struct treeNode
		{
			int data;
			treeNode * left;
			treeNode * right;
		};
		typedef treeNode * treePtr;
		treePtr root;
	public:
		binaryTree()
		{
			root = NULL;
		}
		~binaryTree()
		{
			deleteTree(root);
		}
		void insert(int newDataValue)
		{
			if (root != NULL)
			{
				privateInsert(newDataValue, root);
			}
			else
			{
				root = new treeNode;
				root->data = newDataValue;
				root->left = NULL;
				root->right = NULL;
			}
		}
	/*	void printBinaryTree()
		{
			if (root == NULL)
			{
				cout << "No data stored in binary tree." << endl;
			}
			privatePrintBT(root);
		}	*/
	
	private:
		void privateInsert(int newDataValue, treeNode * leaf)
		{
			if (newDataValue < leaf->data)
			{
				if (leaf->left != NULL)
				{
					privateInsert(newDataValue, leaf->left);
				}
				else
				{
					leaf->left = new treeNode;
					leaf->left->data = newDataValue;
					leaf->left->left = NULL;
					leaf->left->right = NULL;
				}
			}
			else if (newDataValue >= leaf->data)
			{
				if (leaf->right != NULL)
				{
					privateInsert(newDataValue, leaf->right);
				}
				else
				{
					leaf->right = new treeNode;
					leaf->right->data = newDataValue;
					leaf->right->left = NULL;
					leaf->right->right = NULL;
				}
			}
		}
		void deleteTree(treeNode * leaf)
		{
			if (leaf != NULL)
			{
				deleteTree(leaf->left);
				deleteTree(leaf->right);
				delete leaf;
			}
		}
	/*	void privatePrintBT(treeNode * rootPtr)
		{
			if (rootPtr != NULL)
			{
				cout << rootPtr->data << " ";
				if (rootPtr->left != NULL)
				{
					privatePrintBT(rootPtr->left);
				}
				if (rootPtr->right != NULL)
				{
					privatePrintBT(rootPtr->right);
				}
			}
			else
			{
				return;
			}
		}	*/
};

int main ()
{
	binaryTree bt;
	bt.insert(5);
	bt.insert(6);
	bt.insert(4);
	bt.insert(2);
//	bt.printBinaryTree();
}

