#include <iostream>
using namespace std;
#ifndef ADDRESS_H
#define ADDRESS_H


class address
{
    public:
        address();
         address(string,string,string);
       void set_address(string);
        void set_type(string);
        void set_description(string);
        void print() const;
        bool is_Matched(string) const;
    protected:

    private:
        string m_address;
        string m_type;
        string m_description;
};

#endif // ADDRESS_H
