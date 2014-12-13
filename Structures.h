/*************************************************************************
Structures.h  -  permet d'inclure la declaration des structures simple telles qu'un document ou un arc
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
{
    std::string NomDocument;
    int NbAcces;
    Document(std::string nom="nomParDefaut", int nb=1):
            NomDocument(nom), NbAcces(nb){}
};
struct Arc
{
    std::string IdArc;
    int NbParcours;
    Document* Refer;
    Document* Cible;
    Arc(Document* ref, Document* cib, int nb=1, std::string id=""):
            Refer(ref), Cible(cib), NbParcours(nb), IdArc(id){}
};
//------------------------------------------------------------------------

#endif // STRUCTURES_H
