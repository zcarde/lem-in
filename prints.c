/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/06 19:52:05 by zcarde            #+#    #+#             */
/*   Updated: 2015/08/08 21:38:04 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_room(t_room *room)
{
	ft_putstr(room->name);
	ft_putstr(" ");
	ft_putnbr(room->x);
	ft_putstr(" ");
	ft_putnbr(room->y);
	ft_putstr("\n");
}

void	print_pipe(t_pipe *pipe)
{
	ft_putstr(pipe->s_name);
	ft_putstr("-");
	ft_putendl(pipe->e_name);
}

void	print_map(t_data *data)
{
	t_room *room;
	t_pipe *pipes;

	ft_putnbr(data->nb_fourmis);
	ft_putendl("\n##start");
	print_room(data->start);
	ft_putendl("##end");
	print_room(data->end);
	room = data->rooms;
	while (room)
	{
		if (ft_strcmp(room->name, data->start->name)
			&& ft_strcmp(room->name, data->end->name))
			print_room(room);
		room = room->next;
	}
	pipes = data->pipes;
	while (pipes)
	{
		print_pipe(pipes);
		pipes = pipes->next;
	}
	ft_putendl("");
}
