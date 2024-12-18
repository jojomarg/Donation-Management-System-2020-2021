#pragma once
#include"Entity.h"

class Service: public Entity
{
    //Μέθοδοι
    public:
    Service(string name, string description) // Service's Constractor
    {
        this-> name = name;
        this-> description = description;
    }

    string getDetails() { return "Service"; }
    string getClass() { return "Service"; }
};
