/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:18:46 by marvin            #+#    #+#             */
/*   Updated: 2025/04/21 14:18:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcheck(char s1, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (s1 == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*new_str;

	start = 0;
	if (!s1)
		return (NULL);
	end = ft_strlen(s1) - 1;
	while (ft_strcheck(s1[start], (char *)set))
	{
		start++;
	}
	while (start < end && ft_strcheck(s1[end], (char *)set))
	{
		end--;
	}
	if (start > end)
		return (ft_substr(s1, start, 0));
	new_str = ft_substr(s1, start, end - start + 1);
	return (new_str);
}

/*int	main(void)
{
	char	s1[] = "     ola tudo bem     ";
	char	set[] = "ob m";

	printf("%s\n", ft_strtrim(s1, set));
	return (0);
}*/
