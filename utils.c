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