/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-16 17:08:54 by antabord          #+#    #+#             */
/*   Updated: 2025-04-16 17:08:54 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*p = (const unsigned char *)s;

	i = 0;
	while (i < n)
	{
		if (p[i] == (unsigned char)c)
			return ((void *)&p[i]);
		i++;
	}
	return (NULL);
}

/*int main(void)
{
	char s[] = "ola tudo bem";
	int c = 0;
	size_t n = 0;
	char *res1 = ft_memchr(s, c, n);
	char *res2 = memchr(s, c, n);
	if (res1 == NULL)
		printf("Nulo\n");
	if (res2 == NULL)
		printf("Nulo\n");
	else
	{
		printf("%s\n", res1);
		printf("%s\n", res2);
	}
	return (0);
}*/
