 
import java.util.ArrayList;
import java.util.Scanner;
public class Menu 
{
    //Μέθοδοι
    public Menu(Organization o) throws Exception
    {
        Scanner input = new Scanner(System.in); // Για την εισαγωγή από το πληκτ�?ολόγιο
        while(true)
        {
            System.out.println("\nEnter phone number: ");
            String phone = input.nextLine();
            System.out.print("\n");
            label1: // Για τα Logout και τα εξωτε�?ικά Back
            {
                boolean flag = false;
                if(o.getAdmin().getPhone().equals(phone)) // Αν είναι Admin με έλεγχο τηλεφώνου
                {
                    // Admin menu
                    System.out.println("Welcome " + o.getAdmin().getName() + ".");
                    System.out.println("User " + o.getAdmin().getName() + " is an Admin." + "\n");
                    System.out.println("Your credentials are: ");
                    System.out.println("Name: " + o.getAdmin().getName());
                    System.out.println("Phone: " + o.getAdmin().getPhone() + "\n");
                    while(true)
                    {
                        label2:
                        {
                            System.out.println("Choose an action: ");
                            System.out.println("1. View \n2. Monitor Organization \n3. Back \n4. Logout \n5. Exit");
                            switch (input.nextInt()) 
                            {
                                case 1: // View
                                while (true)
                                {
                                    System.out.println("\n" + "Choose an Entity category: ");
                                    System.out.println("1. Material \n2. Services \n3. Back");
                                    switch (input.nextInt())
                                    {
                                        case 1: // Material
                                        System.out.print("\n");
                                        ArrayList <RequestDonation> mList = o.listMaterial(); // Δημιου�?γία της mList και μέσω της, κάλεσμα της listMaterial του ο�?γανισμο�?
                                        while (true)
                                        {
                                            if(mList.size() == 0) // Αν η mList είναι άδεια
                                            {
                                                break;
                                            }
                                            int a;
                                            System.out.println("Choose a Material to view Information: ");
                                            if ((a = input.nextInt()) <= mList.size()) // Το a, δηλαδή ο α�?ιθμός που εισάγεται π�?έπει να είναι μέσα στα ό�?ια μεγέθους της λίστας Material
                                            {
                                                a = a-1; // Γιατί α�?χίζει να μετ�?άει ο υπολογιστής από το 0, ενώ εμείς θέλουμε να μετ�?άει από το 1
                                                System.out.println("\n" + mList.get(a).getEntity().toString()); // Εκτυπώνει τις toString() πλη�?οφο�?ίες, δηλαδή όλες, του Material που επέλεξε ο χ�?ήστης
                                                break;
                                            }
                                            else // Δώθηκε τιμή που δεν αντιστοιχεί στο μέγεθος του πίνακα
                                            {
                                                System.out.println("\n" + "Wrong Input.");
                                            }
                                        }
                                        break;
                                        case 2: // Services -- Εκτελεί την ίδια διαδικασία με το Material, απλά για τα Services
                                        System.out.print("\n");
                                        ArrayList <RequestDonation> sList = o.listServices();
                                        while (true)
                                        {
                                            if(sList.size() == 0)
                                            {
                                                break;
                                            }
                                            int a;
                                            System.out.println("\n" + "Choose a Service to view Information: ");
                                            if ((a = input.nextInt()) <= sList.size())
                                            {
                                                a = a-1;
                                                System.out.println("\n" + sList.get(a).getEntity().toString());
                                                break;
                                            }
                                            else
                                            {
                                                System.out.println("\n" + "Wrong Input.");
                                            }
                                            break;
                                        }
                                        break;
                                        case 3: // Back -- Επιστ�?έφει στην Choose an action: 1. View 2. Monitor Organization 3. Back 4. Logout 5. Exit
                                        input.nextLine();
                                        break label2;
                                        default: // αν δωθεί τιμή μεγαλ�?τε�?η από τον α�?ιθμό των cases
                                        System.out.println("\n" + "Wrong Input.");
                                        continue;
                                    }
                                }
                                case 2: // Monitor Organization
                                while(true)
                                {
                                    label3:
                                    {
                                        System.out.println("Choose an action: ");
                                        System.out.println("1. List Beneficiaries \n2. List Donators \n3. Reset Beneficiaries Lists \n4. Back");
                                        switch(input.nextInt())
                                        {
                                            case 1: // List Beneficiaries
                                            System.out.println("The Beneficiaries are: ");
                                            ArrayList <Beneficiary> bList = o.getBeneficiaryList(); // Δημιου�?γία της bList και μέσω της, κάλεσμα της BeneficiaryList του ο�?γανισμο�?
                                            for(int i=0; i < bList.size(); i++)
                                            {
                                                System.out.println((i+1) + ". " + bList.get(i).getName()); // Εκτ�?πωση των Beneficiaries α�?ιθμημένων
                                            }
                                            while (true)
                                            {
                                                if(bList.size() == 0) // Αν η bList είναι άδεια
                                                {
                                                    break;
                                                }
                                                int a;
                                                System.out.println("Choose a Beneficiary: ");
                                                if ((a = input.nextInt()) <= bList.size()) // Το a, δηλαδή ο α�?ιθμός που εισάγεται, π�?έπει να είναι μέσα στα ό�?ια μεγέθους της λίστας των Beneficiaries
                                                {
                                                    a = a-1;
                                                    o.listBeneficiary(bList.get(a)); // καλείται ο a Beneficiary της bList της listBeneficiary του ο�?γανισμο�?, η οποία εκτυπώνει τα entities που έχει πα�?αλάβει ο a με την κατηγο�?ία που ανήκουν
                                                    System.out.println("Choose an action: ");
                                                    System.out.println("1. Clear receivedList \n2. Delete Beneficiary \n3. Back");
                                                    switch (input.nextInt())
                                                    {
                                                        case 1: // Clear receivedList
                                                        o.getBeneficiaryList().get(a).getReceivedList().clear();
                                                        break;
                                                        case 2: // Delete Beneficiary
                                                        o.removeBeneficiary(bList.get(a));
                                                        break;
                                                        case 3: // Back
                                                        break label3;
                                                        default: // αν δωθεί τιμή μεγαλ�?τε�?η από τον α�?ιθμό των cases
                                                        System.out.println("Wrong Input.");
                                                        continue;
                                                    }
                                                }
                                                else // if the number doesn't
                                                {
                                                    System.out.println("Wrong Input.");
                                                    break;
                                                }
                                            }
                                            break;
                                            case 2: // List Donators -- Εκτελείται η ίδια διαδικασία με την List Beneficiaries, μέχ�?ι την επιλογή συγκεκ�?ιμένου Donator
                                            System.out.println("The Donators are: ");
                                            ArrayList <Donator> dList = o.getDonatorsList();
                                            for(int i=0; i < dList.size(); i++)
                                            {
                                                System.out.println((i+1) + ". " +dList.get(i).getName());
                                            }
                                            while (true)
                                            {
                                                if(dList.size() == 0)
                                                {
                                                    break;
                                                }
                                                int a;
                                                System.out.println("Choose a Donator: ");
                                                if ((a = input.nextInt()) <= dList.size())
                                                {
                                                    label5:
                                                    {
                                                        a = a-1;
                                                        o.listDonators(dList.get(a)); // καλείται ο a Donator της dList της listDonators του ο�?γανισμο�?, η οποία εκτυπώνει τα entities που έχειπ�?οσφέ�?ει ο a με την κατηγο�?ία που ανήκουν
                                                        System.out.println("Choose an action: ");
                                                        System.out.println("1. Delete Donator \n2. Back");
                                                        switch (input.nextInt())
                                                        {
                                                            case 1: // Delete Donator
                                                            o.removeDonator(dList.get(a));
                                                            break;
                                                            case 2: // Back
                                                            break label5;
                                                            default: // if they press a wrong key
                                                            System.out.println("Wrong Input.");
                                                            continue;
                                                        }
                                                    }
                                                    break;
                                                }
                                                else // if the number doesn't
                                                {
                                                    System.out.println("Wrong Input.");
                                                    break;
                                                }
                                            }
                                            break;
                                            case 3: // Reset Beneficiaries Lists
                                            for(int i=0; i < o.getBeneficiaryList().size(); i++)
                                            {
                                                o.getBeneficiaryList().get(i).getReceivedList().clear(); // καθα�?ίζει την ReceivedList του κάθε Beneficiary της BeneficiaryList
                                            }
                                            break;
                                            case 4: // Back
                                            break label2;
                                            default: // if they press a wrong key
                                            System.out.println("Wrong Input.");
                                            continue;
                                        }
                                    }
                                }
                                case 3: // Back
                                input.nextLine();
                                break label1;
                                case 4: // Logout
                                input.nextLine();
                                break label1;
                                case 5: // Exit
                                System.exit(0);
                                default: // if they press a wrong key
                                System.out.println("Wrong Input");
                                continue;
                            }
                        }
                    }
                }
                else
                {
                    for(int i=0; i < o.getBeneficiaryList().size(); i++) // π�?οσπέλαση του μεγέθους της λίστας BeneficiaryList
                    {
                        if(o.getBeneficiaryList().get(i).getPhone().equals(phone)) // Αν είναι Beneficiary με έλεγχο τηλεφώνου
                        {
                            // Beneficiary menu
                            System.out.println("Welcome to " + o.getName() + " " + o.getBeneficiaryList().get(i).getName() + ".\nYour credentials are: ");
                            System.out.println("Name: " + o.getBeneficiaryList().get(i).getName());
                            System.out.println("Phone: " + o.getBeneficiaryList().get(i).getPhone());
                            System.out.println("User " + o.getBeneficiaryList().get(i).getName() + " is a Beneficiary.");
                            Requests requestList = new Requests(); // Δημιου�?γία αντικειμένου requestList, τ�?που Requests
                            flag = true;
                            while(true)
                            {
                                label6:
                                {
                                    System.out.println("\nChoose an action: ");
                                    System.out.println("1. Add Requests \n2. Show Requests \n3. Commit \n4. Back \n5. Logout \n6. Exit");
                                    switch(input.nextInt())
                                    {
                                        case 1: // Add Requests
                                        while(true)
                                        {
                                            label7:
                                            {
                                                System.out.println("\nChoose an Entity category: ");
                                                System.out.println("1. Materials \n2. Services \n3. Back");
                                                switch(input.nextInt())
                                                {
                                                    case 1: // for Material list -- Ιδια διαδικασία με τον Admin και Beneficiary
                                                    ArrayList <RequestDonation> mList = o.listMaterial();
                                                    while(true)
                                                    {
                                                        if(mList.size() == 0)
                                                        {
                                                            break;
                                                        }
                                                        int a;
                                                        System.out.println("\nChoose a Material to view Information: ");
                                                        if ((a = input.nextInt()) <= mList.size())
                                                        {
                                                            label8:
                                                            {
                                                                a = a-1;
                                                                System.out.println(mList.get(a).getEntity().toString());
                                                                System.out.println("\nDo you want to request this Material? \n1. Yes \n2. No \n3. Back");
                                                                switch(input.nextInt())
                                                                {
                                                                    case 1: // Yes
                                                                    while(true)
                                                                    {
                                                                        System.out.println("\nRequested quantity is: ");
                                                                        double q = input.nextDouble(); // εισάγει ο χ�?ήστης την ποσότητα που ζητά σε τ�?πο double
                                                                        RequestDonation request = new RequestDonation(mList.get(a).getEntity(), q); // Δημιου�?γία αντικειμένου request, τ�?που RequestDonation, στο οποίο εισάγεται το Entity του επιλεγμένου Material και η επιθυμητή ποσότητα
                                                                        requestList.getrdEntities().add(request); // Π�?οστίθεται το αντικείμενο request, τ�?που RequestDonation, στο αντικείμενο requestList, τ�?που Requests
                                                                        System.out.println("\nWould you like to Request more Materials? \n1. Yes \n2. No \n3. Back");
                                                                        switch(input.nextInt())
                                                                        {
                                                                            case 1: // Yes
                                                                            continue;
                                                                            case 2: // No
                                                                            System.out.println("\nNo more Requests.");
                                                                            input.nextLine();
                                                                            break label6;
                                                                            case 3: // Back
                                                                            break label8;
                                                                            default: // if they press a wrong key
                                                                            System.out.println("\nWrong Input");
                                                                            continue;
                                                                        }
                                                                    }
                                                                    case 2: // No
                                                                    System.out.println("\nNo Requests for this Material.");
                                                                    case 3: // Back
                                                                    break label7;
                                                                    default: // if they press a wrong key
                                                                    System.out.println("\nWrong Input");
                                                                    continue;
                                                                }
                                                            }
                                                        }
                                                    }
                                                    case 2: // for Services list -- Ιδια διαδικασία με την Material
                                                    ArrayList <RequestDonation> sList = o.listServices();
                                                    while(true)
                                                    {
                                                        if(sList.size() == 0)
                                                        {
                                                            break;
                                                        }
                                                        int a;
                                                        System.out.println("\nChoose a Service to view Information: ");
                                                        if ((a = input.nextInt()) <= sList.size())
                                                        {
                                                            label9:
                                                            {
                                                                a = a-1;
                                                                System.out.println(sList.get(a).getEntity().toString());
                                                                System.out.println("\nDo you want to request this Service? \n1. Yes \n2. No \n3. Back");
                                                                switch (input.nextInt())
                                                                {
                                                                    case 1: // Yes
                                                                    System.out.println("\nRequested service time is: ");
                                                                    double t = input.nextDouble();
                                                                    RequestDonation request = new RequestDonation(sList.get(a).getEntity(), t);
                                                                    requestList.getrdEntities().add(request);
                                                                    System.out.println("\nWould you like to Request more Services?\n1. Yes \n2. No \n3. Back");
                                                                    switch(input.nextInt())
                                                                    {
                                                                        case 1: // Yes
                                                                        continue;
                                                                        case 2: // No
                                                                        System.out.println("\nNo more Requests.");
                                                                        break label6;
                                                                        case 3: // Back
                                                                        break label9;
                                                                        default: // if they press a wrong key
                                                                        System.out.println("\nWrong Input");
                                                                        continue;
                                                                    }
                                                                    case 2: // No
                                                                    System.out.println("\nNo Requests for this Service.");
                                                                    case 3: // Back
                                                                    break label7;
                                                                    default: // if they press a wrong key
                                                                    System.out.println("\nWrong Input");
                                                                    continue;
                                                                }
                                                            }
                                                        }
                                                        else
                                                        {
                                                            System.out.println("\nWrong Input.");
                                                        }
                                                    }
                                                    case 3: // Back
                                                    break label6;
                                                    default: // if they press a wrong key
                                                    System.out.println("\nWrong Input");
                                                    continue;
                                                }
                                            }
                                        }
                                        case 2: // Show Requests
                                        int rdSize = o.listrdBeneficiary(o.getBeneficiaryList().get(i)); // Δημιου�?γία ακε�?αίου rdSize, ο οποίος δείχνει 
                                        while(true)
                                        {
                                            label10:
                                            {
                                                ArrayList <Integer> changedItemPos = new ArrayList <Integer>(); // changed item's position
                                                ArrayList <Double> newQ = new  ArrayList <Double>(); // RequestDonation's new Quantity
                                                //changedItemPos: 5, 9, 2, 4, -1                    example of what im doing
                                                //newRD:		  4, 2, -1, 2, δε με νοιαζει
                                                System.out.println("\nChoose an action: ");
                                                System.out.println("1. Choose a Request \n2. Clear all Requests \n3. Save your Requests \n4. Back");
                                                switch (input.nextInt())
                                                {
                                                    case 1: // Choose a Request
                                                    int a;
                                                    if ((a = input.nextInt()) <= rdSize) // Αν υπά�?χει ο α�?ιθμός που ζητά ο χ�?ήστης
                                                    {
                                                        if(rdSize == 0) // Αν είναι άδεια
                                                        {
                                                            break;
                                                        }
                                                        a = a-1;
                                                        System.out.println("\nChoose an action: ");
                                                        System.out.println("1. Delete Request \n2. Modify Request Quantity \n3. Back");
                                                        switch (input.nextInt())
                                                        {
                                                            case 1: // Delete Request
                                                            changedItemPos.add(a); // Π�?οσθέτεται η θέση που β�?ίσκεται το Request στην changedItemPos λίστα
                                                            newQ.add(-1.0); // Βάζω μία ειδική τιμή στην newQ λίστα, για να την ξεχω�?ίζω πιο μετά
                                                            break;
                                                            case 2: // Modify Request Quantity
                                                            int temp = a; // temp = η μεταβλητή που χ�?ησιμοποιείται για να β�?ω την θέση του RequestDonation, έτσι ώστε να β�?ω αν είναι Material ή Service
                                                            int count = 0;
                                                            while(o.getBeneficiaryList().get(i).getRequestedList().get(count).getrdEntities().size() < temp) // όσο η θέση του RequestDonation που κάνει ο χ�?ήστης Request είναι μεγαλ�?τε�?η από τον α�?ιθμό των RequestDonation που πε�?ιέχει το συγκεκ�?ιμένο RequestDonationList
                                                            {
                                                                temp -= o.getBeneficiaryList().get(i).getRequestedList().get(count++).getrdEntities().size();  // temp = temp - τον α�?ιθμό αυτό των RequestDonation της RequestDonationList
                                                            }
                                                            String[] details = o.getBeneficiaryList().get(i).getRequestedList().get(count).getrdEntities().get(temp).getEntity().getDetails().split(" ");
                                                            if( details[0].equals("Material")) // αν το Entity είναι Material
                                                            {
                                                                changedItemPos.add(a); // το π�?οσθέτω στην λίστα changedItemPos
                                                                System.out.println("\nNew Quantity is: ");
                                                                double q = input.nextDouble(); // του δίνω νέα ποσότητα
                                                                newQ.add(q);
                                                            }
                                                            else
                                                            {
                                                                System.out.println("\nItem is a Service, unable to modify."); // αν είναι Service δεν έχει ποσότητα να αλλάξουμε
                                                            }
                                                            break;
                                                            case 3: // Back
                                                            break label10;
                                                            default: // Wrong key
                                                            System.out.println("\nWrong Input.");
                                                            continue;
                                                        }
                                                    }
                                                    case 2: // Clear all Requests
                                                    changedItemPos.add(-1); // -1 ειδικός χα�?ακτή�?ας που σηματοδοτεί το άδειασμα της λίστας RequestDonationList, το οποίο θα π�?αγματοποιηθεί στην Commit
                                                    break;
                                                    case 3: // Save your Requests - Commit
                                                    System.out.println("\nSaving Requested items.");
                                                    boolean flag2 = false;
                                                    for(int j=0; j < changedItemPos.size(); j++) // αν έχει επιλεχθεί case 2 (Clear all Requests)
                                                    {
                                                        if(changedItemPos.get(j) == -1) // εδώ ελέγχεται ο ειδικός χα�?ακτή�?ας -1 που σηματοδοτεί το άδειασμα της λίστας RequestDonationList
                                                        {
                                                            o.getBeneficiaryList().get(i).getRequestedList().clear(); // Clear all Donations -  εδώ π�?αγματοποιείται το άδειασμα
                                                            flag2 = true;
                                                            break;
                                                        }
                                                    }
                                                    if(flag2 == true)
                                                    {
                                                        break;
                                                    }
                                                    for(int j=0; j < changedItemPos.size(); j++) // αν έχει επιλεχθεί case 1 (Choose a Request)
                                                    {
                                                        int count = 0;
                                                        while(o.getBeneficiaryList().get(i).getRequestedList().get(count).getrdEntities().size() < changedItemPos.get(j)) // όσο η θέση του RequestDonation που έχει αποθηκευτεί στην changedItemPos στην γ�?αμμή j αυτής της λίστας είναι μεγαλ�?τε�?η από τον α�?ιθμό των RequestDonation που πε�?ιέχει το συγκεκ�?ιμένο RequestDonationList
                                                        {
                                                            changedItemPos.set(j, changedItemPos.get(j)-o.getBeneficiaryList().get(i).getRequestedList().get(count++).getrdEntities().size()); // Θέτεται στο συγκεκ�?ιμένη γ�?αμμή j τιμή: j = j - τον α�?ιθμό των RequestDonation που πε�?ιέχει το συγκεκ�?ιμένο RequestDonationList
                                                        }
                                                        if(newQ.get(j) > -1) // Αν η newQ != -1 , δηλαδή δεν έχει καθα�?ιστεί η λίστα changedItemPos
                                                        {
                                                            o.getBeneficiaryList().get(i).getRequestedList().get(count).getrdEntities().get(changedItemPos.get(j)).setQuantity(newQ.get(changedItemPos.get(j))); // Modify Request Quantity - �?α αποθηκευτο�?ν επισήμως οι αλλαγές
                                                        }
                                                        else
                                                        {
                                                            o.getBeneficiaryList().get(i).getRequestedList().get(count).getrdEntities().remove((int)changedItemPos.get(j)); // Delete Request - Αλλιώς να διαγ�?αφεί επισήμως το Request
                                                        }
                                                    }
                                                    break;
                                                    case 4: // Back
                                                    System.out.println("\nBefore you leave, don't forget to save your changes.\nAre you sure you want to exit? \n1. Yes \n2. No");
                                                    switch(input.nextInt())
                                                    {
                                                        case 1: // Yes
                                                        break label6;
                                                        case 2: // No
                                                        continue;
                                                        default: // Wrong key
                                                        System.out.println("\nWrong Input. Exit aborted.");
                                                        continue;
                                                    }
                                                    default: // Wrong key
                                                    System.out.println("\nWrong Input.");
                                                    continue;
                                                }
                                            }
                                        }
                                        case 3: // Commit
                                        System.out.println("\nYou are able to receive these Requests: ");
                                        o.getBeneficiaryList().get(i).getRequestedList().add(requestList); // Requested Donations
                                        for(int j=0; j < o.getBeneficiaryList().get(i).getRequestedList().size(); j++)
                                        {
                                            try 
                                            {
                                                requestList.commit(o, o.getBeneficiaryList().get(i)); // Valid Received Requests
                                            } 
                                            catch (Exception e) // επειδή το commit έχει throw Exception
                                            {
                                                e.printStackTrace();
                                            }
                                        }
                                        break;
                                        case 4: // Back
                                        input.nextLine();
                                        break label1;
                                        case 5: // Logout
                                        input.nextLine();
                                        break label1;
                                        case 6: // Exit
                                        System.exit(0);
                                        break;
                                        default: // if they press a wrong key
                                        System.out.println("\nWrong Input");
                                        continue;
                                    }
                                }
                            }
                        }
                    }
                    for(int i=0; i < o.getDonatorsList().size(); i++) // π�?οσπέλαση του μεγέθους της λίστας DonatorsList
                    {
                        if(o.getDonatorsList().get(i).getPhone().equals(phone) && flag ==false) // Αν είναι Donator με έλεγχο τηλεφώνου και flag ==false, δηλαδή δεν είναι ο�?τε Admin, ο�?τε Beneficiary
                        {
                            // Donator menu
                            System.out.println("Welcome to "+ o.getName() +" " + o.getDonatorsList().get(i).getName() + ".\nYour credentials are: ");
                            System.out.println("Name: " + o.getDonatorsList().get(i).getName());
                            System.out.println("Phone: " + o.getDonatorsList().get(i).getPhone());
                            System.out.println("User " + o.getDonatorsList().get(i).getName() + " is a Donator.");
                            Offers offerList = new Offers(); // Δημιου�?γία αντικειμένου offerList, τ�?που Offers
                            flag = true;
                            while(true)
                            {
                                label11:
                                {
                                    System.out.println("\nChoose an action: ");
                                    System.out.println("1. Add Offer. \n2. Show Offers \n3. Commit \n4. Back \n5. Logout \n6. Exit");
                                    switch (input.nextInt())
                                    {
                                        case 1: // Add Offer -- Πα�?όμοια διαδικασία με την Add Requests
                                        while(true)
                                        {
                                            label12:
                                            {
                                                System.out.println("\nChoose an Entity category: ");
                                                System.out.println("1. Materials \n2. Services \n3. Back");
                                                switch(input.nextInt())
                                                {
                                                    case 1: // for Material list
                                                    ArrayList <RequestDonation> mList = o.listMaterial();
                                                    while(true)
                                                    {
                                                        if(mList.size() == 0)
                                                        {
                                                            break;
                                                        }
                                                        int a;
                                                        System.out.println("\nChoose a Material to view Information: ");
                                                        if ((a = input.nextInt()) <= mList.size())
                                                        {
                                                            label13:
                                                            {
                                                                a = a-1;
                                                                System.out.println(mList.get(a).getEntity().toString());
                                                                System.out.println("\nDo you want to offer a Material? \n1. Yes \n2. No \n3. Back");
                                                                switch(input.nextInt())
                                                                {
                                                                    case 1: // Yes
                                                                    while(true)
                                                                    {
                                                                        System.out.println("\nOffered quantity is: ");
                                                                        double q = input.nextDouble();
                                                                        offerList.getrdEntities().add(new RequestDonation(mList.get(a).getEntity(), q));
                                                                        System.out.println("\nWould you like to Offer more Materials? \n1. Yes \n2. No \n3. Back");
                                                                        switch(input.nextInt())
                                                                        {
                                                                            case 1: // Yes
                                                                            continue;
                                                                            case 2: // No
                                                                            System.out.println("\nNo more Offers.");
                                                                            input.nextLine();
                                                                            break label11;
                                                                            case 3: // Back
                                                                            break label13;
                                                                            default: // if they press a wrong key
                                                                            System.out.println("\nWrong Input");
                                                                            continue;
                                                                        }
                                                                    }
                                                                    case 2: // No
                                                                    System.out.println("\nNo Offer for this Material.");
                                                                    case 3: // Back
                                                                    break label12;
                                                                    default: // if they press a wrong key
                                                                    System.out.println("\nWrong Input");
                                                                    continue;
                                                                }
                                                            }
                                                        }
                                                    }
                                                    case 2: // for Services list
                                                    ArrayList <RequestDonation> sList = o.listServices();
                                                    while(true)
                                                    {
                                                        if(sList.size() == 0)
                                                        {
                                                            break;
                                                        }
                                                        int a;
                                                        System.out.println("\nChoose a Service to view Information: ");
                                                        if ((a = input.nextInt()) <= sList.size())
                                                        {
                                                            label14:
                                                            {
                                                                a = a-1;
                                                                System.out.println(sList.get(a).getEntity().toString());
                                                                System.out.println("\nDo you want to offer a Service? \n1.Yes \n2.No \n3. Back");
                                                                switch (input.nextInt())
                                                                {
                                                                    case 1: // Yes
                                                                    System.out.println("\nOffered service time is: ");
                                                                    double t = input.nextDouble();
                                                                    RequestDonation offer = new RequestDonation(sList.get(a).getEntity(), t);
                                                                    offerList.getrdEntities().add(offer);
                                                                    System.out.println("\nWould you like to Offer more Services? \n1. Yes \n2. No \n3. Back");
                                                                    switch(input.nextInt())
                                                                    {
                                                                        case 1: // Yes
                                                                        continue;
                                                                        case 2: // No
                                                                        System.out.println("\nNo more Offers.");
                                                                        break label11;
                                                                        case 3: // Back
                                                                        break label14;
                                                                        default: // Wrong key
                                                                        System.out.println("\nWrong Input.");
                                                                        continue;
                                                                    }
                                                                    case 2: // No
                                                                    System.out.println("\nNo Offer for this Service.");
                                                                    case 3: // Back
                                                                    break label12;
                                                                    default: // Wrong key
                                                                    System.out.println("\nWrong Input.");
                                                                    continue;
                                                                }
                                                            }
                                                        }
                                                        else
                                                        {
                                                            System.out.println("\nWrong Input.");
                                                        }
                                                        break;
                                                    }
                                                    case 3: // Back
                                                    break label11;
                                                    default: // Wrong key
                                                    System.out.println("\nWrong Input.");
                                                    continue;
                                                }
                                            }
                                        }
                                        case 2: // Show Offers -- Πα�?όμοια διαδικασία με την Show Requests
                                        int rdSize = o.listrdDonator(o.getDonatorsList().get(i));
                                        while(true)
                                        {
                                            label15:
                                            {
                                                if(rdSize == 0)
                                                {
                                                    break;
                                                }
                                                ArrayList <Integer> changedItemPos = new ArrayList <Integer>();
                                                ArrayList <Double> newQ = new  ArrayList <Double>();
                                                System.out.println("\nChoose an action: ");
                                                System.out.println("1. Choose a Donation \n2. Clear all Donations \n3. Save your Donations \n4. Back");
                                                switch (input.nextInt())
                                                {
                                                    case 1: // Choose a Donation
                                                    int a;
                                                    System.out.println("\nYour donations are: ");
                                                    o.listrdDonator(o.getDonatorsList().get(i));
                                                    if ((a = input.nextInt()) <= rdSize) // if the number exists in the oList
                                                    {
                                                        System.out.println("\nChoose an action: ");
                                                        System.out.println("1. Delete Offer \n2. Modify Offers Quantity/Time \n3. Back");
                                                        switch (input.nextInt())
                                                        {
                                                            case 1: // Delete Offer
                                                            changedItemPos.add(a);
                                                            newQ.add(-1.0);
                                                            break;
                                                            case 2: // Modify Offers Quantity/Time
                                                            int temp = a;
                                                            int count = 0;
                                                            while(o.getDonatorsList().get(i).getOffersList().get(count).getrdEntities().size() < temp) // που β�?ίσκεται το RequestDonation σε όλα τα RequestDonationList
                                                            {
                                                                temp -= o.getDonatorsList().get(i).getOffersList().get(count++).getrdEntities().size(); 
                                                            }
                                                            String[] details = o.getDonatorsList().get(i).getOffersList().get(count).getrdEntities().get(temp).getEntity().getDetails().split(" ");
                                                            if( details[0].equals("Material"))
                                                            {
                                                                changedItemPos.add(a);
                                                                System.out.println("\nNew Quantity is: ");
                                                                double q = input.nextDouble();
                                                                newQ.add(q);
                                                            }
                                                            else
                                                            {
                                                                System.out.println("\nItem is a Service, unable to modify.");
                                                            }
                                                            break;
                                                            case 3: // Back
                                                            break label15;
                                                            default: // Wrong key
                                                            System.out.println("\nWrong Input.");
                                                            continue;
                                                        }
                                                    }
                                                    case 2: // Clear all Donations
                                                    changedItemPos.add(-1);
                                                    break;
                                                    case 3: // Save your Donations - Commit
                                                    System.out.println("\nSaving Offered items.");
                                                    boolean flag2 = false;
                                                    for(int j=0; j < changedItemPos.size(); j++) // we check if the user has cleared all
                                                    {
                                                        if(changedItemPos.get(j) == -1)
                                                        {
                                                            o.getDonatorsList().get(i).getOffersList().clear(); // Clear all Donations
                                                            flag2 = true;
                                                            break;
                                                        }
                                                    }
                                                    if(flag2 == true)
                                                    {
                                                        break;
                                                    }
                                                    for(int j=0; j < changedItemPos.size(); j++) // if they have chosen case 1 (Choose a Donation)
                                                    {
                                                        int count = 0;
                                                        while(o.getDonatorsList().get(i).getOffersList().get(count).getrdEntities().size() < changedItemPos.get(j)) // που β�?ίσκεται το RequestDonation σε όλα τα RequestDonationList
                                                        {
                                                            changedItemPos.set(j, changedItemPos.get(j)-o.getDonatorsList().get(i).getOffersList().get(count++).getrdEntities().size()); 
                                                        }
                                                        if(newQ.get(j) > -1)
                                                        {
                                                            o.getDonatorsList().get(i).getOffersList().get(count).getrdEntities().get(changedItemPos.get(j)).setQuantity(newQ.get(changedItemPos.get(j))); // Modify Offers Quantity/Time
                                                        }
                                                        else
                                                        {
                                                            o.getDonatorsList().get(i).getOffersList().get(count).getrdEntities().remove((int)changedItemPos.get(j)); // Delete Offer
                                                        }
                                                    }
                                                    break;
                                                    case 4: // Back
                                                    System.out.println("\nBefore you leave, don't forget to save your changes.\nAre you sure you want to exit? \n1. Yes \n2. No");
                                                    switch(input.nextInt())
                                                    {
                                                        case 1: // Yes
                                                        break label11;
                                                        case 2: // No
                                                        continue;
                                                        default: // Wrong key
                                                        System.out.println("\nWrong Input. Exit aborted.");
                                                        continue;
                                                    }
                                                    default: // Wrong key
                                                    System.out.println("\nWrong Input.");
                                                    continue;
                                                }
                                            }
                                        }
                                        case 3: // Commit
                                        System.out.println("\nSaving Offered items...");
                                        o.getDonatorsList().get(i).getOffersList().add(offerList); // adds offerList to Donator's offersList
                                        for(int j=0; j < offerList.getrdEntities().size(); j++)
                                        {
                                            o.getCurrentDonations().add(o, offerList.getrdEntities().get(j));
                                        }
                                        offerList.commit(o); // call's commit() method for the organization in offerList
                                        continue;
                                        case 4: // Back
                                        input.nextLine();
                                        break label1;
                                        case 5: // Logout
                                        input.nextLine();
                                        break label1;
                                        case 6: // Exit
                                        System.exit(0);
                                        break;
                                    }
                                }
                            }
                        }
                    } 
                    if(flag == false)  // create User
                    {
                        System.out.println("You are not a User. Do you wish to sign in: \n1. Yes \n2. No \n3. Back");
                        switch(input.nextInt())
                        {
                            case 1: // Yes
                            System.out.println("\nSign in as: ");
                            System.out.println("1. Beneficiary \n2. Donator");
                            String name;
                            String Phone;
                            switch(input.nextInt())
                            {
                                case 1: // Beneficiary
                                input.nextLine();
                                System.out.println("\nWrite your name: ");
                                name = input.nextLine();
                                System.out.println("\nWrite your phone number: ");
                                Phone = input.nextLine();
                                System.out.println("\nWrite the number of people in your family: ");
                                int noPersons = input.nextInt();
                                input.nextLine();
                                Beneficiary b = new Beneficiary(name, Phone, noPersons);
                                o.insertBeneficiary(b);
                                break label1;
                                case 2: // Donator
                                input.nextLine();
                                System.out.println("\nWrite your name: ");
                                name = input.nextLine();
                                System.out.println("\nWrite your phone number: ");
                                Phone = input.nextLine();
                                Donator d = new Donator(name, Phone);
                                o.insertDonator(d);
                                break label1;
                                default: // Wrong key
                                System.out.println("\nWrong Input.");
                                continue;
                            }
                            case 2: // No
                            System.exit(0);
                            case 3: // Back
                            input.nextLine();
                            break label1;
                        }
                    }
                } 
            }   
        } 
    }
}