/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-16 10:32:26 by antabord          #+#    #+#             */
/*   Updated: 2025-04-16 10:32:26 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	int	a;

	if (c >= 'A' && c <= 'Z')
	{
		a = c + 32;
		return (a);
	}
	else
		return (c);
}

/*int main(void)
{
	printf("%d\n", ft_tolower('a'));
	printf("%d\n", tolower('a'));
}*/