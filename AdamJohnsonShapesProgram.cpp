// Shapes V1
// Adam Johnson
// Shapes porgram with do-while loop


#include <iostream>
#include <string>

using namespace std;

//constant variables
const double PI = 3.14;

int main()
{
	//declare variables
	int shapeChoice;
	string shapeName;
	double length;
	double width;
	double height;
	double radius;
	double base;
	double area;

	//Program title
	cout << "Shapes Program" << endl;
	cout << "Created by: NAME" << endl << endl;

	//Program description
	cout << "This program will ask the user to make 1 menu selection " << endl;
	cout << "by choosing a shape and then calculate its area." << endl << endl;
	do
	{


		do
		{


			//Shape menu and slection
			cout << "Shape choices: " << endl;
			cout << " 1 - Rectangle" << endl;
			cout << " 2 - Circle" << endl;
			cout << " 3 - Triangle" << endl;
			cout << " 4 - Parallelogram" << endl;
			cout << "Enter number for your shape choice: ";
			cin >> shapeChoice;
			cout << endl;

			if (shapeChoice != 1 && shapeChoice != 2 && shapeChoice != 3 && shapeChoice != 4)
			{
				cout << "You've entered an invalid input, please try again" << endl;
			}
			cin.clear();
			cin.ignore();
		} while (shapeChoice != 1 && shapeChoice != 2 && shapeChoice != 3 && shapeChoice != 4);
		
		//error check user input for shapeChoice
	
		if (!cin)
		{
			cout << "You entered invalid data. Program is terminating." << endl;
			return 1;
		}

		//assign shape, ask the user for input and calculations



		if (shapeChoice == 1) {
			shapeName = "Rectangle";
			cout << "Enter the length of the rectangle in inches (ex: 5.5): ";
			cin >> length;

			cout << "Enter the width of the rectangle in inches (ex: 3.2): ";
			cin >> width;
			//calculations
			area = (length * width);
		}
		else if (shapeChoice == 2) {
			shapeName = "Circle";
			cout << "Enter the radius of the circle in inches (ex: 8.0): ";
			cin >> radius;
			//calculations
			area = PI * (radius * radius);
		}
		else if (shapeChoice == 3) {
			shapeName = "Triangle";
			cout << "Enter the base of the triangle in inches (ex: 6.8): ";
			cin >> base;
			cout << "Enter the height of the triangle in inches (ex: 5.5): ";
			cin >> height;
			//calculations
			area = (base * height) / 2;
		}
		else if (shapeChoice == 4) {
			shapeName = "Parallelogram";
			cout << "Enter the base of the parallelogram in inches (ex: 8.5): ";
			cin >> base;
			cout << "Enter the height of the parallelogram in inches (ex: 4.2): ";
			cin >> height;
			//calculations
			area = (base * height);
		}
		else
		{
			cout << "You entered a number outside of range. Program is terminating." << endl;
			return 1;
		}

		// Output
		cout << endl;
		cout << "You chose shape: " << shapeName << endl << endl;
		cout << "The area is :" << area << " inches squared." << endl;

		if (!cin|| area == 0)
		{
			cout << "It seams there was an error with some of your inputs, please try again" << endl;
			cin.clear();
			cin.ignore();

				area = 0;
		}


	} while (area == 0);
	return 0;
}

