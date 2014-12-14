#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include <fstream>
#include "Graphe.h"

using namespace std;

const int AUCUNE_ERREUR=0;
const int PAS_DE_ARG_FICHIER=1;
const int FICHIER_LOG_INTROUVABLE =2;
const int TROP_ARGUMENTS=3;
const int ARG_HEURE_NON_VALIDE=4;
const int FICHIER_DOT_NON_MODIFIABLE=5;
const string DIRECTION_FICHIER="config.conf";

static string getBaseUrl()
{
    ifstream fileConfig(DIRECTION_FICHIER.c_str());
    string res="";
    if(fileConfig.good())
    {
        getline(fileConfig, res, ';');
    }
    else
    {
        cerr<<endl;
        cerr<<"Erreur, le fichier de config a été déplacé, supprimé ou vous n'avez plus les droits en lecture dessus."<<endl;
        cerr<<"Ce fichier doit contenir l'url de base de votre site web suivit d'un point virgule ex : "<<endl;
        cerr<<"http://monsupersiteweb.com;"<<endl;
        cerr<<endl;
        cerr<<"Ce fichier doit être dans le même dossier que l'exécutable et doit se nommer \""<<DIRECTION_FICHIER<<"\"."<<endl;
        cerr<<"Pour plus d'informations sur le fonctionnement de cette application, vous pouvez vous reporter au README.txt"<<endl;
        exit(1);
    }
    return res;
}

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
                xFlag=true;
                break;
            case 't':
                argTFlag.assign(optarg);
                tFlag=true;
                break;
            case 'g':
                argGFlag.assign(optarg);
                gFlag=true;
                break;
        }
    }

    if(optind==(argc-1)) // si il ne reste qu'un argument sans flag (le nom du fichier normalement)
    {
        string nomFichierLog(argv[optind]);
        ifstream file(nomFichierLog.c_str());
        if(file.good())
        {
            //on peut commencer le traitement
            Log monLog(file);
            int heure=-1;
            string baseUrl=getBaseUrl();
            if(tFlag)
            {
                try {
                    heure=atoi(argTFlag.c_str());
                }catch(int e){
                    heure=-1;
                    res=ARG_HEURE_NON_VALIDE;
                }
                if(heure>23 || heure<-1 || (heure==0 && argTFlag.compare("0")!=0) )
                {
                    heure=-1;
                    res=ARG_HEURE_NON_VALIDE;
                }
            }
            if(gFlag)
            {
                string nomFichierDot(argGFlag);
                ofstream fileDot(nomFichierDot.c_str());
                if(fileDot.good())
                {
                    Graphe monGraphe(baseUrl,monLog,heure,xFlag,fileDot,true);
                }
                else
                {
                    res=FICHIER_DOT_NON_MODIFIABLE;
                }
            }
            else
            {
                Graphe monGraphe(baseUrl,monLog,heure,xFlag);
            }
        }
        else
        {
            res= FICHIER_LOG_INTROUVABLE;
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
            cerr<<endl;
            cerr<<"Erreur de commande."<<endl;
            cerr<<"Vous devez indiquer en dernier paramètre le nom du fichier log que vous souhaitez traiter."<<endl;
            cerr<<"exemple d'appel :     ./LogApache.exe nomFichier.log"<<endl;
            cerr<<"Ceci est peut-être dû au fait que vous avez omis de spécifier le paramètre obligatoire après '-t' ou un '-g'"<<endl;
            cerr<<"Pour plus d'informations sur le fonctionnement de cette application, vous pouvez vous reporter au README.txt"<<endl;
            break;
        case FICHIER_LOG_INTROUVABLE:
            cerr<<endl;
            cerr<<"Erreur d'ouverture de fichier."<<endl;
            cerr<<"Vous devez indiquer en dernier paramètre le nom du fichier log que vous souhaitez traiter."<<endl;
            cerr<<"Conditions d'utilisation : Le fichier doit exister à l'adresse spécifiée et vous devez avoir les droits en lecture dessus."<<endl;
            cerr<<"exemple d'appel :     ./LogApache.exe /sousDossier/nomFichier.log"<<endl;
            cerr<<"Pour plus d'informations sur le fonctionnement de cette application, vous pouvez vous reporter au README.txt"<<endl;
            break;
        case TROP_ARGUMENTS:
            cerr<<endl;
            cerr<<"Erreur."<<endl;
            cerr<<"Vous avez lancé le programme avec trop d'options, ou des options qui n'existe pas !"<<endl;
            cerr<<"Les options possibles sont :"<<endl;
            cerr<<endl;
            cerr<<"    [-g nomFichier.dot]"<<endl;
            cerr<<"       Permet de produire un fichier au format GraphViz représentant le fichier log."<<endl;
            cerr<<"       Le fichier sera produit à l'adresse [nomFichier.dot]."<<endl;
            cerr<<"       Chaque document apparaîtra sous la forme d'un noeud et chaque arc indiquera le nombre de parcours associés."<<endl;
            cerr<<endl;
            cerr<<"    [-x]"<<endl;
            cerr<<"       Permet d'exclure tous les documents qui ont une extension de type image, css ou javascript"<<endl;
            cerr<<endl;
            cerr<<"    [-t heure]"<<endl;
            cerr<<"       Permet de ne prendre en compte que les hits qui sont dans le créneau horaire [heure, heure+1[."<<endl;
            cerr<<"       l'argument [heure] est donc un entier, allant de 0 à 23."<<endl;
            cerr<<endl;
            cerr<<"Pour plus d'informations sur le fonctionnement de cette application, vous pouvez vous reporter au README.txt"<<endl;
            break;
        case FICHIER_DOT_NON_MODIFIABLE:
            cerr<<endl;
            cerr<<"Erreur d'ecriture dans le fichier dot."<<endl;
            cerr<<"Vous devez indiquer en paramètre derière le -g le nom du fichier dot que vous souhaitez générer."<<endl;
            cerr<<"Conditions d'utilisation : L'adresse spécifiée doit être valide et vous devez avoir les droits d'ecriture à l'emplacement considéré."<<endl;
            cerr<<"Syntaxe de l'option :"<<endl;
            cerr<<endl;
            cerr<<"    [-g nomFichier.dot]"<<endl;
            cerr<<"       Permet de produire un fichier au format GraphViz représentant le fichier log."<<endl;
            cerr<<"       Le fichier sera produit à l'adresse [nomFichier.dot]."<<endl;
            cerr<<"       Chaque document apparaîtra sous la forme d'un noeud et chaque arc indiquera le nombre de parcours associés."<<endl;
            cerr<<endl;
            cerr<<"exemple d'appel :     ./LogApache.exe -g nomFichier.dot /sousDossier/nomFichier.log"<<endl;
            cerr<<"Pour plus d'informations sur le fonctionnement de cette application, vous pouvez vous reporter au README.txt"<<endl;
            break;
        case ARG_HEURE_NON_VALIDE:
            cerr<<"Erreur dans l'option -t. L'heure spécifiée n'est pas valide."<<endl;
            cerr<<"Vous devez indiquer en paramètre derière le -t une heure."<<endl;
            cerr<<"Syntaxe de l'option :"<<endl;
            cerr<<endl;
            cerr<<"    [-t heure]"<<endl;
            cerr<<"       Permet de ne prendre en compte que les hits qui sont dans le créneau horaire [heure, heure+1[."<<endl;
            cerr<<"       l'argument [heure] est donc un entier, allant de 0 à 23."<<endl;
            cerr<<endl;
            cerr<<"exemple d'appel :     ./LogApache.exe -h 12 /sousDossier/nomFichier.log"<<endl;
            cerr<<"Pour plus d'informations sur le fonctionnement de cette application, vous pouvez vous reporter au README.txt"<<endl;
            break;
        default:
            break;
    }
    return 0;
}
