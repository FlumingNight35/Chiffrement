#include <ctype.h>
#include <stdio.h>

void CODE_HOMOPHONE(char msg[50], char cle[26])
{
    int i = 0;
    int j;
    int nbr3;
    char tab[50] = {'a','b','c','d','e',
                    'f','g','h','i','j',
                    'k','l','m','n','o',
                    'p','q','r','s','t',
                    'u','v','w','x','y',
                    'z'};
    char msg1[50];
    char msg2[50];

    FILE* fichier = NULL;
    fichier = fopen("CODE_HOMOPHONE.txt", "a+");

    printf("\nCHIFFREMENT HOMOPHONE\n");

    printf("\nMessage : ");
    gets(msg);

    //Ecriture du message dans le fichier texte
    fprintf(fichier, "%s => ", msg);

    printf("Cle : ");
    scanf("%s",cle);

    /*La variable 'lca' est égale à la longueur de la clé entrée + 25*/
    int lca = strlen(cle)+26;

    if(strlen(msg) >=1 && strlen(msg) <= 50)
    {
        if(strlen(cle) >= 1 && strlen(cle) <= 26)
        {
            /*Ici on ajoute la clé*/
            for(i = 0; i < strlen(cle); i++)
            {
                msg1[i] = cle[i];
            }

            /*La variable nbr3 prends la valeur de la variable lca*/
            nbr3 = lca;

            /*On ajoute la clé dans le tableau contenant l'alphabet*/
            for(i = 0, j = strlen(cle); j < nbr3 && i < 50; i++, j++)
            {
                msg1[j] = tab[i];
            }

            // Supprimer les doublons
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

            //Codage du message
            for(i=0;msg[i]!=0;i++)
            {
                //Pour les lettres en minuscules
                if((msg[i]>='a') && (msg[i]<='z'))
                {
                    int rang = msg[i] - 'a';
                    msg2[i] = msg1[rang];
                }
                //Pour les lettres en majuscules
                if((msg[i]>='A') && (msg[i]<='Z'))
                {
                    /*La fonction toupper converti les minuscules en majuscules*/
                    int rang = msg[i] - 'A';
                    msg2[i] = toupper(msg1[rang]);
                }
                //Pour les espaces
                if(msg[i] == ' ')
                {
                    msg2[i] = ' ';
                }
            }
            msg2[i]='\0';

            //Affichage message codé
            printf("\nMessage code : %s\n",msg2);

            //Ecriture du message dans le fichier texte
            fprintf(fichier, "%s", msg2);

            printf("\nRESOLUTION CHIFFREMENT HOMOPHONE\n");

            //Décodage du message
            for(i=0;msg2[i]!='\0';i++)
            {
                //Pour les lettres en minuscules
                if((msg2[i]>='a') && (msg2[i]<='z'))
                {
                    /*La fonction strchr cherche les caractères de msg1 dans msg2*/
                    char * pos = strchr(msg1,msg2[i]);
                    int rang = pos - msg1;
                    msg[i] = 'a' + rang;
                }
                //Pour les lettres en majuscules
                if((msg2[i]>='A') && (msg2[i]<='Z'))
                {
                    /*La fonction tolower converti les majuscules en minuscules*/
                    char * pos = strchr(msg1,tolower(msg2[i]));
                    int rang = pos - msg1;
                    msg[i] = 'A' + rang;
                }
                //Pour les espaces
                if(msg2[i] == ' ')
                {
                    msg[i] = ' ';
                }
            }
            msg[i]='\0';

            //Affichage message décodé
            printf("\nMessage decode : %s\n",msg);

            //Ecriture du message dans le fichier texte
            fprintf(fichier, " => %s", msg);
            fprintf(fichier, "\n");
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

