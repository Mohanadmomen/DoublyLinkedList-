#include "DoublyLinkedList.h"
#include <limits> // For clearing input buffer
#include <map>

using namespace std;

DoublyLinkedList library[10];

// Function to print a boxed message
void printBoxedMessage(const string& message) {
    int length = message.length();
    string border(length + 6, '='); // Top and bottom border
    string sideBorder = "|";        // Side borders

    cout << border << endl;                        // Top border
    cout << sideBorder << " " << string(length + 3, ' ') << sideBorder << endl; // Top padding
    cout << sideBorder << " " << message << "   " << sideBorder << endl;         // Message line
    cout << sideBorder << " " << string(length + 3, ' ') << sideBorder << endl; // Bottom padding
    cout << border << endl;                        // Bottom border
}

void MainInterface(int user) {

    int choice;
    do {


        printBoxedMessage("Library Management System");
        cout << "\n1. Insert Book\n";
        cout << "2. Display Library\n";
        cout << "3. Search for Book\n";
        cout << "4. Remove Book\n";
        cout << "5. Sort Library\n";
        cout << "6. Destroy Library\n";
        cout << "7. User\n";
        cout << "8. Exit Program\n";
        cout << "9. Save Library to File\n";
        cout << "10. Load Library from File\n";
        cout << "11. Insert User\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Clear the input buffer in case of invalid input
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
        case 1: {
            string data;
            cout << "Enter the name of the book to insert: ";
            cin.ignore(); // Clear newline character from input buffer
            getline(cin, data);
            library[user].insert(data);
            system("cls");
            printBoxedMessage("Record inserted successfully!");
            cout << endl;
            break;
        }

        case 2:
            system("cls");
            printBoxedMessage("Library Contents:");
            cout << endl;
            library[user].display();
            cout << endl;
            break;

        case 3: {
            string key;
            cout << "Enter the name of the book to search for: ";
            cin.ignore();
            getline(cin, key);
            Node* result = library[user].search(key);
            system("cls");
            if (result) {
                printBoxedMessage("Record found: " + result->data);
            }
            else {
                printBoxedMessage("Record not found!");
            }

            break;
        }

        case 4: {
            string key;
            cout << "Enter the name of the book to remove: ";
            cin.ignore();
            getline(cin, key);
            system("cls");
            library[user].remove(key);
            break;
        }

        case 5:
            system("cls");
            library[user].sort();
            printBoxedMessage("Library sorted successfully!");
            break;

        case 6:
            system("cls");
            library[user].destroy();
            break;


        case 7:
            system("cls");
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            LoginScreen();
            return;

        case 8:
            system("cls");
            printBoxedMessage("Exiting the system. Goodbye!");
            return;

        case 9:
            system("cls");
            library[user].saveToFile("library_user_" + to_string(user) + ".txt");
            
            break;

        case 10:
            system("cls");
            library[user].loadFromFile("library_user_" + to_string(user) + ".txt");
            
            break;

        case 11: {
            system("cls");
            string newuser1, newpass1;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter username: ";
            getline(cin, newuser1);
            cout << "Enter password: ";
            getline(cin, newpass1);

            insertCredential(newuser1, newpass1);

            break;
        }

        default: {
            system("cls");
            cout << "Invalid choice. Please try again.\n";
            break;
        }
        }

    } while (choice != 7);
}


void LoginScreen() {
    int trials = 3;
    string UserName, Password;
    bool Loginfailed = true;
   


    do {
        cout << "Enter UserName: ";

        getline(cin, UserName);

        cout << "Enter Password: ";
        getline(cin, Password);

        // Check if the username exists and the password matches
        if (credentials.count(UserName) > 0 && credentials[UserName].first == Password) {
            Loginfailed = false;
            //cout << "Login successful! Welcome, " << UserName << "!\n";
            system("cls");
            MainInterface(credentials[UserName].second);
        } else if (--trials == 0) {
            cout << "You have exceeded your trials\n";
            return;
        } else {
            cout << "Username or Password you have entered is wrong\n";
            cout << "You have only " << trials << " trials left\n";
        }
    } while (Loginfailed);


}








