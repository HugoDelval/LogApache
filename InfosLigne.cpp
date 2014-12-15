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
const int JANVIER=0;
const int FEVRIER=1;
const int MARS=2;
const int AVRIL=3;
const int MAI=4;
const int JUIN=5;
const int JUILLET=6;
const int AOUT=7;
const int SEPTEMBRE=8;
const int OCTOBRE=9;
const int NOMVEMBRE=10;
const int DECEMBRE=11;

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

//------------------------------------------------- Surcharge d'operateurs
int trouveMois(string mois);

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

    return is;
}//----- Fin de operator >>


//-------------------------------------------- Constructeurs - destructeur
InfosLigne::InfosLigne ()
{
    addresseIP="";
    user="";
    logName="";
    date=tm();
    diffGTM="";
    action="";
    protocole="";
    urlDemandee="";
    status=0;
    quantiteTransferee=0;
    urlReferent="";
    navigateur="";
}


InfosLigne::~InfosLigne ( )
{
    addresseIP.clear();
    user.clear();
    logName.clear();
    diffGTM.clear();
    action.clear();
    protocole.clear();
    urlDemandee.clear();
    urlReferent.clear();
    navigateur.clear();

#ifdef MAP
    cout << "Appel au destructeur de InfosLigne" << endl;
#endif
} //----- Fin de ~InfosLigne


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Methodes protegees

//------------------------------------------------------- Methodes privees
int trouveMois(string mois)
{
    int res(-1);

    if(mois.compare("Jan"))
    {
        res = JANVIER;
    }
    else
    {
        if(mois.compare("Feb"))
        {
            res = FEVRIER;
        }
        else
        {
            if (mois.compare("Mar"))
            {
                res = MARS;
            }
            else
            {
                if(mois.compare("Apr"))
                {
                    res = AVRIL;
                }
                else
                {
                    if (mois.compare("May"))
                    {
                        res = MAI;
                    }
                    else
                    {
                        if (mois.compare("Jun"))
                        {
                            res = JUIN;
                        }
                        else
                        {
                            if (mois.compare("Jul"))
                            {
                                res = JUILLET;
                            }
                            else
                            {
                                if (mois.compare("Aug"))
                                {
                                    res = AOUT;
                                }
                                else
                                {
                                    if (mois.compare("Sep"))
                                    {
                                        res = SEPTEMBRE;
                                    }
                                    else
                                    {
                                        if (mois.compare("Oct"))
                                        {
                                            res = OCTOBRE;
                                        }
                                        else
                                        {
                                            if (mois.compare("Nov"))
                                            {
                                                res = NOMVEMBRE;
                                            }
                                            else
                                            {
                                                if (mois.compare("Dec"))
                                                {
                                                    res = DECEMBRE;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return res;
}
