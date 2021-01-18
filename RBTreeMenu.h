#pragma once
#ifndef _H_RBTREEMENU_F4A2BB
#define _H_RBTREEMENU_F4A2BB

#include "RBTree.h"

/// @brief ���� ��� ������-������� ������
///
/// @param tree ������-������ ������
void RBTreeMenu(RBTree* tree);

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
