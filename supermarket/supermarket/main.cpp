#include <iostream>
#include <algorithm>
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
	item(string n, float f, int q) :name(n), price(f), quantity(q) {}
	//method to print item
	void pr() { cout << name << "            " << price << "            " << quantity << endl; }
	//method to set item name
	void set_name(string n) { name = n; }
	//method to set item price
	void set_price(float n) { price = n; }
	//method to set item quantity
	void set_quantity(int n) { quantity = n; }
	//method to retutn item name
	string get_name() { return name; }
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
		cout << "ID       Name       Price       Quantity" << endl;
		for (int i = 0; i < goods.size(); i++) { cout << i + 1 << "       "; goods[i].pr(); }
	}
	// method to change item
	void change(int id, string n, float p, int q) 
	{
		goods[id - 1].set_name(n);
		goods[id - 1].set_price(p);
		goods[id - 1].set_quantity(q);
	}
	// method to delete item
	void del(int id) { goods.erase(goods.begin() + id - 1); }
	//method to print total price
	void total_price()
	{
		float r = 0;
		for (int i = 0; i < goods.size(); i++) r += goods[i].get_price() * goods[i].qet_quantity();
		cout << "Total price = " << r << endl;
	}
	// Method to sort items alphabetically by name
	void sort_items() {
		sort(goods.begin(), goods.end(), [](item& a, item& b) {
			return a.get_name() < b.get_name();
			});
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
		cout << "2 = Change Item" << endl;
		cout << "3 = Delete Item" << endl;
		cout << "4 = Print Items" << endl;
		cout << "5 = Print Total Price" << endl;
		cout << "6 = Exit" << endl;
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
		{
			cout << "Enter ID of item you want to change it..." << endl;
			int i; cin >> i;
			string n; float p; int q;
			cout << "Enter New Name..." << endl;
			cin >> n;
			cout << "Enter New Price..." << endl;
			cin >> p;
			cout << "Enter New Quantity..." << endl;
			cin >> q;
			s.change(i, n, p, q);
			break;
		}
		case 3:
		{
			cout << "Enter ID of item you want to delete it..." << endl;
			int i; cin >> i;
			s.del(i);
		}
		case 4:
			s.print();
			break;
		case 5:
			s.total_price();
			break;
		case 6:
			return 0; //exit the program
		default:
			cout << "Invalid Input" << endl;
			break;
		}
		s.sort_items();
	}
	return 0;
}