#include "AVLTree.h"

void InitTree(AVLTree*& tree)
{
	tree->RootNode = nullptr;
}


void DeleteTree(AVLNode* treeNode)
{
	if (treeNode == nullptr)
	{
		return;
	}

	DeleteTree(treeNode->LeftNode);
	DeleteTree(treeNode->RightNode);
	delete treeNode;
}


unsigned char GetHeight(AVLNode* treeNode)
{
	return treeNode ? treeNode->Height : 0;
}


int GetBalanceFactor(AVLNode* treeNode)
{
	return static_cast<int>(GetHeight(treeNode->RightNode) - GetHeight(treeNode->LeftNode));
}


void FixHeight(AVLNode* treeNode)
{
	unsigned char heightLeft = GetHeight(treeNode->LeftNode);
	unsigned char heightRight = GetHeight(treeNode->RightNode);
	treeNode->Height = (heightLeft > heightRight ? heightLeft : heightRight) + 1;
}


AVLNode* RotateLeft(AVLNode* treeNode)
{
	AVLNode* current = treeNode->RightNode;

	treeNode->RightNode = current->LeftNode;
	current->LeftNode = treeNode;
	
	FixHeight(treeNode);
	FixHeight(current);

	return current;
}


AVLNode* RotateRight(AVLNode* treeNode)
{
	AVLNode* current = treeNode->LeftNode;

	treeNode->LeftNode = current->RightNode;
	current->RightNode = treeNode;

	FixHeight(treeNode);
	FixHeight(current);

	return current;
}


AVLNode* Balance(AVLNode* treeNode)
{
	FixHeight(treeNode);

	if (GetBalanceFactor(treeNode) == 2)
	{
		if (GetBalanceFactor(treeNode->RightNode) < 0)
		{
			treeNode->RightNode = RotateRight(treeNode->RightNode);
		}
		return RotateLeft(treeNode);
	}

	if (GetBalanceFactor(treeNode) == -2)
	{
		if (GetBalanceFactor(treeNode->LeftNode) > 0)
		{
			treeNode->LeftNode = RotateLeft(treeNode->LeftNode);
		}
		return RotateRight(treeNode);
	}
	return treeNode;
}


AVLNode* Insert(AVLNode* treeNode, int key)
{
	if (treeNode == nullptr)
	{
		treeNode = new AVLNode;
		treeNode->Key = key;
		return treeNode;
	}

	if (key < treeNode->Key)
	{
		treeNode->LeftNode = Insert(treeNode->LeftNode, key);
	}
	else
	{
		treeNode->RightNode = Insert(treeNode->RightNode, key);
	}

	return Balance(treeNode);
}


AVLNode* Find(AVLNode* treeNode, int key)
{
	if (treeNode == nullptr)
	{
		return nullptr;
	}

	if (treeNode->Key == key)
	{
		return treeNode;
	}

	if (treeNode->Key > key)
	{
		return Find(treeNode->LeftNode, key);
	}

	return Find(treeNode->RightNode, key);
}


AVLNode* Remove(AVLNode* treeNode, int key)
{
	if (treeNode == nullptr)
	{
		return nullptr;
	}

	if (key < treeNode->Key)
	{
		treeNode->LeftNode = Remove(treeNode->LeftNode, key);
	}
	else if (key > treeNode->Key)
	{
		treeNode->RightNode = Remove(treeNode->RightNode, key);
	}
	else
	{
		AVLNode* leftPoint = treeNode->LeftNode;
		AVLNode* rightPoint = treeNode->RightNode;
		delete treeNode;

		if (rightPoint == nullptr)
		{
			return leftPoint;
		}

		AVLNode* minimal = FindMinimal(rightPoint);
		minimal->RightNode = RemoveMinimal(rightPoint);
		minimal->LeftNode = leftPoint;

		return Balance(minimal);
	}

	return Balance(treeNode);
}


AVLNode* FindMinimal(AVLNode* treeNode)
{
	return treeNode->LeftNode ? FindMinimal(treeNode->LeftNode) : treeNode;
}


AVLNode* RemoveMinimal(AVLNode* treeNode)
{
	if (treeNode->LeftNode == nullptr)
	{
		return treeNode->RightNode;
	}

	treeNode->LeftNode = RemoveMinimal(treeNode->LeftNode);

	return Balance(treeNode);
}