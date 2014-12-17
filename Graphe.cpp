/*************************************************************************
Graphe  -  description
-------------------
debut                : 13/12/2014
copyright            : (C) 2014 par PAPIN/DELVAL
*************************************************************************/

//---------- Realisation de la classe <Graphe> (fichier Graphe.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systeme
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Graphe.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types prives


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Methodes publiques


//-------------------------------------------- Constructeurs - destructeur

Graphe::Graphe (string bUrl, Log &unLog, int heure, bool xFlag, ostream &direction, bool fichierDot )
// Algorithme :
// initialise le graphe avec le log et genere le fichier graphe + affiche le top 10
{
#ifdef MAP
    cout << "Appel au constructeur de <Graphe>" << endl;
#endif
    baseUrl=bUrl;
    // on initialise le graphe
    initialiserGraphe(unLog, heure, xFlag,fichierDot);
    //et on genere le fichier
    if(fichierDot)
    {
        genererFichier(direction);
    }
    afficherTop10();
} //----- Fin de Graphe


Graphe::~Graphe ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Graphe>" << endl;
#endif
    dicoIdArc.clear();
    for(DicoNomDocument::iterator i=dicoNomDoc.begin(); i!=dicoNomDoc.end(); ++i)
    {
        delete (i->second);
    }
    dicoNomDoc.clear();
    listeDocTrieeSelonVisites.clear();
} //----- Fin de ~Graphe


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Methodes protegees

//------------------------------------------------------- Methodes privees
void Graphe::initialiserGraphe(Log &unLog, int heure, bool xFlag, bool fichierDot)
{
    list<InfosLigne> leFichierLog = unLog.GetListeLignes();
    string id="";
    string ref="";
    string cib="";

    for (list<InfosLigne>::iterator ci = leFichierLog.begin(); ci != leFichierLog.end(); ++ci)
    {
        cib=ci->GetUrlDemandee();
        nettoyer(cib);
        // si la ligne est compatible avec les filtres qu'a demande l'utilisateur alors on ajoute la ligne aux structures de donnees
        if( (!xFlag || xFlagCompatible(cib)) && (heure==-1 || ci->GetDate().tm_hour==heure) )
        {
            ref=ci->GetUrlReferent();
            nettoyer(ref);
            if(fichierDot)
            {
                id=ref + cib;
                //chercher l'id dans la map
                DicoIdArc::iterator it = dicoIdArc.find(id);
                if(it!=dicoIdArc.end())
                {
                    //si il existe nbParcours ++
                    it->second.NbParcours++;
                }
                else
                {
                    //sinon on l'ajoute avec nbParcours=1 en creant les deux documents
                    Document* cible=new Document(cib,1);
                    Document* referent=new Document(ref,1);
                    Arc arc(referent,cible,1,id);
                    dicoIdArc.insert(make_pair(id, arc));
                }
            }
            DicoNomDocument::iterator it_nomDoc = dicoNomDoc.find(cib);
            if(it_nomDoc!=dicoNomDoc.end())
            {
                //si il existe NbAcces ++
                it_nomDoc->second->NbAcces++;
            }
            else
            {
                //sinon on l'ajoute avec NbAcces=1 et un identifiant quelconque (-1) car il ne sera paas utilise
                Document* cible=new Document(cib,1);
                dicoNomDoc.insert(make_pair(cib, cible));
                listeDocTrieeSelonVisites.push_back(cible); //complexite en O(1)
            }
        }

    }
}

void Graphe::nettoyer(string &stringANettoyer) const
{
    string to="";
    size_t start_pos_base = stringANettoyer.find(baseUrl);

    // on supprime l'url de base
    if(start_pos_base!=string::npos)
    {
        stringANettoyer.replace(start_pos_base, baseUrl.length(), to);
    }

    // on supprime tout apres le diese
    string::size_type pos = stringANettoyer.find('#');
    if (pos != string::npos)
        stringANettoyer=stringANettoyer.substr(0, pos);

    // on supprime tout apres le point d'interrogation
    pos = stringANettoyer.find('?');
    if (pos != string::npos)
        stringANettoyer=stringANettoyer.substr(0, pos);

    // on supprime tout apres le point d'interrogation
    pos = stringANettoyer.find(';');
    if (pos != string::npos)
        stringANettoyer=stringANettoyer.substr(0, pos);

    while(stringANettoyer.back() == '/')
        stringANettoyer=stringANettoyer.substr(0, stringANettoyer.size()-1);

}

void Graphe::genererFichier(ostream &direction) const
{
    if(direction.good())
    {
        direction<<"digraph {"<<endl;
        int numC=-1;
        int numR=-1;
        for(DicoIdArc::const_iterator it=dicoIdArc.begin() ; it!=dicoIdArc.end() ; ++it)
        {
            direction<<'"'<<it->second.Refer->NomDocument<<"\" -> \""
                          <<it->second.Cible->NomDocument<<"\" [label=\""
                          <<it->second.NbParcours<<"\"];"
                     <<endl;
        }
        direction<<"}"<<endl;
    }
    else
    {
        cout<<"Erreur dans le programme principal, mauvaise gestion de l'ofstream. Le fichier dot ne peut pas être ecrit."<<endl;
        exit(1);
    }
}

bool Graphe::xFlagCompatible(const string &cib) const
{
    bool res=true;
    //si l'extension correspond a un fichier css ou js ou un des formats d'image relativement assez connus
    string extensions[] = {".css",".js",".jpeg",".jpg",".gif",".png",".svg",".bmp",".ico"};
    int taille=9;
    for(int i=0 ; i<taille && res; i++)
    {
        if(cib.find(extensions[i])!=string::npos)
        {
            res=false;
        }
    }
    return res;
}

/*
compare deux Document, permet de trier la liste du top10
 */
bool compareDocuments(const Graphe::Document* first, const Graphe::Document* second)
{
    return (first->NbAcces > second->NbAcces) ;
}

void Graphe::afficherTop10()
{
    listeDocTrieeSelonVisites.sort(compareDocuments);
    unsigned long N = 9L;
    if (listeDocTrieeSelonVisites.size() <= N)
    {
        N=listeDocTrieeSelonVisites.size()-1;
    }
    Document* docTop10;
    ListeDoc::const_iterator it = listeDocTrieeSelonVisites.begin();
    int numero=1;
    while(numero<=10 && it!=listeDocTrieeSelonVisites.end())
    {
        docTop10 = *it;
        cout<<docTop10->NomDocument<<" ("<<docTop10->NbAcces<<" hits)"<<endl;
        it++;
        numero++;
    }
}
