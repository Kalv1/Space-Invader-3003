# Space-3003 :milky_way:
Nous pilotons un petit vaisseau qui doit éviter des rochers, lorsque le vaisseau est touché il perd une vie ainsi que de la vitesse. Plus le temps passe plus la vitesse augmente, et ainsi, la difficulté. Tout ceci en 2D. Pour vous déplacer vous devez utiliser les touches directionnelles du clavier ←↑↓→. Une fois votre partie terminée le jeu se ferme automatiquement et si le score de votre partie est supérieur au highscore actuel. Il sera enregistré dans le fichier myFile.txt.

# Prérequis | Installation :hammer:
Pour démarrer le projet vous aurez besoin des librairies SDL :

`$ sudo apt install libsdl2-2.0-0 libsdl2-ttf-2.0-0`

Une fois les librairies installé il ne vous restera plus qu'à cloner le projet ou de télécharger le zip.

`$ git clone https://github.com/Kalv1/Space-Invader-3003.git`

Pour lancer le projet placez-vous dans la racine de celui-ci pour compiler le avec la commande make et lancez le avec :

`$ ./main`


# Suivi :clipboard:
Semaine 0:
Mise à jour du READ ME / Creation du makefile / Initialisation SDL

Semaine 1: 
Affichage du fond et du vaisseau 

Semaine 2: 
Integration de Zixun, creation d'une structure world et vaisseau et debut de la creation d'evenement (mouvements vaisseau)

Semaine 3:
Mouvements vaisseaux + Limites du monde + debut systeme de sauvegarde des scores dans un fichier

Semaine 4: 
Ajout Detection collision + initialisation d'un rocher, deplacement et affichage 

Semaine 5:
Tableau rochers avec position aléatoire + score + vie + collisions

Semaine 6:
Ajout du tableau dynamique contenant les rochers. Fix des différentes fuites mémoire via valgrind, optimisation du code. Changement de texture vers des textures plus propres. Ajout de la sauvegarde du highscore ainsi que l'affichage de la vie et du score.
