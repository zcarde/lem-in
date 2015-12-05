/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/02 23:38:25 by zcarde            #+#    #+#             */
/*   Updated: 2015/12/05 17:48:07 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_data	*init_data(void)
{
	t_data	*data;
	char	*line;

	if (!(line = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		exit_error("Memoire insuffisante");
	if (!(data = (t_data *)malloc(sizeof(t_data) * 1)))
		exit_error("Memoire insuffisante");
	while (get_next_line(0, &line) >= 0)
	{
		if (ft_strncmp(line, "#", 1))
			break ;
	}
	if (!ft_is_str_number(line))
		exit_error("Not a number");
	data->nb_fourmis = ft_atoi(line);
	data->start = NULL;
	data->end = NULL;
	data->pipes = NULL;
	data->rooms = NULL;
	data->ways = NULL;
	if (data->nb_fourmis <= 0)
		exit_error("Not enough ants");
	return (data);
}

int		lecture(t_data *data)
{
	char *line;

	line = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	while (get_next_line(0, &line) >= 0 && ft_strcmp(line, ""))
	{
		if (!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end"))
		{
			if (!command(line, data))
				return (0);
		}
		else if (get_room_from_line(line) != NULL && data->pipes == NULL)
		{
			add_room(get_room_from_line(line), data);
		}
		else if (get_pipe_from_line(line, data) != NULL)
			add_pipe(get_pipe_from_line(line, data), data);
		else if (ft_strncmp(line, "#", 1))
			exit_error("Syntax");
		free(line);
	}
	if (data->pipes != NULL)
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	t_data *data;

	(void)av;
	if (ac != 1)
		exit_error("Usage : ./lem-in | ./lem-in < file");
	data = init_data();
	if (!data)
		return (2);
	if (!lecture(data))
		return (1);
	if (!data->start)
		exit_error("No start room");
	if (!data->end)
		exit_error("No end room");
	print_map(data);
	data->rooms = create_successors(data);
	data->start->fourmis = data->nb_fourmis;
	djikstra(data);
	data->ways = get_all_ways(data);
	if (!data->ways)
		exit_error("No way out");
	data->ways = order_ways(data);
	moove_ants(data);
}
