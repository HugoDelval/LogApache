/*************************************************************************
Graphe  -  description
-------------------
debut                : date
copyright            : (C) ${year} par ${user}
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
// type Graphe::Methode ( liste de parametres )
// Algorithme :
//
//{
//} //----- Fin de Methode



//-------------------------------------------- Constructeurs - destructeur

Graphe::Graphe (string bUrl, Log &unLog, int heure, bool xFlag, ostream &direction, bool fichierDot )
// Algorithme :
//
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
    int num=0;

    //cout<<leFichierLog.size()<<endl;
    for (list<InfosLigne>::iterator ci = leFichierLog.begin(); ci != leFichierLog.end(); ++ci)
    {
        cib=nettoyer(ci->GetUrlDemandee());
        // si la ligne est compatible avec les filtres qu'a demande l'utilisateur alors on ajoute la ligne aux structures de donnees
        if( (!xFlag || xFlagCompatible(cib)) && (heure==-1 || ci->Getdate().tm_hour==heure) )
        {
            if(fichierDot)
            {
                ref=nettoyer(ci->GetUrlReferent());
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
                    Document* cible=new Document(num,cib,1);
                    num++;
                    Document* referent=new Document(num,ref,1);
                    num++;
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
                Document* cible=new Document(-1,cib,1);
                dicoNomDoc.insert(make_pair(cib, cible));
                listeDocTrieeSelonVisites.push_back(cible); //complexite en O(1)
            }
        }

    }
}

string Graphe::nettoyer(string stringANettoyer)
{
    string to="";
    size_t start_pos_base = stringANettoyer.find(baseUrl);

    // on supprime l'url de base
    if(start_pos_base != string::npos)
        stringANettoyer.replace(start_pos_base, stringANettoyer.length(), to);

    // on supprime tout apres le diese
    string::size_type pos = stringANettoyer.find('#');
    if (pos != string::npos)
        stringANettoyer=stringANettoyer.substr(0, pos);

    // on supprime tout apres le point d'interrogation
    pos = stringANettoyer.find('?');
    if (pos != string::npos)
        stringANettoyer=stringANettoyer.substr(0, pos);

    return stringANettoyer;
}

void Graphe::genererFichier(ostream &direction)
{
    if(direction.good())
    {
        direction<<"diagraph {"<<endl;
        string labelC="";
        string labelR="";
        int numC=-1;
        int numR=-1;
        for(DicoIdArc::iterator it=dicoIdArc.begin() ; it!=dicoIdArc.end() ; ++it)
        {
            labelC=it->second.Cible->NomDocument;
            labelR=it->second.Refer->NomDocument;
            numC=it->second.Cible->NumNoeud;
            numR=it->second.Refer->NumNoeud;
            EnsembleNumNoeud::const_iterator it_label_cible = traceLabels.find(numC);
            EnsembleNumNoeud::const_iterator it_label_ref = traceLabels.find(numR);
            if(it_label_cible==traceLabels.end())
            {
                // il n'existe pas = ajout au traceLabels + ajout au graphe
                traceLabels.insert(numC);
                direction<<"node"<<numC<<" [label=\""<<labelC<<"\"];"<<endl;
            }
           if(it_label_ref!=traceLabels.end())
            {
                // il n'existe pas = ajout au traceLabels + ajout au graphe
                traceLabels.insert(numR);
                direction<<"node"<<numR<<" [label=\""<<labelR<<"\"];"<<endl;
            }
            direction<<"node"<<numR<<" -> node"<<numC<<" [label=\""<<it->second.NbParcours<<"\"];"<<endl;
        }
        direction<<"}"<<endl;
    }
    else
    {
        cout<<"Erreur dans le programme principal, mauvaise gestion de l'ofstream. Le fichier dot ne peut pas être ecrit."<<endl;
        exit(1);
    }
}

bool Graphe::xFlagCompatible(string cib)
{
    bool res=true;
    string extension=cib.substr(cib.find_last_of(".") + 1);
    //si l'extension correspond a un fichier css ou js ou un des formats d'image relativement assez connus
    if(extension.compare("css")==0 || extension.compare("js")==0 ||
                extension.compare("jpg")==0 || extension.compare("jpeg")==0 ||
                extension.compare("gif")==0 || extension.compare("png")==0 ||
                extension.compare("svg")==0 || extension.compare("bmp")==0 || extension.compare("ico")==0)
    {
        res=false;
    }
    return res;
}

bool compareDocuments(const Document* first, const Document* second)
{
    return (first->NbAcces < second->NbAcces) ;
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
    ListeDoc::iterator it = listeDocTrieeSelonVisites.begin();
    advance(it, N);
    for(;it!=listeDocTrieeSelonVisites.begin();it--)
    {
        docTop10 = *it;
        cout<<docTop10->NomDocument<<" ("<<docTop10->NbAcces<<" hits)"<<endl;
    }
    it=listeDocTrieeSelonVisites.begin();
    docTop10 = *it;
    cout<<docTop10->NomDocument<<" ("<<docTop10->NbAcces<<" hits)"<<endl;

}
