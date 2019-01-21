/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_select.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 17:02:20 by marvin            #+#    #+#             */
/*   Updated: 2019/01/21 15:13:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_split_stacks(int *stack, size_t len, size_t pivot,
		int *stacks[2])
{
	size_t	i;
	size_t	n[2];

	i = -1;
	n[0] = 0;
	n[1] = 0;
	while (++i < len)
	{
		if (stack[i] <= stack[pivot])
		{
			stacks[0][n[0]] = stack[i];
			n[0]++;
		}
		else
		{
			stacks[1][n[1]] = stack[i];
			n[1]++;
		}
	}
}

static size_t	*ft_sort_ints(int *stack, size_t len, size_t pivot)
{
	size_t	i;
	int		n[2];
	size_t	*res;

	i = -1;
	n[0] = 0;
	n[1] = 0;
	while (++i < len)
	{
		if (stack[i] <= stack[pivot])
			n[0]++;
		else
			n[1]++;
	}
	if (!(res = (size_t*)malloc(sizeof(size_t) * 2)))
		exit(-20);
	res[0] = n[0];
	res[1] = n[1];
	return (res);
}

static int		ft_check_solution(size_t *n, int num, int *stacks[2])
{
	int		res;

	if (n[0] > (size_t)num)
		res = ft_quick_select(stacks[0], n[0], num);
	else
		res = ft_quick_select(stacks[1], n[1], num - n[0]);
	free(stacks[0]);
	free(stacks[1]);
	free(n);
	return (res);
}

int				ft_quick_select(int *stack, size_t len, int num)
{
	size_t	pivot;
	size_t	*n;
	int		*stacks[2];
	int		i;

	i = 0;
	if (len == 1)
		return (stack[0]);
	pivot = len / 2;
	printf("Select pivot: %d\n", stack[pivot]);
	while (1)
	{
		n = ft_sort_ints(stack, len, pivot);
		if ((n[0] != 0 && n[1] != 0) || (n[0] == 1 && n[1] == 0) || (n[0] == 0 && n[1] == 1))
			break ;
		else
			pivot = ++i;
		printf("%zu %zu\n", n[0], n[1]);
	}
	if (!(stacks[0] = (int*)malloc(sizeof(int) * n[0])) ||
			!(stacks[1] = (int*)malloc(sizeof(int) * n[1])))
		exit(-20);
	ft_split_stacks(stack, len, pivot, stacks);
	return (ft_check_solution(n, num, stacks));
}
