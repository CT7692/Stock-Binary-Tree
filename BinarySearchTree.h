//*****************************************************************************************************
//
//		File:				BinarySearchTree.h
//
//		Student:			Joseph Rydel
//
//		Assignment:	 		Assignment  #6
//
//		Course Name:		Data Structures II
//
//		Course Number:		COSC 3100 - 01
//
//		Due:				March 07, 2022
//
//		Modification Date:	August 31, 2022
// 
//		Description: This program is an implementation of
//					 a binary search tree.
//
//
//      Other files required: Stock.h
//							  Stock.cpp
//							  TreeStockDriver.cpp
//							  Node.h							 
//
//*****************************************************************************************************

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "Node.h"
#include <ostream>

//*****************************************************************************************************

template<typename T>
class BinarySearchTree
{

private:
	Node<T>* root;
	void deleteTree(Node<T>*& r);
	void insert(Node<T>*& r, const T& dataIn, std::ostream& os);
	void invert(Node<T>*& r);
	void inOrder(Node<T>* r, std::ostream& os) const;
	void preOrder(Node<T>* r, std::ostream& os) const;
	void postOrder(Node<T>* r, std::ostream& os) const;
	T* search(Node<T>* r, const T&) const;
	int height(Node<T>* r) const;
	int max(int, int) const;

public:
	BinarySearchTree();
	~BinarySearchTree();
	void destroy();
	void insert(const T& dataIn, std::ostream& os = std::cout);
	void invert();
	void inOrder(std::ostream& os = std::cout) const;
	void preOrder(std::ostream& os = std::cout) const;
	void postOrder(std::ostream& os = std::cout) const;
	T* search(const T& desiredData) const;
	int height() const;
};

//*****************************************************************************************************

template<typename T>
inline BinarySearchTree<T>::BinarySearchTree()
	{	root = nullptr;	}

//*****************************************************************************************************

template<typename T>
inline BinarySearchTree<T>::~BinarySearchTree()
	{	deleteTree(root);	}

//*****************************************************************************************************

template<typename T>
inline void BinarySearchTree<T>::destroy()
	{	deleteTree(root);	}

//*****************************************************************************************************

template<typename T>
inline void BinarySearchTree<T>::insert(const T& dataIn, std::ostream& os)
	{	insert(root, dataIn, os);	}

//*****************************************************************************************************

template<typename T>
inline void BinarySearchTree<T>::inOrder(std::ostream& os) const
	{	inOrder(root, os);	}

//*****************************************************************************************************

template<typename T>
inline void BinarySearchTree<T>::preOrder(std::ostream& os) const
	{	preOrder(root, os);	}

//*****************************************************************************************************

template<typename T>
inline void BinarySearchTree<T>::postOrder(std::ostream& os) const
	{	postOrder(root, os);	}

//*****************************************************************************************************

template<typename T>
inline void BinarySearchTree<T>::invert()
	{	invert(root);	}

//*****************************************************************************************************


template<typename T>
T* BinarySearchTree<T>::search(const T& desiredData) const
{
	T* ptr;
	ptr = search(root, desiredData);
	return ptr;
}

//*****************************************************************************************************

template<typename T>
int BinarySearchTree<T>::height() const
{
	int h = height(root);
	return h;
}

//*****************************************************************************************************

template<typename T>
inline int BinarySearchTree<T>::max(int a, int b) const
	{	return (a > b) ? a : b;	}

//*****************************************************************************************************

template<typename T>
void BinarySearchTree<T>::deleteTree(Node<T>*& r)
{
	if (r != nullptr)
	{
		deleteTree(r->left);
		deleteTree(r->right);
		delete r;
		r = nullptr;
	}
}

//*****************************************************************************************************

template<typename T>
int BinarySearchTree<T>::height(Node<T>* r) const
{
	int result;

	if (r == nullptr)
		result = 0;

	else
		result = 1 + max(height(r->left), height(r->right));

	return result;
}

//*****************************************************************************************************

template<typename T>
void BinarySearchTree<T>::insert(Node<T>*& r, const T& dataIn, std::ostream& os)
{
	if (r == nullptr)
	{	
		r = new Node<T>;
		r->data = dataIn;

		r->left = nullptr;
		r->right = nullptr;
	}

	else if (dataIn < r->data)
		insert(r->left, dataIn, os);

	else if (dataIn > r->data)
		insert(r->right, dataIn, os);

	else
		os << "Duplicate node. Cancelled. \n";
}

//*****************************************************************************************************

template<typename T>
void BinarySearchTree<T>::invert(Node<T>*& ptr)
{
	if (ptr == nullptr)
		ptr = nullptr;

	else
	{
		if (ptr->left != nullptr || ptr->right != nullptr)
		{
			Node<T>* pHolder = ptr->left;
			ptr->left = ptr->right;
			ptr->right = pHolder;
			invert(ptr->left);
			invert(ptr->right);
		}
	}
}

//*****************************************************************************************************

template<typename T>
void BinarySearchTree<T>::inOrder(Node<T>* r, std::ostream& os) const
{
	if (r != nullptr)
	{
		inOrder(r->left, os);

		os << r->data << "\n";

		inOrder(r->right, os);
	}
}

//*****************************************************************************************************

template<typename T>
void BinarySearchTree<T>::preOrder(Node<T>* r, std::ostream& os) const
{
	if (r != nullptr)
	{
		os << r->data << "\n";

		preOrder(r->left, os);
		preOrder(r->right, os);
	}
}

//*****************************************************************************************************

template<typename T>
void BinarySearchTree<T>::postOrder(Node<T>* r, std::ostream& os) const
{
	if (r != nullptr)
	{
		postOrder(r->left, os);
		postOrder(r->right, os);

		os << r->data << "\n";
	}
}

//*****************************************************************************************************

template<typename T>
T* BinarySearchTree<T>::search(Node<T>* r, const T& desiredData) const
{
	T* ptr;

	if (r == nullptr)
		ptr = nullptr;

	else if (desiredData < r->data)
		ptr = search(r->left, desiredData);

	else if (desiredData > r->data)
		ptr = search(r->right, desiredData);

	else
		ptr = new T(r->data);

	return ptr;
}

//*****************************************************************************************************

#endif