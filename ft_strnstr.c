/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-azzo <oel-azzo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 18:02:49 by oel-azzo          #+#    #+#             */
/*   Updated: 2025/11/08 18:59:37 by oel-azzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_of_nstr(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

static int	to_find(const char *str, const char *l, size_t len, int index)
{
	size_t	lt_l;
	size_t	i;

	lt_l = ft_strlen_of_nstr((char *)l);
	if (lt_l + index > len)
		return (0);
	i = 0;
	while (l[i])
	{
		if (str[index] != l[i])
			return (0);
		i++;
		index++;
	}
	if (i == lt_l)
		return (1);
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	index;

	if (little[0] == '\0')
		return ((char *)big);
	index = 0;
	while (index < len && big[index])
	{
		if (big[index] == little[0])
		{
			if (to_find(big, little, len, index))
				return ((char *)big + index);
		}
		index++;
	}
	return (NULL);
}
