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

//------------------------------------------------------ Include personnel
#include "InfosLigne.h"

//------------------------------------------------------------- Constantes
static const char SEP1='/';
static const char SEP2='[';
static const char SEP3=']';
static const char SEP4=':';
static const char SEP5='"';

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


tm InfosLigne::GetDate() const {
    return date;
}

string InfosLigne::GetDiffGTM() const {
    return diffGTM;
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

int InfosLigne::GetQuantiteTransferee() const {
    return quantiteTransferee;
}


// type InfosLigne::Methode ( liste de parametres )
// Algorithme :
//
//{
//} //----- Fin de Methode


//------------------------------------------------- Surcharge d'operateurs

istream & operator>>(istream &is, InfosLigne &ligne)
{
    string jour;
    string mois;
    string annee;
    string heure;
    string minute;
    string seconde;
    string chaineStatus;
    string chaineQuantiteTransferee;
    string poubelle;

    getline(is,ligne.addresseIP,' ');
    getline(is,ligne.user,' ');
    getline(is,ligne.logName,' ');
    getline(is,poubelle,SEP2);
    getline(is,jour,SEP1);
    getline(is,mois,SEP1);
    getline(is,annee, SEP1);
    getline(is,poubelle,SEP4);
    getline(is,heure,SEP4);
    getline(is,minute,SEP4);
    getline(is,seconde,' ');
    getline(is,ligne.diffGTM, SEP3);
    getline(is,poubelle,SEP5);
    getline(is,ligne.action,' ');
    getline(is,ligne.urlDemandee,' ');
    getline(is,ligne.protocole,SEP5);
    getline(is,poubelle,' ');
    getline(is,chaineStatus,' ');
    getline(is,chaineQuantiteTransferee,' ');
    getline(is,poubelle,SEP5);
    getline(is,ligne.urlReferent,SEP5);
    getline(is,poubelle,SEP5);
    getline(is,ligne.navigateur,SEP5);
    getline(is, poubelle);

    ligne.date.tm_mday= atoi(jour.c_str());
    ligne.date.tm_mon= atoi(mois.c_str());
    ligne.date.tm_year=atoi(annee.c_str());
    ligne.date.tm_hour=atoi(heure.c_str());
    ligne.date.tm_min= atoi(minute.c_str());
    ligne.date.tm_sec= atoi(seconde.c_str());

    ligne.status=atoi(chaineStatus.c_str());
    ligne.quantiteTransferee=atoi(chaineQuantiteTransferee.c_str());


    return is;
} //----- Fin de operator >>


//-------------------------------------------- Constructeurs - destructeur
InfosLigne::InfosLigne ()
{
}

InfosLigne::InfosLigne ( string addresseIPLigne,string userLigne,string logNameLigne, string actionLigne,
                string protocoleLigne, string urlDemandeeLigne, int statusLigne, string diffGTMLigne,
                    string urlReferentLigne, string navigateurLigne, int quantiteTransfereeLigne,tm dateLigne )
{
    addresseIP=addresseIPLigne;
    user=userLigne;
    logName=logNameLigne;
    date=dateLigne;
    diffGTM=diffGTMLigne;
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

