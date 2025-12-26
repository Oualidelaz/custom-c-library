/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-azzo <oel-azzo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:48:53 by oel-azzo          #+#    #+#             */
/*   Updated: 2025/10/29 17:51:09 by oel-azzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*m;

	i = 0;
	if (!s || !f)
		return (NULL);
	while (s[i])
		i++;
	m = malloc((i + 1) * sizeof(char));
	if (!m)
		return (NULL);
	i = 0;
	while (s[i])
	{
		m[i] = f(i, s[i]);
		i++;
	}
	m[i] = '\0';
	return (m);
}
