/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-azzo <oel-azzo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 22:52:20 by oel-azzo          #+#    #+#             */
/*   Updated: 2025/11/03 18:12:19 by oel-azzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char		uc;
	const unsigned char	*p;

	p = (const unsigned char *)s;
	uc = (unsigned char)c;
	while (*p)
	{
		if (*p == uc)
			return ((char *)p);
		p++;
	}
	if (uc == '\0')
		return ((char *)p);
	return (NULL);
}
