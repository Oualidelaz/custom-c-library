/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-azzo <oel-azzo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 10:01:38 by oel-azzo          #+#    #+#             */
/*   Updated: 2025/11/04 00:07:43 by oel-azzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_extract(char **arr, char *s, int start_index, int end_mode)
{
	char	*str;
	int		i;

	if (end_mode == 0)
	{
		while (start_index > 0)
			free(arr[--start_index]);
		free(arr);
		return (NULL);
	}
	else
	{
		str = malloc(((end_mode - start_index) + 1) * sizeof(char));
		if (!str)
			return (NULL);
		i = 0;
		while (start_index < end_mode)
		{
			str[i++] = s[start_index++];
		}
		str[i] = '\0';
		return (str);
	}
}

static int	ft_count_words(char *s, char c)
{
	int	i;
	int	counter;

	counter = 0;
	i = 0;
	if (s[0] != c)
		counter++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] && s[i + 1] != c)
			counter++;
		i++;
	}
	return (counter);
}

static int	ft_detection(char *s, char c, int i, int mode)
{
	if (mode == 0)
	{
		while (s[i] && s[i] == c)
			i++;
	}
	else if (mode == 1)
	{
		while (s[i] && s[i] != c)
			i++;
	}
	return (i);
}

static char	**split_helper(char **arr, char const *s, char c, int start)
{
	int		index;
	int		i;
	char	*word;
	int		end;

	index = 0;
	i = 0;
	while (s[++i])
	{
		if (s[i] == c || s[i + 1] == '\0')
		{
			end = ft_detection((char *)s, c, i, 1);
			if (start < end)
			{
				word = ft_extract(NULL, (char *)s, start, end);
				if (word)
					arr[index++] = word;
				else
					return ((char **)ft_extract(arr, (char *)s, index, 0));
			}
			start = ft_detection((char *)s, c, end, 0);
		}
	}
	arr[index] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		start;
	char	**arr;

	i = 0;
	if (!s)
		return (NULL);
	start = ft_detection((char *)s, c, i, 0);
	if (start == (int)(ft_strlen((char *)s)))
	{
		arr = malloc(sizeof(char *));
		if (!arr)
			return (NULL);
		arr[0] = NULL;
		return (arr);
	}
	arr = malloc((ft_count_words((char *)s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	return (split_helper(arr, s, c, start));
}
