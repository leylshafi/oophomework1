#pragma once
class Stock
{
private:
	char* _stockname = nullptr;
	Product** _products = nullptr; // dynamic array
	size_t _count = 0;

public:
	Stock();
	Stock(const char* stockName, Product** products, size_t count);

	void setStockName(const char* stockname);

	const char* getStockName();
	Product** getProducts();
	size_t getCount();


	void print(); // show all products in Stock
	void clear();
	void appendProduct(Product* product);
	void removeProduct();
	void deleteProductById(size_t id);
	Product* getProductById(int id);

	~Stock();
};

/////////// CONSTRUCTOR
Stock::Stock() = default;
Stock::Stock(const char* stockName, Product * *products, size_t count)
	:Stock()
{
	setStockName(stockName);
	_count = count;
	_products = products;
}


///////////GETTER	
const char* Stock::getStockName() { return _stockname; }
Product** Stock::getProducts() { return _products; }
size_t Stock::getCount() { return _count; }

/////////// SETTER
void Stock::setStockName(const char* stockname)
{
	if (stockname == nullptr)
		assert(!"name == nullptr");

	if (_stockname != nullptr)
		delete[] _stockname;


	size_t len = strlen(stockname) + 1;
	_stockname = new char[len];
	strcpy_s(_stockname, len, stockname);
}

/////////// FUNCTIONS

void Stock::print()
{
	cout << "Name: " << (_stockname ? _stockname : "null") << endl;


	cout << "=======   Products   =======" << endl;
	if (_products != nullptr) {
		for (size_t i = 0; i < _count; i++)
			_products[i]->print();
	}
	else cout << "Products are deleted" << endl;


	cout << "\n=======   End   =======\n";
}

Stock::~Stock()
{
	cout << "\nDestructor -> " << (_stockname ? _stockname : "null") << endl;

	delete[] _stockname;

	for (size_t i = 0; i < _count; i++)
		delete _products[i];

	delete[] _products;

	_stockname = nullptr;
	_products = nullptr;
}

void Stock::clear() {
	for (size_t i = 0; i < _count; i++)
		_products[i] = nullptr;
	_products = nullptr;

	cout << "=== Cleared successfully ===" << endl;
}


void Stock::appendProduct(Product* product) {
	Product** p = new Product * [_count + 1];
	for (size_t i = 0; i < _count; i++)
	{
		p[i] = _products[i];
	}
	p[_count++] = product;
	delete[]_products;
	_products = p;
}

void Stock::removeProduct() {
	Product** p = new Product * [_count - 1];
	for (size_t i = 0; i < _count - 1; i++)
	{
		p[i] = _products[i];
	}
	_count--;
	delete[]_products;
	_products = p;
	cout << "=== Removed successfully ===" << endl;
}

void Stock::deleteProductById(size_t id) {
	if (id > 0 && id <= _count) {
		Product** p = new Product * [_count - 1];
		for (size_t i = 0, j = 0; i < _count; i++)
		{
			if (_products[i]->getId() == id)
				continue;
			p[j++] = _products[i];
		}
		_count--;
		delete[]_products;
		_products = p;
		cout << "Deleted successfully" << endl;
	}
	else cout << "Incorrect input range" << endl;
}

Product* Stock::getProductById(int id) {
	if (id > 0 && id <= _count) {
		for (size_t i = 0; i < _count; i++)
		{
			if (_products[i]->getId() == id)
				return _products[i];
		}
	}
	else {
		cout << "Incorrect input range" << endl;
		return nullptr;
	}
}
