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
    string GetAddresseIP();
    string GetUser();
    string GetLogName();
    time_t GetDate();
    string GetAction();
    string GetProtocole();
    string GetUrlDemandee();
    string GetStatus();
    int GetQuantiteeTransferee();
    string GetUrlReferent();
    string GetNavigateur();


    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'operateurs
    InfosLigne & operator = ( const InfosLigne & unInfosLigne );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    InfosLigne ( string addresseIPLigne,string userLigne,string logNameLigne,time_t dateLigne,
            string actionLigne,string protocoleLigne, string urlDemandeeLigne,
            string statusLigne,int quantiteeTransfereeLigne,string urlReferentLigne,
            string navigateurLigne);
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
    time_t date;
    string action;
    string protocole;
    string urlDemandee;
    string status;
    int quantiteeTransferee;
    string urlReferent;

private:
    string navigateur;
//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privees

//----------------------------------------------------------- Types prives

};

//----------------------------------------- Types dependants de <InfosLigne>

#endif // INFOS_LIGNE_H
