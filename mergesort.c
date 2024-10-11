// Implementação do Mergesort em C
// Mergesort é um algoritmo de ordenação baseado na técnica de divisão e
// conquista. Ele divide o array em duas metades, ordena cada metade de forma
// recursiva, e depois mescla as duas metades ordenadas em um único array.

// Função para mesclar dois subvetores ordenados em um único vetor resultante
// O vetor 'v' é dividido em dois subvetores: v1 (esquerda) e v2 (direita).
void merge(int v[], int inicio, int meio, int fim) {
  int i, j, k; // i é o índice para o primeiro subvetor, j para o segundo, e k
               // para o vetor resultante
  int n1 = meio - inicio + 1; // Tamanho do primeiro subvetor
  int n2 = fim - meio;        // Tamanho do segundo subvetor

  int v1[n1], v2[n2]; // Vetores temporários para armazenar os subvetores

  // Copia os elementos da primeira metade do vetor original para o subvetor v1
  for (i = 0; i < n1; i++)
    v1[i] = v[inicio + i];
  // Copia os elementos da segunda metade do vetor original para o subvetor v2
  for (j = 0; j < n2; j++)
    v2[j] = v[meio + 1 + j];

  i = 0;      // Reinicia o índice do primeiro subvetor
  j = 0;      // Reinicia o índice do segundo subvetor
  k = inicio; // Reinicia o índice do vetor original

  // Mescla os dois subvetores v1 e v2 em ordem crescente
  while (i < n1 && j < n2) {
    if (v1[i] <= v2[j]) { // Se o elemento de v1 for menor ou igual ao de v2
      v[k] = v1[i];       // Copia o elemento de v1 para o vetor resultante
      i++;                // Avança no subvetor v1
    } else {
      v[k] = v2[j]; // Caso contrário, copia o elemento de v2
      j++;          // Avança no subvetor v2
    }
    k++; // Avança no vetor resultante
  }

  // Copia os elementos restantes de v1, se houver
  while (i < n1) {
    v[k] = v1[i];
    i++;
    k++;
  }

  // Copia os elementos restantes de v2, se houver
  while (j < n2) {
    v[k] = v2[j];
    j++;
    k++;
  }
}

// Função para ordenar o vetor usando o Mergesort
// O vetor é recursivamente dividido em duas metades até que as partes tenham
// tamanho 1. Em seguida, as partes são mescladas para formar o vetor ordenado.
void merge_sort(int v[], int inicio, int fim) {
  if (inicio < fim) { // Condição de parada: o vetor tem tamanho 1 ou 0
    int meio = inicio + (fim - inicio) / 2; // Calcula o índice do meio do vetor

    // Ordena recursivamente a primeira metade
    merge_sort(v, inicio, meio);
    // Ordena recursivamente a segunda metade
    merge_sort(v, meio + 1, fim);

    // Mescla as duas metades ordenadas
    merge(v, inicio, meio, fim);
  }
}

// Função para exibir o conteúdo do vetor
void exibe_vetor(int v[], int n) {
  for (int i = 0; i < n; i++)
    printf("%d ", v[i]);
  printf("\n");
}

// O Mergesort funciona através de divisão e conquista: o vetor é dividido em
// duas metades, cada metade é ordenada recursivamente, e então os subvetores
// resultantes são mesclados. Sua complexidade é O(n log n), o que o torna
// eficiente para grandes conjuntos de dados.

int main() {
  int v[] = {12, 9, 10, 13, 11, 14}, n = 6; // Exemplo de vetor para ordenar

  printf("Vetor de entrada: \n");
  exibe_vetor(v, n);

  // Chama a função merge_sort para ordenar o vetor
  merge_sort(v, 0, n - 1);

  printf("Vetor ordenado: \n");
  exibe_vetor(v, n);

  return 0;
}
