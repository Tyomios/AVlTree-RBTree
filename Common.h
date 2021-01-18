#pragma once
#ifndef _H_COMMON_E67C
#define _H_COMMON_E67C

#include "AVLTree.h"
#include "RBTree.h"

/// @brief Меню для работы с АВЛ-деревом
///
/// @param tree Используемое АВЛ-дерево
void AVLTreeMenu(AVLTree* tree);

/// @brief Меню для красно-черного дерева
///
/// @param tree Красно-черное дерево
void RBTreeMenu(RBTree* tree);

/// @brief Функция отображения дерева слева-направо
///
/// @param treeNode Узел дерева
/// @param indent Расстояние между отображением узлов 
void ShowTree(AVLNode* treeNode, int indent);

/// @brief Функция получения корректного значения 
///
/// @return Корректное значение
int GetValue();

/// @brief Функция получения цвета узла
///
/// @param node Узел дерева
/// 
/// @retval 4 если узел красный
/// @retval 0 если узел черный
/// @return целочисленное значение
int Getcolor(RBTreeNode* node);

/// @brief Измняет цвет узла в консоли
/// @param node Узел дерева
void PaintNode(RBTreeNode* node);

/// @brief Функция отображения красно-черного дерева слева-направо
///
/// @param node Узел дерева
/// @param tree Используемое дерево
/// @param indent Растояние между узлами
void PaintTree(RBTreeNode* node, RBTree* tree, const int indent);
#endif