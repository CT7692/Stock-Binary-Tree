//*****************************************************************************************************
//
//		File:				Node.h
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
//		Description: This program creates a node
//					 for a binary search tree.
//
//
//      Other files required: Stock.cpp
//							  Stock.h
//							  TreeStockDriver.cpp
//							  BinarySearchTree.h	
//
//*****************************************************************************************************

#ifndef NODE_H
#define NODE_H

//*****************************************************************************************************

template<typename T>
struct Node
{
	T data;
	Node<T>* left;
	Node<T>* right;

	Node();
	Node(const T& d, Node<T>* l, Node<T>* r);
};

//*****************************************************************************************************

template<typename T>
Node<T>::Node()
{
	left = nullptr;
	right = nullptr;
}


//*****************************************************************************************************

template<typename T>
Node<T>::Node(const T& d, Node<T>* l, Node<T>* r)
{
	data = d;
	left = l;
	right = r;
}

//*****************************************************************************************************

#endif