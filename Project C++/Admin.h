#pragma once
#include "User.h"

class Admin: public User
{
    //Πεδία
    private:
    static const bool isAdmin = true;

    //Admins Constractor
    public:
    Admin(string n, string p)
    {
        name = n;
        phone = p;
    }
    Admin(){}
    bool getIsAdmin() { return isAdmin; }
};