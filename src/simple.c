/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apodader <apodader@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:49:21 by apodader          #+#    #+#             */
/*   Updated: 2023/04/28 18:49:21 by apodader         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fck_norminette(t_list **a, int min)
{
	t_list	*head;

	head = *a;
	if (head->next->index == min)
		ra(a);
	else
	{
		sa(a);
		rra(a);
	}
}

static int	get_min(t_list **stack, int val)
{
	t_list	*head;
	int		min;

	head = *stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && (head->index != val))
			min = head->index;
	}
	return (min);
}

static void	sort_3(t_list **a)
{
	t_list	*head;
	int		min;
	int		next_min;

	head = *a;
	min = get_min(a, -1);
	next_min = get_min(a, min);
	if (sorted(a))
		return ;
	if (head->index == min && head->next->index != next_min)
	{
		ra(a);
		sa(a);
		rra(a);
	}
	else if (head->index == next_min)
	{
		if (head->next->index == min)
			sa(a);
		else
			rra(a);
	}
	else
		fck_norminette(a, min);
}

static void	sort_4(t_list **a, t_list **b)
{
	int	distance;

	if (sorted(a))
		return ;
	distance = get_distance(a, get_min(a, -1));
	if (distance == 1)
		ra(a);
	else if (distance == 2)
	{
		ra(a);
		ra(a);
	}
	else if (distance == 3)
		rra(a);
	if (sorted(a))
		return ;
	pb(a, b);
	sort_3(a);
	pa(a, b);
}

static void	sort_5(t_list **a, t_list **b)
{
	int	distance;

	distance = get_distance(a, get_min(a, -1));
	if (distance == 1)
		ra(a);
	if (distance == 2)
	{
		ra(a);
		ra(a);
	}
	if (distance == 3)
	{
		rra(a);
		rra(a);
	}
	if (distance == 4)
		rra(a);
	if (sorted(a))
		return ;
	pb(a, b);
	sort_4(a, b);
	pa(a, b);
}

void	simple_sort(t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_3(a);
	else if (size == 4)
		sort_4(a, b);
	else if (size == 5)
		sort_5(a, b);
}