/*************************************************************************
Graphe  -  Represente un graphe, compose d'arcs et de documents
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
//      Cette classe selectionne, dans l'objet Log, et stocke les informations necessaires
//              a la generation du script du graph et a l'affichage du top 10, en fonction
//              des options selectionnee par l'utilisateur.
//      La classe permet aussi d'afficher le top 10 et de generer le fichier contenant
//              le script de creation du graph.
//
//------------------------------------------------------------------------

class Graphe
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Methodes publiques


//-------------------------------------------- Constructeurs - destructeur

    Graphe (string bUrl, Log &unLog, int heure, bool xFlag=false, ostream& direction=cout, bool fichierDot=false);
    // Mode d'emploi :
    //      Construit un objet Graphe grace aux infos contenus dans le Log, selectionne et traite les infos interessantes
    // Contrat :
    //      Le Log est correctement construit

    virtual ~Graphe ( );
    // Mode d'emploi :
    //      Detruit le Graphe et tous les objets associes (en faisant attention aux pointeurs)
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

private:
//------------------------------------------------------- Methodes privees
    void initialiserGraphe(Log &unLog, int heure, bool xFlag, bool fichierDot);
    // Mode d'emploi :
    //       Initialise le graphe en lisant le log et en ne selectionnant que les infos correspondantes a l'heure le xFlag
    //       Remplissage de l'architecture correspondante au dot si fichierDot=true
    // Contrat :
    //

    void nettoyer(string &stringANettoyer) const;
    // Mode d'emploi :
    //      Nettoie l'url : supprime l'url de base, les options, etc... et renvoie la partie de l'URL dont
    //              on a besoin pour l'application.
    // Contrat :
    //

    void genererFichier(ostream &direction) const;
    // Mode d'emploi :
    //      Ecrit les informations dans le fichier output stream en parametre.
    // Contrat :
    //

    bool xFlagCompatible(const string &cib) const;
    // Mode d'emploi :
    //       Determine si l'extension est autorisee (elle est non autorisee si c'est une extension d'image).
    //              Retourne false si c'est une image
    //              Retourne vrai si ca n'est pas une image
    // Contrat :
    //

    void afficherTop10();
    // Mode d'emploi :
    //      Affiche a la sortie standard le top10 des ressources les plus consultees.

    // Contrat :
    //

private:
//------------------------------------------------------- Attributs prives
    typedef map<string, Arc> DicoIdArc;                  // map d'Arcs identifies par l'IdArc de l'Arc
    typedef map<string, Document*> DicoNomDocument;      // map de pointeurs vers des Document identifies par le NomDocument du Document
    typedef list<Document*> ListeDoc;                    // liste  des Document
    DicoIdArc dicoIdArc;
    string baseUrl;                                      // base de l'URL
    DicoNomDocument dicoNomDoc;
    ListeDoc listeDocTrieeSelonVisites;

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privees

//----------------------------------------------------------- Types prives

};

//----------------------------------------- Types dependants de <Graphe>

#endif // GRAPHE_H
