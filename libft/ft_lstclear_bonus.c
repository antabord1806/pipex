/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-03 15:42:22 by antabord          #+#    #+#             */
/*   Updated: 2025-05-03 15:42:22 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void	del(void *content)
{
	free(content);
}*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

/*int	main(void)
{
	t_list	*n1;
	t_list	*n2;
	t_list	*n3;
	t_list	*n4;
	t_list	*tmp;

	n1 = ft_lstnew_bonus(ft_strdup("tralalero"));
	n2 = ft_lstnew_bonus(ft_strdup("tralala"));
	n3 = ft_lstnew_bonus(ft_strdup("bombradiro"));
	n4 = ft_lstnew_bonus(ft_strdup("crocodilo"));
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;
	tmp = n1;
	while (tmp != NULL)
	{
		printf("pre cleanup:%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	n2->next = NULL;
	ft_lstclear_bonus(&n3, del);
	tmp = n1;
	while (tmp != NULL)
	{
		printf("post cleanup:%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	ft_lstclear_bonus(&n1, del);
	return (0);
}*/
