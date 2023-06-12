#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR 61

/*Fonction pour d�coder le message, on prends un pointeur
  pour le message et la variable 'cle' prends la valeur
  de la variable 'cle2'*/
void decode_cesar_auto_dclge(char *msg, char *msg2, int cle)
{
    int i = 0;
    /*Tant que le message ne contient pas le caract�re '\0',
      on code toutes les lettres du message*/
    while (msg[i] != '\0')
    {
        /*Si les caract�res du message sont compris entre 'a' et 'z'*/
        if (msg[i] >= 'a' && msg[i] <= 'z')
        {
            /*Chaque lettre du message va etre cod�
            On incremente la cle pour le d�calage dans le sens inverse
            On conserve le r�sultat avec modulo 26*/
            msg2[i] = 'a' + ((msg[i] - 'a') + 26-cle)%26;
        }
        if (msg[i] >= 'A' && msg[i] <= 'Z')
        {
            /*Chaque lettre du message va etre cod�
              On incremente la cle pour le d�calage dans le sens inverse
              On conserve le r�sultat avec modulo 26*/
            msg2[i] = 'A' + ((msg[i] - 'A') + 26-cle)%26;
        }
        if (msg[i] == ' ')
        {
            msg2[i] = ' ';
        }
        i++;    //On code pour chaque nombre de lettre dans le message
    }

    //On affiche le message d�cod�
    printf("message dechiffre : %s\n",msg2);
}

/*Fonction pour coder le message, on prends un pointeur
  pour le message et la variable 'cle' prends la valeur
  de la variable 'cle1'*/
void code_cesar_auto(char *msg, int cle)
{
    int i = 0;
    /*Tant que le message ne contient pas le caract�re '\0',
      on code toutes les lettres du message*/
    while (msg[i] != '\0')
    {
        //Si les caract�res du message sont compris entre 'a' et 'z'
        if (msg[i] >= 'a' && msg[i] <= 'z')
        {
            /*Chaque lettre du message va etre cod�
              On incremente la cle pour le d�calage
              On conserve le r�sultat avec modulo 26*/
            msg[i] = 'a' + ((msg[i] - 'a') + cle)%26;
        }
        if (msg[i] >= 'A' && msg[i] <= 'Z')
        {
            /*Chaque lettre du message va etre cod�
              On incremente la cle pour le d�calage
              On conserve le r�sultat avec modulo 26*/
            msg[i] = 'A' + ((msg[i] - 'A') + cle)%26;
        }
        if (msg[i] == ' ')
        {
            msg[i] = ' ';
        }
        i++;    //On code pour chaque nombre de lettre dans le message
    }
    //On affiche le message cod�
    printf("Message code : %s\n",msg);
}

void chercher(char *mot, FILE *file, int n_line)
{
    int counter = 0;
    //Si le fichier n'est pas trouv�
    if (file == NULL)
    {
        puts("Erreur de lecture");
        exit(1);
    }
    while (counter != n_line)
    {
        /*On fait une recherche dans le fichier
          Avec un num�ro ligne al�atoire
          On s�l�ctionne le mot � la ligne s�l�ctionn�e*/
        fgets(mot, MAX_CHAR, file);
        //Si on ne trouve pas de lignes qui correspond
        if(mot == NULL)
        {
            puts("Ligne non trouv�e");
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

    /*On g�n�re un nombre al�atoire pour la variable 'al�atoire' pour entre 1 et 61
      Pour trouver une ligne dans le fichier texte*/
    aleatoire = rand() % MAX_CHAR + 1;

    //On cherche un mot dans le fichier � partir d'une ligne al�atoire
    chercher(msg, fichier, aleatoire);

    int lca = strlen(msg) - 1;

    //On g�n�re une valeur al�atoire entre 1 et 26 pour la cle
    cle1 = rand() % 26 + 1;

    printf("\nCODE CESAR AUTOMATIQUE\n");

    /*Si le message ne depasse pas la limite de caract�re autoris�e et si la cl� propos�e
      se situe bien entre 1 et 26*/
    if(strlen(msg) >=1 && strlen(msg) <= 61)
    {
        if(cle1 >= 1 && cle1 <= 26)
        {
            //Appel de la fonction pour coder le message en fonction de la cl� de cryptage
            code_cesar_auto(msg, cle1);

            printf("\nRESOLUTION CODE CESAR AUTOMATIQUE\n");

            //La variable 'msg2' prends la meme taille que le message choisi
            char msg2[lca];

            //Pour toutes les valeurs possibles entre 1 et 26, on d�chiffrer le message
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
