/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-15 10:28:14 by antabord          #+#    #+#             */
/*   Updated: 2025-04-15 10:28:14 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*source;
	unsigned char	*destino;
	size_t			i;

	source = (unsigned char *)src;
	destino = (unsigned char *)dest;
	if (!dest && !src)
		return (NULL);
	i = 0;
	while (n--)
	{
		destino[i] = source[i];
		i++;
	}
	return (destino);
}

/*int main(void)
{
	char src[] = "";
	char dest1[] = "123456789101112";
	char dest2[] = "";
	//ft_memcpy(dest1, src, 4);
	memcpy(dest2, src, 2);
	//printf("%s\n", dest1);
	printf("%s", dest2);
	return (0);
}*/