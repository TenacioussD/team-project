#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to create a new account
void create_account()
{
    string firstName;
    string lastName;
    string classroom; 
    string username; 
    string password; 

    // User details
    cout << "\n CREATE A NEW ACCOUNT \n";
    cout << "Please enter your first name: ";
    cin >> firstName;
    cout << "Please enter your last name: ";
    cin >> lastName;
    cout << "Please enter the students classroom number: ";
    cin >> classroom;
    cout << "Please enter a username: ";
    cin >> username;
    cout << "Please enter a password: ";
    cin >> password;

    // Open file and append user details
    ofstream outfile("newUsers.txt", ios::app);
    outfile << firstName << "," << lastName << "," << classroom << "," << username << "," << password << endl;
    outfile.close();

    cout << "Account created successfully.\n";
}

// Function to log in to an existing account
void login()
{
    string username;
    string password;
    bool found = false;

    // Get user details for login
    cout << "\n LOG IN TO AN EXISTING ACCOUNT \n";
    cout << "Please enter your username: ";
    cin >> username;
    cout << "Please enter your password: ";
    cin >> password;

    // Open file to find login
    ifstream infile("newUsers.txt");
    if (infile)
    {
        string line;

        while (getline(infile, line))
        {
            if (line.find(username + "," + password) != string::npos)
            {
                found = true;
                cout << "Login successful.\n";
                break;
            }
        }

        infile.close();
    }

    if (!found)
    {
        cout << "Invalid username or password. Please try again.\n";
    }
}

// Function for admin login
void adminLogin()
{
    string username;
    string password;
    bool found = false;

    // Get user details for login
    cout << "\n LOG IN TO AN EXISTING ACCOUNT \n";
    cout << "Please enter your username: ";
    cin >> username;
    cout << "Please enter your password: ";
    cin >> password;

    // Open file to find login
    ifstream infile("admin.txt");
    if (infile)
    {
        string line;

        while (getline(infile, line))
        {
            if (line.find(username + "," + password) != string::npos)
            {
                found = true;
                cout << "Login successful.\n";
                break;
            }
        }

        infile.close();
    }

    if (!found)
    {
        cout << "Invalid username or password. Please try again.\n";
    }
}

int main()
{
    int choice;

    cout << "Welcome to the schools lunch ordering program!" << endl;

    do {
        cout << "\n Please choose an option: \n";
        cout << "1. Create an account \n";
        cout << "2. Parent/Student Login \n";
        cout << "3. Admin login \n";
        cout << "4. Exit \n \n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            create_account();
            break;

        case 2:
            login();
            break;

        case 3:
            adminLogin();
            break;

        case 4:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 4);

    return 0;
}



