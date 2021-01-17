#include <iostream>
#include <iomanip>
#include <Windows.h>

struct Node
{
	int Data;
	bool IsRed = true;
	Node* Left = nullptr;
	Node* Right = nullptr;
	Node* Parent = nullptr;
};

struct Tree
{
	Node* Root = nullptr;
	Node* Nil;
};

int Getcolor(Node* node)
{
	if (node->IsRed)
	{
		return 4;
	}
	return 0;
}
void PaintNode(Node* node)
{
	int backGround = 7;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	int color = Getcolor(node);
	SetConsoleTextAttribute(hStdOut, (WORD)((backGround << 4) | color));
}
void PrintTree(Node* node, const int indent)
{
	if (!node)
	{
		return;
	}
	if (node->Right)
	{
		PrintTree(node->Right, indent + 4);
	}

	if (indent)
	{
		std::cout << std::setw(indent) << ' ';
	}

	if (node->Right)
	{
		std::cout << " /\n" << std::setw(indent) << ' ';
	}

	PaintNode(node);
	std::cout << node->Data << "\n ";
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((7 << 4) | 0));
	if (node->Left)
	{
		std::cout << std::setw(indent) << ' ' << " \\\n";
		PrintTree(node->Left, indent + 4);
	}
}

Node* GetGrandfather(Node* node)
{
	if (node->Parent->Parent)
	{
		return node->Parent->Parent;
	}
	return nullptr;
}

Node* GetUncle(Node* node)
{
	Node* parent = node->Parent;
	Node* grandFa = GetGrandfather(node);
	if (!node->Parent || !grandFa)
	{
		return nullptr;
	}
	if (!grandFa->Right && parent == grandFa->Right)
	{
		if (grandFa->Left)
		{
			return grandFa->Left;
		}
	}
	if (grandFa->Right)
	{
		return grandFa->Right;
	}
	return nullptr;
}

Node* leftRotate(Node* treeNode)
{
	Node* current = treeNode->Right;

	treeNode->Right = current->Left;
	current->Left = treeNode;

	return current;
}
Node* rightRotate(Node* treeNode)
{
	Node* current = treeNode->Left;

	treeNode->Left = current->Right;
	current->Right = treeNode;

	return current;
}

void RotateLeft(Node*& root, Node*& node)
{
	Node* rightChild = node->Right;
	node->Right = rightChild->Left;

	if (node->Right)
	{
		node->Right->Parent = node;
	}

	rightChild->Parent = node->Parent;

	if (!node->Parent)
	{
		root = rightChild;
	}
	else if (node == node->Parent->Left)
	{
		node->Parent->Left = rightChild;
	}
	else
	{
		node->Parent->Right = rightChild;
	}

	rightChild->Left = node;
	node->Parent = rightChild;
}
void RotateRight(Node*& root, Node*& node)
{
	Node* leftChild = node->Left;
	node->Left = leftChild->Right;

	if (node->Left)
	{
		node->Left->Parent = node;
	}

	leftChild->Parent = node->Parent;

	if (!node->Parent)
	{
		root = leftChild;
	}
	else if (node == node->Parent->Left)
	{
		node->Parent->Left = leftChild;
	}
	else
	{
		node->Parent->Right = leftChild;
	}

	leftChild->Right = node;
	node->Parent = leftChild;
}


void InitTree(Tree* tree)
{
	tree->Nil = new Node;
	tree->Nil->IsRed = false;
}

Node* fixAdd(Node* node, Tree*& tree)
{
	if (node == tree->Root)
	{
		node->IsRed = false;
		return node;
	}

	Node* parent = node->Parent;
	Node* grandFa = GetGrandfather(node);
	Node* uncle = GetUncle(node);

	if (parent->IsRed)
	{
		if (uncle->IsRed)
		{
			parent->IsRed = false;
			uncle->IsRed = false;
			grandFa->IsRed = true;
			tree->Root->IsRed = false;
		}
		if (!uncle->IsRed)
		{
			if (node == parent->Right)
			{
				node = leftRotate(parent);
				//RotateLeft(tree->Root, parent);
			}
			node = rightRotate(node);
			//RotateRight(tree->Root, node);
		}
	}
}

void Add(Tree*& tree, int data)
{
	Node* node = new Node;
	if (!tree->Root)
	{
		node->Data = data;
		node->IsRed = false;
		node->Left = tree->Nil;
		node->Right = tree->Nil;
		tree->Root = node;
		return;
	}

	Node* temp = tree->Root;
	Node* parent = tree->Nil;

	while (temp != tree->Nil)
	{
		parent = temp;
		if (temp->Data > data)
		{
			temp = temp->Left;
		}
		else 
		{
			temp = temp->Right;
		}
		
	}

	node->Parent = parent;
	node->Data = data;
	if (parent->Data < node->Data)
	{
		parent->Right = node;
	}
	if (parent->Data >= node->Data)
	{
		parent->Left = node;
	}
	node->Right = node->Left = tree->Nil;
	
	node = fixAdd(node, tree);

	return;//fixAdd(node, tree); 
}


int main()
{
	Tree* tree = new Tree;
	InitTree(tree);
	Add(tree, 3);
	Add(tree, 1);
	Add(tree, 5);
	Add(tree, 6);
	Add(tree, 2);
	PrintTree(tree->Root, 3);
	return 0;
}