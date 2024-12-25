# Library Management System

A *Library Management System* that uses a *Doubly Linked List* to manage books and users, providing operations like adding, searching, removing books, and managing user accounts. Data is stored in flat files for user credentials and book records.

## Features

### Library Operations:
- *Insert Book*: Add a new book to the library.
- *Display Library*: View all books in the library.
- *Search for Book*: Search for a specific book by title.
- *Remove Book*: Delete a book from the library.
- *Sort Library*: Sort books based on title or other criteria.
- *Clear Library*: Remove all books from the library.

### File Management:
- *Save Library to File*: Persist library data to a flat file.
- *Load Library from File*: Load library data from an existing file.

### User Management:
- *Admin Login*: Admins can log in to manage the library (add, remove, sort books, and manage users).
- *User Registration & Login*: Users can register and log in with their credentials to borrow and manage their books.

### Data Storage:
- *User Credentials*: Stored in credentials.txt in the format username:password.
- *User's Books*: Stored in individual files library_user_[username].txt, which track the books borrowed by the user.

## File Structure

- DoublyLinkedList.cpp: Implements the core book management logic using a doubly linked list.
- DoublyLinkedList.h: Declares the methods for book management in the doubly linked list.
- MainInterface.cpp: Handles the user interface and interactions with the system.
- credentials.txt: Stores user credentials (username:password).
- library_user_[user].txt: Stores a user's borrowed books.

## Main Menu Options

1. *Insert Book*: Add a new book to the library.
2. *Display Library*: View all books available in the library.
3. *Search for Book*: Search for a specific book by title.
4. *Remove Book*: Delete a book from the library.
5. *Sort Library*: Sort books alphabetically or by other criteria.
6. *Destroy Library*: Clear all books from the library.
7. *User*: Access the user management menu (for admins).
8. *Exit Program*: Close the application.
9. *Save Library to File*: Save the current library to a file.
10. *Load Library from File*: Load a saved library from a file.
11. *Insert User*: Add a new user to the system.

## How It Works

1. *Admin Login*: Admins can log in using their credentials stored in credentials.txt and perform actions such as managing books and user accounts.
2. *User Registration and Login*: New users can register by providing a unique username and password. Once registered, they can log in to manage their borrowed books stored in library_user_[user].txt.
3. *Books Management*: Books are stored in a doubly linked list, providing efficient insertion, deletion, and search operations.

## Getting Started

### Prerequisites
Make sure you have the following installed:
- A C++ compiler (e.g., GCC)
- An IDE or text editor to edit and compile C++ code (e.g., Visual Studio, Code::Blocks)

### Compilation and Running

1. Clone the repository to your local machine:
   ```bash
   git clone https://github.com/yourusername/Library-Management-System.git
   cd Library-Management-System
