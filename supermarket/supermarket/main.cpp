#include <iostream>
#include <vector>

using namespace std;

class item
{
private:
	string name;
	float price;
	int quantity;
public:
	//constructor to initialize item with name and price and qunatity
	item(string n, float f, int q):name(n), price(f), quantity(q){}
	//method to print item
	void pr() { cout << name << "            " << price << "            " << quantity << endl; }
	//method to retutn item price
	float get_price() { return price; }
	//methid to return item quantity
	int qet_quantity() { return quantity; }
};

class store 
{
private:
	vector<item>goods;
public:
	//method to add item to the store
	void add(item a) { goods.push_back(a); }
	//method to print all items in super matket
	void print() 
	{
		cout << "Name       Price       Quantity" << endl;
		for (int i = 0; i < goods.size(); i++) goods[i].pr();
	}
	//method to print total price
	void total_price() 
	{
		float r = 0;
		for (int i = 0; i < goods.size(); i++) r += goods[i].get_price() * goods[i].qet_quantity();
		cout << "Total price = " << r << endl;
	}
};

int main() 
{
	//create store
	store s;
	cout << "Welcome to our supermarket" << endl;
	while (1)
	{
		//options
		cout << "\n=================" << endl;
		cout << "=================" << endl;
		cout << "1 = Add Item" << endl;
		cout << "2 = Print Items" << endl;
		cout << "3 = Print Total Price" << endl;
		cout << "4 = Exit" << endl;
		cout << "What do you want..." << endl;
		cout << "=================" << endl;
		cout << "=================" << endl;
		int i; cin >> i;
		switch (i)
		{
		case 1:
		{
			string n; float p; int q;
			cout << "Enter Name..." << endl;
			cin >> n;
			cout << "Enter Price..." << endl;
			cin >> p;
			cout << "Enter Quantity..." << endl;
			cin >> q;
			item it(n, p, q);
			s.add(it);
			break;
		}
		case 2:
			s.print();
			break;
		case 3:
			s.total_price();
			break;
		case 4:
			return 0; //exit the program
		default:
			cout << "Invalid Input" << endl;
			break;
		}
	}
	return 0;
}