#include <bits/stdc++.h> // Including all standard libraries
using namespace std;

// Structure to store contact information
struct contacts
{
    string name, phone;
};

#define phonebook_size 20 // Maximum number of contacts
contacts c[phonebook_size]; // Array to store contacts

// Function prototypes
void contact_search(string n);
void sort_contacts();
void contact_add();
void contacts_display();
void contact_delete();
void contact_update();

int main()
{
    // Initializing the phonebook with some contacts
    c[0].name = "Mohamed Khaled";
    c[0].phone = "01155757280";

    c[1].name = "Ali Sayed";
    c[1].phone = "01030710862";

    c[2].name = "Mostafa Mohamed";
    c[2].phone = "01153422230";

    c[3].name = "Abdalla Hisham";
    c[3].phone = "01119573849";

    // Main loop for user interaction
    while (1)
    {
        cout << endl;
        string operation;
        string n;
        // Displaying menu options
        cout << "======== My Contacts ========" << endl;
        cout << "1. Search for contact" << endl;
        cout << "2. Add contact" << endl;
        cout << "3. Display all contacts" << endl;
        cout << "4. Delete contact" << endl;
        cout << "5. Update contact" << endl;
        cout << "6. Exit" << endl;
        cout << "=============================" << endl;
        cin >> operation;
        
        // Processing user input
        if (operation == "1")
        {
            cout << "Contact name to search: ";
            cin.ignore(); // Clear input buffer
            getline(cin, n); // Get full line input
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
            break; // Exit the loop and program
        }
        else
        {
            cout << "Invalid Operation" << endl; // Handle invalid input
        }
    }
    return 0;
}

// Function to search for a contact by name
void contact_search(string n)
{
    bool found = false;
    for (int i = 0; i < phonebook_size; i++)
    {
        // Check if the name contains the search string
        if (c[i].name.find(n) != string::npos)
        {
            cout << c[i].name << ": " << c[i].phone << endl;
            found = true;
        }
    }
    if (!found)
    {
        cout << "Not Found" << endl; // Contact not found
    }
}

// Function to sort contacts alphabetically by name
void sort_contacts()
{
    for (int i = 0; i < phonebook_size - 1; i++)
    {
        for (int j = i; j < phonebook_size; j++)
        {
            // Swap contacts if they are out of order
            if (c[i].name > c[j].name)
            {
                swap(c[i].name, c[j].name);
                swap(c[i].phone, c[j].phone);
            }
        }
    }
}

// Function to add a new contact
void contact_add()
{
    string n, p;
    cout << "Enter name: ";
    cin.ignore(); // Clear input buffer
    getline(cin, n); // Get full line input
    cout << "Enter phone: ";
    cin >> p;
    for (int i = 0; i < phonebook_size; i++)
    {
        // Find the first empty spot in the phonebook
        if (c[i].name.empty())
        {
            c[i].name = n;
            c[i].phone = p;
            cout << "Contact Added Successfully" << endl;
            sort_contacts(); // Sort the phonebook after adding
            return;
        }
    }
    cout << "Contact list is full. Cannot add more contacts." << endl;
}

// Function to display all contacts
void contacts_display()
{
    bool hasContacts = false;
    for (int i = 0; i < phonebook_size; i++)
    {
        // Check if the spot is not empty
        if (!c[i].name.empty())
        {
            cout << c[i].name << ": " << c[i].phone << endl;
            hasContacts = true;
        }
    }
    if (!hasContacts) 
    {
        cout << "No contacts to display." << endl; // No contacts in the phonebook
    }
}

// Function to delete a contact by name
void contact_delete()
{
    string n;
    cout << "Contact name to delete: ";
    getline(cin, n); // Get full line input
    for (int i = 0; i < phonebook_size; i++)
    {
        if (c[i].name == n)
        {
            c[i].name.clear(); // Clear the contact's name
            c[i].phone.clear(); // Clear the contact's phone
            cout << "Deleted Successfully" << endl;
            return;
        }
    }
    cout << "Not found to delete" << endl; // Contact not found
}

// Function to update a contact's information
void contact_update()
{
    string name, newName, newPhone;
    cout << "Enter name of contact to update: ";
    cin.ignore(); // Clear input buffer
    getline(cin, name); // Get full line input
    bool found = false;
    for (int i = 0; i < phonebook_size; i++) 
    {
        if (c[i].name == name) 
        {
            cout << "Enter new name (or press Enter to keep the current name): ";
            getline(cin, newName);
            if (!newName.empty()) 
            {
                c[i].name = newName; // Update the name if a new one is provided
            }
            cout << "Enter new phone (or press Enter to keep the current phone): ";
            getline(cin, newPhone);
            if (!newPhone.empty()) 
            {
                c[i].phone = newPhone; // Update the phone if a new one is provided
            }
            cout << "After update: " << c[i].name << ": " << c[i].phone << endl;
            found = true;
            sort_contacts(); // Sort the phonebook after updating
            return;
        }
    }
    if (!found) 
    {
        cout << "Not Found" << endl; // Contact not found
    }
}
