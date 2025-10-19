/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-14 12:39:56 by antabord          #+#    #+#             */
/*   Updated: 2025-04-14 12:39:56 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
	{
		*p = (unsigned char)c;
		p++;
	}
	return (s);
}
/*int main(void)
{
	char str1[] = "";
	char str2[] = "";
	ft_memset(str1, 'a', 5);
	//memset(str2, 'a', 5);
	printf("%s\n", str1);
	printf("%s", str2);
	return (0);
}*/
