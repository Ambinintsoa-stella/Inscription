#include <iostream>
#include <vector>
#include <algorithm>
#include "Liste.hpp"
using namespace std;
Liste::Liste()
{

}
Liste::~Liste()
{

}
void Liste::inscrire(Personne p)
{
    //cout << "\n\tAjout de "  << p.getName() << endl;
    conteneur.push_back(p);
}
bool Liste::recherche(Personne p)
{
    cout << "\n\tRecherche de " << p.getName() << endl;
    for (vector<Personne>::iterator i = conteneur.begin(); i!=conteneur.end(); ++i)
    {
        if ((i->getName()==p.getName()) && (i->getId()==p.getId()))
        {
            cout << "Name: " << i->getName() << endl;
            cout << "Id: " << i->getId() << endl;
            return (true);
        }
    }
    cout << p.getName() << " Not found" << endl;
    return (false);

}
void Liste::desabonner(Personne p)
{
    //cout << "\n\tSuppression de "  << p.getName() << endl;
    if (recherche(p))
    {
        auto i = find(conteneur.begin(), conteneur.end(), p);
        conteneur.erase (i);
    }
    else if (recherche(p)==false)
    {
        //cout << "not found" << endl;
    }
}
void Liste::afficher()
{
    cout << "\n\tAffichage liste: " << endl;
    for(vector<Personne>::iterator i =conteneur.begin(); i!=conteneur.end(); ++i)
    {
        cout << i->getName() << endl;
    }
}
