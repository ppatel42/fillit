/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:35:16 by ppatel            #+#    #+#             */
/*   Updated: 2016/12/08 17:40:28 by ppatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static t_tet	*ft_create_tet(int *pos, char c)
{
	int		i;
	t_tet	*new;

	i = 0;
	if (!(new = (t_tet *)malloc(sizeof(t_tet))))
		return (NULL);
	if (pos == NULL)
	{
		new->pos[0] = '\0';
		new->c = 0;
	}
	else
	{
		while (i < 4)
		{
			new->pos[i] = pos[i];
			i++;
		}
		new->c = c;
	}
	new->next = NULL;
	return (new);
}

static void		ft_list_push_back(t_tet **start, int *pos, char c)
{
	t_tet	*cur;
	t_tet	*new;

	cur = 0;
	new = ft_create_tet(pos, c);
	if (start)
	{
		cur = *start;
		while (cur && cur->next)
			cur = cur->next;
		if (cur)
			cur->next = new;
		else
			cur = new;
	}
}

static void		reset(int *new)
{
	int		i;
	int		n;

	i = 3;
	n = 0;
	while (i >= 0)
	{
		new[i] -= new[0];
		if (new[i] > 100 && new[i] < 105 && n < 105 - new[i])
			n = 105 - new[i];
		if (new[i] > 200 && new[i] < 210 && n < 210 - new[i])
			n = 210 - new[i];
		i--;
	}
	while (++i < 4)
		new[i] += n;
}

static int		*r_tet(char *str)
{
	int		i;
	int		j;
	int		p;
	int		*new;

	i = 0;
	j = 0;
	p = 0;
	if (!(new = (int *)ft_memalloc(4)))
		return (NULL);
	while (str && str[i])
	{
		while (str[i] && (str[i] == '.' || str[i] == '\n'))
			if (str[i++] == '\n')
				j += 100;
		if (p < 4)
			new[p++] = i + j;
		i++;
	}
	reset(new);
	return (new);
}

void			fillit_data(char **tab)
{
	int		i;
	t_tet	*tetris;

	i = 1;
	if (tab && tab[0])
		tetris = ft_create_tet(r_tet(tab[0]), 'A');
	while (tab && tab[i])
	{
		ft_list_push_back(&tetris, r_tet(tab[i]), i + 'A');
		i++;
	}
	free(tab);
	print_fillit(sol_fillit(tetris));
}
