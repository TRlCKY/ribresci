#include "push_swap.h"

int	is_in_order(t_list **a)
{
	t_list	*b;
	t_list	*c;

	b = *a;
	c = *a;
	c = c->next;
	while (c->next)
	{
		if (b->index > c->index)
			return (1);
		b = b->next;
		c = c->next;
	}
	return (0);
}

void	manual_sort(t_list **a)
{
	t_list	*b;
	t_list	*c;
	int		i;

	i = ft_lstsize(a);
	b = *a;
	c = *a;
	c = c->next;
	if (is_in_order(b))
		return ;
	else
	{
		while (i--)
		{
			if (b->index > c->index)
				rotate(b, b, 0);
			b = b->next;
			c = c->next;
		}
	}
}
