
// Adam Johnson
// Business Project V2
// V2 adds to V1 by adding error checking and allowing the customer to order more then one item
// 10-4-2026

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

//Constants
const double TAX_RATE = 0.10;
const double SMALL_AC = 10.00;
const double MEDIUM_AC = 18.00;
const double LARGE_AC = 25.00;
const double SINGLE = 5.00;
const double TRADE = 15.00;
const double OMNIBUS = 35.00;

int main()
{
    //Setting all numbers to 2 decimal places
    cout << fixed << showpoint << setprecision(2);

    //Variables
    char orderAgain;
    int itemCount = 0;
    double itemPrice = 0.00;
    double subtotal = 0.00;
    double tax;
    double total;
    char itemChoice;
    int actionFigureSize;
    char comicBookSize;
    string productName;

    //Menu
    cout << "Welcome to Cosmic Comics" << endl;
    cout << "Come catch your favorite heroes and villains at Cosmic Comics" << endl << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << " MENU" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "Comics" << endl;
    cout << left << setw(25) << "Single Issue (S)" << "$" << SINGLE << endl;
    cout << left << setw(25) << "Trade Paperback (T)" << "$" << TRADE << endl;
    cout << left << setw(25) << "Omnibus (O)" << "$" << OMNIBUS << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "Action Figures" << endl;
    cout << left << setw(25) << "Small (1)" << "$" << SMALL_AC << endl;
    cout << left << setw(25) << "Medium (2)" << "$" << MEDIUM_AC << endl;
    cout << left << setw(25) << "Large (3)" << "$" << LARGE_AC << endl;
    cout << "------------------------------------------------------------" << endl << endl;

    //Customer choice
    do
    {


        cout << "Would you like a Comic book or Action Figure? (Please enter C or A): ";
        cin >> itemChoice;
        while (itemChoice != 'C' && itemChoice != 'c' && itemChoice != 'A' && itemChoice != 'a')
        {
            cout << "Invalid input. Please enter C or A: ";
            cin >> itemChoice;
        }

        cout << endl;

        //Error Checking
        if (itemChoice == 'C' || itemChoice == 'c')
        {
            //Comic size
            cout << "Select your comic size (S, T, O): ";
            cin >> comicBookSize;

            while (comicBookSize != 'S' && comicBookSize != 's' &&
                comicBookSize != 'T' && comicBookSize != 't' &&
                comicBookSize != 'O' && comicBookSize != 'o')
            {
                cout << "Invalid input. Please enter S, T, or O: ";
                cin >> comicBookSize;
            }

            if (comicBookSize == 'S' || comicBookSize == 's')
            {
                productName = "single issue";
                itemPrice = SINGLE;
            }
            else if (comicBookSize == 'T' || comicBookSize == 't')
            {
                productName = "Trade Paperback";
                itemPrice = TRADE;
            }
            else if (comicBookSize == 'O' || comicBookSize == 'o')
            {
                productName = "Omnibus";
                itemPrice = OMNIBUS;
            }
            else
            {
                cout << "You've entered an invalid input, program terminating" << endl;
                return 0;
            }
        }
        else if (itemChoice == 'A' || itemChoice == 'a')
        {
            //Action figure size
            cout << "Select your action figure size (1, 2, 3): ";
            cin >> actionFigureSize;

            while (!cin || actionFigureSize < 1 || actionFigureSize > 3)
            {

                cin.clear();
                cin.ignore();

                cout << "Invalid input. Please enter 1, 2, or 3: ";
                cin >> actionFigureSize;

            }



            if (!cin)
            {
                cout << "You've entered an invalid input, program terminating" << endl;
                return 0;
            }

            if (actionFigureSize == 1)
            {
                productName = "small Action Figure";
                itemPrice = SMALL_AC;
            }
            else if (actionFigureSize == 2)
            {
                productName = "medium Action Figure";
                itemPrice = MEDIUM_AC;
            }
            else if (actionFigureSize == 3)
            {
                productName = "large Action Figure";
                itemPrice = LARGE_AC;
            }
            else
            {
                cout << "You've entered an invalid input, program terminating" << endl;
                return 0;
            }
        }
        subtotal += itemPrice;
        itemCount++;

        cout << "Would you like to purchase another item? (Y/N): ";
        cin >> orderAgain;

        while(orderAgain != 'Y' && orderAgain != 'y' && orderAgain != 'N' && orderAgain != 'n')
        {
            cout << "Invalid input. Please enter Y or N: ";
            cin >> orderAgain;
        }

    } while (orderAgain == 'Y' || orderAgain == 'y');

    //Calculations
    tax = subtotal * TAX_RATE;
    total = subtotal + tax;

    //Receipt
    cout << "------------------------------------------------------------" << endl;
    cout << "You've ordered " << itemCount << " items." << endl << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << left << setw(20) << "Subtotal:" << "$" << subtotal << endl;
    cout << left << setw(20) << "Tax (10%):" << "$" << tax << endl;
    cout << left << setw(20) << "Total:" << "$" << total << endl;
    cout << "------------------------------------------------------------" << endl << endl;

    cout << "Thank you for coming to Cosmic Comics! Have a good day!" << endl;

    return 0;
}
