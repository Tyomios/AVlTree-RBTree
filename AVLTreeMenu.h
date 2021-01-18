#pragma once
#ifndef _H_AVLTREEMENU_D52A
#define _H_AVLTREEMENU_D52A

#include "AVLTree.h"

/// @brief ���� ��� ������ � ���-�������
///
/// @param tree ������������ ���-������
void AVLTreeMenu(AVLTree* tree);


/// @brief ������� ����������� ������ �����-�������
///
/// @param treeNode ���� ������
/// @param indent ���������� ����� ������������ ����� 
void ShowTree(AVLNode* treeNode, int indent);
#endif