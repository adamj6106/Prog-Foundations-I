// JohnsonAGradelist_.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Adam Johnson
//9.14.26
//Gradelist V1: read in a from file test scores, calculate avg, then output to file

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

//constants
const int STUDENT = 20;
const int TEST = 8;
const int TEST_AVG = 10;

int main()
{
    //delcare variables
    string name;
    double test1;
    double test2;
    double test3;
    double average;

    //decalre file stream variables
    ifstream fin;
    ofstream fout;

    //open file
    fin.open("AJohnson_Testscores.txt"); //needs to be created before opening

    //output file
    fout.open("Results.txt");

    //program title and description
    cout << "Grade List Program" << endl;
    cout << "Created by: Adam Johnson" << endl;
    cout << "This program will read in student names, and 3 test scores from a file. \n";
    cout << "and then calculate each students exam average." << endl;
    cout << "the results will print to an external file named: \"results.txt\"." << endl << endl;


    //output to file- coulmn headings
    fout << setw(STUDENT) << left << "Name" << setw(TEST) << right << "Test 1" << setw(TEST) << "Test 2" << setw(TEST) << "Test 3" << setw(TEST) << "Test Avg" << endl;

    //reading in data- student 1
    getline(fin, name);
    fin >> test1 >> test2 >> test3;

    //calculations- student 1
    average = (test1 + test2 + test3) / 3;

    //output to file- student 1
    fout << fixed << setprecision(2) << showpoint;
    fout << setw(STUDENT) << left << name << setw(TEST) << right << test1 << setw(TEST) << test2 << setw(TEST) << test3 << setw(TEST) << average << endl;


    //reading in data- student 2
    fin.ignore();
    getline(fin, name);
    fin >> test1 >> test2 >> test3;

    //calculations- student 2
    average = (test1 + test2 + test3) / 3;

    //output to file- student 2
    fout << fixed << setprecision(2) << showpoint;
    fout << setw(STUDENT) << left << name << setw(TEST) << right << test1 << setw(TEST) << test2 << setw(TEST) << test3 << setw(TEST) << average << endl;

    //reading in data- student 3
    fin.ignore();
    getline(fin, name);
    fin >> test1 >> test2 >> test3;

    //calculations- student 3
    average = (test1 + test2 + test3) / 3;

    //output to file- student 3
    fout << fixed << setprecision(2) << showpoint;
    fout << setw(STUDENT) << left << name << setw(TEST) << right << test1 << setw(TEST) << test2 << setw(TEST) << test3 << setw(TEST) << average << endl;

    //out put to console
    cout << "The program ran successfully. Check output file" << endl;
    cout << " \"results.txt\" for results." << endl;

    //close file
    fin.close();
    fout.close();


    return 0;

}
