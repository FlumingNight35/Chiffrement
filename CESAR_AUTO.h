#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR 61

/*Fonction pour décoder le message, on prends un pointeur
  pour le message et la variable 'cle' prends la valeur
  de la variable 'cle2'*/
void decode_cesar_auto_dclge(char *msg, char *msg2, int cle)
{
    int i = 0;
    /*Tant que le message ne contient pas le caractère '\0',
      on code toutes les lettres du message*/
    while (msg[i] != '\0')
    {
        /*Si les caractères du message sont compris entre 'a' et 'z'*/
        if (msg[i] >= 'a' && msg[i] <= 'z')
        {
            /*Chaque lettre du message va etre codé
            On incremente la cle pour le décalage dans le sens inverse
            On conserve le résultat avec modulo 26*/
            msg2[i] = 'a' + ((msg[i] - 'a') + 26-cle)%26;
        }
        if (msg[i] >= 'A' && msg[i] <= 'Z')
        {
            /*Chaque lettre du message va etre codé
              On incremente la cle pour le décalage dans le sens inverse
              On conserve le résultat avec modulo 26*/
            msg2[i] = 'A' + ((msg[i] - 'A') + 26-cle)%26;
        }
        if (msg[i] == ' ')
        {
            msg2[i] = ' ';
        }
        i++;    //On code pour chaque nombre de lettre dans le message
    }

    //On affiche le message décodé
    printf("message dechiffre : %s\n",msg2);
}

/*Fonction pour coder le message, on prends un pointeur
  pour le message et la variable 'cle' prends la valeur
  de la variable 'cle1'*/
void code_cesar_auto(char *msg, int cle)
{
    int i = 0;
    /*Tant que le message ne contient pas le caractère '\0',
      on code toutes les lettres du message*/
    while (msg[i] != '\0')
    {
        //Si les caractères du message sont compris entre 'a' et 'z'
        if (msg[i] >= 'a' && msg[i] <= 'z')
        {
            /*Chaque lettre du message va etre codé
              On incremente la cle pour le décalage
              On conserve le résultat avec modulo 26*/
            msg[i] = 'a' + ((msg[i] - 'a') + cle)%26;
        }
        if (msg[i] >= 'A' && msg[i] <= 'Z')
        {
            /*Chaque lettre du message va etre codé
              On incremente la cle pour le décalage
              On conserve le résultat avec modulo 26*/
            msg[i] = 'A' + ((msg[i] - 'A') + cle)%26;
        }
        if (msg[i] == ' ')
        {
            msg[i] = ' ';
        }
        i++;    //On code pour chaque nombre de lettre dans le message
    }
    //On affiche le message codé
    printf("Message code : %s\n",msg);
}

void chercher(char *mot, FILE *file, int n_line)
{
    int counter = 0;
    //Si le fichier n'est pas trouvé
    if (file == NULL)
    {
        puts("Erreur de lecture");
        exit(1);
    }
    while (counter != n_line)
    {
        /*On fait une recherche dans le fichier
          Avec un numéro ligne aléatoire
          On séléctionne le mot à la ligne séléctionnée*/
        fgets(mot, MAX_CHAR, file);
        //Si on ne trouve pas de lignes qui correspond
        if(mot == NULL)
        {
            puts("Ligne non trouvée");
            exit(1);
        }
        counter++;
    }
}

void CODE_CESAR_AUTO(int cle1, int cle2)
{
    int aleatoire;
    char msg[MAX_CHAR];

    //int cle = 0;
    FILE *fichier;
    srand(time(NULL));

    //On cherche dans le fichier 'liste_francais.txt'
    fichier = fopen("liste_francais.txt","rt");

    /*On génère un nombre aléatoire pour la variable 'aléatoire' pour entre 1 et 61
      Pour trouver une ligne dans le fichier texte*/
    aleatoire = rand() % MAX_CHAR + 1;

    //On cherche un mot dans le fichier à partir d'une ligne aléatoire
    chercher(msg, fichier, aleatoire);

    int lca = strlen(msg) - 1;

    //On génère une valeur aléatoire entre 1 et 26 pour la cle
    cle1 = rand() % 26 + 1;

    printf("\nCODE CESAR AUTOMATIQUE\n");

    /*Si le message ne depasse pas la limite de caractère autorisée et si la clé proposée
      se situe bien entre 1 et 26*/
    if(strlen(msg) >=1 && strlen(msg) <= 61)
    {
        if(cle1 >= 1 && cle1 <= 26)
        {
            //Appel de la fonction pour coder le message en fonction de la clé de cryptage
            code_cesar_auto(msg, cle1);

            printf("\nRESOLUTION CODE CESAR AUTOMATIQUE\n");

            //La variable 'msg2' prends la meme taille que le message choisi
            char msg2[lca];

            //Pour toutes les valeurs possibles entre 1 et 26, on déchiffrer le message
            for(cle2=1;cle2<=26;cle2++)
            {
                printf("\nAvec une cle de %d, ",cle2);
                decode_cesar_auto_dclge(msg, msg2, cle2);
            }
        }
        else
        {
            printf("\nMauvaise entree de cle\n");
            printf("Relancez le programme\n");
        }
    }
    else
    {
        printf("\nMauvaise entree de message\n");
        printf("Relancez le programme\n");
    }
}
