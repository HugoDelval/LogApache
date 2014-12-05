/*************************************************************************
Log  -  description
-------------------
debut                : date
copyright            : (C) year par user
*************************************************************************/

//---------- Interface de la classe <Log> (fichier Log.h) ------
#if ! defined ( XXX_H )
#define XXX_H

//--------------------------------------------------- Interfaces utilisees
#include <string.h>
#include <time.h>
#include <list>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

typedef struct AVLTreeNode* ptrOnAVLTreeNode;

//------------------------------------------------------------------------
// Role de la classe <Log>
//
//
//------------------------------------------------------------------------

class Log
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Methodes publiques
    // void Log::LireFichier ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    InfosLigne &getListeLignes() const;

//------------------------------------------------- Surcharge d'operateurs
    Log & operator = ( const Log & unLog );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Log ( const Log & unLog );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Log ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Log ( );
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

//----------------------------------------- Types dependants de <Log>

#endif // XXX_H
