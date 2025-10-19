/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-18 09:36:35 by antabord          #+#    #+#             */
/*   Updated: 2025-04-18 09:36:35 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	max;

	if (!s)
		return (NULL);
	i = 0;
	max = ft_strlen(s);
	if (start > max)
		return ((char *)ft_strdup(""));
	if (len > max - start)
		len = max - start;
	sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
/*int main(void)
{
	char	*s;

	s = ft_substr("ola tudo bem", 30, 10);
	if (!s)
	{
		printf("rip\n");
		return (1);
	}
	printf("%s\n", s);
	free (s);
	return (0);
}
int	main(void)
{
	char *s = ft_substr("ola tudo bem", 7, 20); // "tudo bem"

	if (!s)
	{
		printf("Erro na substring.\n");
		return (1);
	}

	printf("Substring: %s\n", s);
	free(s);
	return (0);
}*/