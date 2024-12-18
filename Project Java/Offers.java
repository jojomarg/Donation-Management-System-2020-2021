 
public class Offers extends RequestDonationList
{
    // Μέθοδοι
    // κάνει save τις π�?οσφο�?ές της rdEntities στο αντικείμενο CurrentDonations, τ�?που RequestDonationList
    public void commit(Organization o) throws Exception
    {
        for (int i = 0; i < getrdEntities().size(); i++)
        {
            boolean flag = false;
            RequestDonation current_rd = getrdEntities().get(i);
            for (int j = 0; j < o.getCurrentDonations().getrdEntities().size(); j++)
            {
                RequestDonation current_cd = o.getCurrentDonations().getrdEntities().get(j);
                String[] details_cd = (current_cd.getEntity().getDetails()).split(" ");
                if(current_rd.getEntity().getEntityInfo().equals(current_cd.getEntity().getEntityInfo()))
                {
                    if (details_cd[0].equals("Service"))
                    {
                        getrdEntities().remove(i--);    // μικ�?αίνουμε την λίστα rdEntites (out of bounds error), αφαι�?ο�?με το Entity Service του current_cd
                        flag = true;
                        break;
                    }  
                    else // αν είναι Material, του δίνουμε νέα ποσότητα, το άθ�?οισμα της υπά�?χουσας ποσότητας του ο�?γανισμο�? με την ποσότητα της RequestDonation της rdEntities λίστας που εξετάζω
                    {
                        double nq = current_cd.getQuantity() + current_rd.getQuantity();
                        super.modify(current_cd, nq);
                        getrdEntities().remove(i--); // μικ�?αίνουμε την λίστα rdEntites (out of bounds error), αφαι�?ο�?με το Entity Material του current_cd
                        flag = true;
                        break;
                    }
                }
            }
            if(flag == false)
            {   
                o.getCurrentDonations().getrdEntities().add(getrdEntities().get(i)); // αν δεν υπά�?χει εκεί ήδη, κάνει add το entity στην currentDonations
            }
        }
    }
}