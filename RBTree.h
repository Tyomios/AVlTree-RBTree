#pragma once
#ifndef _H_RDTREE_A34EFF
#define _H_RDTREE_A34EFF

struct RBTreeNode
{
	int Data;						//< Данные
	bool IsRed = true;				//< Цвет узла
	RBTreeNode* Left = nullptr;		//< Указатель на левого потомка
	RBTreeNode* Right = nullptr;	//< Указатель на правого потомка
	RBTreeNode* Parent = nullptr;	//< Указатель на родительский узел
};


struct RBTree
{
	RBTreeNode* Root = nullptr;		//< Корень дерева
	RBTreeNode* Nil;				//< Листовой узел
};

/// @brief Функция инициализации дерева
///
/// @param tree Инициализируемое дерево
void InitTree(RBTree*& tree);

/// @brief Функция отчистки дерева
///
/// @param node Узел дерева
/// 
/// @param tree Удаляемое дерево
void FreeTree(RBTreeNode* node, RBTree* tree);

/// @brief Функция левого поворота
///
/// @param node Узел, относительно которого произведется поворот
/// @param tree Используемое дерево
void RotateLeft(RBTreeNode* node, RBTree* tree);

/// @brief Функция правого поворота
///
/// @param node Узел, относительно которого произведется поворот
/// @param tree Используемое дерево
void RotateRight(RBTreeNode* node, RBTree* tree);

/// @brief Функция добавления узла в дерево
///
/// @param tree Используемое дерево
/// @param data Данные для нового узла
/// @return Указатель на узел
RBTreeNode* Add(RBTree* tree, int data);

/// @brief Функция корректировки дерева, после добавления узла
///
/// @param node Узел для корректировки
/// @param tree Используемое дерево
void FixAdd(RBTreeNode* node, RBTree*& tree);

/// @brief Функция удаления узла из дерева
///
/// @param node Адрес удаляемого узла
/// @param tree Используемое дерево
void RemoveNode(RBTreeNode* node, RBTree* tree);

/// @brief Функция корректировки дерева, после удаления узла
///
/// @param node Узел для корректировки
/// @param tree Используемое дерево
void FixRemove(RBTreeNode* node, RBTree* tree);

/// @brief Функция поиска узла в дереве по значению
///
/// @param data Искомое значение
/// @param tree Используемое дерево
/// 
/// @retval nullptr если узел с данными не существует
/// @return Адрес узла с данным значением
RBTreeNode* FindNode(int data, RBTree* tree);
#endif