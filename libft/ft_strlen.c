/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-14 11:36:50 by antabord          #+#    #+#             */
/*   Updated: 2025-04-14 11:36:50 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *str)
{
	int	l;

	l = 0;
	if (!str)
		return (l);
	while (str[l])
		l++;
	return (l);
}

/*int	main(void)
{
	char str1[] = "ola mundo";
	char str2[] = "ola mundo";
	strlen(str1);
	ft_strlen(str2);
	printf("%d\n", strlen(str1));
	printf("%d", ft_strlen(str2));
	return (0);
}*/