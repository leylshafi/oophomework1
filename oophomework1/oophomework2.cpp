#include <iostream>
#include<cassert>
using namespace std;

#include"products.h"
#include"stock.h"

int main()
{
	int choose;
	int chooseID;
	size_t size = 2;
	Product** products = new Product * [size] {
		new Product("P1", "D1",10.5,30),
			new Product("P2", "D2", 12.5, 20)
	};

	Stock* stock = new Stock("Stock", products, size);
	stock->print();

	Product *p=new Product;

	while (true) {
		cout << "For append product:1, remove product:2, delete by id:3, get by id:4, clear:5,show all:6,exit:0" << endl;
		cin >> choose;
		switch (choose)
		{
		case 0:
			cout << "Good bye!!!" << endl;
			exit(0);
			break;
		case 1:
			cout << "Append product: " << endl;
			stock->appendProduct(p->createProduct());
			break;
		case 2:
			stock->removeProduct();
			break;
		case 3:
			cout << "Enter id for delete: " << endl;
			cin >> chooseID;
			stock->deleteProductById(chooseID);
			break;
		case 4:
			cout << "Enter id to get product: " << endl;
			cin >> chooseID;
			stock->getProductById(chooseID)->print();
			break;
		case 5:
			cout << "Clear" << endl;
			stock->clear();
			break;
		case 6:
			stock->print();
			break;
		default:
			break;
		}
	}






	delete stock;
}

