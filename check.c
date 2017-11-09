/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 16:45:17 by askochen          #+#    #+#             */
/*   Updated: 2016/12/23 15:03:30 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_neighbors1(char *m, int i)
{
	if (m[i + 1] == '#')
	{
		if (m[i + 2] == '#')
		{
			if (m[i + 3] == '#' || m[i + 6] == '#'
				|| m[i + 5] == '#' || m[i + 7] == '#')
				return (1);
		}
		if ((m[i + 5] == '#' && m[i + 6] == '#')
			|| (m[i + 6] == '#' && m[i + 7] == '#')
			|| (m[i + 4] == '#' && m[i + 5] == '#')
			|| (m[i + 6] == '#' && m[i + 11] == '#'))
			return (1);
	}
	return (0);
}

int		ft_neighbors(char *m, int i)
{
	if (m[i + 5] == '#')
	{
		if (m[i + 10] == '#')
		{
			if (m[i + 15] == '#' || m[i + 4] == '#' || m[i + 6] == '#'
				|| m[i + 1] == '#' || m[i + 11] == '#' || m[i + 9] == '#')
				return (1);
		}
		if ((m[i + 6] == '#' && m[i + 11] == '#')
			|| (m[i + 4] == '#' && m[i + 9] == '#')
			|| (m[i + 4] == '#' && m[i + 6] == '#')
			|| (m[i + 6] == '#' && m[i + 7] == '#')
			|| (m[i + 4] == '#' && m[i + 3] == '#'))
			return (1);
	}
	return (ft_neighbors1(m, i));
}

void	ft_to_letter(char **map, char letter)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (map[i][j] == '#')
				map[i][j] = letter;
			++j;
		}
		++i;
	}
}

int		ft_checking(char *buf)
{
	int		cts;
	int		ctd;
	int		i;

	cts = 0;
	ctd = 0;
	i = -1;
	if (buf[19] != '\n' || buf[14] != '\n' || buf[9] != '\n' || buf[4] != '\n')
		return (0);
	while (buf[++i])
	{
		if (buf[i] == '.')
			ctd++;
		if (buf[i] == '#')
			cts++;
	}
	if (ctd != 12 || cts != 4)
		return (0);
	i = 0;
	while (buf[i] != '#')
		i++;
	if (ft_neighbors(buf, i) == 0)
		return (0);
	return (1);
}
