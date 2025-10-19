/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-03 15:42:29 by antabord          #+#    #+#             */
/*   Updated: 2025-05-03 15:42:29 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*void ft_uppercase(void *content)
{
	char *c;

	c = (char *)content;
	while (*c)
	{
		if (*c >= 'a' && *c <= 'z')
			*c = *c - 32;
		c++;
	}
}

int	main(void)
{
	t_list	*tmp;
	t_list	*n1 = ft_lstnew_bonus(ft_strdup("tralalero"));
	t_list	*n2 = ft_lstnew_bonus(ft_strdup("tralala"));
	t_list	*n3 = ft_lstnew_bonus(ft_strdup("ola"));
	t_list	*n4 = ft_lstnew_bonus(ft_strdup("adeus"));

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;
	tmp = n1;
	while (tmp != NULL)
	{
		printf("pre_function: %s\n",(char *)tmp->content);
		tmp = tmp->next;
	}
	tmp = n1;
	ft_lstiter_bonus(n1, ft_uppercase);
	while (tmp != NULL)
	{
		printf("post_function: %s\n",(char *)tmp->content);
		tmp = tmp->next;
	}
	free(n1);
	free(n2);
	free(n3);
	free(n4);
	return (0);
}*/