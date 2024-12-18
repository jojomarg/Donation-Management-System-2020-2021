#pragma once
#include"Entity.h"

class RequestDonation
{
    //Πεδία
    private:
    Entity *entity;
    double quantity = 1;

    //Μέθοδοι
    public:
    RequestDonation(Entity *e, double q) // RequestDonation's Constractor 1
    {
        entity = e;
        quantity = q;
    }

    RequestDonation(Entity *e) { entity = e; } // RequestDonation's Constractor 2

    Entity *getEntity() { return entity; }

    void setQuantity(double q) {  quantity = q; }

    double getQuantity() { return quantity; }
};
