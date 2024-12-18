#pragma once
#include"RequestDonationList.h"
#include"Beneficiary.h"

class Organization;

class Requests: public RequestDonationList
{
    //Μέθοδοι
    public:
    void add(vector <Entity*> entity_list, Beneficiary b, RequestDonation rd)
    {
        for (int i = 0; i < getrdEntities().size(); i++)
        {
            RequestDonation current_rd = getrdEntities()[i];
            if (current_rd.getQuantity() >= rd.getQuantity())
            {
                if (validRequestDonation(entity_list, b, rd) == 1) 
                {
                    RequestDonationList::add(entity_list, rd);
                } 
                else
                {

                    try{
                        throw "Benefiaciary is Invalid.";
                    }catch(const char* e)
                    {
                        cout << e << endl;
                    }
                }
                break;
            } else
            {
                try{
                    throw "Entity is Unavailiable.";
                }catch(const char* e)
                {
                    cout << e << endl;
                }
            }
        }
        if(getrdEntities().size() == 0)
        {
            rdEntities.push_back(rd);
        }

    }

    void modify(vector <Entity*> entity_list, RequestDonation rd, Beneficiary b, double newQuantity)
    {
        bool flag = false;
        for (int i = 0; i < getrdEntities().size(); i++)
        {
            RequestDonation current_rd = getrdEntities()[i];
            if (current_rd.getQuantity() >= rd.getQuantity())
            {
                if (validRequestDonation(entity_list, b, rd) == true)
                {
                    RequestDonationList::modify(rd, newQuantity);
                }
                else
                {
                    try{
                        throw "Benefiaciary is Invalid.";
                    }catch(const char* e)
                    {
                        cout << e << endl;
                    }
                    
                }
                flag = true;
                break;
            } 
            else 
            {
                try{
                    throw "Entity is Unavailiable.";
                }catch(const char* e)
                {
                    cout << e << endl;
                }
                
            }
        }
    }

    bool validRequestDonation(vector <Entity*> entity_list, Beneficiary b, RequestDonation rd)
    {
        double allowedQuantity, requestedQuantity;
        vector <string> details;
        tokenize(rd.getEntity()->getDetails(), ' ', details);

        if (!(details[0].compare("Service")))
        {
            for (int i = 0; i < entity_list.size(); i++)
            {
                if (!(entity_list[i]->getEntityInfo().compare(rd.getEntity()->getEntityInfo())))
                {
                    return true;
                }
            }
        }
        if (b.getnoPersons() == 1)
        {
            allowedQuantity = stod(details[1]); // to double metatrepei to details[0] se double
        }
        else if ((b.getnoPersons() > 1) && (b.getnoPersons() < 5))
        {
            allowedQuantity = stod(details[2]);
        }
        else
        {
            allowedQuantity = stod(details[3]);
        }
        requestedQuantity = rd.getQuantity();
        cout << "\nAllowed Quantity = " << allowedQuantity << endl;
        cout << "Requested Quantity = " << requestedQuantity << endl;
        if (requestedQuantity > allowedQuantity)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    void commit(RequestDonationList &CurrentDonations, vector <Entity*> entityList, Beneficiary b) //o->getCurrentDonations()
    {
        for (int i = 0; i < getrdEntities().size(); i++)
        {
            RequestDonation current_rd = getrdEntities()[i];
            for(int j=0; j < CurrentDonations.getrdEntities().size(); j++)
            {
                RequestDonation o_rd = CurrentDonations.getrdEntities()[j];
                vector <string> details;
                tokenize(o_rd.getEntity()->getDetails(), ' ', details);
                if(!(current_rd.getEntity()->getEntityInfo().compare(o_rd.getEntity()->getEntityInfo())))
                {
                    if (!(details[0].compare("Service")))
                    {
                        getrdEntities().erase(getrdEntities().begin() + i--); // μικραίνουμε την λίστα rdEntites (out of bounds error), αφαιρούμε το Entity Service του current_rd
                        cout << current_rd.getEntity()->getName() << endl << endl;
                        break;
                    }
                    else
                    {
                        if (current_rd.getQuantity() <= o_rd.getQuantity())
                        {
                            if(validRequestDonation(entityList, b, current_rd) == true)
                            {
                                cout << current_rd.getQuantity() << endl;
                                double nq = o_rd.getQuantity() - current_rd.getQuantity();
                                CurrentDonations.modify(o_rd, nq);
                                getrdEntities().erase(getrdEntities().begin() + i--); // μικραίνουμε την λίστα rdEntites (out of bounds error), αφαιρούμε το Entity Material του current_cd
                                cout << current_rd.getEntity()->getName() << endl << endl;
                                break;
                                // vector<RequestDonation> rdEntities = getrdEntities();
                                // // getrdEntities().remove(current_rd);
                                // remove(current_rd);

                            }
                            else
                            {
                                try{
                                    throw "Benefiaciary is Invalid.";
                                }catch(const char* e)
                                {
                                    cout << e << endl;
                                }
                                
                            }
                            break;
                        }
                        else
                        {
                            try{
                                throw "Entity is Unavailiable.";
                            }catch(const char* e)
                            {
                                cout << e << endl;
                            }
                            
                        }
                    }
                }
            }
        }
    }
};
