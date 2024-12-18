 
import java.util.List;
public class Requests extends RequestDonationList 
{
    //Μέθοδοι
    // add: αφο�? ελέγξει τα α, β, καλεί την add της RequestDonationList
    public void add(Organization o, Beneficiary b, RequestDonation rd) throws Exception 
    {
        for (int i = 0; i < getrdEntities().size(); i++) // π�?οσπέλαση του μεγέθους της λίστας rdEntities
        {
            RequestDonation current_rd = getrdEntities().get(i); // ονομασία της συγκεκ�?ιμένης RequestDonation της λίστας rdEntities
            if (current_rd.getQuantity() >= rd.getQuantity()) // αν το Quantity της rd υπά�?χει στον ο�?γανισμό (rd <= current_rd)
            {
                if (validRequestDonation(o, b, rd) == true) // αν ο Beneficiary δικαιο�?ται την ποσότητα
                {
                    super.add(o, rd); // καλείται η add της RequestDonationList
                } 
                else 
                {
                    throw new Exception("Benefiaciary is Invalid."); // εξαί�?εση του β
                }
                break;
            } 
            else 
            {
                throw new Exception("Entity is Unavailiable."); // εξαί�?εση του α
            }
        }
        if(getrdEntities().size() == 0) // αν οι rdEntities λίστα είναι άδεια, να π�?οστεθεί η RequestDonation σε αυτήν
        {
            rdEntities.add(rd);
        }
    }

    // λειτου�?γεί όπως η add, αλλά για την modify
    public void modify(Organization o, RequestDonation rd, Beneficiary b, double newQuantity) throws Exception 
    {
        for (int i = 0; i < getrdEntities().size(); i++) 
        {
            RequestDonation current_rd = getrdEntities().get(i);
            if (current_rd.getQuantity() >= rd.getQuantity()) 
            {
                if (validRequestDonation(o, b, rd) == true) 
                {
                    super.modify(rd, newQuantity);
                } 
                else 
                {
                    throw new Exception("Benefiaciary is Invalid.");
                }
                break;
            } 
            else 
            {
                throw new Exception("Entity is Unavailiable.");
            }
        }
    }

    // validRequestDonation: ελέγχει αν ο Beneficiary δικαιο�?ται, σ�?μφωνα με τον α�?ιθμό μελών στην οικογένειά του, την ποσότητα που ζητά
    public boolean validRequestDonation(Organization o, Beneficiary b, RequestDonation rd) 
    {
        double allowedQuantity, requestedQuantity;
        String[] details = (rd.getEntity().getDetails()).split(" ");
        if (details[0].equals("Service")) 
        {
            List<Entity> eList = o.getEntityList(); // δημιου�?γία λίστας eList από Entity στην οποία εισάγουμε την EntityList της Organization
            for (int i = 0; i < eList.size(); i++) // π�?οσπέλαση του μεγέθους της λίστας eList
            {
                if (eList.get(i).getEntityInfo().equals(rd.getEntity().getEntityInfo())) // αν τα EntityInfo των eList και των Entity της rd είναι κοινά
                {
                    return true; // δεν χ�?ειάζεται να ελέγξει αν ο Beneficiary την δικαιο�?ται, αφο�? η Service δεν έχει ποσότητα
                }
            }
        }
        if (b.getnoPersons() == 1) // αν ο Beneficiary ανήκει στο level1
        {
            allowedQuantity = Double.parseDouble(details[1]); // θέση της ποσότητας που ζήτησε ο Beneficiary στην allowedQuantity, Double.parseDouble(details[1]) -> μετατ�?οπή του String πε�?ιεχομένου του πίνακα details σε double
        } 
        else if ((b.getnoPersons() > 1) && (b.getnoPersons() < 5))  // αν ο Beneficiary ανήκει στο level2
        {
            allowedQuantity = Double.parseDouble(details[2]); // θέση της ποσότητας που ζήτησε ο Beneficiary στην allowedQuantity
        } 
        else  // αν ο Beneficiary ανήκει στο level3
        {
            allowedQuantity = Double.parseDouble(details[3]);  // θέση της ποσότητας που ζήτησε ο Beneficiary στην allowedQuantity
        }
        requestedQuantity = rd.getQuantity(); // θέση της requestedQuantity ίση με το Quantity της rd
        System.out.println("\nAllowed Quantity = " + allowedQuantity);
        System.out.println("Requested Quantity = " + requestedQuantity + "\n");
        if (requestedQuantity > allowedQuantity) // αν ζητήσει ο Beneficiary πε�?ισσότε�?α από όσα μπο�?εί να πά�?ει να επιστ�?έψει η validRequestDonation false, αλλιώς true
        {
            return false;
        } 
        else 
        {
            return true;
        }
    }

    // ελέγχει εκ νέου επειδή ο Beneficiary, μπο�?εί να κάνει δυο Requests και να του επιτ�?έπεται να πά�?ει το π�?ώτο, αλλά να μην μπο�?εί πλέον με τις αλλαγές στην ποσότητα, να μπο�?εί να πά�?ει το δε�?τε�?ο
    // ουσιαστικά η commit κάνει save τα Requests που ζητά και μπο�?εί να πά�?ει και τα διαγ�?άφει από την λίστα με RequestDonations
    public void commit(Organization o, Beneficiary b) throws Exception
    {
        boolean flag = false;
        for (int i = 0; i < getrdEntities().size(); i++)
        {
            RequestDonation current_rd = getrdEntities().get(i);
            String[] current_details = (current_rd.getEntity().getDetails()).split(" ");
            for(int j=0; j < o.getCurrentDonations().getrdEntities().size(); j++) // π�?οσπέλαση του μεγέθους της λίστας rdEntities του συγκεκ�?ιμένου CurrentDonations, τ�?που RequestDonationList
            {
                RequestDonation o_rd = o.getCurrentDonations().getrdEntities().get(j);
                //String[] details = (o_rd.getEntity().getDetails()).split(" ");
                if(current_rd.getEntity().getEntityInfo().equals(o_rd.getEntity().getEntityInfo()))
                {
                    if (current_details[0].equals("Service")) // αν είναι Service
                    {
                        flag = true;
                        System.out.println(current_rd.getEntity().getName()); // να εκτυπωθεί το όνομα του Entity του current_rd, δηλαδή του συγκεκ�?ιμένου RequestDonation της getrdEntities()
                        break;
                    }
                    if (current_details[0].equals("Material")) // αν είναι Material
                    {
                        if (current_rd.getQuantity() <= o_rd.getQuantity()) // αν ισχ�?ουν οι α, β έλεγχοι
                        {
                            if(validRequestDonation(o, b, current_rd) == true)
                            {
                                double nq = o_rd.getQuantity() - current_rd.getQuantity(); // αφαί�?εση της current_rd ποσότητας από την o_rd ποσότητα
                                o.getCurrentDonations().modify(o_rd, nq); // κλήση της modify της RequestDonationList μέσω της getCurrentDonations() του ο�?γανισμο�?
                                getrdEntities().remove(current_rd); // αφαί�?εση της current_rd από την rdEntities λίστα
                            }
                            else 
                            {
                                throw new Exception("Benefiaciary is Invalid."); // εξαί�?εση του β
                            }
                            flag = true;
                            break;
                        } 
                        else 
                        {
                            throw new Exception("Entity is Unavailiable."); // εξαί�?εση του α
                        }
                    }
                }
            }    
        }
    }
}