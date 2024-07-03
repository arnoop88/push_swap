/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apodader <apodader@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:19:55 by apodader          #+#    #+#             */
/*   Updated: 2023/04/12 18:19:55 by apodader         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);	
}

static int	repeat(int num, char **args, int i)
{
	i++;
	while (args[i])
	{
		if (ft_atoi(args[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

void	checker(char **argv)	
{
	int			i;
	long long	temp;

	i = 1;
	while (argv[i])
	{
		temp = ft_atoi(argv[i]);
		if (!ft_isnum(argv[i]))
			error();
		if (temp < -2147483648 || temp > 2147483647)
			error();
		if (repeat(temp, argv, i))
			error();
		i++;
	}
}