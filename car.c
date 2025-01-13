#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include"car.h"

//fonction pour inscrire un nouvel utilisateur
void inscription() {
    char nom[50];
    char mot_de_passe[50];
    FILE *fichier = fopen("utilisateurs.csv", "a");

    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
        return;
    }

    printf("Entrez votre nom: ");
    scanf("%s", nom);
    printf("Entrez votre mot de passe: ");
    scanf("%s", mot_de_passe);

    fprintf(fichier, "%s,%s\n", nom, mot_de_passe);
    fclose(fichier);
    printf("Inscription reussie!\n");
}

//fonction pour se connecter avec un utilisateur existant
void connexion() {
    char nom[50];
    char mot_de_passe[50];
    char ligne[100];
    int trouve = 0;
    FILE *fichier = fopen("utilisateurs.csv", "r");

    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
        return;
    }

    printf("Entrez votre nom: ");
    scanf("%s", nom);
    printf("Entrez votre mot de passe: ");
    scanf("%s", mot_de_passe);

    while (fgets(ligne, sizeof(ligne), fichier)) {
        char *token = strtok(ligne, ",");
        char *nom_fichier = token;
        char *mot_de_passe_fichier = strtok(NULL, "\n");

        if (strcmp(nom_fichier, nom) == 0 && strcmp(mot_de_passe_fichier, mot_de_passe) == 0) {
            trouve = 1;
            break;
        }
    }

    fclose(fichier);

    if (trouve) {
        printf("Connexion reussie!\n");
    } else {
        printf("Nom ou mot de passe incorrect.\n");
    }
}

     //ajouter une voiture
    void ajouterVoiture(Voiture voitures[], int *nbVoitures) {
    if (*nbVoitures >= MAX_VOITURES) {
        printf("Nombre maximum de voitures atteint.\n");
        return;
    }
    Voiture v;
    printf("Entrez l'ID: ");
    scanf("%s", v.id);
    printf("Entrez la marque: ");
    scanf("%s", v.marque);
    printf("Entrez le nom d'utilisateur: ");
    scanf("%s", v.utilisateur);
    printf("Entrez le modele: ");
    scanf("%s", v.modele);
    printf("Entrez le type de carburant: ");
    scanf("%s", v.carburant);
    printf("Entrez le nombre de places: ");
    scanf("%d", &v.places);
    printf("Entrez la transmission (automatique/manuelle): ");
    scanf("%s", v.transmission);
    printf("Entrez le prix de location par jour: ");
    scanf("%f", &v.prix);
    printf("Entrez la disponibilite (disponible/non disponible): ");
    scanf("%s", v.disponibilite);
    voitures[*nbVoitures] = v;
    (*nbVoitures)++;
}

    //afficher la voiture
    void afficherVoitures(Voiture voitures[], int nbVoitures) {
    for (int i = 0; i < nbVoitures; i++) {
        printf("ID: %s, Marque: %s, Utilisateur: %s, Modele: %s, Carburant: %s, Places: %d, Transmission: %s, Prix: %.2f, Disponibilite: %s\n",
               voitures[i].id, voitures[i].marque, voitures[i].utilisateur, voitures[i].modele, voitures[i].carburant, voitures[i].places,
               voitures[i].transmission, voitures[i].prix, voitures[i].disponibilite);
    }
}

//sauvgardage du voiture
void sauvegarderVoitures(Voiture voitures[], int nbVoitures, const char *nomFichier) {
    FILE *fichier = fopen(nomFichier, "w");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }
    for (int i = 0; i < nbVoitures; i++) {
        fprintf(fichier, "%s,%s,%s,%s,%s,%d,%s,%.2f,%s\n",
                voitures[i].id, voitures[i].marque, voitures[i].utilisateur, voitures[i].modele, voitures[i].carburant, voitures[i].places,
                voitures[i].transmission, voitures[i].prix, voitures[i].disponibilite);
    }
    fclose(fichier);
}

//charger la voiture
void chargerVoitures(Voiture voitures[], int *nbVoitures, const char *nomFichier) {
    FILE *fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }
    *nbVoitures = 0;
    while (fscanf(fichier, "%[^,],%[^,],%[^,],%[^,],%[^,],%d,%[^,],%f,%[^\n]\n",
                  voitures[*nbVoitures].id, voitures[*nbVoitures].marque, voitures[*nbVoitures].utilisateur, voitures[*nbVoitures].modele,
                  voitures[*nbVoitures].carburant, &voitures[*nbVoitures].places, voitures[*nbVoitures].transmission, &voitures[*nbVoitures].prix,
                  voitures[*nbVoitures].disponibilite) != EOF) {
        (*nbVoitures)++;
    }
    fclose(fichier);
}

//rechercher la voiture
void rechercherVoitures(Voiture voitures[], int nbVoitures, const char *critere, const char *valeur) {
    for (int i = 0; i < nbVoitures; i++) {
        if ((strcmp(critere, "marque") == 0 && strcmp(voitures[i].marque, valeur) == 0) ||
            (strcmp(critere, "disponibilite") == 0 && strcmp(voitures[i].disponibilite, valeur) == 0)) {
            printf("ID: %s, Marque: %s, Utilisateur: %s, Modele: %s, Carburant: %s, Places: %d, Transmission: %s, Prix: %.2f, Disponibilite: %s\n",
                   voitures[i].id, voitures[i].marque, voitures[i].utilisateur, voitures[i].modele, voitures[i].carburant, voitures[i].places,
                   voitures[i].transmission, voitures[i].prix, voitures[i].disponibilite);
        }
    }
}

//tri du voiture
void trierVoitures(Voiture voitures[], int nbVoitures, const char *critere) {
    for (int i = 0; i < nbVoitures - 1; i++) {
        for (int j = i + 1; j < nbVoitures; j++) {
            if ((strcmp(critere, "marque") == 0 && strcmp(voitures[i].marque, voitures[j].marque) > 0) ||
                (strcmp(critere, "prix") == 0 && voitures[i].prix > voitures[j].prix)) {
                Voiture temp = voitures[i];
                voitures[i] = voitures[j];
                voitures[j] = temp;
            }
        }
    }
}
