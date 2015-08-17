#include<iostream>
#include<stdio.h>

using namespace std;

struct BinaryTreeNode
{
	int value;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};

BinaryTreeNode* constructCore(int *startPreorder, int *endPreorder, int *startInorder, int *endInorder);

BinaryTreeNode* construct(int *preorder, int *inorder, int length)
{
	if (preorder == NULL || inorder == NULL || length <= 0)
		return NULL;

	return constructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

BinaryTreeNode* constructCore(int *startPreorder, int *endPreorder, int *startInorder, int *endInorder)
{
	BinaryTreeNode* root = new BinaryTreeNode();
	int rootValue = startPreorder[0];
	root->value = rootValue;
	root->left = root->right = NULL;

	if (startPreorder == endPreorder)
	{
		if (startInorder == endInorder && *startPreorder == *startInorder)
			return root;
		else
			return NULL;
	}

	int *rootInorder = startInorder;
	while (rootInorder <= endInorder && *rootInorder != rootValue)
		rootInorder++;
	if (rootInorder > endInorder && *rootInorder != rootValue)
		return NULL;

	int leftLength = rootInorder - startInorder;
	int *leftPreorderEnd = startPreorder + leftLength;

	if (leftLength > 0)
	{
		root->left = constructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
	}
	if (leftLength < endPreorder - startPreorder)
		root->right = constructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);

	return root;
}

void PostOrder(BinaryTreeNode *root)
{
	if (root == NULL)
		return;

	if (root->left != NULL)
		PostOrder(root->left);

	if (root->right != NULL)
		PostOrder(root->right);

	cout << root->value << ' ';
}

int main()
{
		
	int length =0;
	scanf_s("%d", &length);

	int *preorder = new int[length];
	int *inorder = new int[length];

	for (int cnt = 0; cnt < 2; cnt++)
	{

		for (int i = 0; i < length; ++i)
			scanf_s("%d ", &preorder[i]);
		for (int i = 0; i < length; ++i)
			scanf_s("%d ", &inorder[i]);


		BinaryTreeNode* root = construct(preorder, inorder, length);

		if (root)
			PostOrder(root);
		else
			printf("NO\n");
	}
	

	delete preorder;
	delete inorder;
}
