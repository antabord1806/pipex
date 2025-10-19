/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-03 15:42:03 by antabord          #+#    #+#             */
/*   Updated: 2025-05-03 15:42:03 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void	del(void *content)
{
	free(content);
}*/

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	t_list	*prox;

	prox = lst->next;
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
	lst = prox;
}

/*int	main(void)
{
	char *str = "tralalerotralala";
	int n = ft_strlen(str);
	char *mal =malloc((n + 1)*sizeof(char *));
	int i = 0;
	if (!mal)
		return (1);
	while (i < n && str[i])
	{
		mal[i] = str[i];
		i++;
	}
	mal[i] = '\0';
	t_list *node = ft_lstnew_bonus(mal);
	if (!node)
	{
		free(mal);
		return (1);
	}
	printf("pré apagar: %s\n", (char *)node->content);
	ft_lstdelone_bonus(node, del);
	printf("apagado com sucesso\n");

	return (0);
}*/