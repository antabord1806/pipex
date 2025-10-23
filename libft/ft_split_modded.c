/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_modded.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:36:39 by antabord          #+#    #+#             */
/*   Updated: 2025/10/23 15:10:01 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_all_modded(char **arr_aloc)
{
	int	i;

	i = 0;
	while (arr_aloc[i])
	{
		free(arr_aloc[i]);
		i++;
	}
	free(arr_aloc);
}

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
			i++;
		while (*s && *s != c)
			s++;
	}
	return (i);
}

static int	ft_str_fill(char **arr_aloc, char const *s, char c, void *arg)
{
	size_t		len;
	int			i;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			len++;
			s++;
		}
		if (len > 0)
		{
			arr_aloc[i] = malloc((len + ft_strlen((char *)arg) + 1) * sizeof(char));
			if (!arr_aloc[i])
				return (ft_free_all_modded(arr_aloc), 0);
			ft_strlcpy(arr_aloc[i], s - len, len + 1);
			ft_strlcat(arr_aloc[i], (char *)arg, len + ft_strlen((char *)arg) + 2);
			i++;
		}
	}
	return (1);
}

char	**ft_split_modded(char const *s, char c, void *arg)
{
	size_t		nwords;
	char		**arr_aloc;

	if (!s)
		return (NULL);
	nwords = ft_count_words(s, c);
	arr_aloc = malloc((nwords + 1) * sizeof(char *));
	if (!arr_aloc)
		return (NULL);
	if (!ft_str_fill(arr_aloc, s, c, arg))
	{
		ft_free_all_modded(arr_aloc);
		return (NULL);
	}
	else
		arr_aloc[nwords] = NULL;
	return (arr_aloc);
}
