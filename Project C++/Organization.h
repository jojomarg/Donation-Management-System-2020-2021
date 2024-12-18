#pragma once
#include<string>
#include"Admin.h"
#include"RequestDonationList.h"
#include"Entity.h"
#include"Beneficiary.h"
#include"Donator.h"
#include"Offers.h"
#include"Requests.h"


class Organization
{
//Πεδία
    private:
    string name;
    Admin admin;
    RequestDonationList currentDonations;
    vector <Entity*> entityList;
    vector <Donator> donatorsList;
    vector <Beneficiary> beneficiaryList;

//Μέθοδοι
    public:
    Organization (string n, vector <Entity*> e) //Organization's Constractor - Gives the Organization a name and gives the entity list an entity
    {
        name = n;
        entityList = e;
    }

    void setTestCurrentDonations(Offers o) { currentDonations = (RequestDonationList) o; }

    string getName() { return name; }    // Returns Organizations name

    //Admin Methods
    void setAdmin(Admin a) { admin = a; } // Creates an Admin User

    Admin getAdmin() { return admin; } // Returns an Admin

    //Entity Methods
    void addEntity(Entity *entity)
    {
        for(int i = 0; i < entityList.size(); i++)
        {
            Entity *current_Entity = entityList[i];
            if(current_Entity->isEqual(*entity))
            {
                try{
                    throw "Entity Exists";
                }catch(const char* e)
                {
                    cout << e << endl;
                }
            }
        }
        entityList.push_back(entity);
    }

    void removeEntity(Entity *entity, bool isAdmin)
    {
        for(int i = 0; i < entityList.size(); i++)
        {
            Entity *current_Entity = entityList[i];
            if(isAdmin == true)
            {
                if(current_Entity->isEqual(*entity))
                {
                   entityList.erase(entityList.begin() + i);
                }
                else
                {
                    try{
                        throw "The Entity you are trying to erase does not exist.";
                    }catch(const char* e)
                    {
                        cout << e << endl;
                    }
                }
            }
            else
            {
                try{
                    throw "You are not an Admin.";
                }catch(const char* e)
                {
                    cout << e << endl;
                }
            }
        }
    }

    //Donator Methods
    void insertDonator(Donator donator)
    {
        for(int i = 0; i < donatorsList.size(); i++)
        {
            Donator current_donator = donatorsList[i];
            if(current_donator.isEqual(donator)) // na ftiajv isEqual ston Donator opos stin Entity
            {
                try{
                    throw "Donator Exists.";
                }catch(const char* e)
                {
                    cout << e << endl;
                }
            }
        }
        donatorsList.push_back(donator);
    }

    void removeDonator(Donator donator)
    {
        for(int i = 0; i < donatorsList.size(); i++)
        {
            Donator current_donator = donatorsList[i];
            if(current_donator.isEqual(donator)) // na ftiajv isEqual ston Donator opos stin Entity
            {
                donatorsList.erase(donatorsList.begin() + i);
            }
            else
            {
                try{
                    throw "The Donator you are trying to erase does not exist.";
                }catch(const char* e)
                {
                    cout << e << endl;
                }
                
            }
        }
    }

    //Beneficiary Methods
    void insertBeneficiary(Beneficiary beneficiary)
    {
        for(int i = 0; i < beneficiaryList.size(); i++)
        {
            Beneficiary current_beneficiary = beneficiaryList[i];
            if(current_beneficiary.isEqual(beneficiary)) // na ftiajv isEqual ston Beneficiary opos stin Entity
            {
                try{
                    throw "Beneficiary Exists.";
                }
                catch(const char* e)
                {
                    cout << e << endl;
                }
            }
        }
        beneficiaryList.push_back(beneficiary);
    }

    void removeBeneficiary(Beneficiary beneficiary)
    {
        for(int i = 0; i < beneficiaryList.size(); i++)//Σκανάρισμα
        {
            Beneficiary current_beneficiary = beneficiaryList[i];
            if(current_beneficiary.isEqual(beneficiary))//Έλεγχος  --  // na ftiajv isEqual ston Beneficiary opos stin Entity
            {
                beneficiaryList.erase(beneficiaryList.begin()+i);
            }
            else
            {
                try{
                    throw "The Beneficiary you are trying to erase does not exist.";
                }
                catch(const char* e)
                {
                    cout << e << endl;
                }
            }
        }
    }

    void listBeneficiaries() // Creates a counted list of the Beneficiaries and all their information
    {
        int count = 0;
        cout<<"Beneficiaries:";
        for(int i=0; i < beneficiaryList.size(); i++)
        {
            cout<<(++count+" "+ beneficiaryList[i].getName())<<endl;
            vector <RequestDonationList> rList = beneficiaryList[i].getReceivedList();
            vector <RequestDonation> mList;
            vector <RequestDonation> sList;
            for(int j=0; j < rList.size(); j++)
            {
                // rList.get(j) einai tupou RequestDonationList
                for(int k=0; k < rList[j].getrdEntities().size(); k++)
                {
                    vector <string> details;
                    tokenize(rList[j].getrdEntities()[k].getEntity()->getDetails(), ' ', details);
                    if (!(details[0].compare("Material")))
                    {
                        for(int l=0; l < mList.size(); l++)
                        {
                            if(!(rList[j].getrdEntities()[k].getEntity()->getName().compare(mList[l].getEntity()->getName())))
                            {
                                mList[l].setQuantity(rList[j].getrdEntities()[k].getQuantity() + mList[l].getQuantity());
                            }
                            else
                            {
                                mList.push_back(rList[j].getrdEntities()[k]);
                            }
                        }
                    }
                    else
                    {
                        bool flag = false;
                        for(int l=0; l < sList.size(); l++)
                        {
                            if(!(rList[j].getrdEntities()[k].getEntity()->getName().compare(sList[l].getEntity()->getName())))
                            {
                                flag = true;
                            }
                        }
                        if(flag == false)
                        {
                            sList.push_back(rList[j].getrdEntities()[k]);
                        }
                    }
                }
            }
            cout << "Material List:" << endl;
            for(int j=0; j < mList.size(); j++)
            {
                cout << (j+1) << ". " << currentDonations.getrdEntities()[j].getEntity()->getName() + " ( " << (mList[j].getQuantity()) << " )" << endl;
            }
            cout << "Services List:" << endl;
            for(int j=0; j < sList.size(); j++)
            {
                cout << (j+1) << ". " << currentDonations.getrdEntities()[j].getEntity()->getName() << endl;
            }
        }
        if(count == 0)
        {
            cout << "Beneficiaries list is empty." << endl;
        }
    }

    void listBeneficiary(Beneficiary b) // Used in Menu/Admin/MonitorOrganization/ListBeneficiaries - Prints specific Beneficiary's current received entities by their category
    {
        vector <RequestDonation> mList;
        vector <RequestDonation> sList;
        for(int i=0; i < beneficiaryList.size(); i++)
        {
            if(!(beneficiaryList[i].getPhone().compare(b.getPhone())))
            {
                vector <RequestDonationList> rList = beneficiaryList[i].getReceivedList();
                for(int j=0; j < rList.size(); j++)
                {
                    for(int k=0; k < rList[j].getrdEntities().size(); k++)
                    {
                        vector <string> details;
                        tokenize(rList[j].getrdEntities()[k].getEntity()->getDetails(), ' ', details);
                        if (!(details[0].compare("Material")))
                        {
                            for(int l=0; l < mList.size(); l++)
                            {
                                if(!(rList[j].getrdEntities()[k].getEntity()->getName().compare(mList[l].getEntity()->getName())))
                                {
                                    mList[l].setQuantity(rList[j].getrdEntities()[k].getQuantity() + mList[l].getQuantity());
                                }
                                else
                                {
                                    mList.push_back(rList[j].getrdEntities()[k]);
                                }
                            }
                        }
                        else
                        {
                            bool flag = false;
                            for(int l=0; l < sList.size(); l++)
                            {
                                if(!(rList[j].getrdEntities()[k].getEntity()->getName().compare(sList[l].getEntity()->getName())))
                                {
                                    flag = true;
                                }
                            }
                            if(flag == false)
                            {
                                sList.push_back(rList[j].getrdEntities()[k]);
                            }
                        }
                    }
                }
            }
        }
        cout << "Material List:" << endl;
        for(int i=0; i < mList.size(); i++)
        {
            cout << (i+1) << ". " << currentDonations.getrdEntities()[i].getEntity()->getName() << " ( " << (mList[i].getQuantity()) << " )" << endl;
        }
        if(mList.size() == 0)
        {
            cout << "Empty" << endl;
        }
        cout << "Services List:" << endl;
        for(int i=0; i < sList.size(); i++)
        {
            cout << (i+1) << ". " << currentDonations.getrdEntities()[i].getEntity()->getName() << endl;
        }
        if(sList.size() == 0)
        {
            cout << "Empty" << endl;
        }
    }

    vector <Beneficiary> &getBeneficiaryList() { return beneficiaryList; } // Returns BeneficiaryList

    vector <Donator> &getDonatorsList() {  return donatorsList; } // Returns DonatorsList

    //List Methods
    void listEntities() // Creates the listEntities in seporate categories (Material, Services)
    {
        cout << "Entities:" << endl;
        listMaterial();
        listServices();
    }

    vector <RequestDonation> listMaterial() // Creates counted list of Materials with their quantity
    {
        int count = 0;
        vector <RequestDonation> mList;
        cout << "Material List:" << endl;

        for(int i=0; i < currentDonations.getrdEntities().size(); i++)
        {
            vector <string> details;
            tokenize(currentDonations.getrdEntities()[i].getEntity()->getDetails(), ' ', details);
            if (!(details[0].compare("Material")))
            {
                mList.push_back(currentDonations.getrdEntities()[i]);
                cout << ++count << ". " << currentDonations.getrdEntities()[i].getEntity()->getName() << " (" << (currentDonations.getrdEntities()[i].getQuantity()) << ")" << endl; // make this with currentDonations
            }
        }
        if(count == 0)
        {
            cout << "Material list is empty." << endl;
        }
        return mList;
    }

    int listrdDonator(Donator d) // fix this - make Donators Request Donation List
    {
        int count = 0;
        for(int i=0; i < donatorsList.size(); i++)
        {
            if(!(donatorsList[i].getPhone().compare(d.getPhone())))
            {
                vector <Offers> oList = donatorsList[i].getOffersList();
                for(int j=0; j < oList.size(); j++)
                {
                    for(int k=0; k < oList[j].getrdEntities().size(); k++)
                    {
                        vector <string> details;
                        tokenize(oList[j].getrdEntities()[i].getEntity()->getDetails(), ' ', details);
                        if (!(details[0].compare("Material")))
                        {
                            cout << ++count << ". " << oList[j].getrdEntities()[k].getEntity()->getName() << " (" << oList[j].getrdEntities()[k].getQuantity() << ")" << endl;
                        }
                        else
                        {
                            cout << ++count << ". " << oList[j].getrdEntities()[k].getEntity()->getName() << endl;
                        }
                    }
                }
            }
        }
        return count;
    }

    int listrdBeneficiary(Beneficiary b)
    {
        int count = 0;
        for(int i=0; i < beneficiaryList.size(); i++)
        {
            if(!(beneficiaryList[i].getPhone().compare(b.getPhone())))
            {
                vector <Requests> rList = beneficiaryList[i].getRequestedList();
                for(int j=0; j < rList.size(); j++)
                {
                    for(int k=0; k < rList[j].getrdEntities().size(); k++)
                    {
                        vector <string> details;
                        tokenize(rList[j].getrdEntities()[i].getEntity()->getDetails(), ' ', details);
                        if (!(details[0].compare("Material")))
                        {
                            cout << ++count << ". " << rList[j].getrdEntities()[k].getEntity()->getName() << " (" << rList[j].getrdEntities()[k].getQuantity() << ")" << endl;
                        }
                        else
                        {
                            cout << ++count << ". " << rList[j].getrdEntities()[k].getEntity()->getName() << endl;                
                        }
                    }
                }
            }
        }
        return count;
    }

    vector <RequestDonation> listServices() // Creates counted list of Services
    {
        int count = 0;
        vector <RequestDonation> sList;
        cout << "Services List:" << endl;

        for(int i=0; i < currentDonations.getrdEntities().size(); i++)
        {
            vector <string> details;
            tokenize(currentDonations.getrdEntities()[i].getEntity()->getDetails(), ' ', details);
            if (!(details[0].compare("Service")))
            {
                sList.push_back(currentDonations.getrdEntities()[i]);
                cout << ++count << ". " << currentDonations.getrdEntities()[i].getEntity()->getName() << endl;
            }
        }
        if(count == 0)
        {
            cout << "Services list is empty." << endl;
        }
        return sList;
    }

    void listDonators(Donator d) // Creates a counted list of Donators
    {
        int count=0;
        vector <RequestDonation> mList;
        vector <RequestDonation> sList;
        vector <Offers> oList;
        for(int i=0; i < donatorsList.size(); i++)
        {
            if(!(donatorsList[i].getPhone().compare(d.getPhone())))
            oList = donatorsList[i].getOffersList();
            for(int j=0; j < oList.size(); j++)
            {
                for(int k=0; k < oList[j].getrdEntities().size(); k++)
                {
                    vector <string> details;
                    tokenize(oList[j].getrdEntities()[k].getEntity()->getDetails(), ' ', details);
                    if (!(details[0].compare("Material")))
                    {
                        for(int l=0; l < mList.size(); l++)
                        {
                            if(!(oList[j].getrdEntities()[k].getEntity()->getName().compare(mList[l].getEntity()->getName()))) // να εμφανισει την τρεχουσα κατασταση των παροχών που κανει offer gia Material
                            {
                                // ti kano gia to quantity pou tha prosferei
                                cout << ++count << ". " << mList[l].getEntity()->getName() << " (" << mList[l].getQuantity() << ") " << endl;
                            }
                        }
                    }
                    else
                    {
                        bool flag = false;
                        for(int l=0; l < sList.size(); l++)
                        {
                            if(!(oList[j].getrdEntities()[k].getEntity()->getName().compare(sList[l].getEntity()->getName()))) // an einai service kai yparxei να εμφανισει την τρεχουσα κατασταση των παροχών που κανει offer gia Service
                            {
                                flag = true;
                            }
                        }
                    }
                }
            }
        }
    }

    vector <Entity*> getEntityList() { return entityList; } // Returns entityList

    RequestDonationList &getCurrentDonations() { return currentDonations; } // Returns currentDonations
};
