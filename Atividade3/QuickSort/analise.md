# Análise de Complexidade do Quick Sort

O Quick Sort é um algoritmo eficiente de ordenação que usa a estratégia de **divisão e conquista**, com complexidade variável dependendo do caso (pior, melhor e médio). Abaixo, detalhamos a análise de complexidade de tempo e espaço do Quick Sort.

## 1. Complexidade de Tempo

### Pior Caso: \(O(n^2)\)
No pior caso, o Quick Sort ocorre quando o pivô escolhido é o maior ou o menor elemento em cada chamada recursiva, dividindo o array de forma desigual (ex.: array já ordenado ou inversamente ordenado). Com isso, o algoritmo realiza \(n\) níveis de recursão com cada nível custando \(O(n)\) operações, resultando em uma complexidade de:

\[
O(n^2)
\]

### Melhor Caso: \(O(n \log n)\)
No melhor caso, o Quick Sort divide o array em duas partes iguais em cada nível de recursão, formando uma árvore de aproximadamente \(\log_2(n)\) níveis. Em cada nível, realiza-se \(O(n)\) operações para dividir e ordenar os elementos, resultando em uma complexidade de:

\[
O(n \log n)
\]

### Caso Médio: \(O(n \log n)\)
Na maioria dos casos, o Quick Sort se comporta de forma próxima ao melhor caso, já que o pivô escolhido geralmente divide o array em partes aproximadamente iguais. Com isso, a complexidade média é:

\[
O(n \log n)
\]

## 2. Complexidade de Espaço

O Quick Sort é um algoritmo in-place, ou seja, ele ordena os elementos sem usar espaço adicional significativo além da pilha de chamadas. No pior caso, ele pode usar \(O(n)\) espaço devido à profundidade da recursão, enquanto no melhor e no caso médio ele utiliza:

\[
O(\log n)
\]

## Conclusão

O Quick Sort é um dos algoritmos de ordenação mais rápidos e eficientes na prática, especialmente para grandes conjuntos de dados, graças à sua complexidade média de \(O(n \log n)\). No entanto, em seu pior caso, ele pode ter uma complexidade quadrática, o que é uma desvantagem em relação ao Merge Sort. Técnicas como a escolha do pivô aleatório ou o uso da mediana de três elementos podem ajudar a minimizar a ocorrência do pior caso.
