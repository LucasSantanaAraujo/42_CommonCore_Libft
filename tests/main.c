/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 01:47:04 by marvin            #+#    #+#             */
/*   Updated: 2026/11/08 23:09:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "libft.h"

/* ========================= verification helpers ========================== */

static void	check_bool(const char *name, int mine, int ref)
{
	if (!mine == !ref)
		printf("OK    %-22s mine:%-5d libc:%d\n", name, mine, ref);
	else
		printf("FAIL  %-22s mine:%-5d libc:%d\n", name, mine, ref);
}

static void	check_chr(const char *name, int mine, int ref)
{
	if (mine == ref)
		printf("OK    %-22s mine:'%c' (%d)  libc:'%c' (%d)\n",
			name, mine, mine, ref, ref);
	else
		printf("FAIL  %-22s mine:'%c' (%d)  libc:'%c' (%d)\n",
			name, mine, mine, ref, ref);
}

static void	check_size(const char *name, size_t mine, size_t ref)
{
	if (mine == ref)
		printf("OK    %-22s mine:%-5zu libc:%zu\n", name, mine, ref);
	else
		printf("FAIL  %-22s mine:%-5zu libc:%zu\n", name, mine, ref);
}

static void	check_mem(const char *name, const void *mine, const void *ref,
	size_t n)
{
	if (memcmp(mine, ref, n) == 0)
		printf("OK    %s\n", name);
	else
		printf("FAIL  %s\n", name);
}

static int	sign_of(int v)
{
	if (v < 0)
		return (-1);
	if (v > 0)
		return (1);
	return (0);
}

static void	check_sign(const char *name, int mine, int ref)
{
	if (sign_of(mine) == sign_of(ref))
		printf("OK    %-22s mine:%-5d libc:%d\n", name, mine, ref);
	else
		printf("FAIL  %-22s mine:%-5d libc:%d\n", name, mine, ref);
}

static void	check_ptr(const char *name, const void *mine, const void *ref)
{
	if (mine == ref)
		printf("OK    %-22s\n", name);
	else
		printf("FAIL  %-22s mine:%p libc:%p\n", name, mine, ref);
}

/* ============================ part 1: ctype ============================== */

static void	test_isalpha(void)
{
	printf("\n===================== ft_isalpha =====================\n");
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
}

static void	test_isdigit(void)
{
	printf("\n===================== ft_isdigit =====================\n");
	check_bool("isdigit '0'", ft_isdigit('0'), isdigit('0'));
	check_bool("isdigit '9'", ft_isdigit('9'), isdigit('9'));
	check_bool("isdigit '/'", ft_isdigit('/'), isdigit('/'));
	check_bool("isdigit ':'", ft_isdigit(':'), isdigit(':'));
	check_bool("isdigit 'A'", ft_isdigit('A'), isdigit('A'));
	check_bool("isdigit 0", ft_isdigit(0), isdigit(0));
	check_bool("isdigit EOF", ft_isdigit(-1), isdigit(-1));
}

static void	test_isalnum(void)
{
	printf("\n===================== ft_isalnum =====================\n");
	check_bool("isalnum '0'", ft_isalnum('0'), isalnum('0'));
	check_bool("isalnum '9'", ft_isalnum('9'), isalnum('9'));
	check_bool("isalnum 'A'", ft_isalnum('A'), isalnum('A'));
	check_bool("isalnum 'z'", ft_isalnum('z'), isalnum('z'));
	check_bool("isalnum '/'", ft_isalnum('/'), isalnum('/'));
	check_bool("isalnum ':'", ft_isalnum(':'), isalnum(':'));
	check_bool("isalnum '@'", ft_isalnum('@'), isalnum('@'));
	check_bool("isalnum '['", ft_isalnum('['), isalnum('['));
	check_bool("isalnum '`'", ft_isalnum('`'), isalnum('`'));
	check_bool("isalnum '{'", ft_isalnum('{'), isalnum('{'));
	check_bool("isalnum 0", ft_isalnum(0), isalnum(0));
	check_bool("isalnum EOF", ft_isalnum(-1), isalnum(-1));
}

static void	test_isascii(void)
{
	printf("\n===================== ft_isascii =====================\n");
	check_bool("isascii 0", ft_isascii(0), isascii(0));
	check_bool("isascii 1 (SOH)", ft_isascii(1), isascii(1));
	check_bool("isascii 32 (space)", ft_isascii(32), isascii(32));
	check_bool("isascii 126 (~)", ft_isascii(126), isascii(126));
	check_bool("isascii 127 (DEL)", ft_isascii(127), isascii(127));
	check_bool("isascii 128", ft_isascii(128), isascii(128));
	check_bool("isascii EOF", ft_isascii(-1), isascii(-1));
}

static void	test_isprint(void)
{
	printf("\n===================== ft_isprint =====================\n");
	check_bool("isprint 31 (US)", ft_isprint(31), isprint(31));
	check_bool("isprint 32 (space)", ft_isprint(32), isprint(32));
	check_bool("isprint 126 (~)", ft_isprint(126), isprint(126));
	check_bool("isprint 127 (DEL)", ft_isprint(127), isprint(127));
	check_bool("isprint 128", ft_isprint(128), isprint(128));
	check_bool("isprint 0", ft_isprint(0), isprint(0));
	check_bool("isprint EOF", ft_isprint(-1), isprint(-1));
}

static void	test_toupper(void)
{
	printf("\n===================== ft_toupper =====================\n");
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
}

static void	test_tolower(void)
{
	printf("\n===================== ft_tolower =====================\n");
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
}

/* ========================== part 1: strings ============================== */

static void	test_strlen(void)
{
	printf("\n===================== ft_strlen ======================\n");
	check_size("strlen empty", ft_strlen(""), strlen(""));
	check_size("strlen one char", ft_strlen("a"), strlen("a"));
	check_size("strlen hello", ft_strlen("hello"), strlen("hello"));
	check_size("strlen spaces", ft_strlen("Hi 42 Porto"),
		strlen("Hi 42 Porto"));
	check_size("strlen long", ft_strlen("0123456789abcdefghijkl"),
		strlen("0123456789abcdefghijkl"));
}

/* =========================== part 1: memory ============================== */

static void	test_memset(void)
{
	char	mine[20];
	char	ref[20];
	void	*ret;

	printf("\n===================== ft_memset ======================\n");
	memset(mine, 'A', 20);
	memset(ref, 'A', 20);
	ret = ft_memset(mine, 'x', 10);
	memset(ref, 'x', 10);
	check_mem("fill 10 of 20", mine, ref, 20);
	check_bool("returns s", ret == mine, 1);
	memset(mine, 'A', 20);
	memset(ref, 'A', 20);
	ft_memset(mine, 'z', 0);
	check_mem("n = 0 changes nothing", mine, ref, 20);
	memset(mine, 'A', 20);
	memset(ref, 'A', 20);
	ft_memset(mine, 300, 5);
	memset(ref, 300, 5);
	check_mem("value 300 truncated", mine, ref, 20);
	memset(mine, 'A', 20);
	memset(ref, 'A', 20);
	ft_memset(mine, 0, 20);
	memset(ref, 0, 20);
	check_mem("fill whole buffer", mine, ref, 20);
}

static void	test_bzero(void)
{
	char	mine[20];
	char	ref[20];

	printf("\n====================== ft_bzero ======================\n");
	memset(mine, 'A', 20);
	memset(ref, 'A', 20);
	ft_bzero(mine, 10);
	memset(ref, 0, 10);
	check_mem("zero 10 of 20", mine, ref, 20);
	memset(mine, 'A', 20);
	memset(ref, 'A', 20);
	ft_bzero(mine, 0);
	check_mem("n = 0 changes nothing", mine, ref, 20);
	memset(mine, 'A', 20);
	memset(ref, 'A', 20);
	ft_bzero(mine, 20);
	memset(ref, 0, 20);
	check_mem("zero whole buffer", mine, ref, 20);
}

static void	test_memcpy(void)
{
	char	mine[20];
	char	ref[20];
	char	src[] = "0123456789";
	void	*ret;

	printf("\n===================== ft_memcpy ======================\n");
	memset(mine, 'A', 20);
	memset(ref, 'A', 20);
	ret = ft_memcpy(mine, src, 10);
	memcpy(ref, src, 10);
	check_mem("copy 10 of 20", mine, ref, 20);
	check_bool("returns dest", ret == mine, 1);
	memset(mine, 'A', 20);
	memset(ref, 'A', 20);
	ft_memcpy(mine, src, 0);
	check_mem("n = 0 changes nothing", mine, ref, 20);
	memset(mine, 'A', 20);
	memset(ref, 'A', 20);
	ft_memcpy(mine, src, 11);
	memcpy(ref, src, 11);
	check_mem("copy including terminator", mine, ref, 20);
}

static void	test_memmove(void)
{
	char	mine[20];
	char	ref[20];
	void	*ret;

	printf("\n==================== ft_memmove ======================\n");
	memset(mine, 'A', 20);
	memset(ref, 'A', 20);
	ret = ft_memmove(mine, "0123456789", 10);
	memmove(ref, "0123456789", 10);
	check_mem("no overlap", mine, ref, 20);
	check_bool("returns dest", ret == mine, 1);
	memcpy(mine, "abcdef", 7);
	memcpy(ref, "abcdef", 7);
	ft_memmove(mine + 2, mine, 4);
	memmove(ref + 2, ref, 4);
	check_mem("overlap, dest after src", mine, ref, 7);
	printf("      got \"%s\", expected \"ababcd\"\n", mine);
	memcpy(mine, "abcdef", 7);
	memcpy(ref, "abcdef", 7);
	ft_memmove(mine, mine + 2, 4);
	memmove(ref, ref + 2, 4);
	check_mem("overlap, dest before src", mine, ref, 7);
	printf("      got \"%s\", expected \"cdefef\"\n", mine);
	memset(mine, 'A', 20);
	memset(ref, 'A', 20);
	ft_memmove(mine, "xyz", 0);
	check_mem("n = 0 changes nothing", mine, ref, 20);
}

static void	test_memchr(void)
{
	char			buf[] = "hello world";
	unsigned char	bytes[5];

	printf("\n===================== ft_memchr ======================\n");
	check_ptr("found in middle", ft_memchr(buf, 'o', 11),
		memchr(buf, 'o', 11));
	check_ptr("found at start", ft_memchr(buf, 'h', 11),
		memchr(buf, 'h', 11));
	check_ptr("found at end", ft_memchr(buf, 'd', 11),
		memchr(buf, 'd', 11));
	check_ptr("not in block", ft_memchr(buf, 'z', 11),
		memchr(buf, 'z', 11));
	check_ptr("exists beyond n", ft_memchr(buf, 'd', 5),
		memchr(buf, 'd', 5));
	check_ptr("n = 0", ft_memchr(buf, 'h', 0), memchr(buf, 'h', 0));
	bytes[0] = 10;
	bytes[1] = 200;
	bytes[2] = 0;
	bytes[3] = 70;
	bytes[4] = 255;
	check_ptr("byte above 127", ft_memchr(bytes, 200, 5),
		memchr(bytes, 200, 5));
	check_ptr("searches past zero", ft_memchr(bytes, 255, 5),
		memchr(bytes, 255, 5));
	check_ptr("456 truncates to 200", ft_memchr(bytes, 456, 5),
		memchr(bytes, 456, 5));
}

static void	test_memcmp(void)
{
	unsigned char	a[5];
	unsigned char	b[5];

	printf("\n===================== ft_memcmp ======================\n");
	check_sign("equal blocks", ft_memcmp("abcde", "abcde", 5),
		memcmp("abcde", "abcde", 5));
	check_sign("first smaller", ft_memcmp("abcde", "abcdf", 5),
		memcmp("abcde", "abcdf", 5));
	check_sign("first bigger", ft_memcmp("abcdf", "abcde", 5),
		memcmp("abcdf", "abcde", 5));
	check_sign("differ at start", ft_memcmp("zbcde", "abcde", 5),
		memcmp("zbcde", "abcde", 5));
	check_sign("n = 0", ft_memcmp("abc", "xyz", 0),
		memcmp("abc", "xyz", 0));
	check_sign("diff beyond n", ft_memcmp("abcde", "abcdX", 4),
		memcmp("abcde", "abcdX", 4));
	a[0] = 'a';
	a[1] = 0;
	a[2] = 'b';
	a[3] = 'c';
	a[4] = 0;
	b[0] = 'a';
	b[1] = 0;
	b[2] = 'b';
	b[3] = 'z';
	b[4] = 0;
	check_sign("past the zero byte", ft_memcmp(a, b, 5), memcmp(a, b, 5));
	a[0] = 200;
	b[0] = 100;
	check_sign("200 against 100", ft_memcmp(a, b, 5), memcmp(a, b, 5));
}

/* ================================ main =================================== */

int	main(void)
{
	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii();
	test_isprint();
	test_toupper();
	test_tolower();
	test_strlen();
	test_memset();
	test_bzero();
	test_memcpy();
	test_memmove();
	test_memchr();
	test_memcmp();
	printf("\n");
	return (0);
}
