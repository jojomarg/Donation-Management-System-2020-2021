 
import java.util.ArrayList;
public class Main
{
    public static void main(String args[]) throws Exception
    {
        // τα Material
        Material rice = new Material("rice", "rice", 1, 2, 3);
        Material milk = new Material("milk", "milk", 1, 2, 3);
        Material sugar = new Material("sugar", "sugar", 1, 2, 3);

        // οι Services
        Service BabySitting = new Service("Babysitting", "Babysitting description");
        Service NurserySupport = new Service("Nursery Support", "Nursery Support description");
        Service MedicalSupport = new Service("Medical Support", "Medical Support description");

        // Δημιου�?γία και γέμισμα της entityList, τ�?που Entity με τα Material και Services
        ArrayList <Entity> entityList = new ArrayList<Entity>();
        entityList.add(rice);
        entityList.add(milk);
        entityList.add(sugar);
        entityList.add(BabySitting);
        entityList.add(NurserySupport);
        entityList.add(MedicalSupport);

        // Δημιου�?γία του Ο�?γανισμο�?
        Organization RedCross = new Organization("RedCross", entityList);
        System.out.println("Welcome to the Project!");

        // Δημιου�?γία του Admin
        Admin A = new Admin("George", "1"); 
        
        // Δημιου�?γία πίνακα τεστα�?ίσματος του π�?ότζεκτ
        ArrayList <Requests> testRequestedList = new ArrayList <Requests> ();

        // Δημιου�?γία των Beneficiary
        Beneficiary B1 = new Beneficiary("Maria", "2", 3);
        RedCross.insertBeneficiary(B1);
        B1.setRequestedList(testRequestedList);
        Beneficiary B2 = new Beneficiary("Jim", "3", 5);
        RedCross.insertBeneficiary(B2);

        // Δημιου�?γία της testRequest, τ�?που Requests, για την διευκόλυνση τεστα�?ίσματος των Requests των Beneficiaries
        Requests testRequest = new Requests();
        testRequest.add(RedCross, B1, new RequestDonation(rice, 1));
        testRequest.add(RedCross, B1, new RequestDonation(BabySitting));
        testRequestedList.add(testRequest);

        // Δημιου�?γία του Donator
        Donator D = new Donator("Kate", "5");
        RedCross.insertDonator(D);

        // Δημιου�?γία της testOffer και της λίστας testOffersList, τ�?που Offers, για την διευκόλυνση τεστα�?ίσματος των Offers του Donator
        Offers testOffer = new Offers();
        ArrayList <Offers> testOffersList = new ArrayList <Offers> ();
        testOffer.add(RedCross, new RequestDonation(rice, 20));
        testOffer.add(RedCross, new RequestDonation(milk, 10));
        testOffer.add(RedCross, new RequestDonation(BabySitting));
        testOffer.add(RedCross, new RequestDonation(NurserySupport));
        testOffersList.add(testOffer);
        D.setOffersList(testOffersList);
        for(int i=0; i < testOffersList.size(); i++)
        {
            RedCross.setTestCurrentDonations(testOffersList.get(i));
        }

        // Θέση του Admin A στον ο�?γανισμό
        RedCross.setAdmin(A);

        // Δημιου�?γία Menu του Ο�?γανισμο�?
        new Menu(RedCross);
    }
}