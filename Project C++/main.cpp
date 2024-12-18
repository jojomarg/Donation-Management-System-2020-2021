#include <iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include"Material.h"
#include"Service.h"
#include"Menu.h"


using namespace std;

// class User;
// class Admin;
// class Beneficiary;
// class Donator;
// class Entity;
// class Material;
// class Service;
// class RequestDonation;
// class Organization;
// class RequestDonationList;
// class Requests;
// class Offers;
// class Menu;


int main()
{
    //Στη C++ δε μπορείς να έχεις λίστα από μικτές κλάσεις (υπερκλάσεις και υποκλάσεις αυτών, πχ Entity και Material/Service), επειδή κατά το compiling, 
    //ο compiler δεν ξέρει πόσο χώρο να δημιουργήσει για την κάθε θέση της λίστας που αποθηκεύονται, αφού κάθε κλάση δημιουργεί αντικείμενα διαφορετικού μεγέθους
    //Μπορείς, όμως να έχεις δείκτες σε μικτές κλάσεις, επειδή οι δείκτες έχουν πάντα ίδιο μέγεθος (ίσο με int). Για αυτό παρακάτω φτιάχνουμε τα αντικείμενα και 
    //αποθηκεύουμε σε vector<Entity*> τους δείκτες προς αυτά.
    Material Rice("rice", "rice", 1, 2, 3); 
    Material *rice = &Rice;
    Material Milk("milk", "milk", 1, 2, 3);
    Material *milk = &Milk;
    Material Sugar("sugar", "sugar", 1, 2, 3);
    Material *sugar = &Sugar;

    Service BabySitting = Service("Babysitting", "Babysitting description");
    Service *babySitting = &BabySitting;
    Service NurserySupport = Service("Nursery Support", "Nursery Support description");
    Service *nurserySupport = &NurserySupport;
    Service MedicalSupport = Service("Medical Support", "Medical Support description");
    Service *medicalSupport = &MedicalSupport;

    vector <Entity*> entityList;
    entityList.push_back(rice);
    entityList.push_back(milk);
    entityList.push_back(sugar);
    entityList.push_back(babySitting);
    entityList.push_back(nurserySupport);
    entityList.push_back(medicalSupport);

    Organization RedCross("RedCross", entityList);

    cout << "Welcome to the Project!" << endl;
    Admin A("George", "1");

    Beneficiary B1("Maria", "2", 3);
    RedCross.insertBeneficiary(B1);
    Beneficiary B2("Jim", "3", 5);
    RedCross.insertBeneficiary(B2);

    Requests testRequest;
    vector <Requests> testRequestedList;
    testRequest.add(RedCross.getEntityList(), B1, RequestDonation(babySitting));
    testRequest.add(RedCross.getEntityList(), B1, RequestDonation(rice, 1));
    testRequestedList.push_back(testRequest);
    B1.setRequestedList(testRequestedList);


    Donator D("Kate", "5");
    RedCross.insertDonator(D);

    Offers testOffer;
    vector <Offers> testOffersList;
    testOffer.add(RedCross.getEntityList(), RequestDonation(rice, 20));
    testOffer.add(RedCross.getEntityList(), RequestDonation(milk, 10));
    testOffer.add(RedCross.getEntityList(), RequestDonation(babySitting));
    testOffer.add(RedCross.getEntityList(), RequestDonation(nurserySupport));
    testOffersList.push_back(testOffer);
    D.setOffersList(testOffersList);

    for(int i=0; i < testOffersList.size(); i++)
    {
        RedCross.setTestCurrentDonations(testOffersList[i]);
    }

    RedCross.setAdmin(A);

    Menu m(RedCross);

    return 0;
}