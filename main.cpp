#include <iostream>
#include "phone.h"
#include "email.h"
#include <unistd.h> // sleep
#include "contacts.h"
#include "user.h"
#include <cstdlib>          // cls
#include <windows.h>        // Sleep
#include <cstring>          // string, to_string
#include <bits/stdc++.h>    // stringstream
#include <windows.h>        // SetConsoleTextAttribute

using namespace std;

HANDLE cout_handle = GetStdHandle(STD_OUTPUT_HANDLE);

/** ASSISTANT INLINE FUNCTIONS **/

inline void wait_or_clear(unsigned int sec, bool clear_screen = false)
{
    Sleep(sec*1000);
    if (clear_screen) system("cls");
}

inline void printline(string msg, bool end_line = true, int color_code=15)
{
    SetConsoleTextAttribute(cout_handle, color_code);
    cout <<  msg << (end_line?"\n":"\t");
}

inline void print_try_again()
{
    printline("\n\n\n\aInvalid Choice Try Again!!!!!!!!",1,4);
    wait_or_clear(3, 1);
}

/** MAIN PRINT MENU FUNCTION **/

int get_menu_choise(string menu, int level = 0)
{
    stringstream X(menu);
    string line, padding;
    int i = 1;
    for(int p=0; p<level+1; ++p)
        padding +="\t";

    while (getline(X, line, ','))
        printline(padding + to_string(i++) + ". " + line,1,level+11);

    printline(level?padding+"0. RETURN BACK":padding+"0. EXIT APP",1,5);
    int c;
    printline("ENTER YOUR CHOICE :",false,2);
    cin >> c;
 return c;
}
 /*
}
void  Edit_users()
{
    contacts contact(100);
    wait_or_clear(0, 1);
    printline("\n\nMAIN MENU -> EDIT USER ....");
    int new_id=0;
    cout<<"Enter user ID to edit : ";
    cin>>new_id;
    contact.editUser(new_id);
    sleep(3);

}
void print_all()
{
    contacts contact(100);
    user s1;
    wait_or_clear(0, 1);
    printline("\n\nMAIN MENU -> PRINT ALL ....");
    s1.print();
    sleep(3);
}*/
/*
void Add_users()
{
    contacts contact(100);
    user s1;
    wait_or_clear(0, 1);
    printline("\n\nMAIN MENU -> ADD USER ....");

    s1.read_nameinput();
    s1.read_ageinput();
    s1.read_genderinput();
    s1.read_phoneinput();
    s1.read_emailinput();
    s1.read_addressinput();

    sleep(1);
    contact.addNewUser();
    sleep(1);
    s1.print();
    sleep(5);
}/*
void  delete_user()
{

    contacts contact(100);
    user s1;
    wait_or_clear(0, 1);
    printline("\n\nMAIN MENU -> DELETE USER ....");
    int delete_id=0;
    cout<<"Enter user ID to delete : ";
    cin>>delete_id;
    contact.detUser(delete_id);
    sleep(3);
}

void search_u()
{
    contacts contact(100);
    wait_or_clear(0, 1);
    printline("\n\nMAIN MENU -> SEARCH ....");
    string key;
    cout<<"Enter your keyword to find : (Name , Phone , Email ,Address)\n";
    cin.ignore();
    getline(cin,key);
    contact.findAll(key);
    sleep(3);
}
*/

int main()
{
contacts contact (100);
    printline("START APPLICATION ....",1,6);
    wait_or_clear(1,1);
    int c = -1;
    while (c!=0)
    {
        wait_or_clear(0,1);
        printline("\n\nMAIN MENU ....",1,10);
        c = get_menu_choise("ADD USER,EDIT USER,SEARCH,PRINT ALL,DELETE USER",0);
        switch(c)
        {
        case 1:
        {

           system("cls");
            printline("\n\nMAIN MENU -> ADD USER ....");
            contact.addNewUser();

        }
        break;
           // Add_users();

        break;
        case 2:
        {
            system("cls");
            printline("\n\nMAIN MENU -> EDIT USER ....");
            int edit_id=0;
            cout<<"Enter user ID to edit : ";
            cin>>edit_id;
            contact.editUser(edit_id);
            sleep(4);
            system("pause");
        }
            //Edit_users();
        break;
        case 3:
        {
            system("cls");
            printline("\n\nMAIN MENU -> SEARCH ....");

            contact.findAll( );
            sleep(4);
        }
            //search_u();
        break;
        case 4:
        {
            system("cls");
            printline("\n\nMAIN MENU -> PRINT ALL ....");
            contact.print();
            sleep(4);
        }
            //print_all();
        break;
        case 5:
        {
            system("cls");
            printline("\n\nMAIN MENU -> DELETE USER ....");
            int delete_id=0;
            cout<<"Enter user ID to delete : ";
            cin>>delete_id;
            contact.detUser(delete_id);
            sleep(4);

        }
            //delete_user();
        break;
        case 0:
            printline("\n\n\a\t\t\tGoodbye :)......\n\n\n\n\n\n",1,112);
            break;
        default:
            wait_or_clear(3, true);
        }
    }

    return 0;
}

