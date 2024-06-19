/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:28:59 by akeldiya          #+#    #+#             */
/*   Updated: 2024/06/19 10:27:40 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	put_img(int x, int y, char sym, t_data *data)
{
	short int	i;

	i = 0;
	if (sym == '1')
		i = 1;
	else if (sym == 'P')
		i = 2;
	else if (sym == 'C')
	{
		i = 3;
		data->c++;
	}
	else if (sym == 'E')
	{
		i = 0;
		data->extx = x;
		data->exty = y;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[i], x
		* IMG_SIZE, y * IMG_SIZE);
	if (sym == 'P')
		return (1);
	if (sym == 'E')
		return (2);
	return (0);
}

void	ft_draw(t_data *data)
{
	t_map	*mapy;
	int	tmp;
	int		x;
	int		y;

	y = 0;
	data->c = 0;
	mapy = data->map;
	while (y < data->y)
	{
		x = 0;
		while (x < data->x)
		{
			tmp = put_img(x, y, mapy->mtxt[x], data);
			if (tmp == 1)
			{
				data->posx = x;
				data->posy = y;
				data->ptry = mapy;
			}
			else if (tmp == 2)
			{
				data->exptry = mapy;
				mapy->mtxt[x] = '0';
			}
			x++;
		}
		y++;
		mapy = mapy->nxt;
	}
}
