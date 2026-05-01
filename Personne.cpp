#include <iostream>
#include "Personne.hpp"
using namespace std;
Personne::Personne()
{

}
Personne::~Personne()
{

}
void Personne::setName(string n)
{
    name=n;
}
string Personne::getName()
{
    return (name);
}
void Personne::setId(string pwd)
{
    id=pwd;
}
string Personne::getId()
{
    return (id);
}
bool Personne::operator==(const Personne& autre) const
{
    return name == autre.name && id == autre.id;
}
