/*************************************************************************
InfosLigne  -  description
-------------------
debut                : 04/12/2014
copyright            : (C) 2014 par PAPIN/DELVAL
*************************************************************************/

//---------- Realisation de la classe <InfosLigne> (fichier InfosLigne.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systeme
using namespace std;

//------------------------------------------------------ Include personnel
#include "InfosLigne.h"

//------------------------------------------------------------- Constantes
static const char SEP_SLASH ='/';
static const char SEP_CROCHET_OUVRANT ='[';
static const char SEP_CROCHET_FERMANT =']';
static const char SEP_DEUX_POINTS =':';
static const char SEP_GUILLEMET ='"';

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types prives


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Methodes publiques

int trouveMois(string mois);

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
    getline(is,poubelle, SEP_CROCHET_OUVRANT);
    getline(is,jour, SEP_SLASH);
    getline(is,mois, SEP_SLASH);
    getline(is,annee, SEP_DEUX_POINTS);
    getline(is,heure, SEP_DEUX_POINTS);
    getline(is,minute, SEP_DEUX_POINTS);
    getline(is,seconde,' ');
    getline(is,ligne.diffGTM, SEP_CROCHET_FERMANT);
    getline(is,poubelle, SEP_GUILLEMET);
    getline(is,ligne.action,' ');
    getline(is,ligne.urlDemandee,' ');
    getline(is,ligne.protocole, SEP_GUILLEMET);
    getline(is,poubelle,' ');
    getline(is,chaineStatus,' ');
    getline(is,chaineQuantiteTransferee,' ');
    getline(is,poubelle, SEP_GUILLEMET);
    getline(is,ligne.urlReferent, SEP_GUILLEMET);
    getline(is,poubelle, SEP_GUILLEMET);
    getline(is,ligne.navigateur, SEP_GUILLEMET);
    getline(is, poubelle);

    ligne.date.tm_mday= atoi(jour.c_str());
    ligne.date.tm_mon= trouveMois(mois);
    ligne.date.tm_year=atoi(annee.c_str());
    ligne.date.tm_hour=atoi(heure.c_str());
    ligne.date.tm_min= atoi(minute.c_str());
    ligne.date.tm_sec= atoi(seconde.c_str());

    ligne.status=atoi(chaineStatus.c_str());
    ligne.quantiteTransferee=atoi(chaineQuantiteTransferee.c_str());
/*
    cout<<"ip:"<<ligne.addresseIP<<'.'<<endl;
    cout<<"mois:"<<mois<<'.'<<endl;
    cout<<"heure:"<<ligne.date.tm_hour<<'.'<<endl;
    cout<<"sec:"<<ligne.date.tm_sec<<'.'<<endl;
    cout<<"ref:"<<ligne.urlReferent<<'.'<<endl;
    cout<<"cib:"<<ligne.urlDemandee<<'.'<<endl;
    cout<<"navigateur:"<<ligne.navigateur<<'.'<<endl;
    cout<<"poubelle:"<<endl<<poubelle<<'.'<<endl;
*/

    return is;
}//----- Fin de operator >>


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
int trouveMois(string mois)
{
    int res=0;
    if(mois.compare("Jan"))
        res=0;
    else if(mois.compare("Feb"))
        res=1;
    else if(mois.compare("Mar"))
        res=2;
    else if(mois.compare("Apr"))
        res=3;
    else if(mois.compare("May"))
        res=4;
    else if(mois.compare("Jun"))
        res=5;
    else if(mois.compare("Jul"))
        res=6;
    else if(mois.compare("Aug"))
        res=7;
    else if(mois.compare("Sep"))
        res=8;
    else if(mois.compare("Oct"))
        res=9;
    else if(mois.compare("Nov"))
        res=10;
    else if(mois.compare("Dec"))
        res=11;

    return res;
}
