/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-03 15:42:43 by antabord          #+#    #+#             */
/*   Updated: 2025-05-03 15:42:43 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void	del(void *content)
{
	free(content);
}*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newstr;
	t_list	*newnode;
	void	*new_content;

	newstr = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		new_content = f(lst->content);
		newnode = ft_lstnew(new_content);
		if (!newnode)
		{
			ft_lstclear(&newstr, del);
			return (NULL);
		}
		ft_lstadd_back(&newstr, newnode);
		lst = lst->next;
	}
	return (newstr);
}
/*void	*ft_uppercase(void *content)
{
	char *str = (char *)content;
	char *copy = strdup(str);
	char *p = copy;

	if (!copy)
		return NULL;

	while (*p)
	{
		if (*p >= 'a' && *p <= 'z')
			*p -= 32;
		p++;
	}
	return (copy);
}


int	main(void)
{
	t_list *tmp;
	t_list *n1 = ft_lstnew(ft_strdup("ola"));
	t_list *n2 = ft_lstnew(ft_strdup("tudo"));
	t_list *n3 = ft_lstnew(ft_strdup("bem"));
	//t_list *newlst;

	n1->next = n2;
	n2->next = n3;
	n3->next = NULL;

	tmp = n1;
	printf("antes da funçao:\n");
	while (tmp != NULL)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	
	printf("depois:\n");
	tmp = n1;
	while (tmp != NULL)
	{
		ft_lstmap(tmp, &ft_uppercase, del);
		ft_lstclear(&newlst, del);
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	tmp = NULL;
	free(n1);
	free(n2);
	free(n3);
	ft_lstclear(&n1, del);
	return (0);
}*/