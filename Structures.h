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
struct Document {
    string nomDocument;
    int nbAcces;
    Document(string nom="nomParDefaut", int nb=0):nomDocument(nom), nbAcces(nb){}

};
//------------------------------------------------------------------------

#endif // STRUCTURES_H
