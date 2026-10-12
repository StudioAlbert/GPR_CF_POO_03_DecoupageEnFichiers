# Le donjon — companion GPR-CF-POO-03

Une étape par point du cours, une target par étape.

| Étape | Ce qu'elle montre |
|---|---|
| `01_donjon_monolithe` | le point de départ : un jeu de donjon **entièrement dans un seul `main.cc`** de près de 300 lignes. Il marche, il est juste illisible — et c'est le sujet. |
| `02_forward_declaration` | deux classes qui se référencent : l'inclusion circulaire, et la déclaration anticipée qui la coupe. |

## Compiler et lancer

```powershell
cmake -S . -B build
cmake --build build
```

Puis `build/01_donjon_monolithe/01_donjon_monolithe.exe`.

Commandes du jeu : `z s q d` pour se déplacer, `a` pour attaquer, `j` pour lire le journal,
`x` pour sortir.

## Les quatre concepts à séparer

`01_donjon_monolithe/main.cc` est découpé par des bandeaux de commentaires. Chacun devient un duo
de fichiers.

| Concept | Ce qu'il porte | Dépend de |
|---|---|---|
| `Vector2` | une position, `Ajouter`, `Identiques`, `EnTexte` | rien |
| `Journal` | la liste des événements, et son affichage | rien |
| `Entite` | nom, vie, dégâts, position — le joueur et les monstres | `Vector2` |
| `Salle` | nom, description, position, le monstre qui s'y trouve | `Vector2`, `Entite` |

La dernière colonne donne l'ordre : `Vector2` et `Journal` d'abord, ils n'ont besoin de
personne.

## Ce qu'on vérifiera

- **le jeu se comporte exactement pareil** après le découpage qu'avant ;
- une **garde** en première ligne de chaque `.h` ;
- dans chaque en-tête, seulement ce que la **déclaration** exige — `<vector>` n'a rien à
  faire dans `vector2.h` ;
- chaque `.cc` déclaré dans le `CMakeLists.txt`, et aucun `.h`.

## Attention

`main.cc` ne contient **aucune** garde d'inclusion aujourd'hui, et c'est normal : un `.cc`
n'est jamais inclus par personne. Les gardes sont pour les en-têtes que vous allez créer.

Conventions : voir `01 courses/companion projects/CLAUDE.md` et la skill `programmation-cpp`
— en-têtes en `.h` dans `include/`, implémentations en `.cc` dans `src/`.
