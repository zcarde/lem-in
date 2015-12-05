/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   djikstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/06 19:59:14 by zcarde            #+#    #+#             */
/*   Updated: 2015/12/05 17:46:44 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_way	*djikstra(t_data *data)
{
	t_room	*temp;
	t_room	*tmp_s;
	t_room	*tmp_r;

	reinit_poid(data);
	while (!check_all_mark(data))
	{
		temp = get_lower_poid(data->rooms);
		if (!temp)
			break ;
		temp->mark = 1;
		tmp_s = temp->succ;
		while (tmp_s)
		{
			tmp_r = get_room_from_name(tmp_s->name, data);
			if (!(tmp_r->poid < (temp->poid + 1)))
				tmp_r->poid = (temp->poid + 1);
			tmp_s = tmp_s->succ;
		}
	}
	data->rooms = put_start_first(data->rooms, data);
	reinit_mark(data->rooms);
	return (NULL);
}

t_room	*get_lower_poid(t_room *rooms)
{
	t_room	*temp;
	t_room	*ret;
	int		min;

	ret = NULL;
	min = 2147483647;
	temp = rooms;
	while (temp)
	{
		if (temp->poid <= min && temp->mark == 0)
		{
			ret = temp;
			min = temp->poid;
		}
		temp = temp->next;
	}
	return (ret);
}

void	reinit_poid(t_data *data)
{
	t_room *temp;

	temp = data->rooms;
	while (temp)
	{
		if (!ft_strcmp(temp->name, data->end->name))
			temp->poid = 0;
		else
			temp->poid = 2147483647;
		temp = temp->next;
	}
}

int		check_all_mark(t_data *data)
{
	t_room	*temp;

	temp = data->rooms;
	while (temp)
	{
		if (temp->mark == 0)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	reinit_mark(t_room *rooms)
{
	t_room *temp;

	temp = rooms;
	while (temp)
	{
		temp->mark = 0;
		temp = temp->next;
	}
}
