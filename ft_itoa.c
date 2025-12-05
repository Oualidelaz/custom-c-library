/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-azzo <oel-azzo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:49:55 by oel-azzo          #+#    #+#             */
/*   Updated: 2025/10/30 16:09:26 by oel-azzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*helper_itoa(void)
{
	char	*m;

	m = malloc(2 * sizeof(char));
	if (!m)
		return (NULL);
	m[0] = '0';
	m[1] = '\0';
	return (m);
}

static int	ft_len(long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i += 1;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long int	nb;
	int			total;
	char		*m;

	if (n == 0)
		return (helper_itoa());
	nb = (long int)n;
	total = ft_len(nb);
	m = malloc((total + 1) * sizeof(char));
	if (!m)
		return (NULL);
	if (nb < 0)
	{
		nb *= -1;
		m[0] = '-';
	}
	m[total--] = '\0';
	while (nb > 0)
	{
		m[total--] = nb % 10 + '0';
		nb /= 10;
	}
	return (m);
}
