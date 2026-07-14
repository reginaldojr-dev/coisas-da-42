*This project has been created as part of the 42 curriculum by rgoulart, vde-alme.*

# push_swap

## Descricao

O **push_swap** e um projeto de algoritmos em C. O programa recebe uma lista de
inteiros, valida a entrada, monta a pilha `a` e imprime em `stdout` uma sequencia
de operacoes Push_swap capaz de deixar a pilha `a` em ordem crescente usando a
pilha auxiliar `b`.

Esta versao foi criada do zero na pasta `fresh_push_swap`, com suporte a:

- argumentos separados, como `1 2 3`;
- argumentos agrupados, como `"1 2 3"`;
- flags `--simple`, `--medium`, `--complex`, `--adaptive` e `--bench`;
- calculo da metrica obrigatoria de desordem;
- quatro estrategias de ordenacao no mesmo binario;
- bonus `checker`.

Se nenhuma estrategia for informada, o comportamento padrao e `--adaptive`.

## Integrantes e contribuicoes

| Login | Contribuicoes |
|---|---|
| `rgoulart` | Parser de tokens e valores, validacao de inteiros e duplicados, estrategias por chunks, estrategia complexa/radix, bonus `checker`, leitura de operacoes e revisao dos testes. |
| `vde-alme` | Estrutura principal do programa, fluxo do `main`, inicializacao e liberacao do contexto, operacoes de pilha, contadores de benchmark, funcoes utilitarias, documentacao e revisao geral. |

O projeto foi dividido para que ambos os integrantes compreendam o fluxo completo:
parsing, normalizacao dos valores, selecao de estrategia, execucao das operacoes,
benchmark e checker bonus.

## Compilacao

```bash
make
```

Gera:

```text
push_swap
```

Para compilar o bonus:

```bash
make bonus
```

Gera:

```text
checker
```

Regras disponiveis:

| Comando | Acao |
|---|---|
| `make` ou `make all` | Compila `push_swap`. |
| `make bonus` | Compila `checker`. |
| `make clean` | Remove arquivos objeto. |
| `make fclean` | Remove objetos e binarios. |
| `make re` | Recompila o projeto. |

## Uso

### Uso padrao

```bash
./push_swap 4 67 3 87 23
```

Equivale a:

```bash
./push_swap --adaptive 4 67 3 87 23
```

### Forcar estrategia

```bash
./push_swap --simple 5 4 3 2 1
./push_swap --medium 5 4 3 2 1
./push_swap --complex 5 4 3 2 1
./push_swap --adaptive 5 4 3 2 1
```

### Argumentos agrupados

```bash
./push_swap "12 2 5" 23 "8" 454 "7"
```

## Operacoes permitidas

| Operacao | Descricao |
|---|---|
| `sa` | Troca os dois primeiros elementos de `a`. |
| `sb` | Troca os dois primeiros elementos de `b`. |
| `ss` | Executa `sa` e `sb` ao mesmo tempo. |
| `pa` | Move o topo de `b` para o topo de `a`. |
| `pb` | Move o topo de `a` para o topo de `b`. |
| `ra` | Move o topo de `a` para o final de `a`. |
| `rb` | Move o topo de `b` para o final de `b`. |
| `rr` | Executa `ra` e `rb` ao mesmo tempo. |
| `rra` | Move o ultimo elemento de `a` para o topo. |
| `rrb` | Move o ultimo elemento de `b` para o topo. |
| `rrr` | Executa `rra` e `rrb` ao mesmo tempo. |

## Estrategias

| Flag | Ideia | Uso no projeto |
|---|---|---|
| `--simple` | Base simples | Usa ordenacao pequena e chunks com janela conservadora para evitar estouro em 500 numeros. |
| `--medium` | Blocos/chunks | Empurra faixas de indices para `b` e depois devolve o maior de `b` para `a`. |
| `--complex` | Alta desordem | Usa chunks calibrados ate 500 elementos e radix como fallback para entradas maiores. |
| `--adaptive` | Escolha automatica | Mede a desordem e escolhe o caminho interno conforme o perfil da entrada. |

### Metrica de desordem

A desordem e calculada contando inversoes:

```text
disorder = inversoes / total_de_pares
total_de_pares = n * (n - 1) / 2
```

- entrada ordenada: `0.0`;
- entrada reversa: `1.0`;
- entradas intermediarias: valor entre `0` e `1`.

A medicao acontece antes de qualquer movimento.

## Benchmark

A flag `--bench` mantem as operacoes em `stdout` e envia o relatorio para
`stderr`.

```bash
./push_swap --bench --adaptive 4 67 3 87 23
```

Para ver so o benchmark:

```bash
./push_swap --bench 4 67 3 87 23 > /dev/null
```

O relatorio inclui:

- estrategia usada;
- complexidade declarada;
- percentual de desordem;
- total de operacoes;
- contagem individual de cada operacao.

## Bonus checker

O `checker` recebe a pilha inicial por argumentos e le operacoes pela entrada
padrao. No fim:

- imprime `OK` se `a` estiver ordenada e `b` vazia;
- imprime `KO` se as operacoes forem validas, mas nao ordenarem;
- imprime `Error` em caso de entrada ou operacao invalida.

Exemplo:

```bash
ARG="3 2 1"
./push_swap $ARG | ./checker $ARG
```

Resultado esperado:

```text
OK
```

## Tratamento de erros

Entradas invalidas imprimem exatamente:

```text
Error
```

em `stderr`.

Sao invalidos:

- tokens nao numericos;
- sinais sem numero, como `+` ou `-`;
- numeros fora de `INT_MIN..INT_MAX`;
- duplicados;
- argumento vazio, como `""`;
- argumento contendo apenas espacos;
- operacao invalida no `checker`.

## Estrutura principal

```text
fresh_push_swap/
|-- Makefile
|-- push_swap.h
|-- main.c
|-- parser.c
|-- parser_token.c
|-- parser_value.c
|-- index.c
|-- ops.c
|-- op_name.c
|-- sort_small.c
|-- sort_chunk.c
|-- sort_radix.c
|-- bench.c
|-- checker_bonus.c
|-- checker_parse_bonus.c
|-- checker_read_bonus.c
`-- checker_exec_bonus.c
```

## Testes uteis

```bash
./push_swap
./push_swap 1 2 3 4 | wc -l
./push_swap 1 2 2
./push_swap 2147483648
ARG="$(shuf -i 0-9999 -n 100)"; ./push_swap $ARG | wc -l
ARG="$(shuf -i 0-9999 -n 500)"; ./push_swap $ARG | wc -l
ARG="3 2 1"; ./push_swap $ARG | ./checker $ARG
```

## Resources

- Subject oficial do Push_swap, versão 1.1;
- *Entendendo Algoritmos: Um Guia Ilustrado para Programadores e Outros Curiosos*, de Aditya Y. Bhargava;
- manuais da 42 sobre linguagem C e das funções autorizadas;
- documentação da 42 sobre Norma;
- discussões técnicas e revisão entre os integrantes do projeto.
