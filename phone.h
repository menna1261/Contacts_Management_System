#include <iostream>
using namespace std;
#ifndef PHONE_H
#define PHONE_H


class phone
{
    public:
        phone();
        phone(string,string,string);
        virtual ~phone();
        void set_phone(string);
        void set_type(string);
        void set_description(string);
        void print() const;
        bool is_matched(string) const;
    protected:

    private:
        string m_phone;
        string m_type;
        string m_description;
};

#endif // PHONE_H
