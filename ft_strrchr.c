/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 19:51:13 by marvin            #+#    #+#             */
/*   Updated: 2026/11/11 20:00:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	target;
	char			*last;

	target = (unsigned char)c;
	last = NULL;
	while (*s != '\0')
	{
		if ((unsigned char)*s == target)
			last = (char *)s;
		s++;
	}
	if (target == '\0')
		return ((char *)s);
	return (last);
}
