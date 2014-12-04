/*************************************************************************
Graphe  -  description
-------------------
debut                : date
copyright            : (C) year par user
*************************************************************************/

//---------- Interface de la classe <Graphe> (fichier Graphe.cpp) ------
#if ! defined ( XXX_H )
#define XXX_H

//--------------------------------------------------- Interfaces utilisees

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Role de la classe <Graphe>
//
//
//------------------------------------------------------------------------ 

class Graphe : public Ancetre
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
    Graphe & operator = ( const Graphe & unGraphe );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Graphe ( const Graphe & unGraphe );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Graphe ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Graphe ( );
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

//----------------------------------------- Types dependants de <Graphe>

#endif // XXX_H
