#pragma once
#include"RequestDonation.h"
#include<vector>
#include"tokenize.h"
#include <iostream>

class RequestDonationList
{
    // Πεδία
    protected:
    vector <RequestDonation> rdEntities;

    //Μέθοδοι
    public:
    RequestDonation &get(int id) { return rdEntities[id]; }

    vector <RequestDonation> &getrdEntities() { return rdEntities; }

    virtual void add(vector <Entity*> entity_list, RequestDonation rd) 
    {
       bool flag=false;
       for(int i=0; i < rdEntities.size(); i++) // προσπέλαση της λίστας
       {
           RequestDonation current_rd = rdEntities[i];
           vector <string> details;
           tokenize(rd.getEntity()->getDetails(), ' ', details);
           if(!(current_rd.getEntity()->getEntityInfo().compare(rd.getEntity()->getEntityInfo()))) // έλεγχος
           {
               if (!(details[0].compare("Material")))
               {
                    current_rd.setQuantity(current_rd.getQuantity()+rd.getQuantity()); // αλλαγή ποσότητας
                    rdEntities[i].setQuantity(current_rd.getQuantity());

                    flag = true;
                    break;
                }
            }
        }
       if(flag == false)
       {
           rdEntities.push_back(rd);
           return;
        }

       flag = false;
       for(int i=0; i < entity_list.size(); i++)
       {
           if(!(rdEntities[i].getEntity()->getEntityInfo().compare(rd.getEntity()->getEntityInfo())))
           {
               flag = true;
               break;
           }
       }
       if(flag == false)
        {
            try{
                throw "None_Existent_Entity";
            }catch(const char* e)
            {
                cout << e << endl;
            }
           
        }
    }

    virtual void remove(RequestDonation rd)
    {

        for(int i=0; i < rdEntities.size(); i++)
        {
            RequestDonation current_rd = rdEntities[i];
            vector <string> details;
            tokenize(rd.getEntity()->getDetails(), ' ', details);
            if(!(rdEntities[i].getEntity()->getEntityInfo().compare(rd.getEntity()->getEntityInfo())))
            {
                if (!(details[0].compare("Material")))
                {
                    current_rd.setQuantity(current_rd.getQuantity()-rd.getQuantity()); // αλλαγή ποσότητας
                    rdEntities[i].setQuantity(current_rd.getQuantity());
                    break;
                }
                break;
            }
        }
    }

    virtual void modify(RequestDonation rd, double newQuantity)
    {
        for(int i=0; i < getrdEntities().size(); i++)
        {
            RequestDonation current_rd = getrdEntities()[i];
            vector <string> details;
            tokenize(rd.getEntity()->getDetails(), ' ', details);
            if(!(current_rd.getEntity()->getEntityInfo().compare(rd.getEntity()->getEntityInfo())))
            {
                if (!(details[0].compare("Material")))
                {
                    current_rd.setQuantity(newQuantity);
                    break;
                }
            }
        }
    }

    void monitor()
    {
        for(int i=0; i < rdEntities.size(); i++)
       {
           cout << rdEntities[i].getEntity()->toString() << endl;
       }
    }

    void reset() { rdEntities.clear(); }

    void setQuantity(int i, RequestDonation rd) {  rdEntities[i] = rd;  }
};
