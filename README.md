
# Phone Book Application

## Overview
This C++ program implements a simple phone book application that allows users to manage contacts. The application can store, display, search, add, delete, update, and sort contacts by name or phone number.

## Features
- **Add a contact**: Save a new contact with a name and phone number.
- **Search contacts**: Look up a contact by their name.
- **Display contacts**: View all contacts stored in the phone book.
- **Sort contacts**: Sort the contact list alphabetically by name.
- **Update a contact**: Modify the details of an existing contact.
- **Delete a contact**: Remove a contact from the phone book.

## Program Structure
- **contacts struct**: Holds the `name` and `phone` for each contact.
- **Array of contacts**: The phone book can store up to 20 contacts.
- **Functions**:
  - `contact_add()`: Adds a new contact.
  - `contact_search(string name)`: Searches for a contact by name.
  - `contacts_display()`: Displays all saved contacts.
  - `contact_delete()`: Deletes a contact by name.
  - `contact_update()`: Updates an existing contact's details.
  - `sort_contacts()`: Sorts the contacts alphabetically.

## How to Use
1. **Compile the program**: Use a C++ compiler to compile the `Phone Book.cpp` file.
   ```bash
   g++ Phone\ Book.cpp -o phonebook
   ```
2. **Run the program**:
   ```bash
   ./phonebook
   ```

3. **Interactive Menu**: The program presents an interactive menu that lets users perform various operations on the phone book. Follow the on-screen instructions to manage your contacts.

## Limitations
- The phone book is limited to storing a maximum of 20 contacts.
- No persistent storage: Data is stored only during runtime and is lost when the program terminates.

## Future Improvements
- Add file-based storage to retain contacts across sessions.
- Increase the phone book's storage capacity.
- Implement search by phone number.

## Requirements
- C++ compiler supporting C++11 or later.
  
## Author
Mohammed Khaled Abdalla

