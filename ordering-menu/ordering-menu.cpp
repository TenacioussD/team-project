#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
    

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
        // include payment function

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


int main()
{ 
    menu();

    return 0;
}
