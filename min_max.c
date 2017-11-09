/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 17:11:40 by askochen          #+#    #+#             */
/*   Updated: 2016/12/21 18:05:58 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_min_i(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (map[i][j] != '.')
				return (i);
			++j;
		}
		++i;
	}
	return (-1);
}

int		ft_min_j(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (map[i][j] != '.')
				return (j);
			++i;
		}
		++j;
	}
	return (-1);
}

int		ft_max_i(char **map)
{
	int		i;
	int		j;

	i = 3;
	while (i >= 0)
	{
		j = 0;
		while (j < 4)
		{
			if (map[i][j] != '.')
				return (i);
			++j;
		}
		--i;
	}
	return (-1);
}

int		ft_max_j(char **map)
{
	int	i;
	int	j;

	j = 3;
	while (j >= 0)
	{
		i = 0;
		while (i < 4)
		{
			if (map[i][j] != '.')
				return (j);
			++i;
		}
		--j;
	}
	return (-1);
}

int		ft_max_sqrt(int n)
{
	int		i;

	i = 0;
	while ((i * i) < n)
		++i;
	return (i);
}
