/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 16:44:11 by askochen          #+#    #+#             */
/*   Updated: 2016/12/21 17:58:37 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_create_matrix_n(int n)
{
	char	**temp;
	int		i;

	i = 0;
	temp = (char **)malloc(sizeof(char*) * n);
	while (i < n)
	{
		temp[i] = (char *)malloc(sizeof(char) * n);
		++i;
	}
	return (temp);
}

void	ft_del_matrix_n(char **map, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		free(map[i]);
		++i;
	}
	free(map);
}

void	ft_print_matrix(char **map, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putchar(map[i][j]);
			++j;
		}
		ft_putchar('\n');
		++i;
	}
}

void	ft_fill_by_dots(char **map, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			map[i][j] = '.';
			++j;
		}
		++i;
	}
}
