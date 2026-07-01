#include <stdlib.h>
#include <unistd.h>
#include "../../../libft.h"

void    print_zero_check(unsigned char *p, size_t n)
{
    size_t i;

    if (n == 0)
    {
        if (!p)
            write(1, "NULL", 4);
        else
            write(1, "OK", 2);
        return ;
    }
    if (!p)
    {
        write(1, "NULL", 4);
        return ;
    }
    i = 0;
    while (i < n)
    {
        if (p[i] != 0)
        {
            write(1, "KO", 2);
            return ;
        }
        i++;
    }
    write(1, "OK", 2);
}
int     main(int argc, const char *argv[])
{
    void *res = NULL; // Variável para segurar o ponteiro alocado

    alarm(5);
    if (argc == 1)
        return (0);
        
    int test_num = atoi(argv[1]);

    if (test_num == 1)
    {
        res = ft_calloc(30, 1);
        print_zero_check(res, 30);
    }
    else if (test_num == 2)
    {
        res = ft_calloc(1, 1);
        print_zero_check(res, 1);
    }
    else if (test_num == 3)
    {
        res = ft_calloc(4, 8);
        print_zero_check(res, 32);
    }
    else if (test_num == 4)
    {
        res = ft_calloc(0, 1);
        print_zero_check(res, 0);
    }
    else if (test_num == 5)
    {
        res = ft_calloc(1, 0);
        print_zero_check(res, 0);
    }
    else if (test_num == 6)
    {
        res = ft_calloc(0, 0);
        print_zero_check(res, 0);
    }
    else if (test_num == 7)
    {
        res = ft_calloc((size_t)-1, 2);
        print_zero_check(res, 0);
    }
    else if (test_num == 8)
    {
        res = ft_calloc((size_t)-1 / 2 + 1, 2);
        print_zero_check(res, 0);
    }
    else if (test_num == 9)
    {
        res = ft_calloc(0, 0);
        if (res)
            write(1, "OK", 2);
        else
            write(1, "NULL", 4);
    }
    else if (test_num == 10)
    {
        res = ft_calloc((size_t)-1, (size_t)-1);
        if (!res)
            write(1, "NULL", 4);
        else
            write(1, "KO", 2);
    }

    // Libera a memória se o ft_calloc tiver retornado algo válido
    if (res != NULL)
        free(res);

    return (0);
}