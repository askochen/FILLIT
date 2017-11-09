/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 16:47:45 by askochen          #+#    #+#             */
/*   Updated: 2016/12/21 17:37:33 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_solve(t_map_list *list)
{
	char	**map;
	int		size;

	size = ft_max_sqrt(ft_lst_size(list) * 4);
	map = ft_create_matrix_n(size);
	ft_fill_by_dots(map, size);
	while (ft_solve(map, size, list) == 0)
	{
		ft_del_matrix_n(map, size);
		++size;
		map = ft_create_matrix_n(size);
		ft_fill_by_dots(map, size);
	}
	ft_print_matrix(map, size);
}

int		ft_solve(char **map, int size, t_map_list *list)
{
	int			i;
	int			j;

	if (list == NULL)
		return (1);
	i = 0;
	while (i < (size - list->height + 1))
	{
		j = 0;
		while (j < (size - list->width + 1))
		{
			if (ft_push(list, map, i, j))
			{
				if (ft_solve(map, size, list->next))
					return (1);
				else
					ft_pop(list, map, i, j);
			}
			++j;
		}
		++i;
	}
	return (0);
}

void	ft_pop(t_map_list *list, char **map, int i, int j)
{
	int		y;
	int		x;

	y = 0;
	while (y < list->height)
	{
		x = -1;
		while (++x < list->width)
			if (list->map[list->min_i + y][list->min_j + x] != '.')
				map[i + y][j + x] = '.';
		++y;
	}
}

int		ft_push(t_map_list *list, char **map, int i, int j)
{
	int		y;
	int		x;

	y = 0;
	while (y < list->height)
	{
		x = 0;
		while (x < list->width)
		{
			if (map[i + y][j + x] != '.'
				&& list->map[list->min_i + y][list->min_j + x] != '.')
				return (0);
			++x;
		}
		++y;
	}
	ft_set_part(list, map, i, j);
	return (1);
}

void	ft_set_part(t_map_list *list, char **map, int i, int j)
{
	int		y;
	int		x;
	char	sym;

	y = 0;
	while (y < list->height)
	{
		x = 0;
		while (x < list->width)
		{
			sym = list->map[list->min_i + y][list->min_j + x];
			if (sym != '.')
				map[i + y][j + x] = sym;
			++x;
		}
		++y;
	}
}
