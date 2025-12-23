# include "../push_swap.h"
#include <stdio.h>

t_stack	*lstnew(int value)
{
	t_stack	*node;
	
	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return node;
}

void	lst_add_front(t_stack **lst, t_stack *new_node)
{
	if (!lst || !new_node)
		return ;
	new_node->next = *lst;
	*lst = new_node;
}

void	lst_add_back(t_stack **lst, t_stack *new_node)
{
	t_stack	*last;
	
	if (!new_node)
		return ;
	if (!*lst)
	{
		lst_add_front(lst, new_node);
		return ;
	}
	last = *lst;
	while (last->next != NULL) 
	{
		last = last->next;
	}
	last->next = new_node;
	new_node->next = NULL;
}