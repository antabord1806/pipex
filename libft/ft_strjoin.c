/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025/04/19 17:47:50 by marvin            #+#    #+#             */
/*   Updated: 2025/04/19 17:47:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		len1;
	int		len2;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s2)
			return NULL;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = malloc(len1 + len2 + 1);
	if (!result)
		return NULL;
	if (s1)
	{
		while (s1[i])
		{
			result[j] = s1[i];
			i++;
			j++;
		}
	}
	i = 0;
	while (s2[i])
	{
		result[j] = s2[i];
		i++;
		j++;
	}
	result[j] = '\0';
	return (result);
}


/*int	main(void)
{
	char s1[] = "ola tudo bem";
	char s2[] = "adeus tudo mal";
	printf("%s\n", ft_strjoin(s1, s2));
	return (0);
}*/
