/*************************************************************************
InfosLigne  -  description
-------------------
debut                : date
copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Realisation de la classe <InfosLigne> (fichier InfosLigne.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systeme
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "InfosLigne.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types prives


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Methodes publiques


public:


    string &getAddresseIP() const {
        return addresseIP;
    }

    string &getUser() const {
        return user;
    }

    string &getLogName() const {
        return logName;
    }

    time_t getDate() const {
        return date;
    }

    string &getAction() const {
        return action;
    }

    string &getProtocole() const {
        return protocole;
    }

    string &getUrlDemandee() const {
        return urlDemandee;
    }

    string &getStatus() const {
        return status;
    }

    int getQuantiteeTransferee() const {
        return quantiteeTransferee;
    }

    string &getUrlReferent() const {
        return urlReferent;
    }

    string &getNavigateur() const {
        return navigateur;
    }



// type InfosLigne::Methode ( liste de parametres )
// Algorithme :
//
//{
//} //----- Fin de Methode


//------------------------------------------------- Surcharge d'operateurs
InfosLigne & InfosLigne::operator = ( const InfosLigne & unInfosLigne )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
InfosLigne::InfosLigne ( const InfosLigne & unInfosLigne )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <InfosLigne>" << endl;
#endif
} //----- Fin de InfosLigne (constructeur de copie)


InfosLigne::InfosLigne ( string addresseIP,string user,string logName,time_t date,string action,string protocole,
                                string urlDemandee,string status,int quantiteeTransferee,string urlReferent,string navigateur;)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <${InfosLigne}>" << endl;
#endif
} //----- Fin de InfosLigne


InfosLigne::~InfosLigne ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <file_bas}>" << endl;
#endif
} //----- Fin de ~InfosLigne


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Methodes protegees

//------------------------------------------------------- Methodes privees
