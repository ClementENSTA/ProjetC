à écrire pour compiler 
    gcc *.c -Wall -lfftw3 -lm
à écrire pour lancer 
    ./a.out

  Les fichiers .c et .h situés dans cette branche forment la partie fonctionnelle de notre programme, qui crée le fichier features.csv servant à l'obtention de la matrice w et du vecteur b via le programme classifier.py.
  Les fichiers .c et .h situés dans la branche experimental_suite sont notre ébauche de code pour la suite du projet, à savoir la prédiction d'un extrait musical de genre inconnu à partir de w et b.

