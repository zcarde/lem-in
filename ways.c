/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ways.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/06 19:50:35 by zcarde            #+#    #+#             */
/*   Updated: 2015/08/08 22:34:37 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_way	*push_way(t_way *ways, t_way *add)
{
	t_way	*tmp;

	if (!ways)
		return (add);
	else
	{
		tmp = ways;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = add;
	}
	return (ways);
}

t_way	*create_way(t_room *room, int size, t_data *data)
{
	t_way	*way;

	way = (t_way *)malloc(sizeof(t_way) * 1);
	if (!way)
		return (NULL);
	way->rooms = (char **)malloc(sizeof(char *) * (size + 1));
	way->rooms[0] = ft_strdup(data->start->name);
	way->rooms[1] = ft_strdup(room->name);
	way->size = 2;
	way->next = NULL;
	return (way);
}

int		already_exist_way(char *name, char *name2, t_data *data)
{
	t_way	*way;
	int		i;

	way = data->ways;
	if (!way)
		return (0);
	while (way)
	{
		i = 0;
		while (i < way->size)
		{
			if (!ft_strcmp(way->rooms[i], name))
			{
				if (i < way->size - 1 && !ft_strcmp(way->rooms[i + 1], name2))
					return (1);
			}
			i++;
		}
		way = way->next;
	}
	return (0);
}

t_way	*order_ways(t_data *data)
{
	t_way	*tmp;
	t_way	*tmp2;
	char	**tmpc;
	int		tmpi;

	tmp = data->ways;
	while (tmp->next)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->size > tmp2->size)
			{
				tmpc = tmp->rooms;
				tmpi = tmp->size;
				tmp->rooms = tmp2->rooms;
				tmp->size = tmp2->size;
				tmp2->rooms = tmpc;
				tmp2->size = tmpi;
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (data->ways);
}
