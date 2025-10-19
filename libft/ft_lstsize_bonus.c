/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-03 15:42:53 by antabord          #+#    #+#             */
/*   Updated: 2025-05-03 15:42:53 by antabord         ###   ########.fr       */
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

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/*int		main(void)
{
	t_list *n1 = create_node("node1");
	t_list *n2 = create_node("node2");
	t_list *n3 = create_node("node3");
	t_list *n4 = create_node("node4");

	n1 -> next = n2;
	n2 -> next = n3;
	n3 -> next = n4;
	n4 -> next = NULL;

	int c = ft_lstsize(n1);

	printf("%d\n", c);

	free(n1);
	free(n2);
	free(n3);
	free(n4);

	return (0);
}*/