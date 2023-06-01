#include <stdio.h>


int main (int argc, char** argv) {

    /* abre arquivo de entrada */
    if (argc != 2) {
        /* mensagem explicando o erro e sai */
    }
    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        /* mensagem explicando o erro e sai */
    }
    
    /* le primeira linha do arquivo de entrada */
    int numVertices, numArestas, numConsultas;
    if (fscanf(fp, "%d %d %d", &numVertices, &numArestas, &numConsultas) != 3){
        /* mensagem explicando o erro e sai */
    }
    int a, b;
    float c;
    if (fscanf(fp, "%d %d %f", &a, &b, &c) != 3){
        /* mensagem explicando o erro e sai */
    }

    /* só testando se li certo */
    printf("%d %d %d %d %d %.1f\n", numVertices, numArestas, numConsultas, a, b, c);


    /* depois de ler todo o arquivo não esqueça de fechá-lo */
    fclose(fp);

    /* gerando arquivo de saída */
    fp = fopen("saida.txt", "w");
    fprintf(fp, "teste\n");
    
    fprintf(fp, "\n");
    fclose(fp);
}