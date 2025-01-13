
#pragma once
//constante
//structure
//prototype

#define MAX_VOITURES 100
#define TAILLE_MAX 50

//structure pour la voiture
typedef struct {
    char id[TAILLE_MAX];
    char marque[TAILLE_MAX];
    char utilisateur[TAILLE_MAX];
    char modele[TAILLE_MAX];
    char carburant[TAILLE_MAX];
    int places;
    char transmission[TAILLE_MAX];
    float prix;
    char disponibilite[TAILLE_MAX];
} Voiture;

//structure pour stocker les utilisateurs
typedef struct  {
    char nom[50];
    char mot_de_passe[50];
}Utilisateur;

void inscription();
void connexion();
void ajouterVoiture(Voiture voitures[], int *nbVoitures);
void afficherVoitures(Voiture voitures[], int nbVoitures);
void sauvegarderVoitures(Voiture voitures[], int nbVoitures, const char *nomFichier);
void chargerVoitures(Voiture voitures[], int *nbVoitures, const char *nomFichier);
void rechercherVoitures(Voiture voitures[], int nbVoitures, const char *critere, const char *valeur);
void trierVoitures(Voiture voitures[], int nbVoitures, const char *critere);
