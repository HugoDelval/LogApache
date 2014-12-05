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
static const char SEP1='1';
static const char SEP2='-';
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


tm InfosLigne::Getdate() const {
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

int InfosLigne::GetStatus() const {
    return status;
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

istream & operator>>(istream &is, InfosLigne &ligne)
{
    string chaineDate;
    string chaineStatus;
    string chaineQuantiteTransferee;
    getline(is,ligne.addresseIP);
    getline(is,ligne.user);
    getline(is,ligne.logName);
    getline(is,chaineDate);
    getline(is,ligne.action);
    getline(is,ligne.protocole);
    getline(is,ligne.urlDemandee);
    getline(is,chaineStatus);
    getline(is,chaineQuantiteTransferee);
    getline(is,ligne.urlReferent);
    getline(is,ligne.navigateur);

    //par defaut \n

    return is;
} //----- Fin de operator >>


//-------------------------------------------- Constructeurs - destructeur


InfosLigne::InfosLigne ( string addresseIPLigne,string userLigne,string logNameLigne, string actionLigne,
                string protocoleLigne, string urlDemandeeLigne, int statusLigne,
                    string urlReferentLigne, string navigateurLigne, int quantiteTransfereeLigne,tm dateLigne )
{
    addresseIP=addresseIPLigne;
    user=userLigne;
    logName=logNameLigne;
    date=dateLigne;
    action=actionLigne;
    protocole=protocoleLigne;
    urlDemandee=urlDemandeeLigne;
    status=statusLigne;
    urlReferent=urlReferentLigne;
    navigateur=navigateurLigne;
    quantiteTransferee=quantiteTransfereeLigne;

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

