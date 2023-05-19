Le montage qui est présenté içi est un compteur de passage de pièces. Il s'agit de la seconde version (la 1er était à base d'un atmega328).
Réalisé avec Kicad pour la partie soft et à l'aide d'une CNC pour la gravure à l'anglaise du PCB.
La version finale mise en production comporte une fonction d'auto extinction automatique.
L'automaintien est confié à un relais qui coupe l'alimention après le temps prédéfini.
Il existe aussi une version avec mémorisation du dernier comptage. Le problème étant lié à la durée de vie de la mémoire EEPROM. Dans les conditions de production actuelle (environ 250 pièces par jour) la durée de vie est d'environ 400 jours.
Il faudrait un algorithme qui modifie l'emplacement mémoire de la sauvegarde, après un certain nombre de comptage.
