#include "phone.h"

phone::phone()
{
    //ctor
}
phone::phone(string phone_number,string phone_type,string phone_description){
    set_phone(phone_number);
    set_type(phone_type);
    set_description(phone_description);

}
phone::~phone()
{
    //dtor
}
void phone::set_phone(string phone_number){
    this->m_phone=phone_number;
}
void phone::set_type(string phone_type){
    this->m_type=phone_type;
}
void phone::set_description(string phone_description){
    this->m_description=phone_description;
}
bool phone::is_matched(string key) const{
    return (m_phone.compare(key)==0);
}
  void phone:: print() const{
  cout<< "Phone: "<<m_phone<<"\t \t | " <<"Type :"<<m_type <<"\t \t | "<<"Description :"<<m_description<<endl;
  }
