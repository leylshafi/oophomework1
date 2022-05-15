#pragma once
class Product
{
private:
	static size_t _staticId;
	size_t _id = 0;
	char* _name = nullptr;
	char* _description = nullptr;
	double _price = 0;
	short _discount = 0; // 0-100%

public:
	Product();
	Product(const char* name, const char* description);
	Product(const char* name, const char* description, double price, short discount);

	static size_t getStaticId();


	const char* getName();
	const char* getDescription();
	double getPrice();
	short getDiscount();
	size_t getId();


	void setName(const char* name);
	void setDescription(const char* description);
	void setPrice(double price);
	void setDiscount(short discount);


	double getDiscountPrice(double price, short discount);


	void print();

	Product* createProduct();

	~Product();
};




size_t Product::_staticId = 0;
/////////////////////////////////  IMPLIMENTATION

//////// CONSTRUCTORS

Product::Product() {
	_id = ++_staticId;
}

Product::Product(const char* name, const char* description)
	:Product()
{
	setName(name);
	setDescription(description);

}

Product::Product(const char* name, const char* description, double price, short discount)
	:Product(name, description)
{
	setPrice(price);
	setDiscount(discount);
}

/////////////////////////////// ACESSORS

//////// GETTER
const char* Product::getName() {
	return _name;
}
const char* Product::getDescription() {
	return _description;
}
double Product::getPrice() {
	return _price;
}
short Product::getDiscount() {
	return _discount;
}

size_t Product::getId() {
	return _id;
}

//////// SETTER

void Product::setName(const char* name)
{
	if (name == nullptr)
		assert(!"name == nullptr");

	if (_name != nullptr)
		delete[] _name;


	size_t len = strlen(name) + 1;
	_name = new char[len];
	strcpy_s(_name, len, name);
}

void Product::setDescription(const char* description)
{
	if (description == nullptr)
		assert(!"description == nullptr");

	if (_description != nullptr)
		delete[] _description;


	size_t len = strlen(description) + 1;
	_description = new char[len];
	strcpy_s(_description, len, description);
}

void Product::setPrice(double price)
{
	if (price > 10 && price < 3000)
		_price = price;
	else
		assert(!"price >10 && price < 3000");
}
void Product::setDiscount(short discount)
{
	if (discount >= 0 && discount <= 100)
		_discount = discount;
	else
		assert(!"discount >= 0 && discount <= 100");
}


double Product::getDiscountPrice(double price, short discount) {
	return (price * (100 - discount)) / 100;
}

void Product::print() {
	cout << "Id: " << _id << endl;
	cout << "Name: " << _name << endl;
	cout << "Description: " << _description << endl;
	cout << "Price: " << _price << endl;
	cout << "Discount: " << _discount << endl;
	cout << endl;
}

Product::~Product()
{
	cout << "Destructor->" << (_name ? _name : "null") << endl;
	delete[]_name;
	delete[]_description;
	_name = _description = nullptr;
}

Product* Product::createProduct() {

	int s = 30;
	Product* newProduct= new Product();
	--_staticId;
	newProduct->_id = _staticId++;
	cin.ignore();
	newProduct->_name =new char[s];
	cout << "Enter product name: " << endl;
	cin.getline(newProduct->_name, s);
	cout << "Enter product description: " << endl;
	newProduct->_description = new char[s];
	cin.getline(newProduct->_description, s);
	cout << "Enter price: " << endl;
	cin >> newProduct->_price;
	cout << "Enter discount: " << endl;
	cin>> newProduct->_discount;

	return newProduct;

}
