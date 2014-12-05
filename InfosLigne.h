/*************************************************************************
InfosLigne  -  description
-------------------
debut                : date
copyright            : (C) year par user
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
//
//
//------------------------------------------------------------------------ 

class InfosLigne
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Methodes publiques
    string GetAddresseIP() const;
    string GetUser()const;
    string GetLogName()const;
    tm Getdate()const;
    string GetAction()const;
    string GetProtocole()const;
    string GetUrlDemandee()const;
    int GetStatus()const;
    int GetQuantiteTransferee()const;
    string GetUrlReferent()const;
    string GetNavigateur()const;

    friend istream & operator>>(istream &is, InfosLigne &ligne);

    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'operateurs
   // istream & operator>>(istream &is, const InfosLigne &ligne);
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    InfosLigne ( string addresseIPLigne,string userLigne,string logNameLigne, string actionLigne,
            string protocoleLigne, string urlDemandeeLigne, int statusLigne,
            string urlReferentLigne, string navigateurLigne, int quantiteTransfereeLigne,tm dateLigne);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~InfosLigne ( );
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
    string addresseIP;
    string user;
    string logName;
    tm date;
    string action;
    string protocole;
    string urlDemandee;
    int status;
    int quantiteTransferee;
    string urlReferent;
    string navigateur;
//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privees

//----------------------------------------------------------- Types prives

};

//----------------------------------------- Types dependants de <InfosLigne>

#endif // INFOS_LIGNE_H
