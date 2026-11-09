
// Adam Johnson
// Business Project V2
// V 3adds to V2 by holding the items purchesed as an array and expanding the recipet 
// 11-8-2026

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
const int MENU_WIDTH = 25;
const int TITLE_WIDTH_L = 30;
const int TITLE_WIDTH_R = 10;
const int RECEIPT_WIDTH = 40;
const int MAX_ITEMS = 100;
const int HASHTAG = 5;
const int ITEM_W = 25;
const int PRICE_W = 10;
const int ENDING_W = 28;

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
    string orderedItems[MAX_ITEMS];
    double orderedPrices[MAX_ITEMS];

    //Menu
    cout << "Welcome to Cosmic Comics" << endl;
    cout << "Come catch your favorite heroes and villains at Cosmic Comics" << endl << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << " MENU" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "Comics" << endl;
    cout << left << setw(MENU_WIDTH) << "Single Issue (S)" << "$" << SINGLE << endl;
    cout << left << setw(MENU_WIDTH) << "Trade Paperback (T)" << "$" << TRADE << endl;
    cout << left << setw(MENU_WIDTH) << "Omnibus (O)" << "$" << OMNIBUS << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "Action Figures" << endl;
    cout << left << setw(MENU_WIDTH) << "Small (1)" << "$" << SMALL_AC << endl;
    cout << left << setw(MENU_WIDTH) << "Medium (2)" << "$" << MEDIUM_AC << endl;
    cout << left << setw(MENU_WIDTH) << "Large (3)" << "$" << LARGE_AC << endl;
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
          
        }
        if (itemCount < MAX_ITEMS)
        {
            orderedItems[itemCount] = productName;
            orderedPrices[itemCount] = itemPrice;

            subtotal += itemPrice;
            itemCount++;
        }
        else
        {
            cout << "Maximum number of items reached." << endl;
        }

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

    cout << endl;
    cout << "========================================" << endl;
    cout << right << setw(TITLE_WIDTH_L) << "COSMIC COMICS RECEIPT" << endl;
    cout << "========================================" << endl;

    cout << left << setw(HASHTAG) << "#" << setw(ITEM_W) << "Item" << right << setw(PRICE_W) << "Price" << endl;

    cout << "----------------------------------------" << endl;

    //Printing purchased items
    for (int i = 0; i < itemCount; i++)
    {
        cout << left << setw(HASHTAG) << i + 1 << setw(ITEM_W) << orderedItems[i]<< right << setw(PRICE_W) << orderedPrices[i] << endl;
    }

    cout << "----------------------------------------" << endl;

    cout << left << setw(TITLE_WIDTH_L) << "Number of Items:" << right << setw(TITLE_WIDTH_R) << itemCount << endl;

    cout << left << setw(TITLE_WIDTH_L) << "Subtotal:"<< right << setw(TITLE_WIDTH_R) << subtotal << endl;

    cout << left << setw(TITLE_WIDTH_L) << "Tax (10%):"<< right << setw(TITLE_WIDTH_R) << tax << endl;

    cout << left << setw(TITLE_WIDTH_L) << "Total:"<< right << setw(TITLE_WIDTH_R) << total << endl;

    cout << "========================================" << endl;
    cout << right << setw(ENDING_W) << "Have a Great Day!" << endl;
    cout << "========================================" << endl;

    return 0;
}
