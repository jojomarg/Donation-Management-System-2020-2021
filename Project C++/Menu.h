#pragma once

#include"Organization.h"


class Menu
{
    //Μέθοδοι
    public:
    Menu(Organization &o)
    {
        int int_input;

        while(true)
        {
            cout << "Enter phone number: " << endl;

            string phone;
            cin >> phone;
            label1:
            {
                bool flag = false;
                if(!(o.getAdmin().getPhone().compare(phone)))
                {
                    while(true)
                    {
                        // Admin menu
                        cout << "Welcome " << o.getAdmin().getName() << ". Your credentials are: " << endl;
                        cout << "Name: " << o.getAdmin().getName() << endl;
                        cout << "Phone: " << o.getAdmin().getPhone() << endl;
                        cout << "User " << o.getAdmin().getName() << " is an Admin." << endl;
                        label2:
                        {
                            cout << "Choose an action: " << endl;
                            cout << "1. View \n2. Monitor Organization \n3. Back \n4. Logout \n5. Exit" << endl;
                            cin >> int_input;
                            switch (int_input)
                            {
                                case 1: // View
                                {
                                    while (true)
                                    {
                                        cout << "Choose an Entity category: " << endl;
                                        cout << "1. Material \n2. Services \n3. Back" << endl;
                                        cin >> int_input;
                                        switch (int_input)
                                        {
                                            case 1: // Material
                                            {
                                                vector <RequestDonation> mList = o.listMaterial();
                                                while (true)
                                                {
                                                    if(mList.size() == 0)
                                                    {
                                                        break;
                                                    }
                                                    int a;
                                                    cout << "Choose a Material to view Information: " << endl;
                                                    cin >> a;
                                                    if (a <= mList.size())
                                                    {
                                                        a = a-1;
                                                        cout << mList[a].getEntity()->toString() << endl;
                                                        break;
                                                    }
                                                    else
                                                    {
                                                        cout << "Wrong Input." << endl;
                                                    }
                                                }
                                                break;
                                            }
                                            case 2: // Services
                                            {
                                                vector <RequestDonation> sList = o.listServices();
                                                while (true)
                                                {
                                                    if(sList.size() == 0)
                                                    {
                                                        break;
                                                    }
                                                    int a;
                                                    cout << "Choose a Service: " << endl;
                                                    cin >> a;
                                                    if (a <= sList.size()) // if the number exists in the sList
                                                    {
                                                        a = a-1;
                                                        cout << sList[a].getEntity()->toString() << endl;
                                                        break;
                                                    }
                                                    else // if the number doesn't
                                                    {
                                                        cout << "Wrong Input." << endl;
                                                    }
                                                }
                                                break;
                                            }
                                            case 3: // Back
                                            {
                                                goto endlabel2;
                                            }
                                            default: // if they press a wrong key
                                            {
                                                cout << "Wrong Input." << endl;
                                                continue;
                                            }
                                        }
                                    }
                                }
                                case 2: // Monitor Organization
                                {
                                    label3:
                                    {
                                        cout << "Choose an action: " << endl;
                                        cout << "1. List Beneficiaries \n2. List Donators \n3. Reset Beneficiaries Lists \n4. Back" << endl;
                                        cin >> int_input;
                                        switch (int_input)
                                        {
                                            case 1: // List Beneficiaries
                                            {
                                                cout << "The Beneficiaries are: " << endl;
                                                vector <Beneficiary> bList = o.getBeneficiaryList();
                                                for(int i=0; i < bList.size(); i++)
                                                {
                                                    cout << (i+1) << ". " << bList[i].getName() << endl;
                                                }
                                                while (true)
                                                {
                                                    if(bList.size() == 0)
                                                    {
                                                        break;
                                                    }
                                                    int a;
                                                    cout << "Choose a Beneficiary: " << endl;
                                                    cin >> a;
                                                    if (a <= bList.size()) // if the number exists in the bList
                                                    {
                                                        label4:
                                                        {
                                                            a = a-1;
                                                            o.listBeneficiary(bList[a]); // prints Beneficiary's current received entities by their category
                                                            cout << "Choose an action: " << endl;
                                                            cout << "1. Clear receivedList \n2. Delete Beneficiary \n3. Back" << endl;
                                                            cin >> int_input;
                                                            switch (int_input)
                                                            {
                                                                case 1: // Clear receivedList
                                                                {
                                                                    o.getBeneficiaryList()[a].getReceivedList().clear();
                                                                    break;
                                                                }
                                                                case 2: // Delete Beneficiary
                                                                {
                                                                    o.removeBeneficiary(bList[a]);
                                                                    break;
                                                                }
                                                                case 3: // Back
                                                                {   goto endlabel3;   }
                                                                default: // if they press a wrong key
                                                                {
                                                                    cout << "Wrong Input." << endl;
                                                                    continue;
                                                                }
                                                            }
                                                            endlabel4: ;
                                                        }
                                                        break;
                                                    }
                                                    else // if the number doesn't
                                                    {
                                                        cout << "Wrong Input." << endl;
                                                        break;
                                                    }
                                                }
                                                break;
                                            }
                                            case 2: // List Donators
                                            {
                                                cout << "The Donators are: " << endl;
                                                vector <Donator> dList = o.getDonatorsList();
                                                for(int i=0; i < dList.size(); i++)
                                                {
                                                    cout << (i+1) << ". " << dList[i].getName() << endl;
                                                }
                                                while (true)
                                                {
                                                    if(dList.size() == 0)
                                                    {
                                                        break;
                                                    }
                                                    int a;
                                                    cout << "Choose a Donator: " << endl;
                                                    cin >> a;
                                                    if (a <= dList.size()) // if the number exists in the dList
                                                    {
                                                        label5:
                                                        {
                                                            a = a-1;
                                                            o.listDonators(dList[a]); // prints Donator's current offered entities by their category
                                                            cout << "Choose an action: " << endl;
                                                            cout << "1. Delete Donator \n2. Back" << endl;
                                                            cin >> int_input;
                                                            switch (int_input)
                                                            {
                                                                case 1: // Delete Donator
                                                                {
                                                                    o.removeDonator(dList[a]);
                                                                    break;
                                                                }
                                                                case 2: // Back
                                                                { goto endlabel5;   }
                                                                default: // if they press a wrong key
                                                                {   
                                                                    cout << "Wrong Input." << endl;
                                                                    continue;
                                                                }
                                                            }
                                                            endlabel5: ;
                                                        }
                                                        break;
                                                    }
                                                    else // if the number doesn't
                                                    {
                                                        cout << "Wrong Input." << endl;
                                                        break;
                                                    }
                                                }
                                                break;
                                            }
                                            case 3: // Reset Beneficiaries Lists
                                            {
                                                for(int i=0; i < o.getBeneficiaryList().size(); i++)
                                                {
                                                    o.getBeneficiaryList()[i].getReceivedList().clear();
                                                }
                                                break;
                                            }
                                            case 4: // Back
                                            {   goto endlabel3;   }
                                            default: // if they press a wrong key
                                            {
                                                cout << "Wrong Input." << endl;
                                                continue;
                                            }
                                        }
                                        endlabel3: ;
                                    }
                                    break;
                                }
                                case 3: // Back
                                {
                                    goto endlabel1;
                                }
                                case 4: // Logout
                                {   goto endlabel1;   }
                                case 5: // Exit
                                {   exit(0); }
                                default: // if they press a wrong key
                                {
                                    cout << "Wrong Input" << endl;
                                    continue;
                                }
                            }
                            endlabel2: ;
                        }
                    }
                }
                else
                {
                    for(int i=0; i < o.getBeneficiaryList().size(); i++)
                    {
                        if(!(o.getBeneficiaryList()[i].getPhone().compare(phone)))
                        {
                            // Beneficiary menu
                            cout << "Welcome to " << o.getName() << " " << o.getBeneficiaryList()[i].getName() << ". Your credentials are: " << endl;
                            cout << "Name: " << o.getBeneficiaryList()[i].getName() << endl;
                            cout << "Phone: " << o.getBeneficiaryList()[i].getPhone() << endl;
                            cout << "User " << o.getBeneficiaryList()[i].getName() << " is a Beneficiary." << endl;
                            Requests requestList;
                            flag = true;
                            while(true)
                            {
                                cout << "Choose an action: " << endl;
                                cout << "1. Add Requests \n2. Show Requests \n3. Commit \n4. Back \n5. Logout \n6. Exit" << endl;
                                label6:
                                {
                                    cin >> int_input;
                                    switch(int_input)
                                    {
                                        case 1: // Add Requests
                                        {
                                            cout << "Choose an Entity category: " << endl;
                                            cout << "1. Materials \n2. Services \n3. Back" << endl;
                                            while(true)
                                            {
                                                cin >> int_input;
                                                switch(int_input)
                                                {
                                                    case 1: // for Material list
                                                    {
                                                        
                                                        vector <RequestDonation> mList = o.listMaterial();
                                                        while(true)
                                                        {
                                                            if(mList.size() == 0)
                                                            {
                                                                break;
                                                            }

                                                            label7:
                                                            {
                                                                int a;
                                                                cout << "Choose a Material to view Information: " << endl;
                                                                cin >> a;
                                                                if (a <= mList.size())
                                                                {
                                                                    // label8:
                                                                    // {
                                                                        a = a-1;
                                                                        cout << mList[a].getEntity()->toString() << endl;
                                                                        cout << "Do you want to request this Material? \n1. Yes \n2. No \n3. Back" << endl;
                                                                        cin >> int_input;
                                                                        switch(int_input)
                                                                        {
                                                                            case 1: // Yes
                                                                            {
                                                                                cout << "Requested quantity is: " << endl;
                                                                                double q;
                                                                                cin >> q;
                                                                                requestList.getrdEntities().push_back(RequestDonation(mList[a].getEntity(), q));
                                                                                cout << "Would you like to Request more Materials? \n1. Yes \n2. No \n3. Back" << endl;
                                                                                cin >> int_input;
                                                                                switch(int_input)
                                                                                {
                                                                                    case 1: // Yes
                                                                                    {   continue;   }
                                                                                    case 2: // No
                                                                                    {   
                                                                                        cout << "No more Requests." << endl;
                                                                                        goto endlabel6;
                                                                                    }
                                                                                    case 3: // Back
                                                                                    {   goto endlabel7; }
                                                                                    default: // if they press a wrong key
                                                                                    {
                                                                                        cout << "Wrong Input" << endl;
                                                                                        continue;
                                                                                    }
                                                                                }
                                                                                break;
                                                                            }
                                                                            case 2: // No
                                                                            {   cout << "No Requests for this Material." << endl;   }
                                                                            case 3: // Back
                                                                            {   goto endlabel7;   }
                                                                            default: // if they press a wrong key
                                                                            {
                                                                                cout << "Wrong Input" << endl;
                                                                                continue;
                                                                            }
                                                                        }
                                                                        // endlabel8:;
                                                                    // }
                                                                }
                                                                endlabel7:;
                                                            }
                                                        }
                                                        break;
                                                    }
                                                    case 2: // for Services list
                                                    {
                                                        vector <RequestDonation> sList = o.listServices();
                                                        while(true)
                                                        {
                                                            if(sList.size() == 0)
                                                            {
                                                                break;
                                                            }
                                                            label9:
                                                            {
                                                                int a;
                                                                cout << "Choose a Service to view Information: " << endl;
                                                                cin >> a;
                                                                if (a <= sList.size())
                                                                {
                                                                    label10:
                                                                    {
                                                                        a = a-1;
                                                                        cout << sList[a].getEntity()->toString() << endl;
                                                                        cout << "Do you want to request this Service? \n1. Yes \n2. No \n3. Back" << endl;
                                                                        cin >> int_input;
                                                                        switch (int_input)
                                                                        {
                                                                            case 1: // Yes
                                                                            {
                                                                                cout << "Requested service time is: " << endl;
                                                                                double t;
                                                                                cin >> t;
                                                                                RequestDonation request(sList[a].getEntity(), t);
                                                                                requestList.getrdEntities().push_back(request);
                                                                                cout << "Would you like to Request more Services?\n1. Yes \n2. No \n3. Back" << endl;
                                                                                cin >> int_input;
                                                                                switch(int_input)
                                                                                {
                                                                                    case 1: // Yes
                                                                                    {   continue;   }
                                                                                    case 2: // No
                                                                                    {
                                                                                        cout << "No more Requests." << endl;
                                                                                        goto endlabel6;
                                                                                    }
                                                                                    case 3: // Back
                                                                                    {   goto endlabel10;    }
                                                                                    default: // if they press a wrong key
                                                                                    {
                                                                                        cout << "Wrong Input" << endl;
                                                                                        continue;
                                                                                    }
                                                                                }
                                                                                break;
                                                                            }
                                                                            case 2: // No
                                                                            {   cout << "No Requests for this Service." << endl;    }
                                                                            case 3: // Back
                                                                            {   goto endlabel9;   }
                                                                            default: // if they press a wrong key
                                                                            {
                                                                                cout << "Wrong Input" << endl;
                                                                                continue;
                                                                            }
                                                                        }
                                                                        endlabel10:;
                                                                    }
                                                                }
                                                                else
                                                                {
                                                                    cout <<"Wrong Input." << endl;
                                                                }
                                                                endlabel9:;
                                                            }
                                                        }
                                                        break;
                                                    }
                                                    case 3: // Back
                                                    {   goto endlabel6;   }
                                                    default: // if they press a wrong key
                                                    {
                                                        cout << "Wrong Input" << endl;
                                                        continue;
                                                    }
                                                }
                                            }
                                            break;
                                        }
                                        case 2: // Show Requests
                                        {
                                            int rdSize = o.listrdBeneficiary(o.getBeneficiaryList()[i]);
                                            label11:
                                            {
                                                while(true)
                                                {
                                                    vector <int> changedItemPos; // changed item's position
                                                    vector <double> newQ; // RequestDonation's new Quantity
                                                    //changedItemPos: 5, 9, 2, 4, -1                    example of what im doing
                                                    //newRD:		  4, 2, -1, 2, δε με νοιαζει
                                                    cout << "Choose an action: " << endl;
                                                    cout << "1. Choose a Request \n2. Clear all Requests \n3. Save your Requests \n4. Back" << endl;
                                                    cin >> int_input;
                                                    switch (int_input)
                                                    {
                                                        case 1: // Choose a Request
                                                        label12:
                                                        {
                                                            int a;
                                                            cin >> a;
                                                            if (a < rdSize) // if the number exists in the rList
                                                            {
                                                                if(rdSize == 0)                                                              // not sure if the if is needed
                                                                {
                                                                    break;
                                                                }
                                                                a = a-1;
                                                                cout << "Choose an action: " << endl;
                                                                cout << "1. Delete Request \n2. Modify Request Quantity \n3. Back" << endl;
                                                                cin >> int_input;
                                                                switch (int_input)
                                                                {
                                                                    case 1: // Delete Request
                                                                    {
                                                                        changedItemPos.push_back(a);
                                                                        newQ.push_back(-1.0);
                                                                        break;
                                                                    }
                                                                    case 2: // Modify Request Quantity/Time
                                                                    {
                                                                        int count = 0;
                                                                        while(o.getBeneficiaryList()[i].getRequestedList()[count].getrdEntities().size() > a) // που βρίσκεται το RequestDonation σε όλα τα RequestDonationList
                                                                        {
                                                                            a -= o.getBeneficiaryList()[i].getRequestedList()[count++].getrdEntities().size();
                                                                        }
                                                                        vector <string> details;
                                                                        tokenize(o.getBeneficiaryList()[i].getRequestedList()[count].getrdEntities()[a].getEntity()->getDetails(), ' ', details);
                                                                        if( !(details[0].compare("Material")))
                                                                        {
                                                                            changedItemPos.push_back(a);
                                                                            cout << "New Quantity is: " << endl;
                                                                            double q;
                                                                            cin >> q;
                                                                            newQ.push_back(q);
                                                                        }
                                                                        else
                                                                        {
                                                                            cout << "Item is a Service, unable to modify." << endl;
                                                                        }
                                                                        break;
                                                                    }
                                                                    case 3: // Back
                                                                    {   goto endlabel12;    }
                                                                    default: // Wrong key
                                                                    {
                                                                        cout << "Wrong Input." << endl;
                                                                        continue;
                                                                    }
                                                                }
                                                            }
                                                            endlabel12: ;
                                                        }
                                                        case 2: // Clear all Requests
                                                        {
                                                            changedItemPos.push_back(-1);
                                                            break;
                                                        }
                                                        case 3: // Save your Requests - Commit
                                                        {
                                                            cout << "Saving Requested items." << endl;
                                                            bool flag2 = false;
                                                            for(int j=0; j < changedItemPos.size(); j++) // we check if the user has cleared all
                                                            {
                                                                if(changedItemPos[j] == -1)
                                                                {
                                                                    o.getBeneficiaryList()[i].getRequestedList().clear(); // Clear all Donations
                                                                    flag2 = true;
                                                                    break;
                                                                }
                                                            }
                                                            if(flag2 == true)
                                                            {
                                                                break;
                                                            }
                                                            for(int j=0; j < changedItemPos.size(); j++) // if they have chosen case 1 (Choose a Request)
                                                            {
                                                                int count = 0;
                                                                while(o.getBeneficiaryList()[i].getRequestedList()[count].getrdEntities().size() > changedItemPos[j]) // που βρίσκεται το RequestDonation σε όλα τα RequestDonationList
                                                                {
                                                                    changedItemPos[j] = changedItemPos[j]-o.getBeneficiaryList()[i].getRequestedList()[count++].getrdEntities().size();
                                                                }
                                                                if(newQ[i] > -1)
                                                                {
                                                                    o.getBeneficiaryList()[i].getRequestedList()[count].getrdEntities()[changedItemPos[j]].setQuantity(newQ[changedItemPos[j]]); // Modify Request Quantity/Time
                                                                }
                                                                else
                                                                {
                                                                    vector<RequestDonation> temp_rd_Entities = o.getBeneficiaryList()[i].getRequestedList()[count].getrdEntities();
                                                                    temp_rd_Entities.erase(temp_rd_Entities.begin() + (int)changedItemPos[j]);  // Delete Request
                                                                }
                                                            }
                                                            break;
                                                        }
                                                        case 4: // Back
                                                        {
                                                            cout << "Before you leave, don't forget to save your changes.\nAre you sure you want to exit? \n 1. Yes \n2. No" << endl;
                                                            cin >> int_input;
                                                            switch(int_input)
                                                            {
                                                                case 1: // Yes
                                                                goto endlabel11;
                                                                case 2: // No
                                                                continue;
                                                                default: // Wrong key
                                                                cout << "Wrong Input. Exit aborted." << endl;
                                                                continue;
                                                            }
                                                        }
                                                        default: // Wrong key
                                                        {
                                                            cout << "Wrong Input." << endl;
                                                            continue;
                                                        }
                                                    }
                                                }
                                                endlabel11:;
                                            }
                                            break;
                                        }
                                        case 3: // Commit
                                        {
                                            cout << "You are able to receive these Requests: " << endl;
                                            o.getBeneficiaryList()[i].getRequestedList().push_back(requestList); // Added to Requested List
                                            for(int j=0; j < requestList.getrdEntities().size(); j++)
                                            {
                                                o.getCurrentDonations().remove(requestList.getrdEntities()[j]);
                                                // requestList.commit(o.getCurrentDonations(), o.getEntityList(),o.getBeneficiaryList()[i]);
                                            }
                                            requestList.commit(o.getCurrentDonations(), o.getEntityList(), o.getBeneficiaryList()[i]);
                                            break;
                                        }
                                        case 4: // Back
                                        {   goto endlabel1; }
                                        case 5: // Logout
                                        {   goto endlabel1; }
                                        case 6: // Exit
                                        {   
                                            exit(0);
                                            break;
                                        }
                                        default: // if they press a wrong key
                                        {
                                            cout << "Wrong Input" << endl;
                                            continue;
                                        }
                                    }
                                    endlabel6:;
                                }
                            }
                        }
                    }
                    for(int i=0; i < o.getDonatorsList().size(); i++)
                    {
                        if(!(o.getDonatorsList()[i].getPhone().compare(phone)) && flag ==false)
                        {
                            // Donator menu
                            cout << "Welcome to " << o.getName() << " " << o.getDonatorsList()[i].getName() << ". Your credentials are: " << endl;
                            cout << "Name: " << o.getDonatorsList()[i].getName() << endl;
                            cout << "Phone: " << o.getDonatorsList()[i].getPhone() << endl;
                            cout << "User " << o.getDonatorsList()[i].getName() << " is a Donator." << endl;
                            Offers offerList;
                            flag = true;
                            while(true)
                            {
                                cout << "Choose an action: " << endl;
                                cout << "1. Add Offer. \n2. Show Offers \n3. Commit \n4. Back \n5. Logout \n6. Exit" << endl;
                                label13:
                                {
                                    cin >> int_input;
                                    switch (int_input)
                                    {
                                        case 1: // Add Offer
                                        {
                                            cout << "Choose an Entity category: " << endl;
                                            cout << "1. Materials \n2. Services \n3. Back" << endl;
                                            while(true)
                                            {
                                                cin >> int_input;
                                                switch(int_input)
                                                {
                                                    case 1: // for Material list
                                                    {
                                                        vector <RequestDonation> mList = o.listMaterial();
                                                        while(true)
                                                        {
                                                            if(mList.size() == 0)
                                                            {
                                                                break;
                                                            }

                                                            label14:
                                                            {
                                                                int a;
                                                                cout << "Choose a Material to view Information: " << endl;
                                                                cin >> a;
                                                                if (a <= mList.size())
                                                                {
                                                                    a = a-1;
                                                                    cout << mList[a].getEntity()->toString() << endl;
                                                                    cout << "Do you want to offer a Material? \n1. Yes \n2. No \n3. Back" << endl;
                                                                    cin >> int_input;
                                                                    switch(int_input)
                                                                    {
                                                                        case 1: // Yes
                                                                        {
                                                                            cout << "Offered quantity is: " << endl;
                                                                            double q;
                                                                            cin >> q;
                                                                            offerList.getrdEntities().push_back(RequestDonation(mList[a].getEntity(), q));
                                                                            cout << "Would you like to Offer more Materials?\n1. Yes \n2. No \n3. Back" << endl;
                                                                            cin >> int_input;
                                                                            switch(int_input)
                                                                            {
                                                                                case 1: // Yes
                                                                                {   continue;   }
                                                                                case 2: // No
                                                                                {   
                                                                                    cout << "No more Offers." << endl;
                                                                                    goto endlabel13;
                                                                                }
                                                                                case 3: // Back
                                                                                {   goto endlabel14;    }
                                                                                default: // if they press a wrong key
                                                                                {
                                                                                    cout << "Wrong Input" << endl;
                                                                                    continue;
                                                                                }
                                                                            }
                                                                            break;
                                                                        }
                                                                        case 2: // No
                                                                        {
                                                                            cout << "No Offer for this Material." << endl;
                                                                            break;
                                                                        }
                                                                        case 3: // Back
                                                                        {   goto endlabel14;    }
                                                                        default: // if they press a wrong key
                                                                        {
                                                                            cout << "Wrong Input" << endl;
                                                                            continue;
                                                                        }
                                                                    }
                                                                }
                                                                endlabel14:;
                                                            }
                                                        }
                                                        break;
                                                    }
                                                    case 2: // for Services list
                                                    {
                                                        vector <RequestDonation> sList = o.listServices();
                                                        while(true)
                                                        {
                                                            if(sList.size() == 0)
                                                            {
                                                                break;
                                                            }
                                                            label15:
                                                            {
                                                                cout << "Choose a Service to view Information: " << endl;
                                                                int a;
                                                                cin >> a;
                                                                if (a <= sList.size())
                                                                {
                                                                    label16:
                                                                    {
                                                                        a = a-1;
                                                                        cout << sList[a].getEntity()->toString() << endl;
                                                                        cout << "Do you want to offer a Service?\n 1.Yes \n2.No \n3. Back" << endl;
                                                                        cin >> int_input;
                                                                        switch (int_input)
                                                                        {
                                                                            case 1: // Yes
                                                                            {
                                                                                cout << "Offered service time is: " << endl;
                                                                                double t;
                                                                                cin >> t;
                                                                                RequestDonation offer(sList[a].getEntity(), t);
                                                                                offerList.getrdEntities().push_back(offer);
                                                                                cout << "Would you like to Offer more Services? \n1. Yes \n2. No \n3. Back" << endl;
                                                                                cin >> int_input;
                                                                                switch (int_input)
                                                                                {
                                                                                    case 1: // Yes
                                                                                    continue;
                                                                                    case 2: // No
                                                                                    cout << "No more Offers." << endl;
                                                                                    goto endlabel13;
                                                                                    case 3: // Back
                                                                                    goto endlabel16;
                                                                                    default: // Wrong key
                                                                                    cout << "Wrong Input." << endl;
                                                                                    continue;
                                                                                }
                                                                                break;
                                                                            }
                                                                            case 2: // No
                                                                            {   cout << "No Offer for this Service." << endl;   }
                                                                            case 3: // Back
                                                                            {   goto endlabel15;    }
                                                                            default: // Wrong key
                                                                            {
                                                                                cout << "Wrong Input." << endl;
                                                                                continue;
                                                                            }
                                                                        }
                                                                        endlabel16:;
                                                                    }
                                                                }
                                                                else
                                                                {
                                                                    cout << "Wrong Input." << endl;
                                                                }
                                                                endlabel15:;
                                                            }
                                                        }
                                                        break;
                                                    }
                                                    case 3: // Back
                                                    {   goto endlabel13;  }
                                                    default: // Wrong key
                                                    {
                                                        cout << "Wrong Input." << endl;
                                                        continue;
                                                    }
                                                }
                                            }
                                            break;
                                        }
                                        case 2: // Show Offers
                                        {
                                            int rdSize = o.listrdDonator(o.getDonatorsList()[i]);
                                            label17:
                                            {
                                                while(true)
                                                {
                                                    label18:
                                                    {
                                                        vector <int> changedItemPos; // changed item's position
                                                        vector <double> newQ; // RequestDonation's new Quantity
                                                        //changedItemPos: 5, 9, 2, 4, -1                    example of what im doing
                                                        //newRD:		  4, 2, -1, 2, δε με νοιαζει
                                                        cout << "Choose an action: " << endl;
                                                        cout << "1. Choose a Donation \n2. Clear all Donations \n3. Save your Donations \n4. Back" << endl;
                                                        cin >> int_input;
                                                        switch (int_input)
                                                        {
                                                            case 1: // Choose a Donation
                                                            int a;
                                                            cin >> a;
                                                            if (a < rdSize) // if the number exists in the oList
                                                            {
                                                                if(rdSize == 0)
                                                                {
                                                                    break;
                                                                }
                                                                cout << "Choose an action: " << endl;
                                                                cout << "1. Delete Offer \n2. Modify Offers Quantity/Time \n3. Back" << endl;
                                                                cin >> int_input;
                                                                switch (int_input)
                                                                {
                                                                    case 1: // Delete Offer
                                                                    {
                                                                        changedItemPos.push_back(a);
                                                                        newQ.push_back(-1.0);
                                                                        break;
                                                                    }
                                                                    case 2: // Modify Offers Quantity/Time
                                                                    {
                                                                        int count = 0;
                                                                        while(o.getDonatorsList()[i].getOffersList()[count].getrdEntities().size() > a) // που βρίσκεται το RequestDonation σε όλα τα RequestDonationList
                                                                        {
                                                                            a -= o.getDonatorsList()[i].getOffersList()[count++].getrdEntities().size();
                                                                        }
                                                                        vector <string> details;
                                                                        tokenize(o.getDonatorsList()[i].getOffersList()[count].getrdEntities()[a].getEntity()->getDetails(), ' ', details);
                                                                        if( !(details[0].compare("Material")))
                                                                        {
                                                                            changedItemPos.push_back(a);
                                                                            cout << "New Quantity is: " << endl;
                                                                            double q;
                                                                            cin >> q;
                                                                            newQ.push_back(q);
                                                                        }
                                                                        else
                                                                        {
                                                                            cout << "Item is a Service, unable to modify." << endl;
                                                                        }
                                                                        break;
                                                                    }
                                                                    case 3: // Back
                                                                    {   goto endlabel18; }
                                                                    default: // Wrong key
                                                                    {
                                                                        cout << "Wrong Input." << endl;
                                                                        continue;
                                                                    }
                                                                }
                                                            }
                                                            case 2: // Clear all Donations
                                                            {
                                                                changedItemPos.push_back(-1);
                                                                break;
                                                            }
                                                            case 3: // Save your Donations - Commit
                                                            {
                                                                cout << "Saving Offered items." << endl;
                                                                bool flag2 = false;
                                                                for(int j=0; j < changedItemPos.size(); j++) // we check if the user has cleared all
                                                                {
                                                                    if(changedItemPos[j] == -1)
                                                                    {
                                                                        o.getDonatorsList()[i].getOffersList().clear(); // Clear all Donations
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
                                                                    while(o.getDonatorsList()[i].getOffersList()[count].getrdEntities().size() > changedItemPos[j]) // που βρίσκεται το RequestDonation σε όλα τα RequestDonationList
                                                                    {
                                                                        changedItemPos[j] =  changedItemPos[j]-o.getDonatorsList()[i].getOffersList()[count++].getrdEntities().size();
                                                                    }
                                                                    if(newQ[j] > -1)
                                                                    {
                                                                        o.getDonatorsList()[i].getOffersList()[count].getrdEntities()[changedItemPos[j]].setQuantity(newQ[changedItemPos[j]]); // Modify Offers Quantity/Time
                                                                    }
                                                                    else
                                                                    {
                                                                        vector<RequestDonation> temp_rdEntities = o.getDonatorsList()[i].getOffersList()[count].getrdEntities();
                                                                        temp_rdEntities.erase(temp_rdEntities.begin() + (int)changedItemPos[j]); // Delete Offer
                                                                    }
                                                                }
                                                                break;
                                                            }
                                                            case 4: // Back
                                                            {
                                                                cout << "Before you leave, don't forget to save your changes.\nAre you sure you want to exit? \n1. Yes \n2. No" << endl;
                                                                cin >> int_input;
                                                                switch (int_input)
                                                                {
                                                                    case 1: // Yes
                                                                    goto endlabel17;
                                                                    case 2: // No
                                                                    continue;
                                                                    default: // Wrong key
                                                                    cout << "Wrong Input. Exit aborted." << endl;
                                                                    continue;
                                                                }
                                                                break;
                                                            }
                                                            default: // Wrong key
                                                            {
                                                                cout << "Wrong Input." << endl;
                                                                continue;
                                                            }
                                                        }
                                                        endlabel18:;
                                                    }
                                                }
                                                endlabel17:;
                                            }
                                            break;
                                        }
                                        case 3: // Commit
                                        {
                                            cout << "Saving Offered items..." << endl;
                                            o.getDonatorsList()[i].getOffersList().push_back(offerList); // adds offerList to Donator's offersList
                                            for(int j=0; j < offerList.getrdEntities().size(); j++)
                                            {
                                                o.getCurrentDonations().add(o.getEntityList(), offerList.getrdEntities()[j]);
                                            }
                                            offerList.commit(o.getCurrentDonations()); // call's commit() method for the organization in offerList
                                            continue;
                                        }
                                        case 4: // Back
                                        {   goto endlabel1;   }
                                        case 5: // Logout
                                        {   goto endlabel1;   }
                                        case 6: // Exit
                                        {   exit(0);    }
                                    }
                                    endlabel13:;
                                }
                            }
                        }
                    }
                    if(flag == false)  // create User Menu
                    {
                        cout << "You are not a User. Do you wish to sign in: \n1. Yes \n2. No \n3. Back" << endl;
                        cin >> int_input;
                        switch (int_input)
                        {
                            case 1: // Yes
                            {
                                cout << "Sign in as: " << endl;
                                cout << "1. Beneficiary \n2. Donator" << endl;
                                string name;
                                string Phone;
                                cin >> int_input;
                                switch(int_input)
                                {
                                    case 1: // Beneficiary
                                    {
                                        cout << "Write your name: " << endl;
                                        cin >> name;
                                        cout << "Write your phone number: " << endl;
                                        cin >> Phone;
                                        cout << "Write the number of people in your family: " << endl;
                                        int noPersons;
                                        cin >> noPersons;
                                        Beneficiary b(name, Phone, noPersons);
                                        o.insertBeneficiary(b);
                                        break;
                                    }
                                    case 2: // Donator
                                    {
                                        cout << "Write your name: " << endl;
                                        cin >> name;
                                        cout << "Write your phone number: " << endl;
                                        cin >> Phone;
                                        Donator d(name, Phone);
                                        o.insertDonator(d);
                                        break;
                                    }
                                    default: // Wrong key
                                    {
                                        cout << "Wrong Input." << endl;
                                        continue;
                                    }
                                }
                                break;
                            }
                            case 2: // No
                            {   exit(0);    }
                            case 3: // Back
                            {   goto endlabel1;   }
                        }
                    }
                }
                endlabel1:;
            }
        }
    }
};
