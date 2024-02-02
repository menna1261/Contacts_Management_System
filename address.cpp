#include "address.h"

address::address()
{
    //ctor
}
  address::address(string address_it,string address_type,string address_des){
        set_address(address_it);
        set_type(address_type);
        set_description(address_des);
   }

       void address::set_address(string address_it){
          this-> m_address=address_it;
       }
        void address::set_type(string address_type){
            this-> m_type=address_type;
        }
        void address::set_description(string address_des){
            this-> m_description=address_des;
        }
        void address::print() const{
        cout<< "Address: "<<m_address<<"\t \t | " <<"Type :"<<m_type <<"\t \t | "<<"Description :"<<m_description<<endl;
  }
        bool address::is_Matched(string key) const{
            return(m_address.compare(key)==0);
        }
