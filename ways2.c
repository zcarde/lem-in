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

t_way	*get_all_ways(t_data *data)
{
	t_way *way;

	while ((way = get_lower_way(get_nb_rooms(data), data)))
	{
		data->ways = push_way(data->ways, way);
	}
	return (data->ways);
}

int		get_nb_ways(t_data *data)
{
	t_way	*ways;
	int		size;

	ways = data->ways;
	size = 0;
	while (ways)
	{
		ways = ways->next;
		size++;
	}
	return (size);
}

int		get_max_nb_ways(t_data *data)
{
	t_room	*start;
	t_room	*end;
	int		s_size;
	int		e_size;

	start = get_room_from_name(data->start->name, data);
	end = get_room_from_name(data->end->name, data);
	s_size = 0;
	e_size = 0;
	while (start->succ)
	{
		start = start->succ;
		s_size++;
	}
	while (end->succ)
	{
		end = end->succ;
		e_size++;
	}
	return ((s_size > e_size) ? e_size : s_size);
}

int		is_ended_way(t_way *way, t_data *data)
{
	if (!way)
		return (0);
	if (!ft_strcmp(way->rooms[way->size - 1], data->end->name))
		return (1);
	return (0);
}

t_way	*get_lower_way(int size, t_data *data)
{
	t_room	*rooms;
	t_room	*lower;
	t_way	*ways;

	ways = NULL;
	lower = NULL;
	rooms = data->rooms;
	if (!rooms->next)
		return (0);
	while ((lower = get_lower_successor(rooms, data))
		&& get_nb_ways(data) < get_max_nb_ways(data))
	{
		ways = push_room_to_way(ways, lower, size, data);
		rooms = get_room_from_name(lower->name, data);
		if (!ft_strcmp(lower->name, data->end->name))
			break ;
		if (ft_strcmp(lower->name, data->end->name)
			&& ft_strcmp(lower->name, data->start->name))
			rooms->mark = 1;
	}
	if (!is_ended_way(ways, data))
		return (NULL);
	return (ways);
}
