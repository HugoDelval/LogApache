#include <iostream>
#include <unistd.h>
#include <fstream>
#include <string.h>
#include "Graphe.h"

using namespace std;

const int AUCUNE_ERREUR=0;
const int PAS_DE_ARG_FICHIER=1;
const int FICHIER_INTROUVABLE=2;
const int TROP_ARGUMENTS=3;

static int executeApplication(int argc, char* argv[])
{
    int res=AUCUNE_ERREUR;

    int optch;
    extern int opterr;
    char format[] = "xt:g:";
    opterr = 1;

    bool xFlag=false;
    bool tFlag=false;
    string argTFlag;
    bool gFlag=false;
    string argGFlag;

    while ((optch = getopt(argc, argv, format)) != -1)
    {
        switch (optch)
        {
            case 'x':
                //cout<<"x"<<endl;
                xFlag=true;
                break;
            case 't':
                argTFlag.assign(optarg);
                tFlag=true;
                //cout<<"t flag avec : "<<argTFlag<<endl;
                break;
            case 'g':
                argGFlag.assign(optarg);
                gFlag=true;
                //cout<<"t flag avec : "<<argGFlag<<endl;
                break;
        }
    }

    if(optind==(argc-1)) // si il ne reste qu'un argument sans flag (le nom du fichier normalement)
    {
        string nomFichier(argv[optind]);
        ifstream file(nomFichier.c_str());
        if(file.good())
        {
            //on peut commencer le traitement
            Log monLog(file);
            Graphe monGraphe(monLog,xFlag,tFlag,gFlag,argTFlag,argGFlag);
        }
        else
        {
            res=FICHIER_INTROUVABLE;
        }
    }
    else
    {
        if(optind<(argc-1)) // si il reste plus d'un argument
        {
            res=TROP_ARGUMENTS;
        }
        else
        {
            res=PAS_DE_ARG_FICHIER;
        }
    }


    return res;
}

int main(int argc, char* argv[]) {
    int retour=executeApplication(argc,argv);
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
            cout<<"Vous devez indiquer en dernier paramètre le nom du fichier log que vous souhaitez traiter."<<endl;
            cout<<"exemple d'appel :     ./analog nomFichier.log"<<endl;
            cout<<"Pour plus d'informations sur le fonctionnement de cette application, vous pouvez vous reporter au README.txt"<<endl;
            break;
        case FICHIER_INTROUVABLE:
            cout<<endl;
            cout<<"Erreur d'ouverture de fichier."<<endl;
            cout<<"Vous devez indiquer en dernier paramètre le nom du fichier log que vous souhaitez traiter."<<endl;
            cout<<"Conditions d'utilisation : Le fichier doit exister à l'adresse spécifiée et vous devez avoir les droits en lecture dessus."<<endl;
            cout<<"exemple d'appel :     ./analog /sousDossier/nomFichier.log"<<endl;
            cout<<"Pour plus d'informations sur le fonctionnement de cette application, vous pouvez vous reporter au README.txt"<<endl;
            break;
        case TROP_ARGUMENTS:
            cout<<endl;
            cout<<"Erreur."<<endl;
            cout<<"Vous avez lancé le programme avec trop d'options, ou des options qui n'existe pas !"<<endl;
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
