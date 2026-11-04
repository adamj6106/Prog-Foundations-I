
// Adam Johnson 
// 11.4.26
// Functions 2 

#include <iostream>
#include <string>

using namespace std;

//declare function
//format: returnType functionName(parameters);
//retureType = type of value the functions sends back 
//functionName = name used to call the function
//parameters = information the needs (if any)

void welcome();
void displayName(string first, string last);
string concat(string fName, string lName);
bool nicknameCheck(string nickname);
void displayNickName(string nickname, bool nncheck);

int main()
{
    //declare variables 
    string first;
    string last;
    string lName;
    string fName;
    string fullName;
    string nickname;
    bool nnCheck;

    //call function 

    //calling function #1
    welcome();

    cout << "Please enter your first name: ";
    cin >> fName;
    cout << "Please enter your last name: ";
    cin >> lName;
    cout << "Please enter your nickname, if you don't have one enter none: ";
    cin >> nickname;



    //call function #2
    displayName(fName, lName);

    //call function #3
    fullName = concat(fName, lName);

    cout << "Your full names is " << fullName << "." << endl;

    //call function 4
    nnCheck = nicknameCheck(nickname);

    //call funtion 5
    displayNickName(nickname, nnCheck);

    return 0;
}

//define function 
//function #1
void welcome()
{
    cout << "Welcome to Programming 1: All about functions!" << endl;
}

//function #2
void displayName(string first, string last)
{
    cout << endl << "Your first names is " << first << "." << endl;
    cout << "Your last name is " << last << "." << endl;
}

//function #3 
string concat(string fName, string lName)
{
    return fName + " " + lName;
}


// fuction 4
// bool means this fuction must return true or false
// nickName recives a copy of nickname from main()
// the rturned value is assigned nnCheck in main()
bool nicknameCheck(string nickname)
{
    bool nn;
    if (nickname == "None" || nickname == "none" || nickname == "NONE")
    {
        nn = false;
    }
    else
    {
        nn = true;
    }

    return nn; //send the boolean result back to main()
}

// fuction 5
// recives the function and boolean results
// it doesn't return a value; but it does siplay a message
void displayNickName(string nickName, bool nnCheck)
{
    if (nnCheck == false)
    {
        cout << "You do not have a perfered nickname" << endl;
    }
    else
    {
        cout << "Your nickname is " << nickName << "." << endl;
    }
}