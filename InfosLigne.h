/*************************************************************************
InfosLigne  -  description
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
//
//
//------------------------------------------------------------------------ 

class InfosLigne
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Methodes publiques

    /*
        retourne les informations lues dans le fichier log
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

    virtual ~InfosLigne ( );

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
    string diffGTM;
    string action;
    string protocole;
    string urlDemandee;
    int status;
    int quantiteTransferee;
    string urlReferent;
    string navigateur;
//---------------------------------------------------------- Classes amies
friend istream & operator>>(istream &is, InfosLigne &ligne);
friend class Log;

//-------------------------------------------------------- Classes privees

//----------------------------------------------------------- Types prives

};

//----------------------------------------- Types dependants de <InfosLigne>

#endif // INFOS_LIGNE_H
