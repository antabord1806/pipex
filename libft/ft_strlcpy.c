/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:11:10 by antabord          #+#    #+#             */
/*   Updated: 2025/10/23 16:51:06 by antabord         ###   ########.fr       */
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

size_t	ft_strlcpy_char_adding_destroyer(char *dst, char *src, char c,
		size_t size)
{
	size_t	i;

	i = -1;
	if (size > 1)
	{
		dst[i] = c;
		i++;
		while (i < size - 2 && src[i])
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