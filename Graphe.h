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
#include <iostream>
#include "Log.h"
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

    Graphe (string bUrl, Log &unLog, int heure, bool xFlag=false, ostream& direction=cout, bool fichierDot=false);
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
    void initialiserGraphe(Log &unLog, int heure, bool xFlag, bool fichierDot);
    string nettoyer(string stringANettoyer);
    void genererFichier(ostream &direction);
    bool xFlagCompatible(string cib);
    void afficherTop10();

private:
//------------------------------------------------------- Attributs prives
    typedef map<string, Arc> DicoIdArc;      // id, arc
    typedef set<int> EnsembleNumNoeud;       // label, pour verifier si le noeud a deja ete insere dans le fichier (utile seulement quand on rempli un fichier)
    typedef map<string, Document*> DicoNomDocument;
    typedef list<Document*> ListeDoc;
    DicoIdArc dicoIdArc;
    EnsembleNumNoeud traceLabels;
    string baseUrl;
    DicoNomDocument dicoNomDoc;
    ListeDoc listeDocTrieeSelonVisites;

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privees

//----------------------------------------------------------- Types prives

};

//----------------------------------------- Types dependants de <Graphe>

#endif // GRAPHE_H
