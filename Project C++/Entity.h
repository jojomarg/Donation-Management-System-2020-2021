#pragma once
#include<string>
#include"UniqueID.h"
using namespace std;

class Entity
{
    //Πεδία
    protected:
    string name;
    string description;
    UniqueID id;

    //Μέθοδοι
    public:
    string getName() { return name; }

    string getEntityInfo() { return name + " " + description + " " + to_string(id.id); }

    virtual string getClass() { return "Entity"; }
    virtual string getDetails(){}
    
    string toString() { return getEntityInfo() + " " + getDetails(); }

    bool isEqual(Entity e)  { return !(this-> toString().compare(e.toString())); }
};
