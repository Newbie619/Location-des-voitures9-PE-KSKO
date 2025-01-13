#include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include"car.h"



int main(){

//fonction pour inscrire un nouvel utilisateur



//fonction pour se connecter avec un utilisateur existant



    char choix[4];
    printf("Etes-vous un nouvel utilisateur? (oui/non): ");
    scanf("%s", choix);

    switch (choix[0]) {
        case 'o':
            inscription();
            break;
        case 'n':
            connexion();
            break;
        default:
            printf("Choix invalide. Veuillez repondre par 'oui' ou 'non'.\n");
            break;
    }

    //ajouter une voiture

//afficher la voiture


//sauvgardage du voiture


//charger la voiture

//rechercher la voiture

//tri du voiture



    Voiture voitures[MAX_VOITURES];
    int nbVoitures = 0;
    const char *nomFichier = "voiture.csv";

    chargerVoitures(voitures, &nbVoitures, nomFichier);

    int C;

    do {
        printf("\n1. AJOUTER UNE VOITURE\n");
        printf("\n2. AFFICHER LES VPOITURE\n");
        printf("\n3. RECHERCHER UNE VOITURE\n");
        printf("\n4. TRIER LE VOITURE\n");
        printf("\n5. SAUVGARDER ET QUITTER \n");
        printf("\nENTRER VOTRE CHOIX: ");
        scanf("%d", &C);

        switch (C) {
            case 2:
            case 1:
                ajouterVoiture(voitures, &nbVoitures);
                break;
                afficherVoitures(voitures, nbVoitures);
                break;
            case 3: {
                char critere[TAILLE_MAX], valeur[TAILLE_MAX];
                printf("Entrez le critere (marque/disponibilite): ");
                scanf("%s", critere);
                printf("Entrez la valeur: ");
                scanf("%s", valeur);
                rechercherVoitures(voitures, nbVoitures, critere, valeur);
                break;
            }
            case 4: {
                char critere[TAILLE_MAX];
                printf("Entrez le critere de tri (marque/prix): ");
                scanf("%s", critere);
                trierVoitures(voitures, nbVoitures, critere);
                break;
            }
            case 5:
                sauvegarderVoitures(voitures, nbVoitures, nomFichier);
                printf("Donnees sauvegardees. Au revoir!\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 5);

    return 0;
}
