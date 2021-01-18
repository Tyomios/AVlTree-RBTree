#include "RBTreeMenu.h"
#include "Common.h"


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
			std::cout << "Node with value " << key
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