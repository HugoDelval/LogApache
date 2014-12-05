/*************************************************************************
Log  -  description
-------------------
debut                : date
copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Realisation de la classe <Log> (fichier Log.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systeme
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Log.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types prives


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Methodes publiques

InfosLigne Log::&getListeLignes() const 
{
    return listeLignes;
}
//
//{
//} //----- Fin de Methode


//------------------------------------------------- Surcharge d'operateurs
Log & Log::operator = ( const Log & unLog )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Log::Log ( const Log & unLog )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Log>" << endl;
#endif
} //----- Fin de Log (constructeur de copie)


Log::Log ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Log>" << endl;
#endif
} //----- Fin de Log


Log::~Log ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <file_bas>" << endl;
#endif
} //----- Fin de ~Log


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Methodes protegees

//------------------------------------------------------- Methodes privees

/*
    void Annuaire::Ajouter(const string &nomFich)
    {
        ifstream file(nomFich.c_str());
        Abonne a;
        if(file.good())
        {
            while(file>>a)
            {
                Ajouter(a);
            }
        }
        else
        {
            cout<<"Erreur, fichier \""<<nomFich<<"\" introuvable."<<endl;
        }
    }
    */


