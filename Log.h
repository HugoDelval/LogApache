/*************************************************************************
Log  -  Represente le fichier Log complet
-------------------
debut                : 04/12/2014
copyright            : (C) 2014 par PAPIN/DELVAL
*************************************************************************/

//---------- Interface de la classe <Log> (fichier Log.h) ------
#if ! defined ( LOG_H )
#define LOG_H

//--------------------------------------------------- Interfaces utilisees
#include <time.h>
#include <list>
#include <iostream>
#include <fstream>
#include "InfosLigne.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Role de la classe <Log>
//      La classe contient contient toutes les informations contenues dans le fichier Log sous la forme d'une liste
//              d'InfosLigne.
//      Les autres classes peuvent acceder a ces informations grace a un accesseur.
//      Cette classe participe a la genericite de l'application puisqu'elle stocke absolument toutes les lignes et donc
//           toutes les informations possibles du fichier Log.
//
//------------------------------------------------------------------------

class Log {
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Methodes publiques

    list<InfosLigne> GetListeLignes() const;

//-------------------------------------------- Constructeurs - destructeur
    Log(istream& file);
    // Mode d'emploi :
    //         Construit un objet Log en ajoutant a la liste 'listeLignes' toutes
    //              les Infosligne, donc toutes les lignes contenues dans le fichier
    //                 Log (input stream en parametre)
    // Contrat :
    //      Le Log est correctement construit


    virtual ~Log();
    // Mode d'emploi :
    //      Detruit le Log
    // Contrat :
    //


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Methodes protegees

private:
//------------------------------------------------------- Methodes privees

protected:
//----------------------------------------------------- Attributs proteges

private:
//------------------------------------------------------- Attributs prives
    list<InfosLigne> listeLignes; //liste d'InfosLigne qui contient l'ensemble des informations
                                  //        du fichier Log
//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privees

//----------------------------------------------------------- Types prives
};
//----------------------------------------- Types dependants de <Log>

#endif // LOG_H
