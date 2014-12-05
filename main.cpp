#include <iostream>
#include <string.h>
#include <fstream>
#include "Graphe.h"

using namespace std;

const int AUCUNE_ERREUR=0;
const int PAS_DE_ARG_FICHIER=1;
const int FICHIER_INTROUVABLE=2;
const int TROP_ARGUMENTS=3;

static int executeApplication(string *tabArgs, int nbrArgs)
{
    int res=AUCUNE_ERREUR;
    if(nbrArgs<=1 || tabArgs[1].empty()) // le 1er argument est l'appel de l'application (ne compte pas pour nous)
    {
        res=PAS_DE_ARG_FICHIER;
    }
    else
    {
        ifstream file(tabArgs[1].c_str());
        if(!file.good())
        {
            res=FICHIER_INTROUVABLE;
        }
        else
        {
            if(nbrArgs==2) // il n'y a pas d'autres arguments
            {
                // on affiche les 10 documents les plus consultes par ordre croissant de popularite
            }
            else
            {
                //on analyse les arguments
                if(nbrArgs>7)
                {
                    res=TROP_ARGUMENTS;
                }
                else
                {

                }
            }
        }
    }
    return res;
}

int main(int argc, char* argv[]) {
    string* args= new string[argc];
    for(int i=0; i<argc ; i++)
    {
        args[i].assign(argv[i]);
    }
    int retour=executeApplication(args,argc);
    switch (retour)
    {
        case AUCUNE_ERREUR:
            cout<<endl;
            cout<<"Fin de l'execution."<<endl;
            cout<<"Merci d'avoir utilisé cette application."<<endl;
            break;
        case PAS_DE_ARG_FICHIER:
            cout<<endl;
            cout<<"Erreur de commande."<<endl;
            cout<<"Vous devez indiquer en 1er paramètre le nom du fichier log que vous souhaitez traiter."<<endl;
            cout<<"exemple d'appel :     ./analog nomFichier.log"<<endl;
            cout<<"Pour plus d'informations sur le fonctionnement de cette application, vous pouvez vous reporter au README.txt"<<endl;
            break;
        case FICHIER_INTROUVABLE:
            cout<<endl;
            cout<<"Erreur d'ouverture de fichier."<<endl;
            cout<<"Vous devez indiquer en 1er paramètre un nom du fichier log que vous souhaitez traiter."<<endl;
            cout<<"Conditions d'utilisation : Le fichier doit exister à l'adresse spécifiée et vous devez avoir les droits en lecture dessus."<<endl;
            cout<<"exemple d'appel :     ./analog /sousDossier/nomFichier.log"<<endl;
            cout<<"Pour plus d'informations sur le fonctionnement de cette application, vous pouvez vous reporter au README.txt"<<endl;
            break;
        case TROP_ARGUMENTS:
            cout<<endl;
            cout<<"Erreur."<<endl;
            cout<<"Vous avez lancé le programme avec trop d'options."<<endl;
            cout<<"Les options possibles sont :"<<endl;
            cout<<endl;
            cout<<"    [-g nomFichier.dot]"<<endl;
            cout<<"       Permet de produire un fichier au format GraphViz représentant le fichier log."<<endl;
            cout<<"       Le fichier sera produit à l'adresse [nomFichier.dot]."<<endl;
            cout<<"       Chaque document apparaîtra sous la forme d'un noeud et chaque arc indiquera le nombre de parcours associés."<<endl;
            cout<<endl;
            cout<<"    [-x]"<<endl;
            cout<<"       Permet d'exclure tous les documents qui ont une extension de type image, css ou javascript"<<endl;
            cout<<endl;
            cout<<"    [-t heure]"<<endl;
            cout<<"       Permet de ne prendre en compte que les hits qui sont dans le créneau horaire [heure, heure+1[."<<endl;
            cout<<"       l'argument [heure] est donc un entier, allant de 0 à 23."<<endl;
            cout<<endl;
            cout<<"Pour plus d'informations sur le fonctionnement de cette application, vous pouvez vous reporter au README.txt"<<endl;
            break;
        default:
            break;
    }
    return 0;
}
