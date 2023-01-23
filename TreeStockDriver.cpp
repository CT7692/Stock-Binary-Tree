//*****************************************************************************************************
//
//		File:				TreeStockDriver.cpp
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
//					 an interface that stores and accesses
//					 relevant stock data with the use of
//					 a binary tree.
//
//
//      Other files required: Stock.cpp
//							  Stock.h
//							  Node.h
//							  BinarySearchTree.h	
//
//*****************************************************************************************************

#include "Stock.h"
#include "BinarySearchTree.h"

#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdlib>
#include<ctime>

using namespace std;

//*****************************************************************************************************

void getRandNum(BinarySearchTree<int>&);
void stockMenu(BinarySearchTree<Stock>&);
void formList(BinarySearchTree<Stock>&);
void getNewStock(BinarySearchTree<Stock>&);
Stock* retName(BinarySearchTree<Stock>&);
Stock* retPrice(BinarySearchTree<Stock>&);
char getChoice();

//*****************************************************************************************************

int main()
{
	BinarySearchTree<int> numTree;
	BinarySearchTree<Stock> stockTree;

	getRandNum(numTree);
	formList(stockTree);

	stockMenu(stockTree);
	

	return 0;
}

//*****************************************************************************************************

void getRandNum(BinarySearchTree<int> &numTree)
{
	ostream& os = cout;
	
	const int MAX = 5000;
	const int MIN = 0;
	int x;
	unsigned seed = time(0);
	srand(seed);
	
	for (int i = 0; i < 10; i++)
	{
		x = (rand() % (MAX - MIN + 1)) + MIN;
		numTree.insert(x, os);
	}

	cout << "Inorder: " << endl;
	numTree.inOrder(os);
	cout << endl;

	cout << "Preorder: " << endl;
	numTree.preOrder(os);
	cout << endl;

	cout << "Postorder: " << endl;
	numTree.postOrder(os);
	cout << endl;

	cout << "Tree height: ";
	int hei = numTree.height();
	cout << hei << endl;

	numTree.destroy();
	cout << "Tree erased." << endl;
}

//*****************************************************************************************************

void stockMenu(BinarySearchTree<Stock>& stockTree)
{
	Stock info;
	ofstream fout;
	ostream& os = cout;
	char opt = getChoice();
	int i = 0;

	while (opt != 'F')
	{
		if (opt == 'A')
			Stock* stoName = retName(stockTree);

		else if (opt == 'B')
			Stock* stoPrice = retPrice(stockTree);

		else if (opt == 'C')
			getNewStock(stockTree);

		else if (opt == 'D')
		{
			cout << endl;
			stockTree.inOrder(os);
		}

		else if (opt == 'E')
		{
			cout << "\nInverting list...\n" << endl;
			stockTree.invert();
		}

		opt = getChoice();
	}

	fout.open("UpdatedStockList.txt");

	if (fout.fail())
		cout << "Failed to write data." << endl;

	else
	{
		cout << "Writing data..." << endl;
		stockTree.inOrder(fout);
	}

	stockTree.destroy();
	cout << "Tree erased." << endl;
	cout << "Good-bye." << endl;
}

//*****************************************************************************************************

void formList(BinarySearchTree<Stock>& stockTree)
{
	Stock info;
	ifstream fin;
	
	fin.open("Stock.txt");

	if (fin.fail())
		cout << "File failed to load." << endl;

	else
	{
		while (fin >> info) 
			stockTree.insert(info);
		
		cout << "\nFile loaded successfully.\n" << endl;
		fin.close();
	}

	int hei = stockTree.height();
	cout << "Height: " << hei << endl;

}

//*****************************************************************************************************

Stock* retName(BinarySearchTree<Stock>& stockTree)
{
	cin.ignore();
	string input;
	Stock* searchPtr;

	cout << "Enter stock symbol: ";
	getline(cin, input);
	Stock info("", input, 0);

	searchPtr = stockTree.search(info);

	if (searchPtr == nullptr)
		cout << "Stock was not found.\n" << endl;
	else
		cout << "\nFound: " << searchPtr->getName() << "\n" << endl;

	return searchPtr;
}

//*****************************************************************************************************

char getChoice()
{
	const string LINE = string(15, '*');
	char opt;

	cout << LINE << "Welcome" << LINE << endl;
	cout << "\na: Find name of stock" << endl;
	cout << "b: Find price of stock" << endl;
	cout << "c: Enter new stock" << endl;
	cout << "d: Display all stocks" << endl;
	cout << "e: Invert stock list" << endl;
	cout << "f: Quit" << endl;

	cout << "\nEnter choice: ";
	cin >> opt;
	opt = toupper(opt);
	
	while (opt < 'A' || opt > 'F')
	{
		cout << "ERROR! Please enter option listed." << endl;
		cout << "Enter choice: ";
		cin >> opt;
		opt = toupper(opt);
	}

	return opt;
}

//*****************************************************************************************************

Stock* retPrice(BinarySearchTree<Stock>& stockTree)
{
	cin.ignore();
	Stock* searchPtr;
	string input;

	cout << "Enter stock symbol: ";
	getline(cin, input);
	Stock info("", input, 0);

	searchPtr = stockTree.search(info);

	if (searchPtr == nullptr)
		cout << "Stock was not found.\n" << endl;

	else
		cout << "\nFound: $" << searchPtr->getPrice() << "\n" << endl;

	return searchPtr;
}

//*****************************************************************************************************

void getNewStock(BinarySearchTree<Stock>& stockTree)
{
	cin.ignore();

	string newSymbol;
	string newName;
	double newPrice;
	ostream& os = cout;

	cout << "Enter stock symbol: ";
	getline(cin, newSymbol);

	cout << "Enter stock name: ";
	getline(cin, newName);

	cout << "Enter stock price: ";
	cin >> newPrice;

	Stock newStock(newName, newSymbol, newPrice);

	stockTree.insert(newStock);
	cout << "Stock inserted.\n" << endl;
}

//*****************************************************************************************************

//Inorder:
//107
//554
//736
//2121
//2613
//2888
//4073
//4432
//4635
//4827
//
//Preorder:
//4432
//2613
//107
//736
//554
//2121
//4073
//2888
//4635
//4827
//
//Postorder:
//554
//2121
//736
//107
//2888
//4073
//2613
//4827
//4635
//4432
//
//Tree height : 5
//Tree erased.
//
//File loaded successfully.
//
//Height : 5
//* **************Welcome * **************
//
//a : Find name of stock
//b : Find price of stock
//c : Enter new stock
//d : Display all stocks
//e : Invert stock list
//f : Quit
//
//Enter choice : 4
//ERROR!Please enter option listed.
//Enter choice : r
//ERROR!Please enter option listed.
//Enter choice : d
//
//AAPL Apple                   $121.73
//AMD  Advanced Micro Devices  $84.51
//F    Ford Motor              $11.7
//GE   General Electric        $12.54
//INTC Intel                   $60.78
//MI   MINE                    $222
//MOT  Motorola Inc.$17.49
//TSLA Tesla                   $564.33
//* **************Welcome * **************
//
//a: Find name of stock
//b : Find price of stock
//c : Enter new stock
//d : Display all stocks
//e : Invert stock list
//f : Quit
//
//Enter choice : a
//Enter stock symbol : g
//Stock was not found.
//
//* **************Welcome * **************
//
//a : Find name of stock
//b : Find price of stock
//c : Enter new stock
//d : Display all stocks
//e : Invert stock list
//f : Quit
//
//Enter choice : a
//Enter stock symbol : MOT
//
//Found : Motorola Inc.
//
//* **************Welcome * **************
//
//a : Find name of stock
//b : Find price of stock
//c : Enter new stock
//d : Display all stocks
//e : Invert stock list
//f : Quit
//
//Enter choice : b
//Enter stock symbol : TSLA
//
//Found : $564.33
//
//* **************Welcome * **************
//
//a : Find name of stock
//b : Find price of stock
//c : Enter new stock
//d : Display all stocks
//e : Invert stock list
//f : Quit
//
//Enter choice : d
//
//AAPL Apple                   $121.73
//AMD  Advanced Micro Devices  $84.51
//F    Ford Motor              $11.7
//GE   General Electric        $12.54
//INTC Intel                   $60.78
//MI   MINE                    $222
//MOT  Motorola Inc.$17.49
//TSLA Tesla                   $564.33
//* **************Welcome * **************
//
//a: Find name of stock
//b : Find price of stock
//c : Enter new stock
//d : Display all stocks
//e : Invert stock list
//f : Quit
//
//Enter choice : e
//
//Inverting list...
//
//* **************Welcome * **************
//
//a : Find name of stock
//b : Find price of stock
//c : Enter new stock
//d : Display all stocks
//e : Invert stock list
//f : Quit
//
//Enter choice : d
//
//TSLA Tesla                   $564.33
//MOT  Motorola Inc.$17.49
//MI   MINE                    $222
//INTC Intel                   $60.78
//GE   General Electric        $12.54
//F    Ford Motor              $11.7
//AMD  Advanced Micro Devices  $84.51
//AAPL Apple                   $121.73
//* **************Welcome * **************
//
//a: Find name of stock
//b : Find price of stock
//c : Enter new stock
//d : Display all stocks
//e : Invert stock list
//f : Quit
//
//Enter choice : f
//Writing data...
//Tree erased.
//Good - bye.
//
//C : \Users\josep\source\repos\COSC3100_AssiVIStocks\x64\Debug\COSC3100_AssiVIStocks.exe(process 20528) exited with code 0.
//Press any key to close this window . . .