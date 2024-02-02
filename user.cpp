#include "user.h"
#include <time.h>
using namespace std;

user::user()
{
    phone_size = 3;
    address_size = 3;
    email_size = 3;

    m_phone = new phone[phone_size];
    m_address = new address[address_size];
    m_email = new email[email_size];

    phone_count =0;
    address_count =0;
    email_count=0;
   // m_added = time(0);
    m_gender= 0;
    m_age=0;
}
user::~user()
{
    delete [] m_phone;
    delete [] m_address;
    delete [] m_email;
}
void user::print() const
{
    cout<<"------------------------------------ \n";
    cout<<"ID : "<<m_id<<"\t\tNAME :   "<<m_fname <<" "<< m_lname<<endl;
    if(m_age>0)
        cout<<"AGE: "<<m_age<<"\t\t";
    cout<<(m_gender==0?"MALE":"FEMALE")<<endl;
    if(phone_count>0)
    {
        cout<<"------------------------------------ \n";
        cout<<"\tPHONE LIST :\n";
        for(int i=0; i<phone_count; i++)
        {
            cout<<"\t"<<i+1<<"-";
            m_phone[i].print();
        }
    }
    if(email_count>0)
    {
        cout<<"------------------------------------ \n";
        cout<<"\tEMAIL LIST :\n";
        for(int i=0; i<email_count; i++)
        {
            cout<<"\t"<<i+1<<"-";
            m_email[i].print();
        }
        if(address_count>0)
        {
            cout<<"\n------------------------------------ \n";
            cout<<"\tADDRESS LIST :\n";
            for(int i=0; i<address_count; i++)
            {
                cout<<"\t"<<i+1<<"-";
                m_address[i].print();
            }
        }
    }
}

void user::set_user_id(int id)
{
    m_id=id;
}
void user::set_fname(string firstname)
{
    m_fname=firstname;
}
void user::set_lname(string lastname)
{
    m_lname=lastname;
}
void user::set_age(int age)
{
    m_age=age;
}
void user::set_gender (int gender)
{
    m_gender = gender;
}
int user::get_user_id() const
{
    return m_id;
}

bool user::find_any( ) const
{
    cout<<"search by:\n (1-name/2-phone/3-email/4-address)";
    int c;
    string key;

           /* cout<<"Enter your keyword to find : (Name , Phone , Email ,Address)\n";
            cin.ignore();
            getline(cin,key);*/
cin>>c;
    switch (c)
    {
    case 1:
    {
        {
             cout<<"Enter your keyword to find : (Name , Phone , Email ,Address)\n";
            cin.ignore();
            getline(cin,key);
            if(m_fname.compare(key)==0 || m_lname.compare(key)==0)

                return true;
                else
                    return false;
        }

    }
        break;


    case 2:
    {
         cout<<"Enter your keyword to find : (Name , Phone , Email ,Address)\n";
            cin.ignore();
            getline(cin,key);
        if(phone_count>0)
        {
            for(int i=0; i<phone_count; ++i)
            {
                if(m_phone[i].is_matched(key))
                    return true;
                    else
                    return false;
            }

        }
    }
        break;


    case 3:
    {
         cout<<"Enter your keyword to find : (Name , Phone , Email ,Address)\n";
            cin.ignore();
            getline(cin,key);
        if(email_count>0)
        {
            for(int i=0; i<email_count; ++i)
            {
                if(m_email[i].isMatched(key))
                    return true;
                else
                    return false;
            }
        }
    }
        break;


    case 4:
    {
         cout<<"Enter your keyword to find : (Name , Phone , Email ,Address)\n";
            cin.ignore();
            getline(cin,key);
        if(address_count>0)
        {
            for(int i=0; i<address_count; ++i)
            {
                if(m_address[i].is_Matched(key))
                    return true;

                else
                    return false;
            }
        }
    }

        break ;

    default:
        cout<<"Not Found";
        return false;

    }
}
void user:: read_nameinput()
{
    cout<<"First Name : ";
    cin.ignore();
    getline(cin,m_fname);
    cout<<"Last Name : ";
    //cin.ignore();
    getline(cin,m_lname);
}
void user::read_genderinput()
{
    cout<<"GENDER (male (0), female (1)): ";
    cin>>m_gender;
}
void user::read_ageinput()
{
    cout<<"AGE : ";
    cin>>m_age;
}
void user::read_phoneinput()
{
    int n=0;
    cout<<"How Many Phones ? ";
    cin>>n;
    cin.ignore();
    for (int i=0; i<n; i++)
    {
        cout<<"------------------------------------ \n";
        string data,type,desc;
        cout<<"Phone number ("  <<i+1 <<") : "<<endl;
        getline(cin,data);
        cout<<"Type : ";
        getline(cin,type);
        cout<<"Description : ";
        getline(cin,desc);
        phone * new_phone=new phone(data,type,desc);
        m_phone[phone_count++]= *new_phone;
    }
}
void user::read_emailinput()
{
    int x=0;
    cout<<"How Many Emails ? ";
    cin>>x;
    cin.ignore();
    for (int i=0; i<x; i++)
    {
        cout<<"------------------------------------ \n";
        string data,type,desc;
        cout<<"Email ("  <<i+1 <<") : "<<endl;
        getline(cin,data);
        cout<<"Type : ";
        getline(cin,type);
        cout<<"Description : ";
        getline(cin,desc);
        email * new_email=new email(data,type,desc);
        m_email[email_count++]= *new_email;
    }
}
void user::read_addressinput()
{
    int y=0;
    cout<<"How Many Adresses ? ";
    cin>>y;
    cin.ignore();
    for (int i=0; i<y; i++)
    {
        cout<<"------------------------------------ \n";
        string data,type,desc;
        cout<<"Adress ("  <<i+1 <<") : "<<endl;
        getline(cin,data);
        cout<<"Type : ";
        getline(cin,type);
        cout<<"Description : ";
        getline(cin,desc);
        address * new_address=new address(data,type,desc);
        m_address[address_count++]= *new_address;
    }

}






