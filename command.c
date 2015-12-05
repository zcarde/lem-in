/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/06 19:49:25 by zcarde            #+#    #+#             */
/*   Updated: 2015/08/06 20:00:07 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		add_start_room(char *str, t_data *data)
{
	t_room *start;

	start = get_room_from_line(str);
	if (!start)
		exit_error("Invalid room");
	data->start = start;
	add_room(start, data);
	return (1);
}

int		add_end_room(char *str, t_data *data)
{
	t_room *end;

	(void)data;
	end = get_room_from_line(str);
	if (!end)
		exit_error("Invalid room");
	data->end = end;
	add_room(end, data);
	return (1);
}

int		command(char *str, t_data *data)
{
	if (!ft_strcmp(str, "##start"))
	{
		if (data->start != NULL)
			exit_error("Can't have two start rooms");
		while (get_next_line(0, &str) >= 0)
			if (ft_strncmp(str, "#", 1))
				break ;
		if (!add_start_room(str, data))
			return (0);
	}
	else if (!ft_strcmp(str, "##end"))
	{
		if (data->end != NULL)
			exit_error("Can't have two end rooms");
		while (get_next_line(0, &str) >= 0)
			if (ft_strncmp(str, "#", 1))
				break ;
		if (!add_end_room(str, data))
			return (0);
	}
	return (1);
}
