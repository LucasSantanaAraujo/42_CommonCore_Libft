/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 01:47:04 by marvin            #+#    #+#             */
/*   Updated: 2026/11/08 01:47:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "libft.h"

static void	check_bool(const char *name, int mine, int ref)
{
	if (!mine == !ref)
		printf("OK    %-20s mine:%-5d libc:%d\n", name, mine, ref);
	else
		printf("FAIL  %-20s mine:%-5d libc:%d\n", name, mine, ref);
}

static void check_chr(const char *name, int mine, int ref)
{
	if (mine == ref)
		printf("OK    %-20s mine:'%c' (%d)  libc:'%c' (%d)\n",
			name, mine, mine, ref, ref);
	else
		printf("FAIL  %-20s mine:'%c' (%d)  libc:'%c' (%d)\n",
			name, mine, mine, ref, ref);
}

static void	check_size(const char *name, size_t mine, size_t ref)
{
	if (mine == ref)
		printf("OK    %-20s mine:%-5zu libc:%zu\n", name, mine, ref);
	else
		printf("FAIL  %-20s mine:%-5zu libc:%zu\n", name, mine, ref);
}

int	main(void)
{
	/* ft_isalpha() tests*/
	printf("\n================= ft_isalpha =================\n");
	check_bool("isalpha 'a'", ft_isalpha('a'), isalpha('a'));
	check_bool("isalpha 'z'", ft_isalpha('z'), isalpha('z'));
	check_bool("isalpha 'A'", ft_isalpha('A'), isalpha('A'));
	check_bool("isalpha 'Z'", ft_isalpha('Z'), isalpha('Z'));
	check_bool("isalpha '@'", ft_isalpha('@'), isalpha('@'));
	check_bool("isalpha '['", ft_isalpha('['), isalpha('['));
	check_bool("isalpha '`'", ft_isalpha('`'), isalpha('`'));
	check_bool("isalpha '{'", ft_isalpha('{'), isalpha('{'));
	check_bool("isalpha 0", ft_isalpha(0), isalpha(0));
	check_bool("isalpha EOF", ft_isalpha(-1), isalpha(-1));

	/* ft_isdigit() tests*/
	printf("\n================= ft_isdigit =================\n");
	check_bool("isdigit '0'", ft_isdigit('0'), isdigit('0'));
	check_bool("isdigit '9'", ft_isdigit('9'), isdigit('9'));
	check_bool("isdigit '/'", ft_isdigit('/'), isdigit('/'));
	check_bool("isdigit ':'", ft_isdigit(':'), isdigit(':'));
	check_bool("isdigit 'A'", ft_isdigit('A'), isdigit('A'));
	check_bool("isdigit 0", ft_isdigit(0), isdigit(0));
	check_bool("isdigit EOF", ft_isdigit(-1), isdigit(-1));

	/* ft_isalnum() tests */
	printf("\n================= ft_isalnum =================\n");
	check_bool("isalnum '0'", ft_isalnum('0'), isalnum('0'));
	check_bool("isalnum '9'", ft_isalnum('9'), isalnum('9'));
	check_bool("isalnum '/'", ft_isalnum('/'), isalnum('/'));
	check_bool("isalnum ':'", ft_isalnum(':'), isalnum(':'));
	check_bool("isalnum 'A'", ft_isalnum('A'), isalnum('A'));
	check_bool("isalnum '['", ft_isalnum('['), isalnum('['));
	check_bool("isalnum '@'", ft_isalnum('@'), isalnum('@'));
	check_bool("isalnum '{'", ft_isalnum('{'), isalnum('{'));
	check_bool("isalnum 0", ft_isalnum(0), isalnum(0));
	check_bool("isalnum EOF", ft_isalnum(-1), isalnum(-1));

	/* ft_isascii() tests */
	printf("\n================= ft_isascii =================\n");
	check_bool("isascii 0", ft_isascii(0), isascii(0));
	check_bool("isascii 1 (SOH)", ft_isascii(1), isascii(1));
	check_bool("isascii 32 (space)", ft_isascii(32), isascii(32));
	check_bool("isascii 126 (~)", ft_isascii(126), isascii(126));
	check_bool("isascii 127 (DEL)", ft_isascii(127), isascii(127));
	check_bool("isascii 128", ft_isascii(128), isascii(128));
	check_bool("isascii EOF", ft_isascii(-1), isascii(-1));

	/* ft_isprint() tests */
	printf("\n================= ft_isprint =================\n");
	check_bool("isprint 32 (space)", ft_isprint(32), isprint(32));
	check_bool("isprint 126 (~)", ft_isprint(126), isprint(126));
	check_bool("isprint 127 (DEL)", ft_isprint(127), isprint(127));
	check_bool("isprint 128", ft_isprint(128), isprint(128));
	check_bool("isprint 31 (US)", ft_isprint(31), isprint(31));
	check_bool("isprint 0", ft_isprint(0), isprint(0));
	check_bool("isprint EOF", ft_isprint(-1), isprint(-1));

	/* ft_toupper() tests */
	printf("\n==================== ft_toupper ====================\n");
	check_chr("toupper 'a'", ft_toupper('a'), toupper('a'));
	check_chr("toupper 'z'", ft_toupper('z'), toupper('z'));
	check_chr("toupper 'A'", ft_toupper('A'), toupper('A'));
	check_chr("toupper 'Z'", ft_toupper('Z'), toupper('Z'));
	check_chr("toupper '0'", ft_toupper('0'), toupper('0'));
	check_chr("toupper '9'", ft_toupper('9'), toupper('9'));
	check_chr("toupper '@'", ft_toupper('@'), toupper('@'));
	check_chr("toupper ':'", ft_toupper(':'), toupper(':'));
	check_chr("toupper 32 (space)", ft_toupper(32), toupper(32));
	check_chr("toupper 126 (~)", ft_toupper(126), toupper(126));

	/* ft_tolower() tests */
	printf("\n==================== ft_tolower =====================\n");
	check_chr("tolower 'A'", ft_tolower('A'), tolower('A'));
	check_chr("tolower 'Z'", ft_tolower('Z'), tolower('Z'));
	check_chr("tolower 'a'", ft_tolower('a'), tolower('a'));
	check_chr("tolower 'z'", ft_tolower('z'), tolower('z'));
	check_chr("tolower '0'", ft_tolower('0'), tolower('0'));
	check_chr("tolower '9'", ft_tolower('9'), tolower('9'));
	check_chr("tolower '@'", ft_tolower('@'), tolower('@'));
	check_chr("tolower ':'", ft_tolower(':'), tolower(':'));
	check_chr("tolower 32 (space)", ft_tolower(32), tolower(32));
	check_chr("tolower 126 (~)", ft_tolower(126), tolower(126));

	printf("\n================= ft_strlen =================\n");
	check_size("strlen \"\"", ft_strlen(""), strlen(""));
	check_size("strlen \"a\"", ft_strlen("a"), strlen("a"));
	check_size("strlen \"hello\"", ft_strlen("hello"), strlen("hello"));
	check_size("strlen with spaces", ft_strlen("Hi 42 Porto"), strlen("Hi 42 Porto"));
	check_size("strlen long", ft_strlen("0123456789abcdefghijkl"), strlen("0123456789abcdefghijkl"));

	return (0);
}
