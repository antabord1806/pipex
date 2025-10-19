/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-16 11:22:30 by antabord          #+#    #+#             */
/*   Updated: 2025-04-16 11:22:30 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == (char)c)
			break ;
		i--;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

/*int main(void)
{
	const char  s[] = "caaaaaab";
	int c = 'o';
	char *res1 = ft_strrchr(s, c);
	char *res2 = strrchr(s, c);
	if (res1 == NULL)
		printf("Nulo");
	if (res2 == NULL)
		printf("Nulo");
	printf("%s\n", res1);
	printf("%s\n", res2);
	return (0);
}*/