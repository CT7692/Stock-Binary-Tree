//*****************************************************************************************************
//
//		File:				Stock.h
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
//      Other files required: Stock.cpp
//							  TreeStockDriver.cpp
//							  BinarySearchTree.h	
//							  Node.h						 
//
//*****************************************************************************************************

#ifndef STOCK_H
#define STOCK_H

#include<string>

//*****************************************************************************************************

class Stock
{
private:
	std::string name;
	std::string symbol;
	double price;

public:
	Stock(const std::string& name = "", const std::string& symbol = "", double price = 0);
	Stock(const Stock&);

	std::string getName() const;
	std::string getSymbol() const;
	double getPrice() const;

	bool operator == (const Stock& rhs) const;
	bool operator != (const Stock& rhs) const;
	bool operator < (const Stock& rhs) const;
	bool operator > (const Stock& rhs) const;
	bool operator <= (const Stock& rhs) const;
	bool operator >= (const Stock& rhs) const;
	operator std::string();

	friend std::istream& operator >> (std::istream&, Stock&);
	friend std::ostream& operator << (std::ostream&, Stock&);
};

//*****************************************************************************************************

inline std::string Stock::getName() const
	{	return name;	}

//*****************************************************************************************************

inline std::string Stock::getSymbol() const
	{	return symbol;	}

//*****************************************************************************************************

inline double Stock::getPrice() const
	{	return price;	}

//*****************************************************************************************************

inline bool Stock::operator == (const Stock& rhs) const
	{	return this->symbol == rhs.symbol;	}

//*****************************************************************************************************

inline bool Stock::operator != (const Stock& rhs) const
	{	return this->symbol != rhs.symbol;	}

//*****************************************************************************************************

inline bool Stock::operator < (const Stock& rhs) const
	{	return this->symbol < rhs.symbol;	}

//*****************************************************************************************************

inline bool Stock::operator > (const Stock& rhs) const
	{	return this->symbol > rhs.symbol;	}

//*****************************************************************************************************

inline bool Stock::operator <= (const Stock& rhs) const
	{	return this->symbol <= rhs.symbol;	}

//*****************************************************************************************************

inline bool Stock::operator >= (const Stock& rhs) const
	{	return this->symbol >= rhs.symbol;	}

//*****************************************************************************************************

inline Stock::operator std::string()
	{	return this->symbol;	}

//*****************************************************************************************************

#endif