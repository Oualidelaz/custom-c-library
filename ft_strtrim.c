/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-azzo <oel-azzo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 22:43:57 by oel-azzo          #+#    #+#             */
/*   Updated: 2025/10/30 15:41:04 by oel-azzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_of_trim(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_case1(void)
{
	char	*m;

	m = malloc(1);
	if (!m)
		return (NULL);
	m[0] = '\0';
	return (m);
}

static int	ft_start_search(const char *s1, const char *set)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (s1[i] != set[j])
			break ;
		i++;
	}
	return (i);
}

static int	ft_end_search(const char *s1, const char *set)
{
	int	j;
	int	i;

	j = 0;
	i = ft_strlen_of_trim(s1) - 1;
	while (i >= 0)
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (s1[i] != set[j])
			break ;
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	char	*start_ptr;
	int		end;
	char	*m;

	if (!s1 || !set)
		return (NULL);
	start = ft_start_search(s1, set);
	start_ptr = (char *)s1 + start;
	end = ft_end_search(s1, set);
	if (start > end)
		return (ft_case1());
	i = 0;
	m = malloc(((end - start + 1) + 1) * sizeof(char));
	if (!m)
		return (NULL);
	while (i < (end - start + 1))
	{
		*(m + i) = *(start_ptr + i);
		i++;
	}
	*(m + i) = '\0';
	return (m);
}
