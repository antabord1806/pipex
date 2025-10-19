/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 09:51:02 by marvin            #+#    #+#             */
/*   Updated: 2025/04/22 09:51:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char const *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, (char *)&s[i]);
		i++;
	}
}

/*void    ft_uppercase(unsigned int i, char *c)
{
	if(i > 3 && *c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

int	main(void)
{
	char str[] = "ola tudo bem";
	ft_striteri(str, ft_uppercase);
	printf("%s\n", str);
	return (0);
}*/