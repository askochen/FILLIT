/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 16:43:06 by askochen          #+#    #+#             */
/*   Updated: 2016/12/23 11:58:25 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_error(int i)
{
	if (i == 0)
		ft_putstr("usage: ./fillit source_file\n");
	if (i == 1)
		ft_putstr("error\n");
	exit(1);
}

int			main(int argc, char **argv)
{
	int			fd;
	t_map_list	*list;

	if (argc != 2)
		ft_error(0);
	if ((fd = open(argv[1], O_RDONLY, 0)) == -1)
		ft_error(1);
	list = ft_read_file(fd);
	if (close(fd) == -1)
		ft_error(1);
	if (list == NULL)
		ft_error(1);
	if (ft_lst_size(list) > 26)
		ft_error(1);
	ft_print_solve(list);
	return (0);
}
