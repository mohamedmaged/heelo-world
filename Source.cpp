#include <iostream>
#include"bill.h"
#include"item.h"
#include "stock.h"
#include<string>
#include "bills.h"
#include <iomanip>      // std::setw
using namespace std;
void main()
{
	stock mystock;
	mystock.read();
	bills mybills;
	mybills.read();
	while(1)
	{
		int k;

		cout <<setw(60)<<"**welcome to mechantus billing APP**"<<endl<<endl;
		cout << "RUlES ARE SIMPLE : " << endl<<endl;
		cout<<"1- "<<"all screens are numbered so you can choose your item by typing the number "<<endl<<endl;
		cout <<"2- "<<"You can always press 0 to go to the previous menu "<<endl<<endl;
		cout << "please choose one tap of these:" << endl << endl;
		cout <<setw(4)<<"1- "<<"customers " << endl;
		cout << setw(4) << "2- "  << "stock" << endl;
		cout << setw(4) << "3- " << "sales" << endl;
		cin >> k;
		if (k == 1)
		{
			bill c;
			int x,y;
			cout << setw(60) << "CUSTOMERS - TAB (WELCOME)" <<endl<<endl;
			cout << setw(40) << "please enter the number of the item you want" << endl<<endl;
			mystock.read();
			while (1) {
				mystock.check();
				mystock.customerdisplay();
				cin >> x;
				cout << "Please enter the qunatity of the item" << endl;
				cin >> y;
				while (mystock.getitem(x - 1).getquantity()< y|| y<0||x>mystock.getn()+1)
				{
					if (x > mystock.getn() + 1)
					{
						cout << "wrong item pressed" << endl;
					}
					else {
						if (mystock.getitem(x - 1).getquantity() == y)
							break;
						cout << "WE ARE SORRY we don't have that quantity  " << endl;
						cout << "the quantity of this item in the stock is :" << mystock.getitem(x - 1).getquantity() << endl;
					}
					cout << "please enter again the quantity of your item or choose another item by hitting 0" << endl;
					cin >> y;
				}
				if (y == 0)
					continue;

				mystock.getitem(x - 1).changequantity(-1 * y);
				item n = mystock.getitem(x - 1);
				n.setquantity(y);
				c.additem(n);
				cout << "if you want to exit and pay for your bill press 0" << endl;
				cin >> y;
				if (y == 0)
				{
				
					while (1)
					{
						c.display();
						cout << "please choose what do you want to do ?" << endl << endl;
						cout << "1- " << "PAY" << endl;
						cout << "2- " << "EDIT" << endl;
						cout << "3- " << "delete item " << endl;
						cout << "4- " << "add aother item" << endl;
						cout << "5- " << "cancel all bill" << endl;
						cin >> y;
						if (y == 1)
						{
							mystock.save();
							mybills.addbill(c);
							mybills.save();
							break;
						}
						if (y == 2)
						{
							cout << "please enter the number of the item you want to edit" << endl;
							c.display();
							cin >> y;
							cout << "please enter the new quantity" << endl;
							cin >> x;
							while (mystock.getitem(y - 1).getquantity()< x||y<0||y>mystock.getn()+ 1)
							{
								if (y > mystock.getn() + 1)
								{
									cout << "wrong item pressed" << endl;
								}
								else {
									if (mystock.getitem(x - 1).getquantity() == y)
										break;
									cout << "WE ARE SORRY we don't have that quantity or wron item " << endl;
									cout << "the quantity of this item in the stock is :" << mystock.getitem(y - 1).getquantity() << endl;
								}
								cout << "please enter again the quantity of your item or choose another item by hitting 0" << endl;
								cin >> y;
							}
							if (y == 0)
								continue;
							mystock.getitem(y - 1).changequantity(c.getitem(y - 1).getquantity());
							mystock.getitem(y - 1).changequantity(-1 * x);
							c.getitem(y - 1).setquantity(x);
							c.display();
						}
						if (y == 3)
						{
							cout << "please enter the number of the item you want to delete" << endl;
							c.display();
							cin >> y;
							mystock.additem(c.getitem(y - 1));
							c.deleteitem(y - 1);
						}
						if (y == 5)
						{
							break;
						}
						if (y == 4)
						{
							mystock.check();
							mystock.customerdisplay();
							cin >> x;
							cout << "Please enter the qunatity of the item" << endl;
							cin >> y;
							while (mystock.getitem(x - 1).getquantity()< y || y<0 || x>mystock.getn() + 1)
							{
								if (x > mystock.getn() + 1)
								{
									cout << "wrong item pressed" << endl;
								}
								else {
									if (mystock.getitem(x - 1).getquantity() == y)
										break;
									cout << "WE ARE SORRY we don't have that quantity  " << endl;
									cout << "the quantity of this item in the stock is :" << mystock.getitem(x - 1).getquantity() << endl;
								}
								cin >> y;
							}
							mystock.getitem(x - 1).changequantity(-1 * y);
							item n = mystock.getitem(x - 1);
							n.setquantity(y);
							c.additem(n);
						}
					}
					mystock.save();
					break;
				}
			}

		} 
		if (k == 2)
		{
			while (1)
			{

				int y;
				cout << setw(40) << "STOCK -TAP (WELCOME )" << endl;
				cout << "please choose one of the following  : " << endl << endl;
				cout << "1- " << "add new items to stock " << endl;
				cout << "2- " << "display stock" << endl;
				cout << "3- " << "delete item from stock " << endl;
				cin >> y;
				if (y == 1)
				{
					int  id;
					string name;
					string manf;
					string type;
					float price;
					bool edible;
					int quantity;
					int z;
					int m;
					int d;
					cout << " enter id : ";
					cin >> id;
					cout << endl << "enter name : ";
					cin >> name;
					cout << endl << "enter manf : ";
					cin >> manf;
					cout << endl << "enter type :";
					cin >> type;
					cout << endl << "enter price : ";
					cin >> price;
					cout << endl << "Quantity is :";
					cin >> quantity;
					cout << endl << "is it edible (0,1) :";
					cin >> edible;
					if (edible)
					{
						cout << endl << "expire year  :";
						cin >> z;
						cout << endl << "expire month : ";
						cin >> m;
						cout << endl << "expire day :";
						cin >> d;
						date e(d,m,z);
						item s(id, name, manf, type, price, quantity, e);
						mystock.additem(s);
						mystock.save();

					}
					else
					{
						item s(id, name, manf, type, price, quantity);
						mystock.additem(s);
						mystock.save();
					}
				}
				if (y == 2)
				{
					mystock.check();
					mystock.display();
				}
				if (y == 3)
				{
					int x;
					cout << " please enter the number of the item you want to delete " << endl;
					mystock.check();
					mystock.display();
					cin >> x;
					mystock.deleteitem(x - 1);
					mystock.save();
				}
			}
			if (k == 3)
			{
				cout << setw(40) << "STOCK -TAP (WELCOME )" << endl;

			}
		}
	}
	mybills.save();
	mystock.save();
	system("pause");
}