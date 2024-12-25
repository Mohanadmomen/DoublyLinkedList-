Library Management System
A library management system that uses a Doubly Linked List to manage books and users,
with operations like adding, searching, removing books, and managing users.
It stores data in flat files for user credentials and book records.

Features:
Library Operations: Insert, display, search, remove, sort, and clear books.
File Management: Save and load library data from flat files (library_user_[user].txt).
User Management: User authentication (username and password), add new users.
Data Storage: User credentials stored in credentials.txt, books in library_user_[user].txt.

Files:
DoublyLinkedList.cpp: Implements the book management logic.
DoublyLinkedList.h: Declares methods for book management.
MainInterface.cpp: User interface for interacting with the system.
credentials.txt: Stores user credentials (username:password).
library_user_[user].txt: Stores user’s borrowed books.

Admin Login:
Admins can log in to manage the library, including adding, removing, sorting books, and managing user accounts.

User Registration and Login:
Users can register and log in with a username and password to access their personal library, borrow books, and manage their collection.

Search Books:
Users and admins can search for specific books in the library by title.


Main Menu:

1. Insert Book
2. Display Library
3. Search for Book
4. Remove Book
5. Sort Library
6. Destroy Library
7. User
8. Exit Program
9. Save Library to File
10. Load Library from File
11. Insert User








