#pragma once
#include"Entity.h"

class Material: public Entity
{
    //Πεδία
    private:
     double level1;
     double level2;
     double level3;

    //Μέθοδοι
    public:
    Material(string name, string description, double lvl1, double lvl2, double lvl3) // Material's Constractor
    {
        this-> name = name;
        this-> description = description;
        level1 = lvl1;
        level2 = lvl2;
        level3 = lvl3;
    }

    string getDetails() { return "Material " + to_string(level1) + " " + to_string(level2) + " " + to_string(level3); }
    string getClass() {return "Material";}
    
};
