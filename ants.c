/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/06 19:50:07 by zcarde            #+#    #+#             */
/*   Updated: 2015/08/08 22:46:59 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	moove_ants_trough_way(t_way *tmp, t_data *data, int *j)
{
	int		i;
	t_room	*room;
	t_room	*room2;

	i = tmp->size;
	while (--i > 0)
	{
		room = get_room_from_name(tmp->rooms[i], data);
		room2 = get_room_from_name(tmp->rooms[i - 1], data);
		if ((room->fourmis == 0 || !ft_strcmp(room->name, data->end->name))
			&& room2->fourmis > 0)
		{
			if (!ft_strcmp(room2->name, data->start->name))
			{
				room->f_name = *j;
				(*j)++;
			}
			else if ((room->f_name = room2->f_name))
				room2->f_name = 0;
			print_ant(room->f_name, room->name);
			room->mark = 1;
			room->fourmis++;
			room2->fourmis--;
		}
	}
}

void	moove_ants(t_data *data)
{
	t_way	*tmp;
	t_room	*tmp2;
	int		i;

	i = 1;
	while ((tmp2 = get_room_from_name(data->end->name, data))->fourmis
		< data->nb_fourmis)
	{
		tmp = data->ways;
		while (tmp)
		{
			reinit_mark(data->rooms);
			moove_ants_trough_way(tmp, data, &i);
			tmp = tmp->next;
		}
		ft_putendl("");
	}
}

void	print_ant(int ant_name, char *r_name)
{
	ft_putstr("L");
	ft_putnbr(ant_name);
	ft_putstr("-");
	ft_putstr(r_name);
	ft_putstr(" ");
}
