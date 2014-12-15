/*************************************************************************
Structures.h  -  Permet d'inclure la declaration des structures simples telles qu'un document ou un arc
-------------------
debut                : 04/12/2014
copyright            : (C) 2014 par PAPIN/DELVAL
*************************************************************************/

#if ! defined ( STRUCTURES_H )
#define STRUCTURES_H

//--------------------------------------------------- Interfaces utilisees
#include <string.h>

//------------------------------------------------------------------ Types
struct Document
/*
Represente un document echange entre le serveur et l'utilisateur
Une entite dans le graph genere par l'application
 */
{
    std::string NomDocument;            // cle d'un Document
    int NbAcces;                        // nombre d'acces a ce Document
    Document(std::string nom="nomParDefaut", int nb=1):
            NomDocument(nom), NbAcces(nb){}
};



struct Arc
/*
Represente un lien entre un Document referent et un Document cible
Un arc associe a une cadinalite dans le graph genere par l'application
 */
{
    std::string IdArc;      // cle d'un Arc
    int NbParcours;         // nombre de lien (dans ce sens) entre un referent et une cible
    Document* Refer;        // Document referent
    Document* Cible;        // Document cible
    Arc(Document* ref, Document* cib, int nb=1, std::string id=""):
            Refer(ref), Cible(cib), NbParcours(nb), IdArc(id){}
};
//------------------------------------------------------------------------

#endif // STRUCTURES_H
