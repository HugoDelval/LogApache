/*************************************************************************
InfosLigne  -  Represente une ligne du fichier Log
-------------------
debut                : 04/12/2014
copyright            : (C) 2014 par PAPIN/DELVAL
*************************************************************************/

//---------- Interface de la classe <InfosLigne> (fichier InfosLigne.h) ------
#if ! defined ( INFOS_LIGNE_H )
#define INFOS_LIGNE_H

//--------------------------------------------------- Interfaces utilisees
#include <string.h>
#include <time.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Role de la classe <InfosLigne>
//      La classe contient contient toutes les informations possibles contenues dans une ligne du fichier Log (sous forme d'attributs)
//      Les autres classes peuvent acceder a ces informations grace a des accesseurs.
//      Cette classe participe a la genericite de l'application puisqu'elle stocke absolument toutes les informations d'une ligne.
//
//------------------------------------------------------------------------ 

class InfosLigne
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Methodes publiques

    /*
        acceseurs a tous les attributs de l'InfosLigne
    */
    string GetAddresseIP() const;
    string GetUser()const;
    string GetLogName()const;
    tm GetDate()const;
    string GetDiffGTM()const;
    string GetAction()const;
    string GetProtocole()const;
    string GetUrlDemandee()const;
    int GetStatus()const;
    int GetQuantiteTransferee()const;
    string GetUrlReferent()const;
    string GetNavigateur()const;

//------------------------------------------------- Surcharge d'operateurs

//-------------------------------------------- Constructeurs - destructeur
    InfosLigne ();
    // Mode d'emploi :
    //      Construit un objet InfosLigne en initialisant les attributs entier a 0, les chaine de caracteres
    //             vide et Date avec le constructeur par defaut de la structure 'tm'
    // Contrat :
    //      l' InfosLigne est correctement construit

    virtual ~InfosLigne ( );
    // Mode d'emploi :
    //      Detruit l'InfosLigne
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
    string addresseIP;      //adresse IP contenue dans la ligne
    string user;            //nom d'utilisateur contenu dans la ligne
    string logName;         //nom du login contenu dans la ligne
    tm date;                //date de la requete contenue dans la ligne
    string diffGTM;         //decalage horaire de la date par rapport au GMT contenu dans la ligne
    string action;          //type de requette contenu dans la ligne
    string protocole;       //protocole contenu dans la ligne
    string urlDemandee;     //URL demandee contenue dans la ligne
    int status;             //status de la requete contenu dans la ligne
    int quantiteTransferee; //quantite de donnees transferees contenue dans la ligne
    string urlReferent;     //URL du referent contenue dans la ligne
    string navigateur;      //navigateur utilise contenu dans la ligne
//---------------------------------------------------------- Classes amies
friend istream & operator>>(istream &is, InfosLigne &ligne);
    // surcharge d'operateur >> pour stocker les donnees contenues dans une ligne du fichier dans les attributs
    //      de l'InfosLigne correspondante

friend class Log;

//-------------------------------------------------------- Classes privees

//----------------------------------------------------------- Types prives

};

#endif // INFOS_LIGNE_H
