// once
#include "item.h"
#include <iostream>
#include<fstream>
#include <string>
#include<iomanip>
using namespace std;
class stock:public bill
{
private :

public :
	 void display()
	{
		cout << " id " << "name " << "\t" << "price " << "\t" << "quantity " << endl;
		item *currentitem = bill::header;
		for (int i = 0; i < n; i++)
		{
			if (currentitem->getedib())
				cout << setw(5) << i + 1 << " - " << currentitem->getname() << "\t" << currentitem->getprice() << "\t" <<currentitem->getquantity()<<"\t"<< currentitem->getexp().getyear() << "/" << currentitem->getexp().getmonth() << "/" << currentitem->getexp().getday() << endl;
			else
				cout << setw(5) << i + 1 << " - " << currentitem->getname() << "\t" << currentitem->getprice() << "\t" << currentitem->getquantity() << endl;
			currentitem = currentitem->next;
		}
	}
	void customerdisplay()
	{
		cout << " index " << "name " << "\t" << "price " <<  endl;
		item *currentitem = bill::header;
		int i = 0;
		while(currentitem!=NULL)
		{
			if(currentitem->getedib())
				cout << setw(5) << i + 1 << " - " << currentitem->getname() << "\t" << currentitem->getprice() << "\t"<<currentitem->getexp().getyear() << "/" << currentitem->getexp().getmonth() << "/" << currentitem->getexp().getday()<<endl;
			else
			cout << setw(5)<<i + 1 << " - " << currentitem->getname() << "\t" << currentitem->getprice() << endl;
			currentitem = currentitem->next;
			i++;
		}
	}
	bool save ()
	{
		ofstream file("stock.csv");
		if (file.is_open())
		{
			item *currentitem;
			currentitem = bill::header;

			while (currentitem != NULL)
			{
				if(currentitem->getedib())
					file << currentitem->getid() << "," << currentitem->getname() << "," << currentitem->getmanf() << "," << currentitem->gettype() << "," << currentitem->getprice() << "," << currentitem->getquantity() <<","<<currentitem->getexp().getyear()<<","<<currentitem->getexp().getmonth()<<","<<currentitem->getexp().getday()<< "\n";
				else
				file << currentitem->getid()<<","<< currentitem->getname()<<"," <<currentitem->getmanf()<<"," <<currentitem->gettype()<<","<< currentitem->getprice()<<","<< currentitem->getquantity()<<"\n";
				currentitem = currentitem->next;
			}

		}
		file.close();
		return true;
	}
	bool read()
	{
		ifstream inf("stock.csv");
		
		if (inf.is_open())
		{
			string x;
			while (1)
			{
				
				string  id1;
				string name;
				string manf;
				string type;
				string price1;
				string quantity1;
				string day;
				string year;
				string month;
				date e;
				getline(inf, x);
				if (x.length() < 3)
					break;
		//		cout << x << endl;
				int z = 0;
				for (int i = 0; i < x.length(); i++)
				{
					if (x[i] == ',')
					{
						z++;
						continue;
					}
					if (z == 5)
					{
						quantity1 = quantity1+x[i];
						
					}
					if (z == 4)
					{
						price1 =price1 + x[i];
						
					}
					if (z == 3)
					{
						type = type+x[i];
						
					}
					if (z == 2)
					{
						manf = manf+x[i];
						
					}
					if (z == 0)
					{
						id1 = id1+x[i];

						
					}
					if (z == 1)
					{
						name = name+x[i];
						
					}
					if (z == 6)
					{
						year = year + x[i];
					}
					if (z == 7)
					{
						month = month + x[i];
					}
					if (z == 8)
					{

						day = day + x[i];
					}
				

				}
			
				if (year.length() > 0)
				{
					e.setday(stoi(day));
					e.setmonth(stoi(month));
					e.setyear(stoi(year));
					item s(stoi(id1), name, manf, type, stof(price1), stof(quantity1),e);
					additem(s);
				}
				else
				{
					item s(stoi(id1), name, manf, type, stof(price1), stof(quantity1));
					additem(s);
				}
			}

		}
		inf.close();
		return true;

	}
};