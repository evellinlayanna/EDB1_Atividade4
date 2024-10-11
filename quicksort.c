// Implementação do Quicksort em C
// Quicksort é um algoritmo de ordenação eficiente que utiliza a técnica de
// divisão e conquista. Ele funciona particionando o array em duas partes em
// torno de um pivô e ordenando recursivamente.

// Função para trocar dois elementos usando ponteiros
// Os ponteiros permitem que os valores de 'a' e 'b' sejam trocados diretamente
// na memória.
void troca(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Função para particionar o array com base no pivô
// O pivô é escolhido como o último elemento, e a função reorganiza o array em
// duas partes: elementos menores ou iguais ao pivô à esquerda, e maiores à
// direita.
int particiona(int v[], int inicio, int fim) {
  int pivo = v[fim];    // O pivô é o último elemento do array
  int i = (inicio - 1); // 'i' vai rastrear a posição do último menor elemento
                        // em relação ao pivô

  // Percorre o array do 'inicio' até 'fim - 1'
  for (int j = inicio; j <= fim - 1; j++) {
    if (v[j] <= pivo) {    // Se o elemento atual for menor ou igual ao pivô
      i++;                 // Incrementa o índice do menor elemento
      troca(&v[i], &v[j]); // Traz o elemento menor para a esquerda do pivô
    }
  }

  // Coloca o pivô na posição correta (i+1)
  troca(&v[i + 1], &v[fim]);

  // Retorna a posição final do pivô
  return (i + 1);
}

// Função para ordenar o array usando Quicksort
// O array é recursivamente dividido em subarrays menores, que são ordenados
// individualmente.
void quick_sort(int v[], int inicio, int fim) {
  if (inicio < fim) { // Condição para parar a recursão quando o subarray tiver
                      // tamanho 1 ou 0
    int indice_pivo = particiona(
        v, inicio, fim); // Particiona o array e encontra a posição do pivô

    // Ordena recursivamente os subarrays à esquerda e à direita do pivô
    quick_sort(v, inicio, indice_pivo - 1); // Subarray à esquerda do pivô
    quick_sort(v, indice_pivo + 1, fim);    // Subarray à direita do pivô
  }
}
// Após cada chamada de particionamento, o pivô é colocado na posição correta,
// e o processo é repetido para os subarrays resultantes.

// Função para exibir o conteúdo do array
void exibe_vetor(int v[], int n) {
  for (int i = 0; i < n; i++) // Laço para percorrer o array
    printf("%d ", v[i]);
  printf("\n");
}

// O algoritmo Quicksort utiliza a técnica de particionamento,
// que organiza os elementos com base em um pivô, e resolve o problema
// dividindo o array até que ele esteja completamente ordenado.

int main() {
  int v[] = {12, 9, 10, 13, 11, 14}, n = 6;

  printf("Vetor de entrada: \n");
  exibe_vetor(v, n);

  // Chama a função quick_sort para ordenar o array
  quick_sort(v, 0, n - 1);

  printf("Vetor ordenado: \n");
  exibe_vetor(v, n);

  return 0;
}
