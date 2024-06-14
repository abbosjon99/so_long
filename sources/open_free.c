/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 22:00:30 by akeldiya          #+#    #+#             */
/*   Updated: 2024/06/14 21:27:00 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_data(t_data *data)
{
	if (data->mlx_ptr != NULL)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	free_nodes(&data->map);
	exit(0);
	return (0);
}

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

char	*map_name_check(char *name)
{
	int	i;

	i = ft_strlen(name);
	if (i >= 4)
	{
		if (ft_strncmp(name + i - 4, ".ber", 4) == 0)
			return (name);
		i = 1;
	}
	if (i < 4)
	{
		error_main(NULL, 0);
		ft_printf("Map should be a file with *.ber extension!\n");
		exit(1);
	}
}
