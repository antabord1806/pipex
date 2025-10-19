/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-17 15:33:47 by antabord          #+#    #+#             */
/*   Updated: 2025-04-17 15:33:47 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int	res;
	int	sig;
	int	i;

	i = 0;
	sig = 1;
	res = 0;
	while ((s[i] >= 9 && s[i] <= 13) || (s[i] == 32))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sig = sig * -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = (res * 10) + s[i] - '0';
		i++;
	}
	return (sig * res);
}
/*int main(void)
{
	char  s[] = "      -16125h";
	int res1 = ft_atoi(s);
	//int res2 = atoi(s);
	printf("%d\n", res1);
   // printf("%s\n", res2);
	return (0);
}*/