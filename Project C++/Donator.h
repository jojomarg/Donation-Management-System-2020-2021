#pragma once
#include "User.h"
#include<vector>

class Offers;

class Donator: public User
{
    //Πεδία
    private:
    vector <Offers> offersList;
    static const bool isAdmin = false;

    //Μέθοδοι
    public:
    Donator(string n, string p) // Donator's Constractor
    {
        name = n;
        phone = p;
    }

    bool getIsAdmin() { return isAdmin; }

    vector <Offers> &getOffersList() { return offersList; }

    void setOffersList(vector <Offers> o) { offersList = o; }
};
