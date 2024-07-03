/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apodader <apodader@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:19:41 by apodader          #+#    #+#             */
/*   Updated: 2023/04/12 18:19:41 by apodader         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_init(char **argv, t_list **stack)
{
	t_list	*new;
	int		i;

	i = 1;
	while (argv[i])
	{
		new = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	index_stack(stack);
}

static void	ft_sort(t_list **a, t_list **b)
{
	int	size;
	
	size = ft_lstsize(*a);
	if (size <= 5)
		simple_sort(a, b);
	else
		radix_sort(a, b, size);
}

int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;

	if (argc < 2)
		return (-1);
	checker(argv);
	a = (t_list **)malloc(sizeof(t_list));
	b = (t_list **)malloc(sizeof(t_list));
	*a = NULL;
	*b = NULL;
	ft_init(argv, a);
	if (sorted(a))
	{
		free_stack(a);
		free_stack(b);
		return (0);
	}
	ft_sort(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}