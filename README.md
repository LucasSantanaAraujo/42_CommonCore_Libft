# Libft

> Libft is the first project of the 42 Common Core. The goal is to rewrite a set of functions from the C standard library from scratch, add a few that the standard library does not provide, and package everything into a static library called `libft.a`.

## The library

The project covers 43 functions, grouped in three parts.

### Part 1 — libc functions

Reimplementations of functions that already exist in the standard library, matching
the behaviour described in their manual pages.

> Character classification: `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`,
> `ft_isprint`, `ft_toupper`, `ft_tolower`.

> Memory manipulation, operating on raw bytes without stopping at a null terminator:
> `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`,
> `ft_calloc`.

> String manipulation, operating on null-terminated text: `ft_strlen`, `ft_strlcpy`,
> `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup`,
> `ft_atoi`.

### Part 2 — additional functions

Functions that are not in the standard library but are useful enough that the
curriculum requires them. Most of them allocate memory and return it to the caller.

> `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`,
> `ft_striteri`, `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`.

### Part 3 — linked lists

A singly linked list built on a `t_list` node holding a `void *` payload and a
pointer to the next node.

> `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`,
> `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`.

## Instructions

The library is built with `make`, which compiles every source file and archives
the resulting object files with `ar`.

```
make        # builds libft.a
make clean  # removes the object files
make fclean # removes the object files and libft.a
make re     # fclean followed by all
```

Everything is compiled with `cc -Wall -Wextra -Werror`.

To use the library in a program, include the header and link against the archive:

```
cc -Wall -Wextra -Werror your_program.c -L. -lft -o your_program
```

`libft.a` is an archive, not an executable. It cannot be run on its own; it only
becomes a program once linked with code that provides a `main`.

## Important notice

**This code is published to be read, not reused.**

It is here so that other people can see how these exercises were approached and
follow the reasoning behind each solution. It is not a drop-in library for anyone
else's project, and copying it into a 42 submission is a bad idea.

Read it, understand the approach, then write your own.
