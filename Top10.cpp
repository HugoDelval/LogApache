/*************************************************************************
Top10  -  description
-------------------
debut                : date
copyright            : (C) year par user
*************************************************************************/

//---------- Interface de la classe <Top10> (fichier Top10.cpp) ------
#if ! defined ( XXX_H )
#define XXX_H

//--------------------------------------------------- Interfaces utilisees

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Role de la classe <Top10>
//
//
//------------------------------------------------------------------------ 

class Top10 : public Ancetre
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
    Top10 & operator = ( const Top10 & unTop10 );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Top10 ( const Top10 & unTop10 );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Top10 ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Top10 ( );
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

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privees

//----------------------------------------------------------- Types prives

};

//----------------------------------------- Types dependants de <Top10>

#endif // XXX_H
