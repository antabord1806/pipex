/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-03 15:42:35 by antabord          #+#    #+#             */
/*   Updated: 2025-05-03 15:42:35 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*t_list	*create_node(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}*/

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*atual;

	atual = lst;
	while (atual != NULL)
	{
		if (atual->next == NULL)
			return (atual);
		atual = atual->next;
	}
	return (NULL);
}
/*int	main(void)
{
	t_list *n1 = create_node("ola");
	t_list *n2 = create_node("tudo");
	t_list *n3 = create_node("contigo");

	n1->next = n2;
	n2->next = n3;
	n3->next = NULL;

	t_list *res = ft_lstlast_bonus(n1);
	printf("ultimo node: %s\n", (char *)res->content);
	free(n1);
	free(n2);
	free(n3);
	return (0);
}*/