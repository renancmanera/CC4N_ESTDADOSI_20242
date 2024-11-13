# Análise de Complexidade do Merge Sort

O Merge Sort é um algoritmo baseado na técnica de **divisão e conquista**, com uma complexidade assintótica estável em diferentes situações. Abaixo, abordamos a complexidade de tempo nos casos pior, melhor e médio, e a complexidade de espaço.

## 1. Complexidade de Tempo

### Pior Caso: \(O(n \log n)\)
No pior caso, o Merge Sort divide o array ao meio repetidamente até obter subarrays de um único elemento, criando uma árvore de recursão de aproximadamente \(\log_2(n)\) níveis. Em cada nível, realiza \(O(n)\) operações para mesclar os elementos, resultando na complexidade de:

\[
O(n \log n)
\]

### Melhor Caso: \(O(n \log n)\)
Mesmo que o array esteja ordenado, o Merge Sort não se beneficia de uma ordenação prévia, pois ele ainda realiza todas as divisões e mesclagens necessárias. Dessa forma, a complexidade no melhor caso também é:

\[
O(n \log n)
\]

### Caso Médio: \(O(n \log n)\)
Como o Merge Sort executa a mesma estrutura de operações independentemente da disposição inicial dos elementos, ele possui a mesma complexidade média, calculada por:

\[
O(n \log n)
\]

## 2. Complexidade de Espaço

O Merge Sort exige espaço adicional para armazenar os subarrays temporários na fase de mesclagem. Esse espaço extra é proporcional ao tamanho do array original, resultando em uma complexidade de espaço de:

\[
O(n)
\]

Esse custo adicional de memória torna o Merge Sort menos eficiente em termos de espaço em comparação a algoritmos in-place, como o Quick Sort.

## Conclusão

O Merge Sort é um algoritmo eficiente e estável com complexidade de tempo consistente de \(O(n \log n)\), ideal para grandes conjuntos de dados e situações em que a estabilidade é necessária. Contudo, o custo de espaço adicional pode ser uma limitação em sistemas com recursos de memória restritos.
