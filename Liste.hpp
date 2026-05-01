#ifndef LISTE_H
#define LISTE_H

#include <iostream>
#include <vector>
#include "Personne.hpp"
class Liste
{
    public:
        Liste();
        ~Liste();
        vector<Personne> conteneur;
        void inscrire(Personne p);
        void desabonner(Personne p);
        bool recherche(Personne p);
        void afficher();
};

#endif
