/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-16 10:21:35 by antabord          #+#    #+#             */
/*   Updated: 2025-04-16 10:21:35 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	int	a;

	if (c >= 'a' && c <= 'z')
	{
		a = c - 32;
		return (a);
	}
	else
		return (c);
}

/*int main(void)
{
	printf("%d\n", ft_toupper('f'));
	printf("%d\n", toupper('f'));
}*/