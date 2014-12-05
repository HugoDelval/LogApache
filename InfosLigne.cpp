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
string& InfosLigne::getAddresseIP() const {
    return addresseIP;
}

string& InfosLigne::getUser() const {
    return user;
}

string& InfosLigne::getLogName() const {
    return logName;
}

time_t InfosLigne::getDate() const {
    return date;
}

string& InfosLigne::getAction() const {
    return action;
}

string& InfosLigne::getProtocole() const {
    return protocole;
}

string& InfosLigne::getUrlDemandee() const {
    return urlDemandee;
}

string& InfosLigne::getStatus() const {
    return status;
}

int InfosLigne::getQuantiteeTransferee() const {
    return quantiteeTransferee;
}

string& InfosLigne::getUrlReferent() const {
    return urlReferent;
}

string& InfosLigne::getNavigateur() const {
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


InfosLigne::InfosLigne ( string addresseIPLigne,string userLigne,string logNameLigne,time_t dateLigne,
        string actionLigne,string protocoleLigne, string urlDemandeeLigne,
        string statusLigne,int quantiteeTransfereeLigne,string urlReferentLigne,
        string navigateurLigne)
{
    addresseIP=addresseIPLigne;
    user=userLigne;
    logName=logNameLigne;
    date=dateLigne;
    action=actionLigne;
    protocole=protocoleLigne;
    urlDemandee=urlDemandeeLigne;
    status=statusLigne;
    quantiteeTransferee=quantiteeTransfereeLigne;
    urlReferent=urlReferentLigne;
    navigateur=navigateurLigne;
}

#ifdef MAP
    cout << "Appel au constructeur de <InfosLigne>" << endl;
#endif
} //----- Fin de InfosLigne


InfosLigne::~InfosLigne ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de InfosLigne" << endl;
#endif
} //----- Fin de ~InfosLigne


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Methodes protegees

//------------------------------------------------------- Methodes privees

