/*************************************************************************
Log  -  description
-------------------
debut                : 04/12/2014
copyright            : (C) 2014 par PAPIN/DELVAL
*************************************************************************/

//---------- Realisation de la classe <Log> (fichier Log.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systeme
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Log.h"


//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types prives


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Methodes publiques

list<InfosLigne> Log::GetListeLignes() const
{
    return listeLignes;
}
//
//{
//} //----- Fin de Methode


//------------------------------------------------- Surcharge d'operateurs



//-------------------------------------------- Constructeurs - destructeur

Log::Log(istream& file)
{
    InfosLigne uneLigne;
    while(file>>uneLigne)
    {
        listeLignes.push_back(uneLigne);
    }
}


Log::~Log ( )
{
    listeLignes.clear();

#ifdef MAP
    cout << "Appel au destructeur de InfosLigne" << endl;
#endif
} //----- Fin de ~Log


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Methodes protegees

//------------------------------------------------------- Methodes privees



