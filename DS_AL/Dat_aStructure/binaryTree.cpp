#include <iostream>
#include <vector>

typedef int BTData;

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;
} BTreeNode;

/*** BTreeNode ���� ����� ****/
BTreeNode* MakeBTreeNode(void) 
{
	BTreeNode* nd = (BTreeNode*)malloc(sizeof(BTreeNode));
	nd->left = NULL;
	nd->right = NULL;
	return nd;
}

BTData GetData(BTreeNode* bt) 
{
	return bt->data;
}

void SetData(BTreeNode* bt, BTData data) 
{
	bt->data = data;
}

BTreeNode* GetLeftSubTree(BTreeNode* bt) 
{
	if (bt->left == nullptr) 
	{
		//return;//오류
	}
	return bt->left;
}
BTreeNode* GetRightSubTree(BTreeNode* bt) 
{
	if (bt->right == nullptr)
	{
		//return ;//오류
	}
	return bt->right;
}

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub) 
{
	if (main->left != NULL)
		free(main->left);

	main->left = sub;
}
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub) 
{
	if (main->right != NULL)
		free(main->right);

	main->right = sub;
}