/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-azzo <oel-azzo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:50:03 by oel-azzo          #+#    #+#             */
/*   Updated: 2025/11/10 15:37:12 by oel-azzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*p;
	size_t			i;
	size_t			total;

	total = count * size;
	p = malloc(total);
	if (!p)
		return (NULL);
	i = 0;
	while (total--)
	{
		p[i] = 0;
		i++;
	}
	return ((void *)p);
}
