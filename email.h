#include<iostream>
using namespace std;
#ifndef EMAIL_H
#define EMAIL_H


class email
{
    public:
        email();
        email(string,string,string);

        void set_email(string);
        void set_type(string);
        void set_description(string);
        void print() const;
        bool isMatched(string) const;
    protected:

    private:
        string m_email;
        string m_type;
        string m_description;
};

#endif // EMAIL_H
