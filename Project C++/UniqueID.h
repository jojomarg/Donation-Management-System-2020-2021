#pragma once
class UniqueID 
{
    protected:
    static int nextID;
    public:
    int id;
    UniqueID(){ id = ++nextID; }
    int getID(){ return id; }
    // UniqueID(const UniqueID& orig);
    // UniqueID& operator=(const UniqueID& orig);
};
int UniqueID::nextID = 0;
