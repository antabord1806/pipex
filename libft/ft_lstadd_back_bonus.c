/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-03 15:43:02 by antabord          #+#    #+#             */
/*   Updated: 2025-05-03 15:43:02 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*atual;

	if (!new || !lst)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		atual = *lst;
		while (atual->next != NULL)
			atual = atual->next;
		atual->next = new;
	}
}

/*int	main(void)
{
	t_list *tail = ft_lstnew_bonus("adeus");
	t_list *n1 = ft_lstnew_bonus("tralalero");
	t_list *n2 = ft_lstnew_bonus("tralala");
	t_list *n3 = ft_lstnew_bonus("ola");

	ft_lstadd_back_bonus(&tail, n1);
	ft_lstadd_back_bonus(&tail, n2);
	ft_lstadd_back_bonus(&tail, n3);

	t_list *atual = tail;
	while (atual != NULL)
	{
		printf("conteudo nó: %s\n", (char *)atual->content);
		atual = atual->next;
	}
	free(n1);
	free(n2);
	free(n3);
	return (0);
}*/