
#include <stdlib.h>
#include <unistd.h>
#include "../../../libft.h"

void	ft_print_result2(char c)
{
	write(1, &c, 1);
}

void	ft_print_result(int n)
{
	if (n >= 0)
	{
		if (n >= 10)
			ft_print_result(n / 10);
		ft_print_result2(n % 10 + '0');
	}
	else
	{
		ft_print_result2('-');
		if (n <= -10)
			ft_print_result(n / -10);
		ft_print_result2(n % -10 * -1 + '0');
	}
}

int main(int argc, const char *argv[])
{
	int		arg;

	alarm(5);
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
		ft_print_result(ft_atoi("0"));
	else if (arg == 2)
		ft_print_result(ft_atoi("546:5"));
	else if (arg == 3)
		ft_print_result(ft_atoi("-4886"));
	else if (arg == 4)
		ft_print_result(ft_atoi("+548"));
	else if (arg == 5)
		ft_print_result(ft_atoi("054854"));
	else if (arg == 6)
		ft_print_result(ft_atoi("000074"));
	else if (arg == 7)
		ft_print_result(ft_atoi("+-54"));
	else if (arg == 8)
		ft_print_result(ft_atoi("-+48"));
	else if (arg == 9)
		ft_print_result(ft_atoi("--47"));
	else if (arg == 10)
		ft_print_result(ft_atoi("++47"));
	else if (arg == 11)
		ft_print_result(ft_atoi("+47+5"));
	else if (arg == 12)
		ft_print_result(ft_atoi("-47-5"));
	else if (arg == 13)
		ft_print_result(ft_atoi("\e475"));
	else if (arg == 14)
		ft_print_result(ft_atoi("\t\n\r\v\f  469 \n"));
	else if (arg == 15)
		ft_print_result(ft_atoi("-2147483648"));
	else if (arg == 16)
		ft_print_result(ft_atoi("2147483647"));
	else if (arg == 17)
		ft_print_result(ft_atoi("\t\n\r\v\fd469 \n"));
	else if (arg == 18)
		ft_print_result(ft_atoi("\n\n\n  -46\b9 \n5d6"));
	else if (arg == 19)
		ft_print_result(ft_atoi(""));
		    else if (arg == 20)
        ft_print_result(ft_atoi("+"));
    else if (arg == 21)
        ft_print_result(ft_atoi("-"));
    else if (arg == 22)
        ft_print_result(ft_atoi("+ 42"));
    else if (arg == 23)
        ft_print_result(ft_atoi("- 42"));
    else if (arg == 24)
        ft_print_result(ft_atoi(" \t\n\r\v\f"));
    else if (arg == 25)
        ft_print_result(ft_atoi("   abc123"));
    else if (arg == 26)
        ft_print_result(ft_atoi("2147483648"));
    else if (arg == 27)
        ft_print_result(ft_atoi("-2147483649"));
    else if (arg == 28)
        ft_print_result(ft_atoi(" \t\v\n\r\f-123"));
    else if (arg == 29)
        ft_print_result(ft_atoi(" \f\r\n\v\t456"));
    else if (arg == 30)
        ft_print_result(ft_atoi(" +123"));
    else if (arg == 31)
        ft_print_result(ft_atoi(" -123"));
    else if (arg == 32)
        ft_print_result(ft_atoi("\t\t\t\n\n\n123"));
    else if (arg == 33)
        ft_print_result(ft_atoi("-0"));
    else if (arg == 34)
        ft_print_result(ft_atoi("+0"));
    else if (arg == 35)
        ft_print_result(ft_atoi("   + 123"));
    else if (arg == 36)
        ft_print_result(ft_atoi("   - 123"));
    else if (arg == 37)
        ft_print_result(ft_atoi("+-123"));
    else if (arg == 38)
        ft_print_result(ft_atoi("-+123"));
    else if (arg == 39)
        ft_print_result(ft_atoi("2147483647"));
    else if (arg == 40)
        ft_print_result(ft_atoi("-2147483648"));
    else if (arg == 41)
        ft_print_result(ft_atoi("0000000000000000000000000000000000000000042"));
    else if (arg == 42)
        ft_print_result(ft_atoi("99999999999999999999999999999999999999"));
    else if (arg == 43)
        ft_print_result(ft_atoi("-99999999999999999999999999999999999999"));
    else if (arg == 44)
        ft_print_result(ft_atoi("100000000000000000000000000000000000000"));
    return (0);
}
