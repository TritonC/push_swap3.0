/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:26:31 by mluis-fu          #+#    #+#             */
/*   Updated: 2023/02/16 18:24:51 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    p_stack(t_list *stack)
{
	while(stack)
	{
		printf("%d\n", ((t_nbr *)stack->content)->nbr);
		stack = stack->next;
	}
}

int	main(int argc, char **argv)
{
	t_pushswap	data;

	if (argc == 1)
		return (EXIT_SUCCESS);
	data.stack_a = NULL;
	data.stack_b = NULL;
	read_stack(&data, argc, argv);
	if (is_sorted(data.stack_a))
	{
		free_stack(&data);
		return (EXIT_SUCCESS);
	}
	if (data.length <= 5)
		small_sort(&data);
	else
		group_sort(&data);
		//radix_binary_sort(&data);
    print_id(data.stack_b);
	free_stack(&data);
	return (1);
}
