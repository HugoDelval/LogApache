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
string InfosLigne::GetAddresseIP() const{
    return addresseIP;
}

string InfosLigne::GetUser() const {
    return user;
}

string InfosLigne::GetLogName() const {
    return logName;
}

time_t InfosLigne::GetDate() const {
    return date;
}

string InfosLigne::GetAction() const {
    return action;
}

string InfosLigne::GetProtocole() const {
    return protocole;
}

string InfosLigne::GetUrlDemandee() const {
    return urlDemandee;
}

string InfosLigne::GetStatus() const {
    return status;
}

int InfosLigne::GetQuantiteeTransferee() const {
    return quantiteeTransferee;
}

string InfosLigne::GetUrlReferent() const {
    return urlReferent;
}

string InfosLigne::GetNavigateur() const {
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

