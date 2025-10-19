/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-17 16:23:31 by antabord          #+#    #+#             */
/*   Updated: 2025-04-17 16:23:31 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > (size_t)-1 / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
/*int	main(void)
{
	int *a;
	size_t n = 6;
	int i = 0;

	a = (int *)ft_calloc(6, sizeof(int));
	if (a == NULL)
	{
		printf("Rip\n");
		return (1);
	}
	while (i < n)
	{
		printf("%d", a[i]);
		i++;
	}
	printf("\n");
	free(a);
	return (0);
}*/