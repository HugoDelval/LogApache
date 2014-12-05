/*************************************************************************
Graphe  -  represente un graphe, compose d'arcs et de documents
-------------------
debut                : 04/12/2014
copyright            : (C) 2014 par PAPIN/DELVAL
*************************************************************************/

//---------- Interface de la classe <Graphe> (fichier Graphe.h) ------
#if ! defined ( GRAPHE_H )
#define GRAPHE_H

//--------------------------------------------------- Interfaces utilisees
#include <map>
#include <set>
#include <string>
#include "Log.h"
#include "Top10.h"
#include "Structures.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Role de la classe <Graphe>
//
//
//------------------------------------------------------------------------

class Graphe
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
    Graphe ( const Graphe & unGraphe );
    // Mode d'emploi (constructeur de copie) :
    //      ne sert pour l'instant qu'a interdire le constructeur de copie (pas d'implementation dans le .cpp)
    // Contrat :
    //

    Graphe (Log &unLog, int typeCommande=0 );
    // Mode d'emploi :
    //      construit un objet Graphe grace aux infos contenus dans le Log, selectionne et traite les infos interessantes
    // Contrat :
    //      le Log est correctement construit

    virtual ~Graphe ( );
    // Mode d'emploi :
    //      detruit le Graphe et tous les objets associes
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

private:
//------------------------------------------------------- Methodes privees


private:
//------------------------------------------------------- Attributs prives
    typedef map<string, Arc*> DicoIdArc;     // id, arc
    typedef set<string> EnsembleLabel;       // label, pour verifier si le noeud a deja ete insere dans le fichier (utile seulement quand on rempli un fichier)
    DicoIdArc dicoIdArc;
    EnsembleLabel traceLabels;
    Top10 monTop10;

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privees

//----------------------------------------------------------- Types prives

};

//----------------------------------------- Types dependants de <Graphe>

#endif // GRAPHE_H
