/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/06 19:46:25 by zcarde            #+#    #+#             */
/*   Updated: 2015/08/07 13:22:14 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room	*create_room(void)
{
	t_room	*room;

	room = (t_room *)malloc(sizeof(t_room) * 1);
	if (!room)
		return (NULL);
	room->name = NULL;
	room->next = NULL;
	room->succ = NULL;
	room->mark = 0;
	room->poid = 2147483647;
	room->x = 0;
	room->f_name = 0;
	room->y = 0;
	room->fourmis = 0;
	return (room);
}

t_room	*add_room(t_room *room, t_data *data)
{
	t_room *temp;

	if (data->rooms)
	{
		temp = data->rooms;
		while (temp->next)
		{
			if (!check_unicity_room(temp, room))
				exit(4);
			temp = temp->next;
		}
		if (!check_unicity_room(temp, room))
			exit(4);
		temp->next = room;
	}
	else
		data->rooms = room;
	return (NULL);
}

int		is_room_name(char *str, t_room *rooms)
{
	t_room *temp;

	temp = rooms;
	while (temp)
	{
		if (!ft_strcmp(str, temp->name))
			return (1);
		temp = temp->next;
	}
	return (0);
}

t_room	*get_room_from_name(char *name, t_data *data)
{
	t_room *temp;

	temp = data->rooms;
	while (temp)
	{
		if (!ft_strcmp(temp->name, name))
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

t_room	*get_room_from_line(char *str)
{
	char	**split;
	int		i;
	t_room	*room;

	i = 0;
	if (ft_strchr(str, '-'))
		return (NULL);
	if (!(room = create_room()))
		return (NULL);
	split = ft_strsplit(str, ' ');
	while (split[i])
		i++;
	if (i == 3 && ft_is_str_number(split[1]) && ft_is_str_number(split[2]))
	{
		if (split[0][0] != 'L' && !ft_strchr(split[0], '-'))
			room->name = ft_strdup(split[0]);
		room->x = ft_atoi(split[1]);
		room->y = ft_atoi(split[2]);
		if (room->x < 0 || room->y < 0)
			return (NULL);
		if (room->name != NULL)
			return (room);
	}
	free(room);
	return (NULL);
}
