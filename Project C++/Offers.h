#pragma once
#include"RequestDonationList.h"

class Offers: public RequestDonationList
{
    // Μέθοδοι
    // κάνει save τις προσφορές της rdEntities στο αντικείμενο CurrentDonations, τύπου RequestDonationList
    public:
    void commit(RequestDonationList &CurrentDonations)
    {
        for (int i = 0; i < getrdEntities().size(); i++)
        {
            bool flag = false;
            RequestDonation current_rd = getrdEntities()[i];
            for (int j = 0; j < CurrentDonations.getrdEntities().size(); j++)
            {
                RequestDonation current_cd = CurrentDonations.getrdEntities()[j];
                vector <string> details_cd;
                tokenize(current_cd.getEntity()->getDetails(), ' ', details_cd);
                if(!(current_rd.getEntity()->getEntityInfo().compare(current_cd.getEntity()->getEntityInfo())))
                {
                    if (!(details_cd[0].compare("Service")))
                    {
                        getrdEntities().erase(getrdEntities().begin() + i--); // μικραίνουμε την λίστα rdEntites (out of bounds error), αφαιρούμε το Entity Service του current_cd
                        flag = true;
                        break;
                    }  
                    else // αν είναι Material, του δίνουμε νέα ποσότητα, το άθροισμα της υπάρχουσας ποσότητας του οργανισμού με την ποσότητα της RequestDonation της rdEntities λίστας που εξετάζω
                    {
                        double nq = current_cd.getQuantity() + current_rd.getQuantity();
                        CurrentDonations.modify(current_cd, nq);
                        getrdEntities().erase(getrdEntities().begin() + i--); // μικραίνουμε την λίστα rdEntites (out of bounds error), αφαιρούμε το Entity Material του current_cd
                        flag = true;
                        break;
                    }
                }
            }
            if(flag == false)
            {   
                CurrentDonations.getrdEntities().push_back(getrdEntities()[i]); // αν δεν υπάρχει εκεί ήδη, κάνει add το entity στην currentDonations
            }
        }
    }
};
