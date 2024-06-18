/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 22:00:30 by akeldiya          #+#    #+#             */
/*   Updated: 2024/06/18 19:09:02 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error_main(t_map **nodes, bool needtoexit)
{
	free_nodes(nodes);
	ft_printf("Error\n");
	if (needtoexit)
		exit(1);
}

void	error_param(void)
{
	error_main(NULL, 0);
	ft_printf("Only a map file must be given as a parameter!\n");
	exit(1);
}

void	map_error_open(void)
{
	error_main(NULL, 0);
	ft_printf("There is an issue with opening the map file!\n");
	exit(1);
}

void	error_texture(t_data *data)
{
	ft_printf("Error\n");
	ft_printf("There is an issue with opening textures!\n");
	free_data(data);
}
