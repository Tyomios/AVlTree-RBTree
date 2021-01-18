#include "RBTree.h"

void InitTree(RBTree*& tree)
{
	tree->Nil = new RBTreeNode;
	tree->Nil->IsRed = false;
	tree->Nil->Left = tree->Nil->Right = nullptr;
}


void FreeTree(RBTreeNode* node, RBTree* tree)
{
	if (node == nullptr || node == tree->Nil)
	{
		return;
	}

	FreeTree(node->Left, tree);
	FreeTree(node->Right, tree);
	delete node;
}


void RotateLeft(RBTreeNode* node, RBTree* tree)
{
	RBTreeNode* rightChild = node->Right;

	// ������������� ����� ��� ������� �������
	node->Right = rightChild->Left;

	if (rightChild->Left != tree->Nil)
	{
		rightChild->Left->Parent = node;
	}
	//�������������� ����� ������������� ����
	if (rightChild != tree->Nil)
	{
		rightChild->Parent = node->Parent;
	}
	if (node->Parent != nullptr)
	{
		if (node == node->Parent->Left)
		{
			node->Parent->Left = rightChild;
		}
		else
		{
			node->Parent->Right = rightChild;
		}

	}
	else
	{
		tree->Root = rightChild;
	}

	//��������� node � �������
	rightChild->Left = node;
	if (node != tree->Nil)
	{
		node->Parent = rightChild;
	}
}


void RotateRight(RBTreeNode* node, RBTree* tree)
{
	RBTreeNode* leftChild = node->Left;

	//������������� ����� ��� ������ �������
	node->Left = leftChild->Right;
	if (leftChild->Right != tree->Nil)
	{
		leftChild->Right->Parent = node;
	}

	//������������� ����� ���������
	if (leftChild != tree->Nil)
	{
		leftChild->Parent = node->Parent;
	}
	if (node->Parent != nullptr)
	{
		if (node == node->Parent->Right)
		{
			node->Parent->Right = leftChild;
		}
		else
		{
			node->Parent->Left = leftChild;
		}
	}
	else
	{
		tree->Root = leftChild;
	}

	//��������� node � �������
	leftChild->Right = node;
	if (node != tree->Nil)
	{
		node->Parent = leftChild;
	}
}


RBTreeNode* Add(RBTree* tree, int data)
{
	RBTreeNode* node = new RBTreeNode;
	RBTreeNode* current = tree->Root;
	RBTreeNode* parent = nullptr;
	if (tree->Root == nullptr)
	{
		node->Data = data;
		node->IsRed = false;
		node->Left = tree->Nil;
		node->Right = tree->Nil;
		tree->Root = node;
		return node;
	}

	//����� ����� ��� ����
	while (current != tree->Nil)
	{
		if (data == current->Data)
		{
			return current;
		}

		parent = current;
		if (data < current->Data)
		{
			current = current->Left;
		}
		else
		{
			current = current->Right;
		}
	}
	node->Data = data;
	node->Parent = parent;
	node->Left = node->Right = tree->Nil;
	node->IsRed = true;

	//������� ���� � ������
	if (parent != nullptr)
	{
		if (data < parent->Data)
		{
			parent->Left = node;
		}
		else
		{
			parent->Right = node;
		}
	}
	else
	{
		tree->Root = node;
	}

	FixAdd(node, tree);
	return node;
}


void FixAdd(RBTreeNode* node, RBTree*& tree)
{
	//�������� �����
	while (node != tree->Root && node->Parent->IsRed == true)
	{
		//���� - ����� �������
		if (node->Parent == node->Parent->Parent->Left)
		{
			RBTreeNode* uncle = node->Parent->Parent->Right;

			// ������ "���� - �������"
			if (uncle->IsRed == true)
			{
				node->Parent->IsRed = false;
				uncle->IsRed = false;
				node->Parent->Parent->IsRed = true;
				node = node->Parent->Parent;
			}

			// ������ "���� - ר����"
			else
			{
				if (node == node->Parent->Right)
				{
					node = node->Parent;
					RotateLeft(node, tree);
				}

				node->Parent->IsRed = false;
				node->Parent->Parent->IsRed = true;
				RotateRight(node->Parent->Parent, tree);
			}
		}

		//���� - ������ �������
		else
		{
			RBTreeNode* uncle = node->Parent->Parent->Left;
			if (uncle->IsRed == true)
			{
				node->Parent->IsRed = false;
				uncle->IsRed = false;
				node->Parent->Parent->IsRed = true;
				node = node->Parent->Parent;
			}
			else
			{
				if (node == node->Parent->Left)
				{
					node = node->Parent;
					RotateRight(node, tree);
				}
				node->Parent->IsRed = false;
				node->Parent->Parent->IsRed = true;
				RotateLeft(node->Parent->Parent, tree);
			}
		}
	}
	tree->Root->IsRed = false;
}


void RemoveNode(RBTreeNode* node, RBTree* tree)
{
	RBTreeNode* temp = new RBTreeNode;
	RBTreeNode* current = new RBTreeNode;

	if (node == nullptr || node == tree->Nil)
	{
		return;
	}
	if (node->Left == tree->Nil || node->Right == tree->Nil)
	{
		current = node;
	}
	//���� ��������� � Nil-�����, � �������� ���������
	else
	{
		current = node->Right;
		while (current->Left != tree->Nil)
		{
			current = current->Left;
		}
	}

	//������ "temp - ������������ ���"
	if (current->Left != tree->Nil)
	{
		temp = current->Left;
	}
	else
	{
		temp = current->Right;
	}

	temp->Parent = current->Parent;
	if (current->Parent != nullptr)
	{
		if (current == current->Parent->Left)
		{
			current->Parent->Left = temp;
		}
		else
		{
			current->Parent->Right = temp;
		}

	}
	else
	{
		tree->Root = temp;
	}

	if (current != node)
	{
		node->Data = current->Data;
	}
	if (current->IsRed == false)
	{
		FixRemove(temp, tree);
	}
	delete current;
}


void FixRemove(RBTreeNode* node, RBTree* tree)
{
	//�������� �����
	while (node != tree->Root && node->IsRed == false)
	{
		//������ "��������� ���� - ����� �������"
		if (node == node->Parent->Left)
		{
			RBTreeNode* brother = node->Parent->Right;
			if (brother->IsRed == true)
			{
				brother->IsRed = false;
				node->Parent->IsRed = true;
				RotateLeft(node->Parent, tree);
				brother = node->Parent->Right;
			}
			if (brother->Left->IsRed == false && brother->Right->IsRed == false)
			{
				brother->IsRed = true;
				node = node->Parent;
			}
			else
			{
				if (brother->Right->IsRed == false)
				{
					brother->Left->IsRed = false;
					brother->IsRed = true;
					RotateRight(brother, tree);
					brother = node->Parent->Right;
				}
				brother->IsRed = node->Parent->IsRed;
				node->Parent->IsRed = false;
				brother->Right->IsRed = false;
				RotateLeft(node->Parent, tree);
				node = tree->Root;
			}
		}
		//������ "��������� ���� - ������ �������"
		else
		{
			RBTreeNode* brother = node->Parent->Left;
			if (brother->IsRed == true)
			{
				brother->IsRed = false;
				node->Parent->IsRed = true;
				RotateRight(node->Parent, tree);
				brother = node->Parent->Left;
			}
			if (brother->Right->IsRed == false && brother->Left->IsRed == false)
			{
				brother->IsRed = true;
				node = node->Parent;
			}
			else
			{
				if (brother->Left->IsRed == false)
				{
					brother->Right->IsRed = false;
					brother->IsRed = true;
					RotateLeft(brother, tree);
					brother = node->Parent->Left;
				}
				brother->IsRed = node->Parent->IsRed;
				node->Parent->IsRed = false;
				brother->Left->IsRed = false;
				RotateRight(node->Parent, tree);
				node = tree->Root;
			}
		}
	}
	node->IsRed = false;
}


RBTreeNode* FindNode(int data, RBTree* tree)
{
	RBTreeNode* current = tree->Root;
	while (current != tree->Nil)
	{
		if (data == current->Data)
		{
			return current;
		}

		if (data < current->Data)
		{
			current = current->Left;
		}
		else
		{
			current = current->Right;
		}
	}
	return nullptr;
}