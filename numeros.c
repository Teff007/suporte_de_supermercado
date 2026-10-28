#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 100
#define TAM_NOME 50

// Estrutura que armazena os dados de cada produto
typedef struct {
    char nome[TAM_NOME];
    float preco;
} Produto;

// Funcao para exibir os produtos e seus precos
void mostrarProdutos(Produto produtos[], int quantidade) {
    int i;

    printf("\n---------------------------------------------\n");
    printf("%-5s %-25s %10s\n", "N.", "PRODUTO", "PRECO (R$)");
    printf("---------------------------------------------\n");

    for (i = 0; i < quantidade; i++) {
        printf("%-5d %-25s R$ %8.2f\n",
               i + 1, produtos[i].nome, produtos[i].preco);
    }

    printf("---------------------------------------------\n");
}

// Bubble Sort: compara produtos vizinhos e troca
// suas posicoes quando o preco esta fora de ordem.
void bubbleSort(Produto produtos[], int quantidade) {
    int i, j;
    Produto temporario;

    for (i = 0; i < quantidade - 1; i++) {
        for (j = 0; j < quantidade - i - 1; j++) {

            if (produtos[j].preco > produtos[j + 1].preco) {
                temporario = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temporario;
            }
        }
    }
}

// Particiona os produtos usando o ultimo preco como pivo.
// Os precos menores ou iguais ao pivo ficam a esquerda.
int particionar(Produto produtos[], int inicio, int fim) {
    float pivo = produtos[fim].preco;
    int i = inicio - 1;
    int j;
    Produto temporario;

    for (j = inicio; j < fim; j++) {
        if (produtos[j].preco <= pivo) {
            i++;

            temporario = produtos[i];
            produtos[i] = produtos[j];
            produtos[j] = temporario;
        }
    }

    // Coloca o pivo na sua posicao correta
    temporario = produtos[i + 1];
    produtos[i + 1] = produtos[fim];
    produtos[fim] = temporario;

    return i + 1;
}

// Quick Sort: divide os produtos em grupos menores
// e maiores em relacao ao pivo, ordenando cada grupo.
void quickSort(Produto produtos[], int inicio, int fim) {
    if (inicio < fim) {
        int posicaoPivo = particionar(produtos, inicio, fim);

        quickSort(produtos, inicio, posicaoPivo - 1);
        quickSort(produtos, posicaoPivo + 1, fim);
    }
}

int main() {
    Produto produtos[MAX_PRODUTOS];
    Produto copia[MAX_PRODUTOS];
    int quantidade, i;
    int caractere;

    printf("=============================================\n");
    printf(" SISTEMA DE ORDENACAO DE PRECOS\n");
    printf(" SUPERMERCADO\n");
    printf("=============================================\n");

    // Solicita a quantidade de produtos ao usuario
    do {
        printf("\nQuantos produtos deseja cadastrar (10 a 100)? ");

        if (scanf("%d", &quantidade) != 1) {
            printf("Entrada invalida. Digite um numero inteiro.\n");

            while ((caractere = getchar()) != '\n' &&
                   caractere != EOF) {
                // Limpa a entrada invalida
            }

            quantidade = 0;
        } else if (quantidade < 10 || quantidade > MAX_PRODUTOS) {
            printf("Cadastre no minimo 10 e no maximo 100 produtos.\n");
        }

    } while (quantidade < 10 || quantidade > MAX_PRODUTOS);

    // Recebe o nome e o preco de cada produto
    for (i = 0; i < quantidade; i++) {
        printf("\nProduto %d\n", i + 1);

        printf("Nome do produto: ");

        // Le nomes com espacos, como "Leite Integral"
        scanf(" %49[^\n]", produtos[i].nome);

        do {
            printf("Preco do produto (R$): ");

            if (scanf("%f", &produtos[i].preco) != 1) {
                printf("Preco invalido. Digite um valor numerico.\n");

                while ((caractere = getchar()) != '\n' &&
                       caractere != EOF) {
                    // Limpa a entrada invalida
                }

                produtos[i].preco = -1;
            } else if (produtos[i].preco < 0) {
                printf("O preco nao pode ser negativo.\n");
            }

        } while (produtos[i].preco < 0);

        // Guarda os mesmos dados para o segundo algoritmo
        copia[i] = produtos[i];
    }

    // Mostra os dados antes da ordenacao
    printf("\n\n===== PRODUTOS ANTES DA ORDENACAO =====\n");
    mostrarProdutos(produtos, quantidade);

    // Ordena uma copia usando Bubble Sort
    bubbleSort(copia, quantidade);

    printf("\n===== RESULTADO DO BUBBLE SORT =====\n");
    mostrarProdutos(copia, quantidade);

    // Ordena os dados originais usando Quick Sort
    quickSort(produtos, 0, quantidade - 1);

    printf("\n===== RESULTADO DO QUICK SORT =====\n");
    mostrarProdutos(produtos, quantidade);

    printf("\nOrdenacao concluida com sucesso!\n");

    return 0;
}
