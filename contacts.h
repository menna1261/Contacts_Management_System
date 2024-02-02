#ifndef CONTACTS_H
#define CONTACTS_H
#include<iostream>
#include "user.h"
using namespace std;


class contacts
{
    public:
        contacts(int);
        virtual ~contacts();
        void addNewUser();
        void detUser(int);
        void editUser(int);
        void print() const;
        void findAll() const;

    protected:

    private:
        int m_count;
        int m_size;
        user * m_users;
};

#endif // CONTACTS_H
