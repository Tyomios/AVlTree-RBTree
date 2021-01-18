#pragma once
#ifndef _H_AVLTREE_CA432
#define _H_AVLTREE_CA432

struct AVLNode
{
	int Key;						//< ������ 
	unsigned char Height = 1;		//< ������ 
	AVLNode* LeftNode  = nullptr;	//< ��������� �� ����� �������� ����
	AVLNode* RightNode = nullptr;	//< ��������� �� ������ �������� ����
};


struct AVLTree
{
	AVLNode* RootNode;				//< ������ ������
};

/// @brief ������� ������������� ���-������
///
/// @param tree ���������������� ������
void InitTree(AVLTree*& tree);

/// @brief ������� ��������� ���-������
///
/// @param treeNode ��������� ���-������
void DeleteTree(AVLNode* treeNode);

/// @brief ������� ��������� ������ ���� ������
///
/// @param treeNode  ���� ������
/// 
/// @return ������ ������� ����
unsigned char GetHeight(AVLNode* treeNode);

/// @brief ������� �������� ������� ����� �������� �����
///
/// @param treeNode  ���� ������ � ��������� ������
/// 
/// @return �����, ������������ ������� ����� 
int GetBalanceFactor(AVLNode* treeNode);

/// @brief ������� ������������� ������ 
///
/// @param treeNode ���� ������, ������ �������� ����� ���������
void FixHeight(AVLNode* treeNode);

/// @brief  ������� ������ ��������  
///
/// @param treeNode ���� ������
/// 
/// @return ��������� �� ����, ����� �������� 
AVLNode* RotateLeft(AVLNode* treeNode);

/// @brief  ������� ������� �������� 
///
/// @param treeNode ���� ������
/// 
/// @return ��������� �� ����, ����� ��������
AVLNode* RotateRight(AVLNode* treeNode);

/// @brief ������� ������������ 
///
/// @param treeNode ���� ������
/// 
/// @return ��������� �� ����� ������
AVLNode* Balance(AVLNode* treeNode);

/// @brief  ������� ������� ��������
///
/// @param treeNode ���� ������
/// @param key ������ ������ ����
/// 
/// @return ����� ������
AVLNode* Insert(AVLNode* treeNode, int key);

/// @brief ������� ������ �������� �� �����
///
/// @param treeNode ���� ������
/// @param key ������� ������
///  
/// @return ��������� �� �������, � ������� 
AVLNode* Find(AVLNode* treeNode, int key);

/// @brief ������� �������� ���� �� �����
///
/// @param treeNode ���� ������
/// @param key ��������� ������
///  
/// @return ��������� �� ����� ������
AVLNode* Remove(AVLNode* treeNode, int key);

/// @brief ������� ������ ����������� �������� � ������
///
/// @param treeNode ���� ������
/// 
/// @return ��������� �� �������, � ����������� ���������
AVLNode* FindMinimal(AVLNode* treeNode);

/// @brief ������� �������� ����������� �������� � ������
///
/// @param treeNode ���� ������
/// 
/// @return ��������� �� ����� ������
AVLNode* RemoveMinimal(AVLNode* treeNode);
#endif