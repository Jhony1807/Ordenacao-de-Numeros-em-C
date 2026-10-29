// Atividade 03: ordenacao de numeros com arquivos
// Cria dados.txt, le os dados, ordena (5 algoritmos), salva em ordenado.txt
// e permite alterar um valor do arquivo e reordenar.
#include <stdio.h>   // printf, fopen, fprintf, fscanf, fgets
#include <stdlib.h>  // atoi, rand, srand
#include <time.h>    // time (usado para sortear numeros diferentes a cada vez)

#define MAX 100                  // maximo de numeros
#define DADOS "dados.txt"        // arquivo com os valores originais (entrada)
#define ORDENADO "ordenado.txt"  // arquivo com os valores ordenados

// ---------- Funcoes auxiliares ----------

// Le um numero inteiro digitado no teclado
int lerInteiro() {
    char linha[50];
    if (fgets(linha, 50, stdin) == NULL) {   // se a entrada acabou, devolve 0 (sair)
        return 0;
    }
    return atoi(linha);          // converte o texto para inteiro
}

// Troca dois valores de lugar usando ponteiros
void trocar(int *a, int *b) {
    int aux = *a;                // guarda o valor de a
    *a = *b;                     // a recebe o valor de b
    *b = aux;                    // b recebe o antigo valor de a
}

// Mostra o vetor na tela
void mostrar(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

// ---------- Arquivos ----------

// Le os numeros do arquivo para o vetor e devolve quantos leu
int lerArquivo(char *nome, int v[]) {
    FILE *arq = fopen(nome, "r");            // abre para leitura
    int n = 0;                               // quantidade de numeros lidos
    if (arq == NULL) {                       // arquivo nao existe
        return 0;
    }
    while (n < MAX && fscanf(arq, "%d", &v[n]) == 1) {   // le um numero por vez
        n++;
    }
    fclose(arq);
    return n;
}

// Grava o vetor no arquivo, um numero por linha
void gravarArquivo(char *nome, int v[], int n) {
    FILE *arq = fopen(nome, "w");            // abre para escrita (apaga o conteudo antigo)
    if (arq == NULL) {
        printf("Erro ao gravar %s!\n", nome);
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(arq, "%d\n", v[i]);
    }
    fclose(arq);
}

// ---------- Algoritmos de ordenacao ----------

// Bubble Sort: compara vizinhos e troca se estiverem fora de ordem
void bubbleSort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                trocar(&v[j], &v[j + 1]);
            }
        }
    }
}

// Selection Sort: acha o menor valor e coloca na primeira posicao livre
void selectionSort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int menor = i;                       // posicao do menor valor encontrado
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[menor]) {
                menor = j;
            }
        }
        trocar(&v[i], &v[menor]);
    }
}

// Insertion Sort: pega cada valor e "encaixa" na parte ja ordenada
void insertionSort(int v[], int n) {
    for (int i = 1; i < n; i++) {
        int atual = v[i];                    // valor que sera encaixado
        int j = i - 1;
        while (j >= 0 && v[j] > atual) {     // empurra os maiores para a direita
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = atual;                    // coloca o valor no lugar certo
    }
}

// Junta duas metades ja ordenadas (ini..meio e meio+1..fim) em ordem
void intercalar(int v[], int aux[], int ini, int meio, int fim) {
    int i = ini;                             // percorre a primeira metade
    int j = meio + 1;                        // percorre a segunda metade
    int k = ini;                             // posicao no vetor auxiliar
    while (i <= meio && j <= fim) {          // pega sempre o menor entre os dois
        if (v[i] <= v[j]) {
            aux[k] = v[i];
            i++;
        } else {
            aux[k] = v[j];
            j++;
        }
        k++;
    }
    while (i <= meio) {                      // sobrou algo na primeira metade
        aux[k] = v[i];
        i++;
        k++;
    }
    while (j <= fim) {                       // sobrou algo na segunda metade
        aux[k] = v[j];
        j++;
        k++;
    }
    for (k = ini; k <= fim; k++) {           // copia o resultado de volta para v
        v[k] = aux[k];
    }
}

// Merge Sort: divide o vetor ao meio, ordena cada metade e junta
void mergeSort(int v[], int aux[], int ini, int fim) {
    if (ini < fim) {
        int meio = (ini + fim) / 2;
        mergeSort(v, aux, ini, meio);        // ordena a primeira metade
        mergeSort(v, aux, meio + 1, fim);    // ordena a segunda metade
        intercalar(v, aux, ini, meio, fim);  // junta as duas
    }
}

// Quick Sort: escolhe um pivo, separa menores e maiores, repete em cada lado
void quickSort(int v[], int ini, int fim) {
    if (ini < fim) {
        int pivo = v[fim];                   // pivo = ultimo elemento
        int i = ini - 1;                     // fim da area dos menores que o pivo
        for (int j = ini; j < fim; j++) {
            if (v[j] < pivo) {
                i++;
                trocar(&v[i], &v[j]);
            }
        }
        trocar(&v[i + 1], &v[fim]);          // coloca o pivo no lugar certo
        int p = i + 1;                       // posicao final do pivo
        quickSort(v, ini, p - 1);            // ordena os menores
        quickSort(v, p + 1, fim);            // ordena os maiores
    }
}

// ---------- Opcoes do menu ----------

// Cria o arquivo dados.txt com numeros desordenados
void criarDados() {
    int v[MAX];
    printf("Quantos numeros (1 a %d)? ", MAX);
    int n = lerInteiro();
    if (n < 1 || n > MAX) {
        printf("Quantidade invalida.\n");
        return;
    }
    printf("1 - Digitar os numeros\n2 - Gerar numeros aleatorios\nEscolha: ");
    int modo = lerInteiro();
    if (modo == 1) {
        for (int i = 0; i < n; i++) {
            printf("Numero %d: ", i + 1);
            v[i] = lerInteiro();
        }
    } else {
        srand(time(NULL));                   // muda a sequencia sorteada a cada execucao
        for (int i = 0; i < n; i++) {
            v[i] = rand() % 100 + 1;         // numero de 1 a 100
        }
    }
    gravarArquivo(DADOS, v, n);
    printf("Arquivo %s criado com: ", DADOS);
    mostrar(v, n);
}

// Mostra o conteudo de um arquivo (dados.txt ou ordenado.txt)
void mostrarArquivo(char *nome) {
    int v[MAX];
    int n = lerArquivo(nome, v);
    if (n == 0) {
        printf("Arquivo %s vazio ou nao existe.\n", nome);
        return;
    }
    printf("%s: ", nome);
    mostrar(v, n);
}

// Pergunta o algoritmo, ordena uma copia dos dados e salva em ordenado.txt
void ordenarEGravar(int dados[], int n) {
    int v[MAX];
    printf("1 - Bubble\n2 - Insertion\n3 - Selection\n4 - Merge\n5 - Quick\nAlgoritmo: ");
    int alg = lerInteiro();
    if (alg < 1 || alg > 5) {
        printf("Opcao invalida.\n");
        return;
    }
    for (int i = 0; i < n; i++) {            // ordena uma copia, dados.txt nao muda
        v[i] = dados[i];
    }
    if (alg == 1)      bubbleSort(v, n);
    else if (alg == 2) insertionSort(v, n);
    else if (alg == 3) selectionSort(v, n);
    else if (alg == 4) {
        int aux[MAX];                        // vetor auxiliar do Merge Sort
        mergeSort(v, aux, 0, n - 1);
    }
    else               quickSort(v, 0, n - 1);

    gravarArquivo(ORDENADO, v, n);           // salva o resultado em outro arquivo
    printf("Ordenado e salvo em %s: ", ORDENADO);
    mostrar(v, n);
}

// Opcao 3: le dados.txt e ordena
void ordenar() {
    int dados[MAX];
    int n = lerArquivo(DADOS, dados);        // le os valores do arquivo
    if (n == 0) {
        printf("Crie o arquivo %s primeiro (opcao 1).\n", DADOS);
        return;
    }
    ordenarEGravar(dados, n);
}

// Opcao 4: altera um valor de dados.txt e reordena
void alterar() {
    int dados[MAX];
    int n = lerArquivo(DADOS, dados);
    if (n == 0) {
        printf("Crie o arquivo %s primeiro (opcao 1).\n", DADOS);
        return;
    }
    for (int i = 0; i < n; i++) {            // mostra as posicoes para facilitar
        printf("Posicao %d: %d\n", i + 1, dados[i]);
    }
    printf("Qual posicao deseja alterar? ");
    int pos = lerInteiro();
    if (pos < 1 || pos > n) {
        printf("Posicao invalida.\n");
        return;
    }
    printf("Novo valor: ");
    dados[pos - 1] = lerInteiro();           // posicao 1 fica no indice 0
    gravarArquivo(DADOS, dados, n);          // grava a alteracao no arquivo
    printf("Valor alterado. Vamos reordenar:\n");
    ordenarEGravar(dados, n);                // reordena com o novo valor
}

// ---------- Programa principal ----------

int main() {
    int opcao;
    do {
        printf("\n===== ORDENACAO COM ARQUIVOS =====\n");
        printf("1 - Criar arquivo de dados\n");
        printf("2 - Mostrar dados originais\n");
        printf("3 - Ordenar e salvar\n");
        printf("4 - Alterar um valor e reordenar\n");
        printf("5 - Mostrar dados ordenados\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        opcao = lerInteiro();

        if (opcao == 1)      criarDados();
        else if (opcao == 2) mostrarArquivo(DADOS);
        else if (opcao == 3) ordenar();
        else if (opcao == 4) alterar();
        else if (opcao == 5) mostrarArquivo(ORDENADO);
        else if (opcao != 0) printf("Opcao invalida!\n");
    } while (opcao != 0);

    return 0;
}
