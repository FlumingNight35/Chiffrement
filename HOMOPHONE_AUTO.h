#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_CHAR 61

void chercher_homophone(char *mot, FILE *file, int n_line)
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

void CODE_HOMOPHONE_AUTO()
{
    int aleatoire;
    char msg[MAX_CHAR];
    char cle[MAX_CHAR];
    int i = 0;
    int j;
    int nbr3;
    char tab[25] = {'a','b','c','d','e',
                    'f','g','h','i','j',
                    'k','l','m','n','o',
                    'p','q','r','s','t',
                    'u','v','x','y','z'};
    char msg1[50];
    char msg2[25];
    FILE *fichier;
    srand(time(NULL));

    //On cherche dans le fichier 'liste_francais.txt'
    fichier = fopen("liste_francais.txt","rt");

    /*On génère un nombre aléatoire pour la variable 'aléatoire' pour entre 1 et 61
      Pour trouver une ligne dans le fichier texte*/
    aleatoire = rand() % MAX_CHAR + 1;

    //On cherche un mot dans le fichier à partir d'une ligne aléatoire
    chercher_homophone(msg, fichier, aleatoire);

    //printf("%s",msg);

    aleatoire = rand() % MAX_CHAR + 1;

    chercher_homophone(cle, fichier, aleatoire);

    printf("\nCHIFFREMENT HOMOPHONE AUTOMATIQUE\n");

    /*La variable 'lca' est égale à la longueur de la clé entrée + 25*/
    int lca = strlen(cle)+25;


            /*Ici on ajoute la clé*/
            for(i = 0; i < strlen(cle); i++)
            {
                msg1[i] = cle[i];
            }

            /*La variable nbr3 prends la valeur de la variable lca*/
            nbr3 = lca;

            /*On ajoute la clé dans le tableau contenant l'alphabet*/
            for(i = 0, j = strlen(cle); j < nbr3 && i < 25; i++, j++)
            {
                msg1[j] = tab[i];
            }

            /*Supprimer les doublons*/
            for (i = 0; i < nbr3; ++i)
            {
                for (j = i + 1; j < nbr3; ++j)
                {
                    if (msg1[i] == msg1[j])
                    {
                        if(j < nbr3)
                        {
                            memmove(&msg1[j],&msg1[j+1],(nbr3-j)*sizeof(*msg1));
                        }
                    }
                }
            }

            /*Codage du message*/
            for(i=0;msg[i]!=0;i++)
            {
                if((msg[i]>='a') && (msg[i]<='z'))
                {
                    int rang = msg[i] - 'a';
                    msg2[i] = msg1[rang];
                }
                if((msg[i]>='A') && (msg[i]<='Z'))
                {
                    int rang = msg[i] - 'A';
                    msg2[i] = toupper(msg1[rang]);
                }
                if(msg[i] == ' ')
                {
                    msg2[i] = ' ';
                }
            }
            msg2[i]='\0';

            /*Affichage message codé*/
            printf("\nMessage code : %s\n",msg2);

            printf("\nRESOLUTION CHIFFREMENT HOMOPHONE\n");

            /*Décodage du message*/
            for(i=0;msg2[i]!='\0';i++)
            {
                if((msg2[i]>='a') && (msg2[i]<='z'))
                {
                    char * pos = strchr(msg1,msg2[i]);
                    int rang = pos - msg1;
                    msg[i] = 'a' + rang;
                }
                if((msg2[i]>='A') && (msg2[i]<='Z'))
                {
                    char * pos = strchr(msg1,tolower(msg2[i]));
                    int rang = pos - msg1;
                    msg[i] = 'A' + rang;
                }
                if(msg2[i]==' ')
                {
                    msg[i] = ' ';
                }
            }
            msg[i]='\0';

            /*Affichage message décodé*/
            printf("\nMessage decode : %s",msg);

            /*Affichage de la clé de cryptage utilisé*/
            printf("\nLa cle de cryptage etait : %s\n",cle);
}
