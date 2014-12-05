/*************************************************************************
Top10  -  description
-------------------
debut                : 04/12/2014
copyright            : (C) 2014 par PAPIN/DELVAL
*************************************************************************/

//---------- Interface de la classe <Top10> (fichier Top10.h) ------
#if ! defined ( TOP10_H )
#define TOP10_H

//--------------------------------------------------- Interfaces utilisees
#include <list>
#include <map>
#include <string>
#include "Log.h"
#include "Structures.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Role de la classe <Top10>
//      la classe permet de gerer les 10 ressources les plus affichees
//
//------------------------------------------------------------------------

class Top10
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Methodes publiques
    // type Methode ( liste de parametres );
    // Mode d'emploi :
    //
    // Contrat :
    //



//-------------------------------------------- Constructeurs - destructeur

    Top10 ( Log &unLog, bool xFlag=false, bool tFlag=false, bool gFlag=false, string argTFflag="", string argGFlag="" );
    // Mode d'emploi :
    //    construit un objet Top10 grace aux infos contenus dans le Log, selectionne et traite les infos interessantes
    // Contrat :
    //    le Log est correctement construit

    virtual ~Top10 ( );
    // Mode d'emploi :
    //    detruit le Top10 et tous les objets associes
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

private:
//------------------------------------------------------- Methodes privees

private:
//------------------------------------------------------- Attributs prives
    typedef map<string, Document*> DicoNomDocument;
    typedef list<Document*> ListeDoc;
    DicoNomDocument dicoNomDoc;
    ListeDoc listeDocTrieeSelonVisites;

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privees

//----------------------------------------------------------- Types prives

};

//----------------------------------------- Types dependants de <Top10>

#endif // TOP10_H
