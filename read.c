/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 16:53:18 by askochen          #+#    #+#             */
/*   Updated: 2016/12/23 12:01:03 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map_list		*ft_read_file(int fd)
{
	char		**map;
	char		buf[21];
	char		letter;
	t_map_list	*my_list;

	letter = 'A';
	my_list = NULL;
	while (read(fd, buf, 20))
	{
		if (ft_checking(buf) == 1)
		{
			map = ft_strsplit(buf, '\n');
			to_list(&my_list, map, letter++);
		}
		else
			ft_error(1);
		ft_bzero(buf, 21);
		if (read(fd, buf, 1))
			if (buf[0] != '\n')
				ft_error(1);
	}
	if (buf[0] == '\n')
		ft_error(1);
	return (my_list);
}

void			to_list(t_map_list **list, char **map, char letter)
{
	t_map_list	*temp;

	ft_to_letter(map, letter);
	temp = ft_lstnew_my(map);
	temp->min_i = ft_min_i(map);
	temp->min_j = ft_min_j(map);
	temp->height = ft_max_i(map) - temp->min_i + 1;
	temp->width = ft_max_j(map) - temp->min_j + 1;
	ft_lstadd_my(list, temp);
}

char			**ft_fill_matrix(char *buf)
{
	int			i;
	int			j;
	char		**map;

	map = ft_create_matrix_n(4);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			map[i][j] = buf[5 * i + j];
			++j;
		}
		++i;
	}
	return (map);
}
