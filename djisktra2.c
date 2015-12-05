/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   djisktra2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/06 19:59:47 by zcarde            #+#    #+#             */
/*   Updated: 2015/08/06 20:00:13 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room	*put_start_first(t_room *rooms, t_data *data)
{
	t_room *temp;
	t_room *tmp2;

	temp = rooms;
	while (temp->next)
	{
		if (!ft_strcmp(temp->next->name, data->start->name))
		{
			tmp2 = temp->next;
			rooms->next = temp->next->next;
			tmp2->next = rooms;
			rooms = tmp2;
			return (rooms);
		}
		temp = temp->next;
	}
	return (rooms);
}
