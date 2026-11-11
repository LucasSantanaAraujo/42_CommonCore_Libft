/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 19:43:15 by marvin            #+#    #+#             */
/*   Updated: 2026/11/11 19:58:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	target;

	target = (unsigned char)c;
	while (*s != '\0')
	{
		if ((unsigned char)*s == target)
			return ((char *)s);
		s++;
	}
	if (target == '\0')
		return ((char *)s);
	return (NULL);
}
