/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:13:26 by akeldiya          #+#    #+#             */
/*   Updated: 2024/06/18 21:33:31 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static short int	to_right(t_data *data)
{
	t_map	*temp;

	temp = data->ptry;
	if (temp->mtxt[data->posx + 1] != '1')
	{
		if (temp->mtxt[data->posx + 1] == 'E' && data->c == 0)
			finish(data);
		if (temp->mtxt[data->posx + 1] == 'E')
			return (0);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[0],
			data->posx * IMG_SIZE, data->posy * IMG_SIZE);
		data->posx++;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[2],
			data->posx * IMG_SIZE, data->posy * IMG_SIZE);
		if (temp->mtxt[data->posx] == 'C')
		{
			temp->mtxt[data->posx] = '0';
			data->c--;
		}
		return (1);
	}
	return (0);
}

static short int	to_left(t_data *data)
{
	t_map	*temp;

	temp = data->ptry;
	if (temp->mtxt[data->posx - 1] != '1')
	{
		if (temp->mtxt[data->posx - 1] == 'E' && data->c == 0)
			finish(data);
		if (temp->mtxt[data->posx - 1] == 'E')
			return (0);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[0],
			data->posx * IMG_SIZE, data->posy * IMG_SIZE);
		data->posx--;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[2],
			data->posx * IMG_SIZE, data->posy * IMG_SIZE);
		if (temp->mtxt[data->posx] == 'C')
		{
			temp->mtxt[data->posx] = '0';
			data->c--;
		}
		return (1);
	}
	return (0);
}

static short int	to_up(t_data *data)
{
	t_map	*temp;

	temp = data->ptry;
	if (temp->prev->mtxt[data->posx] != '1')
	{
		if (temp->prev->mtxt[data->posx] == 'E' && data->c == 0)
			finish(data);
		if (temp->prev->mtxt[data->posx] == 'E')
			return (0);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[0],
			data->posx * IMG_SIZE, data->posy * IMG_SIZE);
		temp = temp->prev;
		data->ptry = temp;
		data->posy--;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[2],
			data->posx * IMG_SIZE, data->posy * IMG_SIZE);
		if (temp->mtxt[data->posx] == 'C')
		{
			temp->mtxt[data->posx] = '0';
			data->c--;
		}
		return (1);
	}
	return (0);
}

static short int	to_bottom(t_data *data)
{
	t_map	*temp;

	temp = data->ptry;
	if (temp->nxt->mtxt[data->posx] != '1')
	{
		if (temp->nxt->mtxt[data->posx] == 'E' && data->c == 0)
			finish(data);
		if (temp->nxt->mtxt[data->posx] == 'E')
			return (0);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[0],
			data->posx * IMG_SIZE, data->posy * IMG_SIZE);
		temp = temp->nxt;
		data->ptry = temp;
		data->posy++;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[2],
			data->posx * IMG_SIZE, data->posy * IMG_SIZE);
		if (temp->mtxt[data->posx] == 'C')
		{
			temp->mtxt[data->posx] = '0';
			data->c--;
		}
		return (1);
	}
	return (0);
}

void	on_keypress(int keysym, t_data *data)
{
	static int	counter;
	int			i;

	i = counter;
	if (keysym == 65307)
		free_data(data);
	else if (keysym == 100 || keysym == 65363)
		i += to_right(data);
	else if (keysym == 97 || keysym == 65361)
		i += to_left(data);
	else if (keysym == 119 || keysym == 65362)
		i += to_up(data);
	else if (keysym == 115 || keysym == 65364)
		i += to_bottom(data);
	if (i != counter)
	{
		ft_printf("%d collectable.\n", data->c);
		counter = i;
		ft_printf("%d moves.\n", counter);
	}
}
