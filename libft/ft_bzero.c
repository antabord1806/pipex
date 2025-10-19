/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-14 14:47:54 by antabord          #+#    #+#             */
/*   Updated: 2025-04-14 14:47:54 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
		*ptr++ = '\0';
}

/*int main(void)
{
	char str1[] = "1234";
	char str2[] = "1234";
	ft_bzero(str1, 3);
	bzero(str2, 3);
	printf("%s\n", str1);
	printf("%s", str2);
	return (0);
}*/