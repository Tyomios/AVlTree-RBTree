#include "Common.h"

#include <iostream>
#include <iomanip>
#include <Windows.h>


int GetValue()
{
	int value;
	std::cout << " Enter value:" << std::endl;
	std::cin >> value;

	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		std::cout << "Error. You need to enter digits (like 1 or -6).\n";
		return GetValue();
	}

	return value;
}


void AVLTreeMenu(AVLTree* tree)
{
	enum class Menu
	{
		Add		= 1,
		Remove	= 2,
		Find	= 3,
		Exit	= 0
	};

	InitTree(tree);
	bool endProgramm = false;

	while (!endProgramm)
	{
		std::cout << "Here is AVL-tree:" << std::endl;
		ShowTree(tree->RootNode, 3);
		std::cout	<< "\n1 - Add\n"
					<< "2 - Remove\n"
					<< "3 - Find\n"
					<< "0 - Exit\n"
					<< std::endl;

		int userChoose = GetValue();

		switch (static_cast<Menu>(userChoose))
		{
			case Menu::Add:
			{
				tree->RootNode = Insert(tree->RootNode, GetValue());
				break;
			}
			case Menu::Remove:
			{
				int key = GetValue();
				if (Find(tree->RootNode, key) == nullptr)
				{
					std::cout << "Not found (" << std::endl;
					system("pause");
					break;
				}
				tree->RootNode = Remove(tree->RootNode, key);
				break;
			}
			case Menu::Find:
			{
				int key = GetValue();
				if (Find(tree->RootNode, key) == nullptr)
				{
					std::cout << "Not found (" << std::endl;
					system("pause");
					break;
				}

				std::cout << Find(tree->RootNode, key);
				system("pause");
				break;
			}
			case Menu::Exit:
			{
				endProgramm = true;
				break;
			}
			default:
			{
				std::cout << "Unknown command. Choose one from the list" << std::endl;
				system("pause");
				break;
			}
		}
		system("cls");
	}
}


void ShowTree(AVLNode* treeNode, int indent)
{
	if (treeNode == nullptr)
	{
		return;
	}

	if (treeNode->RightNode)
	{
		ShowTree(treeNode->RightNode, indent + 4);
	}

	if (indent)
	{
		std::cout << std::setw(indent) << ' ';
	}

	if (treeNode->RightNode)
	{
		std::cout << " /\n" << std::setw(indent) << ' ';
	}

	std::cout << treeNode->Key << "\n ";
	if (treeNode->LeftNode)
	{
		std::cout << std::setw(indent) << ' ' << " \\\n";
		ShowTree(treeNode->LeftNode, indent + 4);
	}
}

int Getcolor(RBTreeNode* node)
{
	if (node->IsRed == true)
	{
		return 4;
	}
	return 0;
}

void PaintNode(RBTreeNode* node)
{
	int backGround = 7;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	int color = Getcolor(node);
	SetConsoleTextAttribute(hStdOut, (WORD)((backGround << 4) | color));
}

void PrintTree(RBTreeNode* node, RBTree* tree, const int indent)
{
	if (node == tree->Nil || node == nullptr)
	{
		return;
	}
	if (node->Right != nullptr)
	{
		PrintTree(node->Right, tree, indent + 4);
	}

	if (indent)
	{
		std::cout << std::setw(indent) << ' ';
	}
	if (node->Right == tree->Nil)
	{
		std::cout << " /*\n" << std::setw(indent) << ' ';
	}
	if (node->Right != nullptr && node->Right != tree->Nil)
	{
		std::cout << " /\n" << std::setw(indent) << ' ';
	}

	PaintNode(node);
	if (node != tree->Nil)
	{
		std::cout << node->Data << "\n ";
	}
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((7 << 4) | 0));
	if (node->Left == tree->Nil)
	{
		std::cout << std::setw(indent) << ' ' << " \\\n";
		std::cout << std::setw(indent) << ' ' << "   *\n";
		PrintTree(node->Left, tree, indent + 4);
	}
	if (node->Left != nullptr && node->Left != tree->Nil)
	{
		std::cout << std::setw(indent) << ' ' << " \\\n";
		PrintTree(node->Left, tree, indent + 4);
	}
}

void RBTreeMenu(RBTree* tree)
{
	enum class Menu
	{
		Add = 1,
		Remove = 2,
		Find = 3,
		Exit = 0
	};

	InitTree(tree);
	bool endProgramm = false;

	while (!endProgramm)
	{
		std::cout << "Here is Red-Black tree:" << std::endl;
		PrintTree(tree->Root, tree, 2);
		std::cout << "\n1 - Add\n"
			<< "2 - Remove\n"
			<< "3 - Find\n"
			<< "0 - Exit\n"
			<< std::endl;

		int userChoose = GetValue();

		switch (static_cast<Menu>(userChoose))
		{
		case Menu::Add:
		{
			Add(tree, GetValue());
			break;
		}
		case Menu::Remove:
		{
			int data = GetValue();
			if (FindNode(data, tree) == nullptr)
			{
				std::cout << "Not found" << std::endl;
				system("pause");
				break;
			}
			RemoveNode(FindNode(data, tree), tree);
			break;
		}
		case Menu::Find:
		{
			int key = GetValue();
			if (FindNode(key, tree) == nullptr)
			{
				std::cout << "Not found" << std::endl;
				system("pause");
				break;
			}
			std::cout	<<"Node with value " << key
						<< " has address: "
						<< FindNode(key, tree) << std::endl;
			system("pause");
			break;
		}
		case Menu::Exit:
		{
			endProgramm = true;
			break;
		}
		default:
		{
			std::cout << "Unknown command. Choose one from the list" << std::endl;
			system("pause");
			break;
		}
		}
		system("cls");
	}
}