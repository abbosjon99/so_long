/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:24:07 by akeldiya          #+#    #+#             */
/*   Updated: 2024/05/15 12:41:46 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_map
{
	int				id;
	char			*mtxt;
	char			*tmp;
	struct s_map	*prev;
	struct s_map	*nxt;
}					t_map;

t_map				*map_opener(int fd, t_map *map);
t_map				*get_last_node(t_map *head);

void				map_checker(t_map *head);
void				free_nodes(t_map **nodes);
void				error_main(t_map **nodes, bool needtoexit);
void				map_error_open(void);
void				map_notrectangle(t_map **nodes);
void				map_notsurrounded(t_map **nodes);
void				map_notreachable(t_map **nodes);
void				map_error_wrong_char(t_map **map);
void				map_error_collectives(t_map **map);
void				points2p(t_map *head, t_map *temp, int i,
						bool isitrun);

#endif
