/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-18 08:38:19 by antabord          #+#    #+#             */
/*   Updated: 2025-04-18 08:38:19 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	unsigned char	*p;
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	p = malloc((ft_strlen((const char *)str) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (i < (size_t)ft_strlen((const char *)str))
	{
		p[i] = (unsigned char)str[i];
		i++;
	}
	p[i] = '\0';
	return ((char *)p);
}
/*int main(void)
{
	char *p;
	int i;
	i = 0;
	p = (char *)ft_strdup("");
	while (i < ft_strlen(p))
	{
		printf("%c", p[i]);
		i++;
	}
	printf("\n");
	free(p);
	return (0);
}*/