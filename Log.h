/*************************************************************************
file_base  -  description
-------------------
debut                : date
copyright            : (C) year par user
*************************************************************************/

//---------- Interface de la classe <file_base> (fichier file_name) ------
#if ! defined ( XXX_H )
#define XXX_H

//--------------------------------------------------- Interfaces utilisees

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Role de la classe <file_base>
//
//
//------------------------------------------------------------------------

class file_base : public Ancetre
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
    file_base & operator = ( const file_base & unfile_base );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    file_base ( const file_base & unfile_base );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    file_base ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~file_base ( );
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

//----------------------------------------- Types dependants de <file_base>

#endif // XXX_H
