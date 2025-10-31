/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 17:11:12 by antabord          #+#    #+#             */
/*   Updated: 2025/10/31 17:11:56 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "structs.h"

void	ft_lstadd_back_cmd(t_comands **lst, t_comands *new)
{
	t_comands	*tmp;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

int	ft_lstsize_cmd(t_comands *lst)
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

void	ft_free_struct(t_comands *cmd)
{
	t_comands	*tmp;
	t_comands	*next;

	if (!cmd)
		return ;
	tmp = cmd;
	while (tmp)
	{
		next = tmp->next;
		if (tmp->name)
			free(tmp->name);
		if (tmp->args)
			ft_free_all(tmp->args);
		free(tmp);
		tmp = next;
	}
}
