/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apodader <apodader@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:34:34 by apodader          #+#    #+#             */
/*   Updated: 2023/04/17 17:34:34 by apodader         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;

}	t_list;

void	error(void);
void	ft_free(char **str);
void	checker(char **argv);
void	index_stack(t_list **stack);
int		sorted(t_list **stack);
void	free_stack(t_list **stack);
void	simple_sort(t_list **a, t_list **b);
void	radix_sort(t_list **a, t_list **b, int size);
int		sa(t_list **a);
int		sb(t_list **b);
int		ss(t_list **a, t_list **b);
int		pa(t_list **a, t_list **b);
int		pb(t_list **a, t_list **b);
int		ra(t_list **a);
int		rb(t_list **b);
int		rr(t_list **a, t_list **b);
int		rra(t_list **a);
int		rrb(t_list **b);
int		rrr(t_list **a, t_list **b);
int		get_distance(t_list **stack, int index);
t_list	*ft_lstnew(int value);
void	ft_lstadd_front(t_list **stack, t_list *new);
t_list	*ft_lstlast(t_list *head);
void	ft_lstadd_back(t_list **stack, t_list *new);
int		ft_lstsize(t_list *head);

#endif