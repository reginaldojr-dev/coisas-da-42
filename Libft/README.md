*This project was created as part of the 42 curriculum by rgoulart*

# Libft — Sua Primeira Biblioteca Própria

## Descrição

A Libft é o primeiro projeto fundamental do currículo da 42.

O objetivo deste projeto é reimplementar do zero diversas funções da biblioteca padrão da linguagem C, permitindo uma compreensão profunda de conceitos de baixo nível como manipulação de memória, ponteiros, strings, alocação dinâmica e comportamento das funções da libc.

O resultado final é uma biblioteca estática chamada `libft.a`, que poderá ser reutilizada nos próximos projetos futuros do currículo.

---

## Restrições Técnicas

Este projeto segue os requisitos definidos no subject e na Norma da 42.

- Linguagem: C
- Variáveis globais são proibidas
- Funções auxiliares devem ser declaradas como `static` quando apropriado
- Todos os arquivos devem compilar com:

```bash
-Wall -Wextra -Werror
```

- A biblioteca deve ser criada utilizando `ar`
- O uso de `libtool` é proibido
- A biblioteca final deve se chamar `libft.a`
- Todos os arquivos devem estar na raiz do repositório

---

## Funções da Biblioteca

### Parte 1 — Funções da Libc

As seguintes funções foram reimplementadas com o prefixo `ft_`:

- ft_isalpha
- ft_isdigit
- ft_isalnum
- ft_isascii
- ft_isprint
- ft_strlen
- ft_memset
- ft_bzero
- ft_memcpy
- ft_memmove
- ft_strlcpy
- ft_strlcat
- ft_toupper
- ft_tolower
- ft_strchr
- ft_strrchr
- ft_strncmp
- ft_memchr
- ft_memcmp
- ft_strnstr
- ft_atoi
- ft_calloc
- ft_strdup

---

### Parte 2 — Funções Adicionais

- ft_substr
- ft_strjoin
- ft_strtrim
- ft_split
- ft_itoa
- ft_strmapi
- ft_striteri
- ft_putchar_fd
- ft_putstr_fd
- ft_putendl_fd
- ft_putnbr_fd

---

### Parte 3 — Listas Encadeadas

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

| Função | Descrição |
|---------|------------|
| ft_lstnew | Cria um novo nó |
| ft_lstadd_front | Adiciona um nó no início |
| ft_lstsize | Conta os elementos da lista |
| ft_lstlast | Retorna o último nó |
| ft_lstadd_back | Adiciona um nó ao final |
| ft_lstdelone | Remove um único nó |
| ft_lstclear | Remove toda a lista |
| ft_lstiter | Aplica uma função a cada nó |
| ft_lstmap | Cria uma nova lista transformada |

---

## Objetivos de Aprendizagem

Durante este projeto foram praticados:

- Manipulação de memória
- Aritmética de ponteiros
- Manipulação de strings
- Gerenciamento de buffers
- Comportamento indefinido (Undefined Behavior)
- Organização modular de código
- Bibliotecas estáticas
- Estruturas de listas encadeadas
- Programação defensiva

---

## Compilação

### Compilar a parte obrigatória

```bash
make
```

### Remover arquivos objeto

```bash
make clean
```

### Remover objetos e biblioteca

```bash
make fclean
```

### Recompilar tudo

```bash
make re
```

---

## Utilização

Inclua o cabeçalho:

```c
#include "libft.h"
```

Compile seu programa vinculando a biblioteca:

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o programa
```

---

## Uso de IA

A inteligência artificial foi utilizada exclusivamente como ferramenta de apoio ao aprendizado.

Seu uso incluiu:

- Esclarecimento de conceitos
- Discussão de edge cases
- Revisão de código
- Explicações sobre gerenciamento de memória
- Discussões sobre o comportamento da libc
- Verificação de conformidade com a Norma

Nenhum código foi copiado diretamente para o projeto.

Todas as implementações finais foram escritas, testadas e compreendidas pelo autor.

---

## Recursos

- Documentação da 42
- Linux Manual Pages (`man`)
- POSIX Documentation
- GNU C Library Documentation
- Algoritmos e Linguagem C — Paulo Feofiloff
- https://www.ime.usp.br/~pf/algoritmos/
- https://stackoverflow.com/
- https://craftofcoding.wordpress.com/2015/12/07/memory-in-c-the-stack-the-heap-and-static/

---

## Autor

**rgoulart**

Aluno da 42
