/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 22:00:30 by akeldiya          #+#    #+#             */
/*   Updated: 2024/05/15 12:18:44 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_nodes(t_map **nodes)
{
	t_map	*node;
	t_map	*tmp;

	if (nodes == NULL)
		return ;
	node = *nodes;
	while (node != NULL)
	{
		tmp = node->nxt;
		if (node->mtxt)
			free(node->mtxt);
		if (node->tmp)
			free(node->tmp);
		free(node);
		node = tmp;
	}
}

void	error_main(t_map **nodes, bool needtoexit)
{
	free_nodes(nodes);
	ft_printf("Error\n");
	if (needtoexit)
		exit(1);
}

void	map_error_open(void)
{
	error_main(NULL, 0);
	ft_printf("There is an issue with opening the map file!\n");
	exit(1);
}

void	map_notrectangle(t_map **nodes)
{
	error_main(nodes, 0);
	ft_printf("The shape of the map must be rectangular!\n");
	exit(1);
}

void	map_notsurrounded(t_map **nodes)
{
	error_main(nodes, 0);
	ft_printf("The map must be surrounded by walls!\n");
	exit(1);
}
