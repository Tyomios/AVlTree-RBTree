#pragma once
#ifndef _H_RBTREEMENU_F4A2BB
#define _H_RBTREEMENU_F4A2BB

#include "RBTree.h"

/// @brief Меню для красно-черного дерева
///
/// @param tree Красно-черное дерево
void RBTreeMenu(RBTree* tree);

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
