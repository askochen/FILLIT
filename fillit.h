/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 15:03:59 by apoplavs          #+#    #+#             */
/*   Updated: 2016/12/23 15:06:42 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"

typedef struct			s_map_list
{
	int					min_i;
	int					min_j;
	int					height;
	int					width;
	char				**map;
	struct s_map_list	*next;
}						t_map_list;

void					ft_lstadd_my(t_map_list **alst, t_map_list *new);
t_map_list				*ft_lstnew_my(char **map);
void					ft_print_list(t_map_list *list);
int						ft_lst_size(t_map_list	*list);
int						ft_neighbors(char *m, int i);
int						ft_neighbors1(char *m, int i);
void					ft_to_letter(char **map, char letter);
int						ft_checking(char *buf);
char					**ft_fill_matrix(char *buf);
t_map_list				*ft_read_file(int fd);
void					to_list(t_map_list **list, char **map, char letter);
void					ft_del_matrix_n(char **map, int size);
char					**ft_create_matrix_n(int n);
void					ft_print_matrix(char **map, int size);
void					ft_fill_by_dots(char **map, int size);
int						ft_max_i(char **map);
int						ft_max_j(char **map);
int						ft_min_i(char **map);
int						ft_min_j(char **map);
int						ft_max_sqrt(int n);
void					ft_print_solve(t_map_list *list);
int						ft_solve(char **map, int size, t_map_list *list);
void					ft_pop(t_map_list *list, char **map, int i, int j);
int						ft_push(t_map_list *list, char **map, int i, int j);
void					ft_set_part(t_map_list *list, char **map, int i, int j);
void					ft_error(int i);

#endif
