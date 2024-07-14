#include <bits/stdc++.h>
using namespace std;

struct contacts
{
	string name, phone;
};

#define phonebook_size 20
contacts c[phonebook_size];

//functions prototype
void contact_search(string n);
void sort_contacts();
void contact_add();
void contacts_display();
void contact_delete();
void contact_update();


int main()
{
	c[0].name = "Mohamed Khaled";
	c[0].phone = "01155757280";

	c[1].name = "Ali Sayed";
	c[1].phone = "01030710862";

	c[2].name = "Mostafa Mohamed";
	c[2].phone = "01153422230";

	c[3].name = "Abdalla Hisham";
	c[3].phone = "01119573849";

	while (1)
	{
		cout << endl;
		string operation;
		string n;
		cout << "======== My Contacts ========" << endl;
		cout << "1. Search for contact" << endl;
		cout << "2. Add contact" << endl;
		cout << "3. Display all contacts" << endl;
		cout << "4. Delete contact" << endl;
		cout << "5. Update contact" << endl;
		cout << "6. Exit" << endl;
		cout << "=============================" << endl;
		cin >> operation;
		if (operation == "1")
		{
			cout << "Contact name to search: ";
			cin.ignore();
			getline(cin, n);
			contact_search(n);
		}
		else if (operation == "2")
		{
			contact_add();
		}
		else if (operation == "3")
		{
			contacts_display();
		}
		else if (operation == "4")
		{
			contact_delete();
		}
		else if (operation == "5")
		{
			contact_update();
		}
		else if (operation == "6")
		{
			break;
		}
		else
		{
			cout << "Invalid Operation" << endl;
		}
	}
	return 0;
}

//functions
void contact_search(string n)
{
	bool found = false;
	for (int i = 0; i < phonebook_size; i++)
	{
		if (c[i].name.find(n) != string::npos)
		{
			cout << c[i].name << ": " << c[i].phone << endl;
			found = true;
		}
	}
	if (!found)
	{
		cout << "Not Found" << endl;
	}
}

void sort_contacts()
{
	for (int i = 0; i < phonebook_size - 1; i++)
	{
		for (int j = i; j < 20; j++)
		{
			if (c[i].name > c[j].name)
			{
				swap(c[i].name, c[j].name);
				swap(c[i].phone, c[j].phone);
			}
		}
	}
}

void contact_add()
{
	string n, p;
	cout << "Enter name: ";
	cin.ignore();
	getline(cin, n);
	cout << "Enter phone: ";
	cin >> p;
	for (int i = 0; i < phonebook_size; i++)
	{
		if (c[i].name.empty())
		{
			c[i].name = n;
			c[i].phone = p;
			cout << "Contact Added Successful" << endl;
			sort_contacts();
			return;
		}
	}
	cout << "Contact list is full. Cannot add more contacts." << endl;
}

void contacts_display()
{
	bool hasContacts = false;
	for (int i = 0; i < phonebook_size; i++)
	{
		if (!c[i].name.empty())
		{
			cout << c[i].name << ": " << c[i].phone << endl;
			hasContacts = true;
		}
	}
	if (!hasContacts) 
	{
		cout << "No contacts to display." << endl;
	}
}

void contact_delete()
{
	string n;
	cout << "Contact name to delete: ";
	getline(cin, n);
	for (int i = 0; i < phonebook_size; i++)
	{
		if (c[i].name == n)
		{
			c[i].name.clear();
			c[i].phone.clear();
			cout << "Deleted Successfuly" << endl;
			return;
		}
	}
	cout << "Not found to delete" << endl;
}

void contact_update()
{
	string name, newName, newPhone;
	cout << "Enter name of contact to update: ";
	cin.ignore();
	getline(cin, name);
	bool found = false;
	for (int i = 0; i < phonebook_size; i++) 
	{
		if (c[i].name == name) 
		{
			cout << "Enter new name (or press Enter to keep the current name): ";
			getline(cin, newName);
			if (!newName.empty()) 
			{
				c[i].name = newName;
			}
			cout << "Enter new phone (or press Enter to keep the current phone): ";
			getline(cin, newPhone);
			if (!newPhone.empty()) 
			{
				c[i].phone = newPhone;
			}
			cout << "After update: " << c[i].name << ": " << c[i].phone << endl;
			found = true;
			sort_contacts();
			return;
		}
	}
	if (!found) 
	{
		cout << "Not Found" << endl;
	}
}