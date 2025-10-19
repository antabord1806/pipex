/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-03 15:42:49 by antabord          #+#    #+#             */
/*   Updated: 2025-05-03 15:42:49 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

/*int	main(void)
{
	char *c;

	c = "tralalero_tralala";
	t_list *node = ft_lstnew(c);
	if (node == NULL)
	{
		printf("rip");
		return (1);
	}
	printf("conteudo do no: %s\n", (char *)node -> content);
	printf("depois do no vem: %p\n", (void *)node -> next);
	free(node);
	return (0);
}*/
