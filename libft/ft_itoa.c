/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-25 15:06:24 by antabord          #+#    #+#             */
/*   Updated: 2025-04-25 15:06:24 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_nb_str(char *str, long nb, int *i)
{
	if (nb < 0)
	{
		str[(*i)++] = '-';
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_nb_str(str, nb / 10, i);
	}
	str[(*i)++] = (nb % 10) + '0';
}

static int	ft_int_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_zero(void)
{
	char	*str;

	str = malloc(2 * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		i;
	long	nb;

	i = 0;
	nb = n;
	if (n == 0)
	{
		return (ft_zero());
	}
	len = ft_int_len(n);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
	{
		return (NULL);
	}
	ft_nb_str(str, nb, &i);
	str[i] = '\0';
	return (str);
}
/*int	main(void)
{
	int n;
	n = 0;
	printf("%s\n", ft_itoa(n));
	return (0);
}*/