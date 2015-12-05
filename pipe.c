/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/06 19:53:20 by zcarde            #+#    #+#             */
/*   Updated: 2015/08/06 22:27:24 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_pipe	*get_pipe_from_line(char *str, t_data *data)
{
	char	**split;
	int		i;
	t_pipe	*pipe;

	i = 0;
	split = ft_strsplit(str, '-');
	while (split[i])
		i++;
	if (i == 2)
	{
		if (is_room_name(split[0], data->rooms)
			&& is_room_name(split[1], data->rooms))
		{
			pipe = (t_pipe *)malloc(sizeof(t_pipe) * 1);
			pipe->s_name = split[0];
			pipe->e_name = split[1];
			pipe->next = NULL;
			return (pipe);
		}
	}
	return (NULL);
}

int		check_already_piped(t_pipe *a, t_pipe *b)
{
	if (!ft_strcmp(a->s_name, b->s_name) && !ft_strcmp(a->e_name, b->e_name))
		exit_error("\033[31mAlready piped");
	if (!ft_strcmp(a->s_name, b->e_name) && !ft_strcmp(a->e_name, b->s_name))
		exit_error("\033[31mAlready piped");
	return (1);
}

t_pipe	*add_pipe(t_pipe *pipe, t_data *data)
{
	t_pipe *temp;

	if (data->pipes == NULL)
		data->pipes = pipe;
	else
	{
		temp = data->pipes;
		while (temp->next)
		{
			if (!check_already_piped(temp, pipe))
				exit(5);
			temp = temp->next;
		}
		if (!check_already_piped(temp, pipe))
			exit(5);
		temp->next = pipe;
	}
	return (NULL);
}

t_pipe	*remove_pipe(t_pipe *pipe, t_data *data)
{
	t_pipe *temp;

	temp = data->pipes;
	if (!temp)
		return (data->pipes);
	if (!ft_strcmp(temp->s_name, pipe->s_name)
		&& !ft_strcmp(temp->e_name, pipe->e_name))
		return (temp->next);
	while (temp->next)
	{
		if (!ft_strcmp(temp->next->s_name, pipe->s_name)
			&& !ft_strcmp(temp->next->e_name, pipe->e_name))
		{
			temp->next = pipe->next;
			return (data->pipes);
		}
		temp = temp->next;
	}
	return (data->pipes);
}
