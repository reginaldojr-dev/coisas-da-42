*This project has been created as part of the 42 curriculum by rgoulart, vde-alme.*

# push_swap

## Descrição

O **push_swap** é um projeto de algoritmos desenvolvido em C. O programa recebe uma sequência de números inteiros, armazena os valores na pilha `a` e imprime a menor sequência possível de operações do idioma Push_swap capaz de ordenar essa pilha em ordem crescente.

O projeto utiliza duas pilhas:

- `a`: recebe os números informados pela linha de comando;
- `b`: começa vazia e é utilizada como pilha auxiliar.

A dificuldade não está apenas em ordenar os valores, mas em escolher uma estratégia adequada e limitar a quantidade de operações geradas.

O projeto deve ser realizado por exatamente dois cadetes. Ambos precisam contribuir para o desenvolvimento e compreender todas as partes do programa.

## Integrantes e contribuições

| Login | Contribuições |
|---|---|
| `rgoulart` | Desenvolvimento, revisão e testes das estruturas de pilha, parsing, operações, estratégias de ordenação, seleção adaptativa, benchmark e documentação. |
| `vde-alme` | Desenvolvimento, revisão e testes das estruturas de pilha, parsing, operações, estratégias de ordenação, seleção adaptativa, benchmark e documentação. |

O projeto foi desenvolvido de forma colaborativa. As decisões de arquitetura, os algoritmos e os testes foram discutidos e revisados pelos dois integrantes para que ambos possam explicar qualquer parte do código durante a defesa.

## Operações disponíveis

| Operação | Descrição |
|---|---|
| `sa` | Troca os dois primeiros elementos de `a`. |
| `sb` | Troca os dois primeiros elementos de `b`. |
| `ss` | Executa `sa` e `sb` ao mesmo tempo. |
| `pa` | Move o primeiro elemento de `b` para o topo de `a`. |
| `pb` | Move o primeiro elemento de `a` para o topo de `b`. |
| `ra` | Move todos os elementos de `a` uma posição para cima; o primeiro vira o último. |
| `rb` | Move todos os elementos de `b` uma posição para cima; o primeiro vira o último. |
| `rr` | Executa `ra` e `rb` ao mesmo tempo. |
| `rra` | Move todos os elementos de `a` uma posição para baixo; o último vira o primeiro. |
| `rrb` | Move todos os elementos de `b` uma posição para baixo; o último vira o primeiro. |
| `rrr` | Executa `rra` e `rrb` ao mesmo tempo. |

## Requisitos algorítmicos

O subject exige quatro estratégias no mesmo executável. A classe de complexidade é avaliada pela quantidade de operações Push_swap geradas, e não apenas pelo custo interno do código em C.

| Flag | Classe exigida | Estratégia do projeto |
|---|---:|---|
| `--simple` | `O(n²)` | Ordenação simples baseada na extração e posicionamento progressivo de elementos. |
| `--medium` | `O(n√n)` | Ordenação por blocos, dividindo os índices em aproximadamente `√n` intervalos. |
| `--complex` | `O(n log n)` | Ordenação escalável baseada em índices e particionamento dos elementos. |
| `--adaptive` | Variável | Mede a desordem inicial e escolhe automaticamente uma das três estratégias. |

Quando nenhuma flag de estratégia é informada, o programa utiliza `--adaptive`.

## Justificativa dos algoritmos

### Estratégia simples — `O(n²)`

A estratégia simples serve como algoritmo-base do projeto. Ela localiza elementos, movimenta a pilha até posicioná-los corretamente e repete esse processo.

Ela foi escolhida porque:

- é direta de compreender e testar;
- funciona bem para entradas pequenas;
- permite observar claramente como rotações e pushes afetam a pilha;
- atende ao limite exigido para o regime de baixa desordem.

No pior caso, vários elementos precisam ser procurados e reposicionados repetidamente, fazendo a quantidade de operações crescer de forma quadrática.

### Estratégia média — `O(n√n)`

A estratégia média divide os índices ordenados em aproximadamente `√n` blocos. Os valores são enviados para a pilha `b` por intervalos e depois devolvidos para `a` na ordem necessária.

Ela foi escolhida porque:

- reduz o espaço de busca em comparação com a estratégia simples;
- evita tratar toda a pilha como um único grupo;
- equilibra simplicidade e quantidade de movimentos;
- é adequada para entradas com desordem intermediária.

Com cerca de `√n` blocos e processamento proporcional a `n` em cada etapa relevante, o crescimento esperado no modelo de operações Push_swap é limitado por `O(n√n)`.

### Estratégia complexa — `O(n log n)`

A estratégia complexa utiliza os índices relativos dos valores para organizar a pilha em etapas de particionamento.

Ela foi escolhida porque:

- escala melhor para entradas grandes;
- trabalha com posições relativas em vez dos valores originais;
- reduz o número de decisões repetitivas;
- atende ao regime de alta desordem.

A quantidade de etapas de particionamento cresce de forma logarítmica, enquanto cada etapa percorre uma quantidade linear de elementos. Assim, o limite superior esperado é `O(n log n)` operações.

### Estratégia adaptativa

A estratégia adaptativa mede a desordem antes de executar qualquer operação e escolhe internamente:

| Desordem | Estratégia |
|---:|---|
| `< 0.20` | simples — `O(n²)` |
| `0.20 ≤ disorder < 0.50` | média — `O(n√n)` |
| `≥ 0.50` | complexa — `O(n log n)` |

Esses limites seguem os regimes obrigatórios definidos pelo subject. A ideia é evitar uma estratégia complexa quando a entrada já está quase ordenada e evitar uma estratégia quadrática quando a entrada está muito desordenada.

## Métrica de desordem

A desordem é um valor entre `0` e `1` que representa o quanto a pilha inicial está distante da ordem crescente.

Ela é calculada contando inversões. Uma inversão ocorre quando um valor maior aparece antes de um valor menor.

```text
disorder = inversões / total de pares possíveis
```

O total de pares possíveis é:

```text
n × (n - 1) / 2
```

Exemplos:

- uma pilha já ordenada possui `disorder = 0`;
- uma pilha em ordem totalmente inversa possui `disorder = 1`;
- valores intermediários indicam uma pilha parcialmente desordenada.

A medição é feita antes de qualquer operação.

## Fluxo de execução

```text
Argumentos e flags
        |
        v
Parsing e validação
        |
        +---- entrada inválida ----> "Error\n" em stderr
        |
        v
Criação da pilha a
Pilha b vazia
        |
        v
Indexação dos valores
        |
        v
Cálculo da desordem inicial
        |
        v
A pilha já está ordenada?
   |                 |
  sim               não
   |                 |
encerra       seleção da estratégia
                     |
          +----------+----------+
          |          |          |
       simple      medium     complex
          \          |          /
           \         |         /
            execução das operações
                     |
                     v
        operações impressas em stdout
                     |
                     v
        benchmark opcional em stderr
                     |
                     v
             liberação da memória
```

## Instructions

### Compilação

Clone o repositório e acesse a pasta do projeto:

```bash
git clone git@vogsphere-v2.42sp.org.br:vogsphere/intra-uuid-369f2095-4e0f-446a-a611-3be8d1899276-7516823-rgoulart
cd "Push_Swap" (ou nome escolhido para o repositório)
```

Compile o programa:

```bash
make
```

O executável gerado será:

```text
push_swap
```

O projeto é compilado com:

```text
-Wall -Wextra -Werror
```

### Regras do Makefile

| Comando | Ação |
|---|---|
| `make` ou `make all` | Compila o executável. |
| `make clean` | Remove os arquivos objeto. |
| `make fclean` | Remove os objetos e o executável. |
| `make re` | Executa uma recompilação completa. |

## Uso

### Estratégia adaptativa padrão

```bash
./push_swap 4 67 3 87 23
```

Equivalente a:

```bash
./push_swap --adaptive 4 67 3 87 23
```

### Forçar uma estratégia

```bash
./push_swap --simple 5 4 3 2 1
./push_swap --medium 5 4 3 2 1
./push_swap --complex 5 4 3 2 1
```

### Argumentos em uma única string

```bash
./push_swap "4 67 3 87 23"
```

### Benchmark

A flag `--bench` mantém as operações em `stdout` e imprime as métricas em `stderr`.

```bash
./push_swap --bench --adaptive 4 67 3 87 23
```

Para visualizar apenas o benchmark:

```bash
./push_swap --bench 4 67 3 87 23 > /dev/null
```

Para salvar as métricas sem misturá-las às operações:

```bash
./push_swap --bench 4 67 3 87 23 2> benchmark.txt
```

O relatório inclui:

- percentual de desordem;
- estratégia escolhida;
- classe de complexidade;
- quantidade total de operações;
- contagem individual de cada operação.

## Tratamento de erros

Entradas inválidas imprimem:

```text
Error
```

em `stderr`.

São inválidos, entre outros:

- valores que não representam números inteiros;
- valores fora do intervalo de `int`;
- números duplicados;
- argumentos vazios;
- sinais sem número;
- flags desconhecidas;
- combinações incompatíveis de flags.

Exemplos:

```bash
./push_swap --adaptive 0 one 2 3
./push_swap --simple 3 2 3
```

## Testes

### Contar operações

```bash
ARG="4 67 3 87 23"
./push_swap $ARG | wc -l
```

### Gerar 100 valores aleatórios

```bash
ARG="$(shuf -i 0-9999 -n 100)"
./push_swap $ARG | wc -l
```

### Gerar 500 valores aleatórios

```bash
ARG="$(shuf -i 0-9999 -n 500)"
./push_swap $ARG | wc -l
```

### Validar com o checker

```bash
ARG="4 67 3 87 23"
./push_swap --complex $ARG | ./checker_linux $ARG
```

Resultado esperado:

```text
OK
```

### Verificar vazamentos

```bash
valgrind --leak-check=full --show-leak-kinds=all \
    ./push_swap --adaptive 4 67 3 87 23
```

### Verificar a Norm

```bash
norminette
```

## Benchmark de desempenho

| Quantidade | Aceitável | Bom | Excelente |
|---:|---:|---:|---:|
| 100 números | `< 2000` operações | `< 1500` | `< 700` |
| 500 números | `< 12000` operações | `< 8000` | `< 5500` |

## Estrutura do projeto

```text
Push_Swap/
├── Makefile
├── push_swap.h
├── main.c
├── parser.c
├── stack_utils.c
├── indexer.c
├── disorder_metric.c
├── math_utils.c
├── op_swap_push.c
├── op_rotate.c
├── op_wrappers_a.c
├── op_wrappers_b.c
├── simple_sort.c
├── medium_sort.c
└── complex_sort.c
```

## Bonus

O programa `checker`, quando implementado, recebe a mesma pilha inicial, lê operações pela entrada padrão e verifica o estado final:

- `OK`: a pilha `a` terminou ordenada e `b` vazia;
- `KO`: as operações são válidas, mas não ordenam a pilha;
- `Error`: entrada ou instrução inválida.

## Resources

### Referências

- Subject oficial do Push_swap, versão 1.1;
- *Entendendo Algoritmos: Um Guia Ilustrado para Programadores e Outros Curiosos*, de Aditya Y. Bhargava;
- manuais da linguagem C e das funções autorizadas;
- documentação da 42 sobre Norm e Makefile;
- discussões técnicas e revisão entre os integrantes do projeto.
