/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/06 19:51:35 by zcarde            #+#    #+#             */
/*   Updated: 2015/08/08 22:32:36 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		check_unicity_room(t_room *a, t_room *b)
{
	if (!ft_strcmp(a->name, b->name))
	{
		ft_putendl("\033[31mError: Already room with same name");
		return (0);
	}
	if (a->x == b->x && a->y == b->y)
	{
		ft_putendl("\033[31mError: Already room with same coord");
		return (0);
	}
	return (1);
}

t_room	*get_room_with_name(char *name, t_data *data)
{
	t_room	*temp;
	t_room	*ret;

	temp = data->rooms;
	while (temp)
	{
		if (!ft_strcmp(temp->name, name))
		{
			ret = (t_room *)malloc(sizeof(t_room) * 1);
			ret->name = temp->name;
			ret->x = temp->x;
			ret->y = temp->y;
			ret->succ = NULL;
			return (ret);
		}
		temp = temp->next;
	}
	return (NULL);
}

t_way	*push_room_to_way(t_way *way, t_room *lower, int size, t_data *data)
{
	if (!way)
		return (create_way(lower, size, data));
	else
	{
		way->rooms[way->size] = ft_strdup(lower->name);
		way->rooms[way->size + 1] = 0;
		way->size++;
	}
	return (way);
}

t_room	*delete_room(t_data *data, t_room *del)
{
	t_room *tmp;

	tmp = data->rooms;
	if (!tmp)
		return (NULL);
	while (tmp->next)
	{
		if (!ft_strcmp(tmp->next->name, del->name))
		{
			tmp->next = del->next;
			return (tmp);
		}
		tmp = tmp->next;
	}
	return (tmp);
}

int		get_nb_rooms(t_data *data)
{
	t_room	*tmp;
	int		i;

	tmp = data->rooms;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
