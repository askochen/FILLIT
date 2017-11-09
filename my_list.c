/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 16:55:23 by askochen          #+#    #+#             */
/*   Updated: 2016/12/23 15:03:06 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_lstadd_my(t_map_list **alst, t_map_list *new)
{
	t_map_list	*temp;

	if (alst != NULL && new != NULL)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			temp = *alst;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = new;
		}
	}
}

t_map_list		*ft_lstnew_my(char **map)
{
	t_map_list	*new;

	new = (t_map_list*)malloc(sizeof(t_map_list));
	if (new == NULL)
		return (NULL);
	new->map = map;
	new->next = NULL;
	return (new);
}

void			ft_print_list(t_map_list *list)
{
	while (list != NULL)
	{
		ft_print_matrix(list->map, 4);
		list = list->next;
	}
}

int				ft_lst_size(t_map_list *list)
{
	int		i;

	i = 0;
	while (list != NULL)
	{
		list = list->next;
		i++;
	}
	return (i);
}
