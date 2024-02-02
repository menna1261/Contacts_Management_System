#include "email.h"

email::email()
{
    //ctor
}
email::email(string email_it,string email_type,string email_des){
    set_email(email_it);
    set_type(email_type);
    set_description(email_des);
  }

        void email::set_email(string email_it){
          this-> m_email=email_it;
        }
        void email::set_type(string email_type){
            m_type=email_type;
        }
        void email::set_description(string email_des){
            m_description=email_des;
        }
        void email::print() const{
            cout<<"Email : "<<m_email<<"\t \t |"<< "Type :"<<m_type<<"\t \t |"<<"Description : "<<m_description;
        }
        bool email::isMatched(string key) const{
            return(m_email.compare(key)==0);
        }
