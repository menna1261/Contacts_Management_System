#ifndef USER_H
#define USER_H
#include<iostream>
#include "phone.h"
#include "address.h"
#include "email.h"


using namespace std;


class user
{
    public:
        user();
        void print() const ;
        void read_nameinput();
        void read_phoneinput();
        void read_emailinput();
        void read_genderinput();
        void read_ageinput();
        void read_addressinput();
        void set_user_id(int);
        void set_fname(string);
        void set_lname(string);
        void set_age(int);
        void set_gender (int);
        int get_user_id() const;
        bool find_any() const;
        virtual ~user();

    protected:

    private:
        int m_id;
        string m_fname;
        string m_lname;
        int m_age;
        int m_gender;
        phone * m_phone;
        address * m_address;
        email * m_email;
        int phone_size;
        int address_size;
        int email_size;
        int phone_count;
        int address_count;
        int email_count;

};

#endif // USER_H
