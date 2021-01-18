#pragma once
#ifndef _H_AVLTREE_CA432
#define _H_AVLTREE_CA432

struct AVLNode
{
	int Key;						//< Данные 
	unsigned char Height = 1;		//< Высота 
	AVLNode* LeftNode  = nullptr;	//< Указатель на левый дочерний узел
	AVLNode* RightNode = nullptr;	//< Указатель на правый дочерний узел
};


struct AVLTree
{
	AVLNode* RootNode;				//< Корень дерева
};

/// @brief Функция инициализация АВЛ-дерева
///
/// @param tree Инициализируемое дерево
void InitTree(AVLTree*& tree);

/// @brief Функция удалениея АВЛ-дерева
///
/// @param treeNode Удаляемое АВЛ-дерево
void DeleteTree(AVLNode* treeNode);

/// @brief Функция получения высоты узла дерева
///
/// @param treeNode  Узел дерева
/// 
/// @return Высоту данного узла
unsigned char GetHeight(AVLNode* treeNode);

/// @brief Функция подсчета разницы высот дочерних узлов
///
/// @param treeNode  Узел дерева с дочерними узлами
/// 
/// @return Число, отображающее разницу высот 
int GetBalanceFactor(AVLNode* treeNode);

/// @brief Функция корректировки высоты 
///
/// @param treeNode Узел дерева, высоту которого нужно настроить
void FixHeight(AVLNode* treeNode);

/// @brief  Функция левого вращения  
///
/// @param treeNode Узел дерева
/// 
/// @return Указатель на узел, после вращения 
AVLNode* RotateLeft(AVLNode* treeNode);

/// @brief  Функция правого вращения 
///
/// @param treeNode Узел дерева
/// 
/// @return Указатель на узел, после вращения
AVLNode* RotateRight(AVLNode* treeNode);

/// @brief Функция балансировки 
///
/// @param treeNode Узел дерева
/// 
/// @return Указатель на новый корень
AVLNode* Balance(AVLNode* treeNode);

/// @brief  Функция вставки элемента
///
/// @param treeNode Узел дерева
/// @param key данные нового узла
/// 
/// @return Новый корень
AVLNode* Insert(AVLNode* treeNode, int key);

/// @brief Функция поиска элемента по ключу
///
/// @param treeNode Узел дерева
/// @param key Искомые данные
///  
/// @return Указатель на элемент, с данными 
AVLNode* Find(AVLNode* treeNode, int key);

/// @brief Функция удаления узла по ключу
///
/// @param treeNode Узел дерева
/// @param key Удаляемые данные
///  
/// @return Указатель на новый корень
AVLNode* Remove(AVLNode* treeNode, int key);

/// @brief Функция поиска наименьшего элемента в дереве
///
/// @param treeNode Узел дерева
/// 
/// @return Указатель на элемент, с минимальным значением
AVLNode* FindMinimal(AVLNode* treeNode);

/// @brief Функция удаления наименьшего элемента в дереве
///
/// @param treeNode Узел дерева
/// 
/// @return Указатель на новый корень
AVLNode* RemoveMinimal(AVLNode* treeNode);
#endif