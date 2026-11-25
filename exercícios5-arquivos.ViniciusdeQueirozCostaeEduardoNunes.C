//Obs: Professor, neste codigo utilizei o arquivo .txt ao inves do .csv; No Online GDB, o arquivo .csv estava acusando erro (infelizmente não entendi o do porque),mas, trocando por .txt resolveu o mesmo sem alterar o resultado final. Para resolver eu fiz o seguinte, alterei  nome do segundo aquivo para "notas.txt" e na linha 17 eu alterei de arquivo = fopen("notas.csv", "r"); para arquivo = fopen("notas.txt", "r"); .Obrigado pela compreenção :).

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *arquivo;
    char linha[200];
    char *campo;
    char nome[100];

    float nota1, nota2, nota3;
    float media, somaMedias = 0;
    int quantidade = 0;

    arquivo = fopen("notas.txt", "r"); //Aqui eu mudei de .csv para .txt

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    fgets(linha, sizeof(linha), arquivo);

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {

        campo = strtok(linha, ",");
        strcpy(nome, campo);

        campo = strtok(NULL, ",");
        nota1 = atof(campo);

        campo = strtok(NULL, ",");
        nota2 = atof(campo);

        campo = strtok(NULL, ",");
        nota3 = atof(campo);

        media = (nota1 + nota2 + nota3) / 3.0;

        printf("%s - Media: %.2f\n", nome, media);

        somaMedias += media;
        quantidade++;
    }

    if (quantidade > 0) {
        printf("\nMedia da turma: %.2f\n",
               somaMedias / quantidade);
    }

    fclose(arquivo);

    return 0;
}
