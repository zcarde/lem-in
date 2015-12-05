/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   successors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/06 19:54:06 by zcarde            #+#    #+#             */
/*   Updated: 2015/08/08 22:28:45 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room	*push_succesor(t_room *room, t_room *add, t_data *data)
{
	t_room *tmp;

	add->poid = 2147483647;
	if (!room->succ)
		room->succ = add;
	else
	{
		if (!ft_strcmp(add->name, data->end->name))
		{
			add->succ = room->succ;
			room->succ = add;
		}
		else
		{
			tmp = room->succ;
			while (tmp && tmp->succ)
				tmp = tmp->succ;
			tmp->succ = add;
		}
	}
	return (room->succ);
}

t_room	*push_other_successor(t_data *data, char *name, char *name2)
{
	t_room *rooms;

	rooms = data->rooms;
	while (rooms)
	{
		if (!ft_strcmp(rooms->name, name))
			rooms->succ = push_succesor(rooms,
				get_room_with_name(name2, data), data);
		rooms = rooms->next;
	}
	return (data->rooms);
}

t_room	*successors_for(t_room *room, t_data *data)
{
	t_pipe *tp;
	t_room *succ;

	tp = data->pipes;
	succ = room->succ;
	while (tp)
	{
		if (!ft_strcmp(tp->s_name, room->name))
		{
			succ = push_succesor(room,
				get_room_with_name(tp->e_name, data), data);
			data->rooms = push_other_successor(data, tp->e_name, tp->s_name);
			data->pipes = remove_pipe(tp, data);
		}
		else if (!ft_strcmp(tp->e_name, room->name))
		{
			succ = push_succesor(room,
				get_room_with_name(tp->s_name, data), data);
			data->rooms = push_other_successor(data, tp->s_name, tp->e_name);
			data->pipes = remove_pipe(tp, data);
		}
		tp = tp->next;
	}
	return (succ);
}

t_room	*create_successors(t_data *data)
{
	t_room *rooms;

	rooms = data->rooms;
	while (rooms)
	{
		if (!ft_strcmp(rooms->name, data->start->name))
			rooms->poid = 0;
		else
			rooms->poid = 2147483647;
		rooms->succ = successors_for(rooms, data);
		rooms = rooms->next;
	}
	return (data->rooms);
}

t_room	*get_lower_successor(t_room *rooms, t_data *data)
{
	t_room	*tmp;
	char	*min_name;
	int		min;
	t_room	*ret;

	if (!rooms)
		return (NULL);
	tmp = rooms->succ;
	min = 2147483647;
	min_name = NULL;
	while (tmp)
	{
		ret = get_room_from_name(tmp->name, data);
		if (ret->poid < min && ret->mark == 0
			&& ft_strcmp(ret->name, data->start->name)
			&& !already_exist_way(rooms->name, ret->name, data))
		{
			min = ret->poid;
			min_name = ret->name;
		}
		tmp = tmp->succ;
	}
	if (!min_name)
		return (NULL);
	return (get_room_from_name(min_name, data));
}
