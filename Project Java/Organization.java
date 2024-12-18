 
import java.util.ArrayList;
public class Organization
{
// Πεδία
    private String name;
    private Admin admin;
    private RequestDonationList currentDonations = new RequestDonationList(); 
    private ArrayList <Entity> entityList = new ArrayList <Entity>();
    private ArrayList <Donator> donatorsList = new ArrayList <Donator>();
    private ArrayList <Beneficiary> beneficiaryList = new ArrayList <Beneficiary>();

// Μέθοδοι
    // Organization Methods
    public Organization (String n, ArrayList <Entity> e) // Organization's Constractor - Α�?χικοποιεί το όνομα του ο�?γανισμο�? και την entityList του, διλαδή της δίνει ένα entity
    {
        name = n;
        entityList = e;
    }

    public String getName() // Επιστ�?έφει το όνομα του ο�?γανισμο�?
    {
        return name;
    }

    public void setTestCurrentDonations(Offers o) // Αρχικοποιεί την currentDonations
    {
        currentDonations = o;
    }
    
    //Admin Methods
    public void setAdmin(Admin a) // Δημιου�?γεί Admin User
    {
        admin = a;   
    }
    
    public Admin getAdmin() // Επιστ�?έφει Admin User
    {
        return admin;
    }

    // Entity Methods
    public void addEntity(Entity entity) throws Exception 
    {
        for(int i = 0; i < entityList.size(); i++)
        {
            Entity current_Entity = entityList.get(i);
            if(current_Entity == entity) // Ελέγχει αν το entity υπά�?χει στην entityList
            {
                throw new Exception("Entity Exists");
            }
        }
        entityList.add(entity); // Π�?οσθέτει το entity στην entityList
    }      
    
    public void removeEntity(Entity entity, boolean isAdmin) throws Exception
    {
        for(int i = 0; i < entityList.size(); i++)
        {
            Entity current_Entity = entityList.get(i);
            if(isAdmin == true) // Ελέγχει αν ο χ�?ήστης είναι Admin
            {
                if(current_Entity == entity)  // Ελέγχει αν το entity υπά�?χει στην entityList
                {
                   entityList.remove(entity); // Αφαι�?εί το entity από την entityList
                }
                else
                {
                    throw new Exception("The Entity you are trying to erase does not exist.");
                }
            }
            else
            {
                throw new Exception("You are not an Admin.");
            }
        }  
    }
    
    //Donator Methods
    public void insertDonator(Donator donator) throws Exception
    {
        for(int i = 0; i < donatorsList.size(); i++)
        {
            Donator current_donator = donatorsList.get(i);
            if(current_donator == donator) // Ελέγχει αν ο donator υπά�?χει στην donatorsList
            {
                throw new Exception("Donator Exists.");
            }
        }
        donatorsList.add(donator); // Π�?οσθέτει τον donator στην donatorsList
    }
    
    public void removeDonator(Donator donator) throws Exception
    {
        for(int i = 0; i < donatorsList.size(); i++)
        {
            Donator current_donator = donatorsList.get(i);
            if(current_donator == donator) // Ελέγχει αν ο donator υπά�?χει στην donatorsList
            {
                donatorsList.remove(donator); // Αφαι�?εί τον donator από την donatorsList
                return;
            }
        } 
        throw new Exception("The Donator you are trying to erase does not exist.");  
    }
    
    public ArrayList <Donator> getDonatorsList() // Επιστ�?έφει DonatorsList
    {
        return donatorsList;
    }

    //Beneficiary Methods
    public void insertBeneficiary(Beneficiary beneficiary) throws Exception
    {
        for(int i = 0; i < beneficiaryList.size(); i++)
        {
            Beneficiary current_beneficiary = beneficiaryList.get(i);
            if(current_beneficiary == beneficiary) // Ελέγχει αν ο beneficiary υπά�?χει στην beneficiary
            {
                throw new Exception("Beneficiary Exists.");
            }
        }  
        beneficiaryList.add(beneficiary);  // Π�?οσθέτει τον beneficiary στην beneficiaryList
    } 
    
    public void removeBeneficiary(Beneficiary beneficiary) throws Exception
    {
        for(int i = 0; i < beneficiaryList.size(); i++)
        {
            Beneficiary current_beneficiary = beneficiaryList.get(i);
            if(current_beneficiary == beneficiary) // Ελέγχει αν ο beneficiary υπά�?χει στην beneficiary
            {
                beneficiaryList.remove(beneficiary); // Αφαι�?εί τον beneficiary από την beneficiaryList
                return;
            }
        }  
        throw new Exception("The Beneficiary you are trying to erase does not exist.");   
    }
    
    public void listBeneficiaries() // Δημιου�?γία α�?ιθμημένης λίστας των Beneficiaries με τις πλη�?οφο�?ίες τους
    {
        int count = 0;
        System.out.println("Beneficiaries:");
        for(int i=0; i < beneficiaryList.size(); i++) // Εκτυπώνονται α�?ιθμημένοι οι Beneficiaries
        {
            System.out.println(++count+" "+ beneficiaryList.get(i).getName());
            ArrayList <RequestDonationList> rList = beneficiaryList.get(i).getReceivedList(); // Δημιου�?γία λίστας των πα�?αλαυμένων RequestDonation, τ�?που RequestDonationList
            ArrayList <RequestDonation> mList = new ArrayList<RequestDonation>(); // Δημιου�?γία λίστας Material
            ArrayList <RequestDonation> sList = new ArrayList<RequestDonation>(); // Δημιου�?γία λίστας Service
            for(int j=0; j < rList.size(); j++)
            {
                for(int k=0; k < rList.get(j).getrdEntities().size(); k++) // Π�?οσπέλαση της rdEntities λίστας του j της rList
                {
                    String[] details = rList.get(j).getrdEntities().get(k).getEntity().getDetails().split(" ");
                    if (details[0].equals("Material")) // Αν το k rdEntities του j της rList είναι Material
                    {
                        for(int l=0; l < mList.size(); l++)
                        {
                            if(rList.get(j).getrdEntities().get(k).getEntity().getName().equals(mList.get(l).getEntity().getName())) // Αν το όνομα του l της mList είναι ίδιο με αυτό του Entity του k της rdEntities του j της rdEntities λίστας 
                            {
                                mList.get(l).setQuantity(rList.get(j).getrdEntities().get(k).getQuantity() + mList.get(l).getQuantity()); // �?α αλλάξει η ποσότητα του l της mList
                            }
                            else // Αλλιώς να π�?οστεθεί στην λίστα mList το k RequestDonation
                            {
                                mList.add(rList.get(j).getrdEntities().get(k));
                            }
                        }
                    }
                    else // Για τα Services -- Πα�?όμοια διαδικασία
                    {
                        boolean flag = false;
                        for(int l=0; l < sList.size(); l++)
                        {
                            if(rList.get(j).getrdEntities().get(k).getEntity().getName().equals(sList.get(l).getEntity().getName()))
                            {
                                flag = true;
                            }
                        }
                        if(flag == false)
                        {
                            sList.add(rList.get(j).getrdEntities().get(k));
                        }
                    }
                }
            }
            System.out.println("Material List:"); // Εκτ�?πωση της Material List στην απα�?αίτητη μο�?φή
            for(int j=0; j < mList.size(); j++)
            {
                System.out.println((j+1)+". "+ currentDonations.getrdEntities().get(j).getEntity().getName() + " ( " + (mList.get(j).getQuantity()) + " )");
            }
            System.out.println("Services List:"); // Εκτ�?πωση της Services List στην απα�?αίτητη μο�?φή
            for(int j=0; j < sList.size(); j++)
            {
                System.out.println((j+1)+". "+ currentDonations.getrdEntities().get(j).getEntity().getName());
            }
        }
        if(count == 0) // Αν η Beneficiaries λίστα είναι άδεια
        {
            System.out.println("Beneficiaries list is empty.");
        }
    }

    public void listDonators(Donator d) // Χ�?ησιμοποιείται στην Menu/Admin/MonitorOrganization/ListDonators - Εκτυπώνει συγκεκ�?ιμένου Donator τα entities που έχει πα�?αλάβει ανά κατηγο�?ία
    {
        
        int count=0;
        ArrayList <RequestDonation> mList = new ArrayList <RequestDonation> (); // Δημιου�?γία της Material λίστας
        ArrayList <RequestDonation> sList = new ArrayList <RequestDonation> (); // Δημιου�?γία της Services λίστα
        for(int i=0; i < donatorsList.size(); i++)
        {
            if(donatorsList.get(i).getPhone().equals(d.getPhone())) // Έλεγχος του Donator
            {
                ArrayList <Offers> oList = new ArrayList <Offers> (); // Δημιου�?γία λίστας Offers του Donator
                oList = donatorsList.get(i).getOffersList(); // Θέση της oList ίση με την OffersList του συγκεκ�?ιμένου i Donator
                for(int j=0; j < oList.size(); j++)
                {
                    for(int k=0; k < oList.get(j).getrdEntities().size(); k++)
                    {
                        String[] details = oList.get(j).getrdEntities().get(k).getEntity().getDetails().split(" ");
                        if (details[0].equals("Material")) // Αν είναι Material
                        {
                            for(int l=0; l < mList.size(); l++)
                            {
                                if(oList.get(j).getrdEntities().get(k).getEntity().getName().equals(mList.get(l).getEntity().getName())) // να εμφανισει την τ�?εχουσα κατασταση των πα�?οχών που κανει offer για Material
                                {
                                    System.out.println(++count+". "+ mList.get(l) + " (" + mList.get(l).getQuantity() + ") ");
                                }
                            }
                        }
                        else // Αν είναι service
                        {
                            boolean flag = false;
                            for(int l=0; l < sList.size(); l++)
                            {
                                if(oList.get(j).getrdEntities().get(k).getEntity().getName().equals(sList.get(l).getEntity().getName())) // Αν είναι service και υπά�?χει, να εμφανισει την τ�?εχουσα κατασταση των πα�?οχών που κανει offer για Service
                                {
                                    flag = true;
                                    System.out.println(++count+". "+ sList.get(l) + " (" + sList.get(l).getQuantity() + ") ");
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    public void listBeneficiary(Beneficiary b) // Χ�?ησιμοποιείται στην Menu/Admin/MonitorOrganization/ListBeneficiaries - Εκτυπώνει συγκεκ�?ιμένου Beneficiary τα entities που έχει πα�?αλάβει ανά κατηγο�?ία
    {
        ArrayList <RequestDonation> mList = new ArrayList <RequestDonation>();
        ArrayList <RequestDonation> sList = new ArrayList <RequestDonation>();
        for(int i=0; i < beneficiaryList.size(); i++)
        {
            if(beneficiaryList.get(i).getPhone().equals(b.getPhone()))
            {
                ArrayList <RequestDonationList> rList = beneficiaryList.get(i).getReceivedList();
                for(int j=0; j < rList.size(); j++)
                {
                    for(int k=0; k < rList.get(j).getrdEntities().size(); k++)
                    {
                        String[] details = rList.get(j).getrdEntities().get(k).getEntity().getDetails().split(" ");
                        if (details[0].equals("Material")) // Για Material
                        {
                            for(int l=0; l < mList.size(); l++)
                            {
                                if(rList.get(j).getrdEntities().get(k).getEntity().getName().equals(mList.get(l).getEntity().getName())) // Αν το όνομα της Entity του l Material της mList είναι ίδιο με αυτό της rList
                                {
                                    mList.get(l).setQuantity(rList.get(j).getrdEntities().get(k).getQuantity() + mList.get(l).getQuantity()); // Θέτεται στην ποσότητα της mList = η ποσότητα rList + η ποσότητα mList
                                }
                                else // Αν δεν είναι το ίδιο
                                {
                                    mList.add(rList.get(j).getrdEntities().get(k)); // Π�?οστίθεται η RequestDonation της rdEntities στην mList
                                }
                            }
                        }
                        else // Για Service
                        {
                            boolean flag = false;
                            for(int l=0; l < sList.size(); l++)
                            {
                                if(rList.get(j).getrdEntities().get(k).getEntity().getName().equals(sList.get(l).getEntity().getName())) // Αν είναι το ίδιο δεν γίνεται τίποτα, αφο�? δεν έχει quantity να επη�?εαστεί 
                                {
                                    flag = true;
                                }
                            }
                            if(flag == false) // Αν δεν υπά�?χει
                            {
                                sList.add(rList.get(j).getrdEntities().get(k)); // Π�?οστίθεται η RequestDonation της rdEntities στην sList
                            }
                        }
                    }
                }
            }
        }
        System.out.println("Material List:"); // Εκτυπώνεται η Material List
        for(int i=0; i < mList.size(); i++)
        {
            System.out.println((i+1)+". "+ currentDonations.getrdEntities().get(i).getEntity().getName() + " ( " + (mList.get(i).getQuantity()) + " )");
        }
        if(mList.size() == 0) // Αν είναι άδεια
        {
            System.out.println("Empty");
        }
        System.out.println("Services List:"); // Εκτυπώνεται η Services List
        for(int i=0; i < sList.size(); i++)
        {
            System.out.println((i+1)+". "+ currentDonations.getrdEntities().get(i).getEntity().getName());
        }
        if(sList.size() == 0) // Αν είναι άδεια
        {
            System.out.println("Empty");
        }
    }

    public ArrayList <Beneficiary> getBeneficiaryList() // Επιστ�?έφει BeneficiaryList
    {
        return beneficiaryList;
    }

    public void listEntities() // Δημιου�?γία της λίστας listEntities κατά κατηγο�?ία (Material, Services)
    {
        System.out.println("Entities:");
        listMaterial();
        listServices();
    }

    public ArrayList <RequestDonation> listMaterial() // Δημιου�?γία της α�?ιθμημένης λίστας Materials με την ποσότητά τους
    {
        int count = 0;
        ArrayList <RequestDonation> mList = new ArrayList<RequestDonation>();
        System.out.println("Material List:");
        
        for(int i=0; i < currentDonations.getrdEntities().size(); i++) // π�?οσπέλαση του μεγέθους της λίστας rdEntities της currentDonations
        {
            String[] details = currentDonations.getrdEntities().get(i).getEntity().getDetails().split(" ");
            if (details[0].equals("Material"))
            {
                mList.add(currentDonations.getrdEntities().get(i)); // π�?οσθέτει το i RequestDonation της rdEntities λίστας της currentDonations στην mList
                System.out.println(++count+". "+ currentDonations.getrdEntities().get(i).getEntity().getName() + " (" + (currentDonations.getrdEntities().get(i).getQuantity()) + ")"); // εκτυπώνει την mList στην μο�?φή που επιθυμείται
            }
        }
        if(count == 0) // Αν η λίστα είναι άδεια 
        {
            System.out.println("Material list is empty.");
        }
        return mList;
    }

    public ArrayList <RequestDonation> listServices() // Δημιου�?γία της α�?ιθμημένης λίστας Services -- Είναι Πα�?όμοια με την listMaterial εκτός της ποσότητας
    {
        int count = 0;
        ArrayList <RequestDonation> sList = new ArrayList<RequestDonation>();
        System.out.println("Services List:");
        for(int i=0; i < currentDonations.getrdEntities().size(); i++)
        {
            String[] details = currentDonations.getrdEntities().get(i).getEntity().getDetails().split(" ");
            if (details[0].equals("Service"))
            {
                sList.add(currentDonations.getrdEntities().get(i));
                System.out.println(++count+". "+ currentDonations.getrdEntities().get(i).getEntity().getName());
            }
        }
        if(count == 0)
        {
            System.out.println("Services list is empty.");
        }
        return sList;
    }
    
    public int listrdDonator(Donator d) // Δημιου�?γία της α�?ιθμημένης λίστας RequestDonation με την ποσότητά τους συγκεκ�?ιμένου Donator
    {
        int count = 0;
        for(int i=0; i < donatorsList.size(); i++)
        {
            if(donatorsList.get(i).getPhone().equals(d.getPhone())) // Έλεγχος Donator
            {
                ArrayList <Offers> oList = donatorsList.get(i).getOffersList();
                for(int j=0; j < oList.size(); j++) // Π�?οσπέλαση OffersList του συγκεκ�?ιμένου Donator της donatorsList
                {
                    for(int k=0; k < oList.get(j).getrdEntities().size(); k++) // Π�?οσπέλαση rdEntities του j της OffersList του συγκεκ�?ιμένου Donator της donatorsList
                    {
                        String[] details = oList.get(j).getrdEntities().get(k).getEntity().getDetails().split(" "); // Σπάσιμο των Details του k entity
                        if (details[0].equals("Material")) // αν είναι Material
                        {
                            System.out.println(++count+". "+ oList.get(j).getrdEntities().get(k).getEntity().getName() + " (" + oList.get(j).getrdEntities().get(k).getQuantity() + ")"); // εκτυπώνει α�?ιθμημένα τα Material με την ποσότητά τους
                        }
                        else // αν είναι Service
                        {
                            System.out.println(++count+". "+ oList.get(j).getrdEntities().get(k).getEntity().getName()); // εκτυπώνει α�?ιθμημένα τα Services
                        }
                    }
                }
            }
        }
        return count;
    }

    public int listrdBeneficiary(Beneficiary b) // Δημιου�?γία της α�?ιθμημένης λίστας RequestDonation με την ποσότητά τους συγκεκ�?ιμένου Beneficiary -- Πα�?όμοια με την listrdDonator
    {
        int count = 0;
        for(int i=0; i < beneficiaryList.size(); i++)
        {
            if(beneficiaryList.get(i).getPhone().equals(b.getPhone()))
            {
                ArrayList <Requests> rList = beneficiaryList.get(i).getRequestedList();
                for(int j=0; j < rList.size(); j++)
                {
                    for(int k=0; k < rList.get(j).getrdEntities().size(); k++)
                    {
                        String[] details = rList.get(j).getrdEntities().get(i).getEntity().getDetails().split(" ");
                        if (details[0].equals("Material"))
                        {
                            System.out.println(++count+". "+ rList.get(j).getrdEntities().get(k).getEntity().getName() + " (" + rList.get(j).getrdEntities().get(k).getQuantity() + ")");
                        }
                        else
                        {
                            System.out.println(++count+". "+ rList.get(j).getrdEntities().get(k).getEntity().getName());
                        } 
                    }
                }
            }
        }
        return count;
    }
    
    public ArrayList <Entity> getEntityList() // Επιστ�?έφει entityList
    {
        return entityList;
    }

    public RequestDonationList getCurrentDonations() // Επιστ�?έφει currentDonations
    {
        return currentDonations;
    }
}    