/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apodader <apodader@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:19:52 by apodader          #+#    #+#             */
/*   Updated: 2023/04/12 18:19:52 by apodader         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_list **stack)
{
	t_list	*head;
	t_list	*next;
	int		tmp_val;
	int		tmp_index;
	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	next = head->next;
	tmp_val = head->value;
	tmp_index = head->index;
	head->value = next->value;
	head->index = next->index;
	next->value = tmp_val;
	next->index = tmp_index;
	return (0);
}

int	sa(t_list **a)
{
	if (swap(a) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	sb(t_list **b)
{
	if (swap(b) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	return (0);
}

int	ss(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) < 2 || ft_lstsize(*b) < 2)
		return (-1);
	swap(a);
	swap(b);
	ft_putendl_fd("ss", 1);
	return (0);
}

int	push(t_list **stack_src, t_list **stack_dest)
{
	t_list	*tmp;
	t_list	*head_dest;
	t_list	*head_src;

	if (ft_lstsize(*stack_src) == 0)
		return (-1);
	head_src = *stack_src;
	head_dest = *stack_dest;
	tmp = head_src;
	head_src = head_src->next;
	*stack_src = head_src;
	if (!head_dest)
	{
		head_dest = tmp;
		head_dest->next = NULL;
		*stack_dest = head_dest;
	}
	else
	{
		tmp->next = head_dest;
		*stack_dest = tmp;
	}
	return (0);
}

int	pa(t_list **a, t_list **b)
{
	if (push(b, a) == -1)
		return (-1);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	pb(t_list **a, t_list **b)
{
	if (push(a, b) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (0);
}

int	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}

int	ra(t_list **a)
{
	if (rotate(a) == -1)
		return (-1);
	ft_putendl_fd("ra", 1);
	return (0);
}

int	rb(t_list **b)
{
	if (rotate(b) == -1)
		return (-1);
	ft_putendl_fd("rb", 1);
	return (0);
}

int	rr(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) < 2 || ft_lstsize(*b) < 2)
		return (-1);
	rotate(a);
	rotate(b);
	ft_putendl_fd("rr", 1);
	return (0);
}

int	rrotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
	return (0);
}

int	rra(t_list **a)
{
	if (rrotate(a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rrb(t_list **b)
{
	if (rrotate(b) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	rrr(t_list **a, t_list **b)
{
	if ((ft_lstsize(*a) < 2) || (ft_lstsize(*b) < 2))
		return (-1);
	rrotate(a);
	rrotate(b);
	ft_putendl_fd("rrr", 1);
	return (0);
}