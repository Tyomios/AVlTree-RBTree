#pragma once
#ifndef _H_AVLTREEMENU_D52A
#define _H_AVLTREEMENU_D52A

#include "AVLTree.h"

/// @brief Меню для работы с АВЛ-деревом
///
/// @param tree Используемое АВЛ-дерево
void AVLTreeMenu(AVLTree* tree);


/// @brief Функция отображения дерева слева-направо
///
/// @param treeNode Узел дерева
/// @param indent Расстояние между отображением узлов 
void ShowTree(AVLNode* treeNode, int indent);
#endif