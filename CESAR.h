#include <stdio.h>

/*Fonction pour d�coder le message, on prends un pointeur
  pour le message et la variable 'cle' prends la valeur
  de la variable 'cle2'*/
void decode_cesar(char *msg, int cle)
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
              On incremente la cle pour le d�calage dans le sens inverse
              On conserve le r�sultat avec modulo 26*/
            msg[i] = 'a' + ((msg[i] - 'a') + 26-cle)%26;
        }
        if (msg[i] >= 'A' && msg[i] <= 'Z')
        {
            /*Chaque lettre du message va etre cod�
              On incremente la cle pour le d�calage dans le sens inverse
              On conserve le r�sultat avec modulo 26*/
            msg[i] = 'A' + ((msg[i] - 'A') + 26-cle)%26;
        }
        if (msg[i] == ' ')
        {
            msg[i] = ' ';
        }
        i++;    //On code pour chaque nombre de lettre dans le message
    }
    //On affiche le message d�cod�
    printf("Message decode : %s\n",msg);
}

/*Fonction pour coder le message, on prends un pointeur
  pour le message et la variable 'cle' prends la valeur
  de la variable 'cle1'*/
void code_cesar(char *msg, int cle)
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

void CODE_CESAR(char msg[50])
{
    //Cr�ation d'un fichier texte
    FILE* fichier = NULL;
    fichier = fopen("CODE_CESAR.txt", "a+");
    int cle;

    //On �crit un message et on donne une cl� de cryptage
    printf("\nCODE CESAR\n");
    printf("Message : ");
    gets(msg);
    printf("Cle : ");
    scanf("%d",&cle);

    if(strlen(msg) >=1 && strlen(msg) <= 50 || msg >= 'a' && msg <= 'z' || msg >= 'A' && msg <= 'Z')
    {
        if(cle >= 1 && cle <= 26)
        {
            //Ecriture du message dans le fichier texte
            fprintf(fichier, "%s", msg);

            //Appel de la fonction pour cod� le message en fonction de la cl� de cryptage
            code_cesar(msg, cle);

            //Ecriture du message cod� dans le fichier texte
            fprintf(fichier, " => %s", msg);

            printf("\nRESOLUTION CODE CESAR\n");

            //Appel de la fonction pour d�coder le message en fonction de la cl� de d�chiffrement
            decode_cesar(msg, cle);

            //Ecriture du message d�cod� dans le fichier texte
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


