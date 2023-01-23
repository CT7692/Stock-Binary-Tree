//*****************************************************************************************************
//
//		File:				Stock.cpp
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
//					 the stock class, which will store 
//					 all relevant information of a stock.
//
//
//      Other files required: Stock.h
//							  TreeStockDriver.cpp
//							  BinarySearchTree.h
//							  Node.h							 
//
//*****************************************************************************************************


#include "Stock.h"

#include<iostream>
#include<iomanip>

using namespace std;

//*****************************************************************************************************

Stock::Stock(const string& na, const string& sym, double pri)
{
	symbol = sym;
	name = na;
	price = pri;
}

//*****************************************************************************************************

Stock::Stock(const Stock& s)
{
	this->symbol = s.symbol;
	this->name = s.name;
	this->price = s.price;
}

//*****************************************************************************************************

istream& operator >> (istream& strm, Stock& sto)
{
	getline(strm, sto.name);
	getline(strm, sto.symbol);
	strm >> sto.price;
	if (!strm.eof())
		strm.ignore();

	return strm;
}

//*****************************************************************************************************

ostream& operator << (ostream& strm, Stock& sto)
{
	strm << setw(4) << left << sto.getSymbol() << " " 
		<< setw(23) << sto.getName() << " $" << sto.getPrice();

	return strm;
}

//*****************************************************************************************************