/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-15 12:11:10 by antabord          #+#    #+#             */
/*   Updated: 2025-04-15 12:11:10 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

/*int main(void)
{
	char src[] = "";
	char dest1[] = "";
	char dest2[] = "";
	ft_strlcpy(dest1, src, 4);
	//strlcpy(dest2, src, 4);
	printf("%s\n", dest1);
	//printf("%s\n", dest2);
	return (0);
}*/