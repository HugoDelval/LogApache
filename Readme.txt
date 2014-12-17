Rôle du programme :
	Le programme sans option traite un log Apache et affiche à la sortie standard linux les 10 ressources du domaine
	les plus consultées, avec le nombre d'accès par ressource.
	Vous pouvez également trier les ressources selon certains critères (heure, type de ressource, cf options ci-dessous)
	et générer un fichier .dot traduisible avec l'application GraphViz

Configuration programme :
	Vous devez ajouter un fichier de configuration nommé 'config.conf' dans le répertoire courant (celui de l'appel du programme)
    Ce fichier doit contenir l'url de base de votre site web suivit d'un point virgule ex : 
    http://monsupersiteweb.com;

Appel du programme :
    ./LogApache.exe [options] monFichierLog.log

	Avec monFichierLog.log le fichier représentant le log Apache au format texte,
	et [options] étant les options facultatives si dessous (séparées d'un espace) :

Options du programme :
	
	[-g nomFichier.dot]
		Permet de générer un fichier au format GraphViz représentant le fichier log.
		Le fichier sera généré à l'adresse [nomFichier.dot].
		Chaque document dans l'image générée par GraphViz apparaîtra sous la forme d'un noeud
		et chaque arc indiquera le nombre de parcours associés.
		
	[-x]
		Permet d'exclure tous les documents qui ont une extension de type image, css ou javascript
		Les images prises en comptes sont : *.jpeg, *.jpg, *.gif, *.png, *.svg, *.bmp", *.ico

	[-t heure]
		Permet de ne prendre en compte que les hits qui sont dans le créneau horaire [heure, heure+1[.
		l'argument [heure] est donc un entier, allant de 0 à 23.

Le graphe GraphViz est généré grâce à une commande externe à notre programme :
 -Tpng -o Graphe.out.png Graphe.dot
 cf la documentation de GraphViz : http://www.graphviz.org/Documentation.php