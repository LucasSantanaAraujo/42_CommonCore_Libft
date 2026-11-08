/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 22:48:19 by marvin            #+#    #+#             */
/*   Updated: 2026/11/08 22:52:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*src;
	unsigned char			target;
	size_t					i;

	src = s;
	target = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (src[i] == target)
			return ((void *)(src + i));
		i++;
	}
	return (NULL);
}
