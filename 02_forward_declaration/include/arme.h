//
// Created by sebas on 12.10.2026.
//

#ifndef GPR_CF_POO_03_DECOUPAGE_EN_FICHIERS_ARME_H
#define GPR_CF_POO_03_DECOUPAGE_EN_FICHIERS_ARME_H
#include <string>

// Probleme : inclusion circulaire -- decommenter pour voir l'erreur.
// #include "joueur.h"

// Solution : une declaration anticipee suffit, Arme ne stocke qu'un pointeur.
class Joueur;

class Arme {
public:
    std::string name_;
    Joueur* joueur_;
    void PrintCaracteristics();
};


#endif //GPR_CF_POO_03_DECOUPAGE_EN_FICHIERS_ARME_H
