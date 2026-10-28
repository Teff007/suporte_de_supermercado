# Sistema de Ordenação de Preços para Supermercado

Aplicação em linguagem C que cadastra produtos de um supermercado e ordena seus preços do menor para o maior, usando dois algoritmos de ordenação: **Bubble Sort** e **Quick Sort**.

## 1. Objetivo da aplicação

Aplicar na prática dois algoritmos clássicos de ordenação em um cenário do cotidiano. O programa recebe uma lista de produtos com nome e preço, ordena os dados com cada algoritmo e exibe os resultados para que seja possível comparar as saídas.

## 2. Situação-problema

Em um supermercado, o cliente ou o operador de estoque costuma precisar comparar preços: encontrar o produto mais barato, montar uma lista de compras econômica ou organizar uma tabela de ofertas. Com dezenas de produtos cadastrados fora de ordem, localizar o menor ou o maior preço manualmente é lento e sujeito a erros.

A aplicação resolve esse problema ordenando automaticamente os produtos por preço crescente, o que facilita a consulta e a tomada de decisão.

## 3. Como executar

### Requisitos

- Compilador C (GCC, por exemplo via MSYS2/MinGW no Windows, ou `gcc` no Linux/macOS)

### Compilação

```bash
gcc numeros.c -o numeros
```

### Execução

```bash
./numeros
```

No Windows (CMD ou PowerShell): `numeros.exe`

### Uso

1. Informe a quantidade de produtos (mínimo 10, máximo 100).
2. Para cada produto, digite o **nome** (aceita espaços, como "Leite Integral") e o **preço** em reais (use ponto como separador decimal, por exemplo `4.99`).
3. O programa exibe:
   - a lista original, antes da ordenação;
   - o resultado ordenado pelo **Bubble Sort**;
   - o resultado ordenado pelo **Quick Sort**.

O programa valida as entradas: rejeita quantidades fora do intervalo, valores não numéricos e preços negativos.

### Exemplo de saída

```
---------------------------------------------
N.    PRODUTO                   PRECO (R$)
---------------------------------------------
1     Arroz                     R$     5.50
2     Feijao                    R$     7.20
...
```

## 4. Algoritmos implementados

Os dois algoritmos ordenam o vetor de produtos pelo campo `preco`, em ordem crescente. Cada um trabalha sobre uma cópia dos dados originais, então ambos partem da mesma lista.

### Bubble Sort

Percorre o vetor comparando pares de produtos vizinhos. Se o preço do primeiro for maior que o do segundo, os dois trocam de posição. A cada passada completa, o maior preço restante "sobe" como uma bolha até o final do vetor, e por isso a região já ordenada cresce a partir do fim. O processo se repete até que todo o vetor esteja ordenado.

- Função: `bubbleSort`
- Complexidade de tempo: O(n²) no pior e no caso médio
- Vantagens: simples de entender e implementar
- Desvantagem: lento para listas grandes

### Quick Sort

Usa a estratégia de **dividir para conquistar**:

1. Escolhe um **pivô** (nesta implementação, o último elemento do trecho).
2. Na função `particionar`, reorganiza o trecho de modo que os preços menores ou iguais ao pivô fiquem à esquerda e os maiores fiquem à direita. O pivô é então colocado na sua posição final.
3. Aplica o mesmo processo, de forma recursiva, ao trecho à esquerda e ao trecho à direita do pivô.

- Funções: `quickSort` e `particionar`
- Complexidade de tempo: O(n log n) em média e O(n²) no pior caso (por exemplo, lista já ordenada com pivô no último elemento)
- Vantagens: bem mais rápido que o Bubble Sort em listas maiores
- Desvantagem: usa recursão e o desempenho depende da escolha do pivô

## 5. Estrutura do projeto

```
saladeaula/
├── numeros.c    # código-fonte da aplicação
└── README.md    # documentação
```

## 6. Tecnologias

- Linguagem C
- Bibliotecas padrão: `stdio.h` e `string.h`

  # 7. Teste
  https://onlinegdb.com/gnI13FBL6e
