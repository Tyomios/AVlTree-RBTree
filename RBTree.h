#pragma once
#ifndef _H_RDTREE_A34EFF
#define _H_RDTREE_A34EFF

struct RBTreeNode
{
	int Data;						//< ������
	bool IsRed = true;				//< ���� ����
	RBTreeNode* Left = nullptr;		//< ��������� �� ������ �������
	RBTreeNode* Right = nullptr;	//< ��������� �� ������� �������
	RBTreeNode* Parent = nullptr;	//< ��������� �� ������������ ����
};


struct RBTree
{
	RBTreeNode* Root = nullptr;		//< ������ ������
	RBTreeNode* Nil;				//< �������� ����
};

/// @brief ������� ������������� ������
///
/// @param tree ���������������� ������
void InitTree(RBTree*& tree);

/// @brief ������� �������� ������
///
/// @param node ���� ������
/// 
/// @param tree ��������� ������
void FreeTree(RBTreeNode* node, RBTree* tree);

/// @brief ������� ������ ��������
///
/// @param node ����, ������������ �������� ������������ �������
/// @param tree ������������ ������
void RotateLeft(RBTreeNode* node, RBTree* tree);

/// @brief ������� ������� ��������
///
/// @param node ����, ������������ �������� ������������ �������
/// @param tree ������������ ������
void RotateRight(RBTreeNode* node, RBTree* tree);

/// @brief ������� ���������� ���� � ������
///
/// @param tree ������������ ������
/// @param data ������ ��� ������ ����
/// @return ��������� �� ����
RBTreeNode* Add(RBTree* tree, int data);

/// @brief ������� ������������� ������, ����� ���������� ����
///
/// @param node ���� ��� �������������
/// @param tree ������������ ������
void FixAdd(RBTreeNode* node, RBTree*& tree);

/// @brief ������� �������� ���� �� ������
///
/// @param node ����� ���������� ����
/// @param tree ������������ ������
void RemoveNode(RBTreeNode* node, RBTree* tree);

/// @brief ������� ������������� ������, ����� �������� ����
///
/// @param node ���� ��� �������������
/// @param tree ������������ ������
void FixRemove(RBTreeNode* node, RBTree* tree);

/// @brief ������� ������ ���� � ������ �� ��������
///
/// @param data ������� ��������
/// @param tree ������������ ������
/// 
/// @retval nullptr ���� ���� � ������� �� ����������
/// @return ����� ���� � ������ ���������
RBTreeNode* FindNode(int data, RBTree* tree);
#endif