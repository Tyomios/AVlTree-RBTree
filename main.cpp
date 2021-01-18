#include "AVLTree.h"
#include "RBTree.h"
#include "Common.h"

#include <iostream>
#include <iomanip>


enum class StructMenu
{
	AVLTree = 1,
	RBTree = 2,
	Exit = 0
}; 


int main()
{
	bool exitProgramm = false;
	while (exitProgramm != true)
	{
		std::cout	<< "Choose one of the struct:\n"
					<< "1 - AVL-tree\n"
					<< "2 - RB-tree\n" 
					<< "0 - Exit"	<< std::endl;

		int structChoose = GetValue();

		switch (static_cast<StructMenu>(structChoose))
		{
			case StructMenu::AVLTree:
			{
				AVLTree* tree = new AVLTree;
				AVLTreeMenu(tree);
				DeleteTree(tree->RootNode);
				break;
			}
			case StructMenu::RBTree:
			{
				RBTree* rbTree = new RBTree;
				RBTreeMenu(rbTree);
				FreeTree(rbTree->Root, rbTree);
				break;
			}
			case StructMenu::Exit:
			{
				exitProgramm = true;
				break;
			}
			default:
			{
				std::cout << "Unknown command (" << std::endl;
				system("pause");
				break;
			}
			
		}
		system("cls");
	}
	return 0;
}