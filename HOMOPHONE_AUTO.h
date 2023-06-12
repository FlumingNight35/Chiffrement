#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_CHAR 61

void chercher_homophone(char *mot, FILE *file, int n_line)
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

    /*On g�n�re un nombre al�atoire pour la variable 'al�atoire' pour entre 1 et 61
      Pour trouver une ligne dans le fichier texte*/
    aleatoire = rand() % MAX_CHAR + 1;

    //On cherche un mot dans le fichier � partir d'une ligne al�atoire
    chercher_homophone(msg, fichier, aleatoire);

    //printf("%s",msg);

    aleatoire = rand() % MAX_CHAR + 1;

    chercher_homophone(cle, fichier, aleatoire);

    printf("\nCHIFFREMENT HOMOPHONE AUTOMATIQUE\n");

    /*La variable 'lca' est �gale � la longueur de la cl� entr�e + 25*/
    int lca = strlen(cle)+25;


            /*Ici on ajoute la cl�*/
            for(i = 0; i < strlen(cle); i++)
            {
                msg1[i] = cle[i];
            }

            /*La variable nbr3 prends la valeur de la variable lca*/
            nbr3 = lca;

            /*On ajoute la cl� dans le tableau contenant l'alphabet*/
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

            /*Affichage message cod�*/
            printf("\nMessage code : %s\n",msg2);

            printf("\nRESOLUTION CHIFFREMENT HOMOPHONE\n");

            /*D�codage du message*/
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

            /*Affichage message d�cod�*/
            printf("\nMessage decode : %s",msg);

            /*Affichage de la cl� de cryptage utilis�*/
            printf("\nLa cle de cryptage etait : %s\n",cle);
}
