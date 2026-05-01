#ifndef PERSONNE_H
#define PERSONNE_H

#include <iostream>
using namespace std;
class Personne
{
    private:
        string name;
        string id;
    public:
        Personne();
        ~Personne();
        void setName(string n);
        string getName();
        void setId(string pwd);
        string getId();
        bool operator==(const Personne& autre) const;
};

#endif
