#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int choice;
string discount;
string cardNumber;
int cvc;
bool found = false;

struct Items                                 // Declaring a structure called Costs, struct names (tag) should begin with an uppercase letter
{
    double sandwich;                         // Structure member type double
    double hotDog;                           // Structure member type double
    double chips;                            // Structure member type double
    double salad;                            // Structure member type double
    double water;                            // Structure member type double
    double fizzyDrink;                       // Structure member type double

    Items()                                  // Structure constructor to initilise members
    {
        sandwich = 8.00;                     // Initilising the structure members
        hotDog = 6.50;
        chips = 5.00;
        salad = 6.00;
        water = 3.00;
        fizzyDrink = 4.00;
    }
};

struct UserInfo
{
    string name;
    string payment;
    vector<Items> costs;
};


void menu();                              // Function prototypes
void comboMenu();
void orderMenu();
void secondMenu();
void orderTotal();
void sandwich();
void hotDog();
void chips();
void salad();
void water();
void fizzyDrink();
void createAccount();
void successfulLogin();
void login();
void adminLogin();
void discountSearch();
void displayOrder();
void payment();

int main()
{


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
            createAccount();
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


void menu()
{
    int choice;

    cout << endl;
    cout << "****************************" << endl;
    cout << "SCHOOL LUNCH ORDERING SYSTEM" << endl;
    cout << "****************************\n" << endl;

    cout << "Food Menu" << endl;
    cout << "*********\n" << endl;

    cout << "Item:\t\t\tCost:\n" << endl;
    cout << "[1] Sandwich\t\t$8.00" << endl;
    cout << "[2] Hot Dog\t\t$6.50" << endl;
    cout << "[3] Chips\t\t$5.00" << endl;
    cout << "[4] Salad\t\t$6.00" << endl;
    cout << "[5] Water\t\t$3.00" << endl;
    cout << "[6] Fizzy Drink\t\t$4.00" << endl;
    cout << "[7] Combo Meal\n" << endl;
    cout << "[8] Cancel\n" << endl;
    cout << "Please choose an option: ";
    cin >> choice;
    cout << endl;

    while (choice > 8 || choice < 1)
    {
        cout << "Please enter a valid choice: " << endl;
        cin >> choice;
    }

    switch (choice)
    {
    case 1:
        sandwich();
        break;

    case 2:
        hotDog();
        break;

    case 3:
        chips();
        break;

    case 4:
        salad();
        break;

    case 5:
        water();
        break;

    case 6:
        fizzyDrink();
        break;

    case 7:
        comboMenu();
        break;
    case 8:
        // Return to previous menu
        break;
    }

}

void comboMenu()
{
    int choice;

    cout << "Combo Options" << endl;
    cout << "*************\n" << endl;
    cout << "All combos include chips and a drink of your choice\n" << endl;

    cout << "[1] Sandwich Combo" << endl;
    cout << "[2] Hot Dog Combo" << endl;
    cout << "[3] Salad Combo\n" << endl;
    cout << "[4] Return to Menu" << endl;
    cout << "[5] Cancel\n" << endl;

    cout << "Please choose an option: ";
    cin >> choice;

    while (choice > 5 || choice < 1)
    {
        cout << "Please enter a valid choice: ";
        cin >> choice;
    }
}

void orderMenu()
{
    int choice;

    cout << "How would you like to proceed?\n" << endl;
    cout << "[1] Add to Order" << endl;
    cout << "[2] View Order Total" << endl;
    cout << "Please enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        menu();
    }

    else if (choice == 2)
    {
        orderTotal();
    }

    else
        cout << "Wrong selection, please choose again: ";
}

void secondMenu()
{
    int choice;
    cout << endl;
    cout << "How would you like to proceed?\n" << endl;
    cout << "[1] Continue to Payment" << endl;
    cout << "[2] Add to Order" << endl;
    cout << "[3] Cancel Order\n" << endl;
    cout << "Please enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        payment();
        break;

    case 2:
        menu();
        break;

    case 3:
        //go to previous menu
        break;
    }
}

void orderTotal()
{
    string line;
    ifstream order;
    order.open("order.txt", ios::in);
    if (order.is_open())
    {
        while (getline(order, line))
        {
            cout << line << '\n';
        }
        order.close();
        secondMenu();
    }
    else
        cout << "Unable to retreive order\n";
    // enter function for main menu or food menu

}

void sandwich()
{
    double quantity;
    struct Items a;
    fstream order;

    cout << "How many sandwiches do you want to order?: ";
    cin >> quantity;

    order.open("order.txt", ios::out | ios::app);
    order << "\nSandwich Quantity: " << quantity << "  Cost: $" << a.sandwich * quantity;
    order.close();

    cout << endl;
    cout << "Thank you, you've added " << quantity << " sandwich/es to your order\n" << endl;

    orderMenu();
}

void hotDog()
{
    double quantity;
    struct Items a;
    fstream order;

    cout << "How many hot dogs do you want to order?: ";
    cin >> quantity;

    order.open("order.txt", ios::out | ios::app);
    order << "\nHot Dog Quantity: " << quantity << "  Cost: $" << a.hotDog * quantity;
    order.close();

    cout << endl;
    cout << "Thank you, you've added " << quantity << " hot dog/s to your order\n" << endl;

    orderMenu();
}

void chips()
{
    double quantity;
    struct Items a;
    fstream order;

    cout << "How many pottles of chips do you want to order?: ";
    cin >> quantity;

    order.open("order.txt", ios::out | ios::app);
    order << "\nChips Quantity: " << quantity << "  Cost: $" << a.chips * quantity;
    order.close();

    cout << endl;
    cout << "Thank you, you've added " << quantity << " pottles of chips to your order\n" << endl;

    orderMenu();
}
void salad()
{
    double quantity;
    struct Items a;
    fstream order;

    cout << "How many salads do you want to order?: ";
    cin >> quantity;

    order.open("order.txt", ios::out | ios::app);
    order << "\nSalad Quantity: " << quantity << "  Cost: $" << a.salad * quantity;
    order.close();

    cout << endl;
    cout << "Thank you, you've added " << quantity << " salad/s to your order\n" << endl;

    orderMenu();
}

void water()
{
    double quantity;
    struct Items a;
    fstream order;

    cout << "How many waters do you want to order?: ";
    cin >> quantity;

    order.open("order.txt", ios::out | ios::app);
    order << "\nWater Quantity: " << quantity << "  Cost: $" << a.water * quantity;
    order.close();

    cout << endl;
    cout << "Thank you, you've added " << quantity << " water/s to your order\n" << endl;

    orderMenu();
}

void fizzyDrink()
{
    double quantity;
    struct Items a;
    fstream order;

    cout << "How many fizzy drinks do you want to order?: ";
    cin >> quantity;

    order.open("order.txt", ios::out | ios::app);
    order << "\nFizzy Drink Quantity: " << quantity << "  Cost: $" << a.fizzyDrink * quantity;
    order.close();

    cout << endl;
    cout << "Thank you, you've added " << quantity << " fizzy drink/s to your order\n" << endl;

    orderMenu();
}
// Function to create a new account
void createAccount()
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

void successfulLogin()
{
    do {
        cout << "**************************** \n";
        cout << "SCHOOL LUNCH ORDERING SYSTEM \n";
        cout << "**************************** \n \n";

        cout << "Welcome \n \n";

        cout << "[1] Create new order \n";
        cout << "[2] Exit \n \n";

        cout << "Please select an option: \n";
        cin >> choice;


        switch (choice)
        {
        case 1:
            menu();
            break;

        case 2:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 2);
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
                successfulLogin();
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

void discountSearch()
{
    ifstream infile("discountCodes.txt");
    if (infile)
    {
        string line;

        while (getline(infile, line))
        {
            if (line.find(discount) != string::npos)
            {
                found = true;
                // Code to apply discount goes here
                cout << "A 15% discount has been applied to your order! \n \n";
                break;
            }
        }

        infile.close();
    }

    if (!found)
    {
        cout << "Invalid discount code, Please try again. \n \n";
    }
}

void displayOrder() {
    ifstream orderFile("order.txt");
    string line;

    while (getline(orderFile, line)) {
        cout << line << endl;
    }

    orderFile.close();
}

void payment() {
    do {
        cout << "**************************** \n";
        cout << "SCHOOL LUNCH ORDERING SYSTEM \n";
        cout << "**************************** \n \n";

        cout << "Payment options \n";
        cout << "*************** \n \n";

        cout << "Your order: \n";
        displayOrder();
        cout << "Total cost: \t \t" << "\n \n";//total cost calculated here

        cout << "[1] Enter discount code \n";
        cout << "[2] Pay with cash \n";
        cout << "[3] Pay with card \n";

        cout << "Please select an option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Use discount code YouGetAnA+ for 15% off your order! \n";
            cout << "Please enter your discount code: \n";
            cin >> discount;
            discountSearch();
            // apply discount to order total
            break;

        case 2:
            cout << "Please make your payment when collecting your order from the lunchroom \n";
            // Back to successful login page?
            break;

        case 3:
            cout << "please enter your card number: \n";
            cin >> cardNumber;
            cout << "please enter your cvc number: \n";
            cin >> cvc;
            cout << "Your payment has been successful! Please collect your order from the lunchroom at lunch time. \n";
            successfulLogin();
            break;

        default:
            cout << "Invalid choice, Please try again. \n";
            break;

        }
    } while (choice != 3);
}