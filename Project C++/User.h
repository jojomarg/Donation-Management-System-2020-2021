#pragma once
#include<string>
using namespace std;

class User
{
   //Πεδία
   protected:
   string name;
   string phone;

   //Μέθοδοι
   public:
   string getName() { return name; }
   string getPhone() { return phone; }
   bool isEqual(User u)  { return !(this->getPhone().compare(u.getPhone())); }
};