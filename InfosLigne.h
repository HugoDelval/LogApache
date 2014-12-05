/*************************************************************************
InfosLigne  -  description
-------------------
debut                : date
copyright            : (C) year par user
*************************************************************************/

//---------- Interface de la classe <InfosLigne> (fichier InfosLigne.h) ------
#if ! defined ( XXX_H )
#define XXX_H

//--------------------------------------------------- Interfaces utilisees

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Role de la classe <InfosLigne>
//
//
//------------------------------------------------------------------------ 

class InfosLigne : public Ancetre
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Methodes publiques
    // type Methode ( liste de parametres );
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
    InfosLigne ( const InfosLigne & unInfosLigne );

    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    InfosLigne ( );
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

#endif // XXX_H
