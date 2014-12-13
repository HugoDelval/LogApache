/*************************************************************************
Log  -  description
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
//
//
//------------------------------------------------------------------------

class Log {
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Methodes publiques
    // Mode d'emploi :
    //
    // Contrat :
    //

    list<InfosLigne> GetListeLignes() const;
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Log(istream& file);

    virtual ~Log();
    // Mode d'emploi :
    //
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
    list<InfosLigne> listeLignes;
//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privees

//----------------------------------------------------------- Types prives
};
//----------------------------------------- Types dependants de <Log>

#endif // LOG_H
