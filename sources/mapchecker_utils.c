/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecker_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:35:27 by akeldiya          #+#    #+#             */
/*   Updated: 2024/05/15 12:41:51 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// just a helper for isitreachable function
static bool	changeit(char *prv, char *nxt, char *up, char *btm)
{
	bool	isitchange;

	isitchange = false;
	if (*nxt != '1' && *nxt != 'P')
	{
		*nxt = 'P';
		isitchange = true;
	}
	if (*prv != '1' && *prv != 'P')
	{
		*prv = 'P';
		isitchange = true;
	}
	if (*up != '1' && *up != 'P')
	{
		*up = 'P';
		isitchange = true;
	}
	if (*btm != '1' && *btm != 'P')
	{
		*btm = 'P';
		isitchange = true;
	}
	return (isitchange);
}

// Function starts to replace connected
// 0 C P and E to different character maybe P itself
// I choose starting point P
// t_map *temp, int i, bool	isitrun -> just saving lines
void	points2p(t_map *head, t_map *temp, int i, bool isitrun)
{
	while (isitrun)
	{
		temp = head;
		isitrun = false;
		while (temp)
		{
			i = 0;
			while (temp->tmp[i])
			{
				if (temp->tmp[i] == 'P')
					isitrun += changeit(&temp->tmp[i - 1], &temp->tmp[i + 1],
							&temp->prev->tmp[i], &temp->nxt->tmp[i]);
				i++;
			}
			temp = temp->nxt;
		}
	}
}

t_map	*get_last_node(t_map *head)
{
	if (head == NULL)
		return (NULL);
	while (head->nxt != NULL)
	{
		head = head->nxt;
	}
	return (head);
}

// Removes the last n and copies the str for further check
static void	map_processor(t_map *node, t_map **nodes)
{
	size_t	len;

	len = ft_strlen(node->mtxt);
	if (node->mtxt[len - 1] == '\n')
		node->mtxt[len - 1] = '\0';
	node->tmp = ft_strdup(node->mtxt);
	if (!node->mtxt)
		error_main(nodes, 1);
}

t_map	*map_opener(int fd, t_map *map)
{
	char	*str;
	t_map	*newline;
	t_map	*last;

	if (fd < 0 || read(fd, 0, 0))
		map_error_open();
	str = get_next_line(fd);
	while (str != NULL)
	{
		newline = malloc(sizeof(t_map));
		if (!newline)
			error_main(&map, 1);
		last = get_last_node(map);
		newline->prev = last;
		newline->nxt = NULL;
		newline->mtxt = str;
		if (last == NULL)
			map = newline;
		else
			last->nxt = newline;
		map_processor(newline, &map);
		str = get_next_line(fd);
	}
	return (map);
}
