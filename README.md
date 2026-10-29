# Ordenacao-de-Numeros-em-C
TRABALHO ACADÊMICO

# Atividade Avaliativa 03 — Ordenação de Números com Arquivos em C

## 1. Especificações da atividade

A atividade tinha como objetivo unir os conceitos de algoritmos de ordenação com a manipulação de arquivos na linguagem C.

Foi solicitado o desenvolvimento de um único programa completo que atendesse aos seguintes requisitos:

1. **Criar e gravar um arquivo:** criar um arquivo com dados numéricos desordenados.
2. **Ler os dados do arquivo:** permitir que o programa leia os números armazenados.
3. **Escolher o tipo de ordenação:** permitir que o usuário escolha entre cinco algoritmos: Bubble Sort, Insertion Sort, Selection Sort, Merge Sort e Quick Sort.
4. **Ordenar e salvar os resultados:** organizar os números em ordem crescente e salvar o resultado em um novo arquivo.
5. **Alterar um valor e ordenar novamente:** permitir que o usuário modifique um número do arquivo original e execute novamente a ordenação.

A atividade também recomendava utilizar os conteúdos dos planos de aula 8, 9, 11 e 12.

## 2. Objetivo do programa

O programa foi desenvolvido em linguagem C para praticar o uso de arquivos, vetores, funções, estruturas de repetição, condições e algoritmos de ordenação.

Ele possui um menu interativo que permite ao usuário escolher o que deseja fazer, sem precisar executar uma operação diferente para cada tarefa.

O programa trabalha com até 100 números inteiros e permite tanto digitar os valores manualmente quanto gerar números aleatórios.

## 3. Arquivos utilizados

O programa utiliza dois arquivos principais:

- **dados.txt:** armazena os números originais, que podem estar desordenados. Quando o usuário altera um valor, a mudança também é gravada nesse arquivo.
- **ordenado.txt:** armazena os números depois que o método de ordenação escolhido é aplicado.

Os arquivos são criados automaticamente pelo programa quando necessário, na pasta em que ele é executado.

## 4. Explicação do código

### 4.1. Bibliotecas e constantes

No começo do código, são utilizadas três bibliotecas:

- `stdio.h`: permite mostrar informações na tela, receber entradas e trabalhar com arquivos.
- `stdlib.h`: permite utilizar funções como `atoi()` e `rand()`.
- `time.h`: permite utilizar `time()` para ajudar a gerar sequências diferentes de números aleatórios.

Também são definidas três constantes:

- `MAX 100`: determina a quantidade máxima de números.
- `DADOS "dados.txt"`: define o nome do arquivo original.
- `ORDENADO "ordenado.txt"`: define o nome do arquivo que recebe os números ordenados.

### 4.2. Função lerInteiro()

Essa função recebe um número digitado pelo usuário.

Ela utiliza `fgets()` para ler o texto digitado e `atoi()` para converter esse texto em um número inteiro.

Isso facilita a leitura das opções do menu e dos valores informados durante a execução.

### 4.3. Função trocar()

A função `trocar()` serve para inverter a posição de dois valores.

Ela utiliza ponteiros para acessar e modificar os valores originais das variáveis.

Essa função é utilizada pelos algoritmos Bubble Sort, Selection Sort e Quick Sort para trocar números de lugar.

### 4.4. Função mostrar()

A função `mostrar()` exibe os números armazenados em um vetor.

Ela utiliza um comando `for` para percorrer os elementos e mostrar cada número na tela.

### 4.5. Funções para manipulação de arquivos

O programa possui duas funções principais para trabalhar com os arquivos.

**lerArquivo():** abre um arquivo para leitura e copia os números encontrados para um vetor. Ela retorna a quantidade de números lidos. Se o arquivo não existir, retorna zero.

**gravarArquivo():** abre um arquivo para escrita e grava os números, colocando cada valor em uma linha. Se o arquivo já existir, seu conteúdo anterior será substituído.

Essas funções evitam que seja necessário repetir o mesmo código de leitura e gravação em várias partes do programa.

## 5. Algoritmos de ordenação

O programa possui cinco métodos diferentes para organizar os números em ordem crescente.

### 5.1. Bubble Sort

O Bubble Sort compara os números vizinhos e troca suas posições quando o número da esquerda é maior que o da direita.

Esse processo se repete até que todos os números estejam na ordem correta.

### 5.2. Selection Sort

O Selection Sort procura o menor número da parte ainda não ordenada e o coloca na posição correta.

O processo continua até que todos os elementos estejam organizados.

### 5.3. Insertion Sort

O Insertion Sort percorre o vetor e encaixa cada número na posição correta em relação aos números anteriores.

Ele desloca os valores maiores para a direita até encontrar o lugar adequado para o número atual.

### 5.4. Merge Sort

O Merge Sort divide o vetor em partes menores até que seja possível organizar os elementos individualmente.

Depois, utiliza a função `intercalar()` para juntar as partes em ordem crescente.

Para realizar esse processo, o código utiliza um vetor auxiliar que armazena temporariamente os números durante a intercalação.

### 5.5. Quick Sort

O Quick Sort escolhe um número chamado pivô, que neste código é o último elemento da parte analisada.

Os números menores que o pivô são separados dos demais. Depois, o algoritmo repete o processo nas duas partes até que todo o vetor esteja ordenado.

## 6. Funções responsáveis pelo funcionamento do programa

### 6.1. Função criarDados()

Essa função cria o arquivo `dados.txt`.

Primeiro, pergunta quantos números serão utilizados. Depois, permite escolher entre digitar os números manualmente ou gerar valores aleatórios entre 1 e 100.

Ao terminar, os números são gravados no arquivo e exibidos na tela.

### 6.2. Função mostrarArquivo()

Essa função recebe o nome de um arquivo, lê seus números e mostra o conteúdo na tela.

Ela pode ser utilizada para visualizar os dados originais ou o resultado da ordenação.

Se o arquivo não existir ou não possuir números válidos para leitura, o programa informa essa situação.

### 6.3. Função ordenarEGravar()

Essa função apresenta as cinco opções de ordenação e executa o algoritmo escolhido pelo usuário.

Antes de ordenar, ela copia os números originais para outro vetor. Dessa forma, a ordenação não modifica diretamente os dados carregados de `dados.txt`.

Depois de ordenar, grava o resultado em `ordenado.txt` e mostra os números organizados na tela.

### 6.4. Função ordenar()

Essa função lê os números de `dados.txt` e verifica se existem dados para ordenar.

Se o arquivo não possuir números, o programa solicita que o usuário crie os dados primeiro.

Caso contrário, chama a função `ordenarEGravar()` para executar a ordenação.

### 6.5. Função alterar()

Essa função permite modificar um número do arquivo original.

Primeiro, mostra os números e suas posições. Depois, solicita a posição que será alterada e o novo valor.

Após a alteração, o programa atualiza `dados.txt` e solicita novamente a escolha de um algoritmo de ordenação. O resultado é salvo em `ordenado.txt`.

### 6.6. Função main()

A função `main()` é a função principal do programa.

Ela apresenta o menu de opções e chama as funções correspondentes à escolha do usuário.

O menu continua aparecendo até que a opção zero seja selecionada, encerrando a execução.

## 7. Opções do menu

O programa apresenta as seguintes opções:

| Opção | Funcionamento |
|---|---|
| 1 | Criar o arquivo de dados, digitando números ou gerando valores aleatórios. |
| 2 | Mostrar os números originais armazenados em `dados.txt`. |
| 3 | Escolher um algoritmo, ordenar os números e salvar em `ordenado.txt`. |
| 4 | Alterar um número do arquivo original e ordenar novamente. |
| 5 | Mostrar os números armazenados em `ordenado.txt`. |
| 0 | Encerrar o programa. |

## 8. Exemplo de funcionamento

Imagine que o usuário escolha a opção 1 e digite os seguintes números:

`8, 3, 10, 1, 5`

Esses valores serão armazenados em `dados.txt`.

Em seguida, ao escolher a opção 3 e selecionar o Bubble Sort, o programa organizará os números em ordem crescente:

`1, 3, 5, 8, 10`

O resultado será gravado em `ordenado.txt`, enquanto os valores originais permanecerão em `dados.txt`.

Se o usuário escolher a opção 4 e alterar o número da segunda posição de `3` para `7`, o arquivo original será atualizado e o programa permitirá executar novamente a ordenação.

## 9. Conclusão

Com o desenvolvimento dessa atividade, foi possível praticar diferentes conceitos da linguagem C, principalmente a criação de funções, a utilização de vetores, a leitura e gravação de arquivos e a implementação de algoritmos de ordenação.

O programa reúne essas funcionalidades em um único sistema com menu interativo, permitindo cadastrar números, visualizar arquivos, escolher métodos de ordenação e modificar valores.

Dessa forma, o trabalho atende aos requisitos propostos na atividade e demonstra, na prática, como os algoritmos de ordenação podem ser utilizados em conjunto com a manipulação de arquivos na linguagem C.
