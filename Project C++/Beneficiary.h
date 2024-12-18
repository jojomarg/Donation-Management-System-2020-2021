#pragma once
#include "User.h"
#include<vector>
class RequestDonationList;
class Requests;

class Beneficiary: public User
{
    //Πεδία
    private:
    int noPersons = 1;
    vector <RequestDonationList> receivedList;
    vector <Requests> requestedList;
    static const bool isAdmin = false;

    //Μέθοδοι
    public:
    Beneficiary(string n, string p, int noP) // Beneficiary's Constractor
    {
        name = n;
        phone = p;
        noPersons = noP;
    }
    bool getIsAdmin() { return isAdmin; }

    int getnoPersons() { return noPersons; }

    vector <RequestDonationList> &getReceivedList() { return receivedList; }

    vector <Requests> &getRequestedList() { return requestedList; }

    // used for initializing requested list for testing
    void setRequestedList(vector <Requests> r) { requestedList = r; }
};
