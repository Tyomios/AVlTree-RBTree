#include "AVLTreeMenu.h"
#include "Common.h"

void AVLTreeMenu(AVLTree* tree)
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
		std::cout << "Here is AVL-tree:" << std::endl;
		ShowTree(tree->RootNode, 3);
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

			std::cout	<< "Node with value " << key
						<< " has address: "
						<< Find(tree->RootNode, key) << std::endl;;
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