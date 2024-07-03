/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apodader <apodader@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:59:29 by apodader          #+#    #+#             */
/*   Updated: 2023/05/16 15:59:29 by apodader         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_list **a)
{
	t_list	*head;
	int		max;
	int		max_bits;

	head = *a;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_list **a, t_list **b, int size)
{
	t_list	*head;
	int		i;
	int		j;
	int		max_bits;

	head = *a;
	i = 0;
	max_bits = get_max_bits(a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head = *a;
			if (((head->index >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b); 
		}
		while (ft_lstsize(*b) != 0)
			pa(a, b);
		i++;
	}
}