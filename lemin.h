/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/06 06:10:12 by zcarde            #+#    #+#             */
/*   Updated: 2015/08/08 22:12:23 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"
# include <stdlib.h>

typedef struct	s_room
{
	char			*name;
	int				x;
	int				y;
	int				fourmis;
	int				f_name;
	int				poid;
	int				mark;
	struct s_room	*next;
	struct s_room	*succ;

}				t_room;

typedef struct	s_way
{
	char			**rooms;
	int				size;
	struct s_way	*next;

}				t_way;

typedef struct	s_pipe
{
	char			*s_name;
	char			*e_name;
	struct s_pipe	*next;

}				t_pipe;

typedef struct	s_data
{
	int				nb_fourmis;
	struct s_room	*start;
	struct s_room	*end;
	struct s_room	*rooms;
	struct s_pipe	*pipes;
	struct s_way	*ways;

}				t_data;

/*
**	ants.c
*/
void			moove_ants_trough_way(t_way *tmp, t_data *data, int *j);
void			moove_ants(t_data *data);
void			print_ant(int ant_name, char *r_name);

/*
**	command.c
*/
int				add_start_room(char *str, t_data *data);
int				add_end_room(char *str, t_data *data);
int				command(char *str, t_data *data);

/*
**	djikstra.c
*/
t_way			*djikstra(t_data *data);
t_room			*get_lower_poid(t_room *rooms);
void			reinit_poid(t_data *data);
int				check_all_mark(t_data *data);
void			reinit_mark(t_room *rooms);

/*
**	djisktra2.c
*/
t_room			*put_start_first(t_room *rooms, t_data *data);

/*
**	error.c
*/
void			exit_error(char *str);

/*
**	pipe.c
*/
t_pipe			*get_pipe_from_line(char *str, t_data *data);
int				check_already_piped(t_pipe *a, t_pipe *b);
t_pipe			*add_pipe(t_pipe *pipe, t_data *data);
t_pipe			*remove_pipe(t_pipe *pipe, t_data *data);

/*
**	prints.c
*/
void			print_room(t_room *room);
void			print_pipe(t_pipe *pipe);
void			print_map(t_data *data);

/*
**	rooms.c
*/
t_room			*create_room(void);
t_room			*add_room(t_room *room, t_data *data);
int				is_room_name(char *str, t_room *rooms);
t_room			*get_room_from_name(char *name, t_data *data);
t_room			*get_room_from_line(char *str);

/*
**	rooms2.c
*/
int				check_unicity_room(t_room *a, t_room *b);
t_room			*get_room_with_name(char *name, t_data *data);
t_way			*push_room_to_way(t_way *way, t_room *lower, int size,
					t_data *data);
t_room			*delete_room(t_data *data, t_room *del);
int				get_nb_rooms(t_data *data);

/*
**	start.c
*/
int				get_start_poid(t_data *data);

/*
**	successors.c
*/
t_room			*push_succesor(t_room *room, t_room *add, t_data *data);
t_room			*push_other_successor(t_data *data, char *name, char *name2);
t_room			*successors_for(t_room *room, t_data *data);
t_room			*create_successors(t_data *data);
t_room			*get_lower_successor(t_room *rooms, t_data *data);

/*
**	ways.c
*/
t_way			*push_way(t_way *ways, t_way *add);
t_way			*create_way(t_room *room, int size, t_data *data);
int				already_exist_way(char *name, char *name2, t_data *data);
t_way			*order_ways(t_data *data);

/*
**	ways2.c
*/
t_way			*get_all_ways(t_data *data);
int				get_nb_ways(t_data *data);
int				get_max_nb_ways(t_data *data);
int				is_ended_way(t_way *way, t_data *data);
t_way			*get_lower_way(int size, t_data *data);

#endif
