#include <string.h>
#include <time.h>
#include "CESAR.h"
#include "HOMOPHONE.h"
#include "CESAR_AUTO.h"
#include "HOMOPHONE_AUTO.h"

int main()
{
    char chx_cesar[50] = "cesar";
    char chx_cesar_auto[50] = "cesar automatique";
    char chx_homophone[50] = "homophone";
    char chx_homophone_auto[50] = "homophone automatique";
    char chx[50];
    char msg[50];
    int cle1 = 0;
    int cle2 = 0;
    char cle3[26];

    printf("PROGRAMME CHIFFREMENT - HERVE Camille \n");
    printf("\nChoisissez le type de chiffrement : \n");
    printf("- Chiffrement cesar\n");
    printf("- Chiffrement cesar automatique\n");
    printf("- Chiffrement homophone\n");
    printf("- Chiffrement homophone automatique\n");
    printf("\nEntrez le nom correspondant au chiffrement voulue : ");
    gets(chx);

    if(strcmp(chx,chx_cesar) == 0)
    {
        CODE_CESAR(msg);                            //Appel de la fonction pour le code de César
    }
    else if(strcmp(chx,chx_homophone) == 0)
    {
        CODE_HOMOPHONE(msg, cle3);                  //Appel de la fonction pour le chiffrement homophone
    }
    else if(strcmp(chx,chx_cesar_auto) == 0)
    {
        CODE_CESAR_AUTO(cle1, cle2);                //Appel de la fonction pour le code de César automatique
    }
    else if(strcmp(chx,chx_homophone_auto) == 0)
    {
        CODE_HOMOPHONE_AUTO();                      //Appel de la fonction pour le chiffrement homophone automatique
    }

}
