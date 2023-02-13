#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "forca.h"

//variaveis globais
char palavraSecreta[TAMANHO_PALAVRA];
char chutes[26];
int chutesDados = 0;

void abertura(){
    printf("*********************\n");
    printf("*   Jogo de Forca   *\n");
    printf("*********************\n\n");
}

void chuta(){
    char chute;
    printf("Qual letra? ");
    scanf(" %c", &chute);

    chutes[chutesDados] = chute;
    chutesDados++;
}

int letraExiste(char letra) {

    for(int j = 0; j < strlen(palavraSecreta); j++) {
        if(letra == palavraSecreta[j]) {
            return 1;
        }
    }

    return 0;
}

int chutesErrados(){
    int erros = 0;

    for(int i = 0; i < chutesDados; i++) {

        if(!letraExiste(chutes[i])) {
            erros++;
        }
    }

    return erros;
}


void desenhaForca(){
    int erros = chutesErrados();
    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (erros>=1?'(':' '), (erros>=1?'_':' '), (erros>=1?')':' '));
    printf(" |      %c%c%c  \n", (erros>=3?'\\':' '), (erros>=2?'|':' '), (erros>=3?'/': ' '));
    printf(" |       %c     \n", (erros>=2?'|':' '));
    printf(" |      %c %c   \n", (erros>=4?'/':' '), (erros>=4?'\\':' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");

    for(int i = 0; i < strlen(palavraSecreta); i++) {
        int achou = jaChutou(palavraSecreta[i]);

        if(achou) {
            printf("%c ", palavraSecreta[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

int acertou(){
    for(int i = 0; i < strlen(palavraSecreta); i++){
        if(!jaChutou(palavraSecreta[i])){
            return 0;
        }
    }
    return 1;
}

int enforcou(){
    int erros = 0;
    for(int i = 0; i < chutesDados; i++){
        int existe = 0;
        for(int j = 0; j < strlen(palavraSecreta); j++){
            if(chutes[i] == palavraSecreta[j]){
                existe = 1;
                break;
            }
        }
        if(!existe) erros++;
    }
    return erros >= 5;
}

void adicionaPalavra(){
    char quer;
    printf("Voce deseja adicionar uma nova palavra no jogo (S/N)?");
    scanf(" %c", &quer);
    if(quer == 'S'){
        char novaPalavra[TAMANHO_PALAVRA];
        printf("Qual a nova palavra? ");
        scanf("%s", novaPalavra);

        FILE* f;
        f = fopen("palavras.txt", "r+");
        if(f == 0){
            printf("Desculpe, o banco de dados nao disponivel\n\n");
            exit(1);
        }

        int quantidade;
        fscanf(f, "%d", &quantidade);
        quantidade++;

        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", quantidade);

        fseek(f, 0, SEEK_END);

        fprintf(f, "%s", novaPalavra);
        fclose(f);
    }
}

void escolhePalavra(){
    FILE* f;
    f = fopen("palavras.txt", "r");
    if(f == 0){
        printf("Desculpe, o banco de dados nao disponivel\n\n");
        exit(1);
    }

    int quantidadeDePalavras;
    fscanf(f, "%d", &quantidadeDePalavras);

    srand(time(0));
    int randomico = rand() % quantidadeDePalavras;

    for(int i = 0; i <= randomico; i++){
        fscanf(f, "%s", palavraSecreta);
    }
    fclose(f);
}

int jaChutou(char letra){
    int achou = 0;
    for(int j = 0; j < chutesDados; j++) {
        if(chutes[j] == letra) {
            achou = 1;
            break;
        }
    }
    return achou;
}

int main(){
    escolhePalavra();
    abertura();
    do {
        desenhaForca();
        chuta();

    } while(!acertou() && !enforcou());
    if(acertou()) {
        printf("\nParabens, voce ganhou!\n\n");

        printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");

    } else {
        printf("\nPuxa, voce foi enforcado!\n");
        printf("A palavra era **%s**\n\n", palavraSecreta);

        printf("    _______________         \n");
        printf("   /               \\       \n");
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n");
    }

    adicionaPalavra();
    return 0;
}
