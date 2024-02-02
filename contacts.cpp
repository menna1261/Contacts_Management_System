#include "contacts.h"

contacts::contacts(int contact_size){
    m_size = contact_size;
    m_users= new user[m_size];
    m_count=0;
}


contacts::~contacts()
{
    delete [] m_users;
}
  void contacts:: addNewUser(){
      user *new_user= new user();
        new_user->set_user_id(m_count+1);

        new_user->read_nameinput();
         new_user->read_ageinput();
        new_user->read_genderinput();
         new_user->read_phoneinput();
         new_user->read_emailinput();
         new_user->read_addressinput();
      //new_user->read_input();
      m_users[m_count++] = * new_user;

  }
        void contacts::detUser(int user_id){
           if(m_count==0){
            cout<<"NOT FOUND!\n";
           return;
        }
        bool deleted =false;
        for(int i=0;i<m_count;++i){
            if(m_users[i].get_user_id()==user_id)
                if(i==m_count-1){
                    m_count--;
                }else{
                    m_users[i]=m_users[m_count-1];
                    m_count--;
                }
                deleted =true;
                break;
        }
        if(deleted=true){
            cout<<"User has been deleted successfully\n";

        }
        else
            cout<<"No user exists\n";
        }
        void contacts::editUser(int user_id){
            if(m_count==0){
                cout<<"No user exists\n";
                return;
            }
            bool edited =false;
            for(int i=0;i<m_count;++i)
            {
                int z=0;
                if(m_users[i].get_user_id()==user_id){
                    cout<<"What do you want to edit ?\n";
                    cout<<"(1)name\n";
                    cout<<"(2)age\n";
                    cout<<"(3)gender\n";
                    cout<<"(4)phone\n";
                    cout<<"(5)email\n";
                    cout<<"(6)address\n";
                    cout<<"Enter your choice \n";
                    cin>>z;

                    switch(z)
                        {
                    case 1:

                        m_users[i].read_nameinput();
                        break;

                    case 2 :
                        m_users[i].read_ageinput();
                        break;
                    case 3 :
                        m_users[i].read_genderinput();
                        break;
                    case 4 :
                        m_users[i].read_phoneinput();
                        break;
                    case 5 :
                        m_users[i].read_emailinput();
                        break;
                    case 6 :
                        m_users[i].read_addressinput();
                        break;
                        }

                   // m_users[i].read_input();
                    edited =true;
                    break;
                }
            }
            if(edited=true)
                cout<<"User has been edited successfully\n";
            else
                cout<<"No user exist";
        }
        void contacts::print() const{
            if(m_count==0){
                cout<<"No user found\n";
                return;
            }
            for(int i=0;i<m_count;++i)
                m_users[i].print();
        }
        void contacts::findAll() const{
            int found=0;
            for(int i=0;i<m_count;++i){
                if(m_users[i].find_any()==true){
                    m_users[i].print();
                    found++;
                }
            }


            if(found==0)
                cout<<"\n\nNOT FOUND\n";
            else
                cout<<"\n\nFOUND\n";
        }
