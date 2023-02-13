#include <stdio.h>
#include <string.h>
int main(){
    /*
    char letra1 = 'O';
    char letra2 = 'L';
    char letra3 = 'A';
    printf("%c%c%c\n", letra1, letra2, letra3);
    */

    //Arrays
    /*
    int notas[10];

    notas[0] = 10;
    notas[2] = 15;
    notas[3] = 20;
    notas[9] = 30;
    printf("notas %d %d %d\n", notas[0], notas[2], notas[9]);
    */

    char palavraSecreta[20];
    /*
    palavraSecreta[0] = 'M';
    palavraSecreta[1] = 'E';
    palavraSecreta[2] = 'L';
    palavraSecreta[3] = 'A';
    palavraSecreta[4] = 'N';
    palavraSecreta[5] = 'C';
    palavraSecreta[6] = 'I';
    palavraSecreta[7] = 'A';
    palavraSecreta[8] = '\0';

    printf("%c%c%c%c%c%c%c%c\n", palavraSecreta[0], palavraSecreta[1],
           palavraSecreta[2], palavraSecreta[3], palavraSecreta[4], palavraSecreta[5],
           palavraSecreta[6], palavraSecreta[7]);
    */
    sprintf(palavraSecreta, "MELANCIA");
    //printf("%s", palavraSecreta);

    int acertou = 0;
    int inforcou = 0;

    char chutes[26];
    int tentativas = 0;
    do {

        for(int i = 0; i < strlen(palavraSecreta); i++) {
            int achou = 0;

            for(int j = 0; j < tentativas; j++) {
                if(chutes[j] == palavraSecreta[i]) {
                    achou = 1;
                    break;
                }
            }

            if(achou) {
                printf("%c ", palavraSecreta[i]);
            } else {
                printf("_ ");
            }
        }
        printf("\n");

        char chute;
        printf("Qual letra? ");
        scanf(" %c", &chute);

        chutes[tentativas] = chute;
        tentativas++;
        /*
        for(int i = 0; i < strlen(palavraSecreta); i++){
            printf("Estou vendo a letra %c na posicao %d\n", palavraSecreta[i], i);
            if(palavraSecreta[i] == chute){
                printf("A posicao %d tem essa letra\n", i);
            }
        }
        */
    } while(!acertou && !inforcou);//while(acertou == 0 && inforcou == 0);

    return 0;
}
