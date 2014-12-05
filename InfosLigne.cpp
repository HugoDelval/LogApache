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
string InfosLigne::GetAddresseIP()  {
    return addresseIP;
}

string InfosLigne::GetUser()  {
    return user;
}

string InfosLigne::GetLogName()  {
    return logName;
}

time_t InfosLigne::GetDate()  {
    return date;
}

string InfosLigne::GetAction()  {
    return action;
}

string InfosLigne::GetProtocole()  {
    return protocole;
}

string InfosLigne::GetUrlDemandee()  {
    return urlDemandee;
}

string InfosLigne::GetStatus()  {
    return status;
}

int InfosLigne::GetQuantiteeTransferee()  {
    return quantiteeTransferee;
}

string InfosLigne::GetUrlReferent()  {
    return urlReferent;
}

string InfosLigne::GetNavigateur()  {
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

