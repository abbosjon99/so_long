/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:32:51 by akeldiya          #+#    #+#             */
/*   Updated: 2024/05/15 12:48:47 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Function checks the collection and exit start points
static void	checkpoints(t_map *head, t_map **nodes)
{
	short int	pe;
	short int	c;
	size_t		i;

	pe = 'P' + 'E';
	c = 0;
	while (head != NULL)
	{
		i = 0;
		while (head->mtxt[i])
		{
			if (head->mtxt[i] == 'P' || head->mtxt[i] == 'E')
				pe = pe - head->mtxt[i];
			else if (head->mtxt[i] == 'C')
				c++;
			else if (head->mtxt[i] != '1' && head->mtxt[i] != '0')
				map_error_wrong_char(nodes);
			i++;
		}
		head = head->nxt;
	}
	if (c == 0 || pe != 0)
		map_error_collectives(nodes);
}

// Function checks if top and bottom wall is 1
static short int	checktopbotwall(char *str)
{
	while (*str)
	{
		if (*str != '1')
			return (0);
		str++;
	}
	return (1);
}

static void	map_char_checker(t_map *head, t_map **nodes)
{
	size_t		len;
	size_t		tmp;
	short int	isitsurr;

	if (!head || !nodes)
		return ;
	checkpoints(head, nodes);
	len = ft_strlen(head->mtxt);
	isitsurr = 0;
	while (head != NULL)
	{
		tmp = ft_strlen(head->mtxt);
		if (tmp != len)
			map_notrectangle(nodes);
		if (head->mtxt[0] != '1' || head->mtxt[tmp - 1] != '1')
			map_notsurrounded(nodes);
		if (head->prev == NULL || head->nxt == NULL)
			isitsurr += checktopbotwall(head->mtxt);
		head = head->nxt;
	}
	if (isitsurr != 2)
		map_notsurrounded(nodes);
}

// After collectives changed that function searchs if one remained
// if yes shows the error
void	finder(t_map *head, t_map **nodes)
{
	while (head)
	{
		if (ft_strchr(head->tmp, 'E') || ft_strchr(head->tmp, 'C'))
			map_notreachable(nodes);
		head = head->nxt;
	}
}

void	map_checker(t_map *head)
{
	if (!head)
		error_main(NULL, 1);
	map_char_checker(head, &head);
	points2p(head, head, 69, true);
	finder(head, &head);
}
