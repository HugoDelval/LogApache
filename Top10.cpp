/*************************************************************************
Top10  -  description
-------------------
debut                : date
copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Realisation de la classe <Top10> (fichier Top10.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systeme
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Top10.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types prives


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Methodes publiques
// type Top10::Methode ( liste de parametres )
// Algorithme :
//
//{
//} //----- Fin de Methode



//-------------------------------------------- Constructeurs - destructeur
Top10::Top10 ( const Top10 & unTop10 )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Top10>" << endl;
#endif
} //----- Fin de Top10 (constructeur de copie)


Top10::Top10 ( Log &unLog, int typeCommande)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Top10>" << endl;
#endif
} //----- Fin de Top10


Top10::~Top10 ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Top10>" << endl;
#endif
} //----- Fin de ~Top10


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Methodes protegees

//------------------------------------------------------- Methodes privees
