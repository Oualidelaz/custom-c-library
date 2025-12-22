/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-azzo <oel-azzo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 20:01:01 by oel-azzo          #+#    #+#             */
/*   Updated: 2025/11/03 21:50:04 by oel-azzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_of_substr(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub_str;
	size_t			i;
	unsigned int	l;

	i = 0;
	if (!s)
		return (NULL);
	l = ft_strlen_of_substr(s);
	if (start >= l)
	{
		sub_str = malloc(1);
		sub_str[0] = '\0';
		return (sub_str);
	}
	if (len > l - start)
		len = l - start;
	sub_str = malloc(len + 1);
	if (!sub_str)
		return (NULL);
	while (start < l && i < len)
		sub_str[i++] = s[start++];
	sub_str[i] = '\0';
	return (sub_str);
}
