/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-17 12:21:23 by antabord          #+#    #+#             */
/*   Updated: 2025-04-17 12:21:23 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 1;
	if (*little == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[j + i] == little[j] && (j + i) < len && big[j + i]
			&& little[j])
		{
			j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
/*int	main(void)
{
	unsigned char little[] = "axx";
	unsigned char big[] = "xx";
	size_t n = 6;
	char *c;
	c = ft_strnstr(big, little, n);
	// NULL
	if (c == NULL)
	{	printf("nulo\n");
		return (0);
	}
	// other
	printf("%s\n", c);
	// printf("%s\n", strnstr(big, little, n));
	return (0);
}*/