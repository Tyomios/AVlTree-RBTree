#pragma once
#ifndef _H_COMMON_E67C
#define _H_COMMON_E67C

#include "AVLTree.h"
#include "RBTree.h"

/// @brief ���� ��� ������ � ���-�������
///
/// @param tree ������������ ���-������
void AVLTreeMenu(AVLTree* tree);

/// @brief ���� ��� ������-������� ������
///
/// @param tree ������-������ ������
void RBTreeMenu(RBTree* tree);

/// @brief ������� ����������� ������ �����-�������
///
/// @param treeNode ���� ������
/// @param indent ���������� ����� ������������ ����� 
void ShowTree(AVLNode* treeNode, int indent);

/// @brief ������� ��������� ����������� �������� 
///
/// @return ���������� ��������
int GetValue();

/// @brief ������� ��������� ����� ����
///
/// @param node ���� ������
/// 
/// @retval 4 ���� ���� �������
/// @retval 0 ���� ���� ������
/// @return ������������� ��������
int Getcolor(RBTreeNode* node);

/// @brief ������� ���� ���� � �������
/// @param node ���� ������
void PaintNode(RBTreeNode* node);

/// @brief ������� ����������� ������-������� ������ �����-�������
///
/// @param node ���� ������
/// @param tree ������������ ������
/// @param indent ��������� ����� ������
void PaintTree(RBTreeNode* node, RBTree* tree, const int indent);
#endif