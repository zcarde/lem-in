/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/06 19:57:15 by zcarde            #+#    #+#             */
/*   Updated: 2015/08/06 20:00:38 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		get_start_poid(t_data *data)
{
	t_room *room;

	room = data->rooms;
	while (room)
	{
		if (!ft_strcmp(room->name, data->start->name))
			return (room->poid);
		room = room->next;
	}
	return (-1);
}
