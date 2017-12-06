/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sol_fillit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:37:32 by ppatel            #+#    #+#             */
/*   Updated: 2016/12/08 17:40:32 by ppatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static int		place(char *str, t_tet *tetris, int len, int i)
{
	int		p;
	int		pos;
	int		strlen;

	p = 0;
	strlen = len * (len + 1);
	while (p < 4)
	{
		pos = (tetris->pos[p] / 100) * (len + 1) + tetris->pos[p] % 5;
		if (pos + i >= strlen || str[pos + i] != '.')
			return (1);
		p++;
	}
	p = 0;
	while (p < 4)
	{
		pos = (tetris->pos[p] / 100) * (len + 1) + tetris->pos[p] % 5;
		str[pos + i] = tetris->c;
		p++;
	}
	return (0);
}

static void		unplace(char *str, t_tet *tetris, int len, int i)
{
	int		p;
	int		pos;

	p = 0;
	while (p < 4)
	{
		pos = (tetris->pos[p] / 100) * (len + 1) + tetris->pos[p] % 5;
		str[pos + i] = '.';
		p++;
	}
}

static int		fill_str(char *str, t_tet *start, int len)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str && str[i])
	{
		j = 0;
		if (place(str, start, len, i) == 0)
		{
			j++;
			if (start->next)
				j = fill_str(str, start->next, len);
			if (!start->next || j == 0)
				return (0);
		}
		if (j != 0)
			unplace(str, start, len, i);
		i++;
	}
	if (j == 0)
		return (1);
	return (0);
}

void			print_fillit(char *s)
{
	while (s && *s)
	{
		write(1, &*s, 1);
		s++;
	}
}

char			*sol_fillit(t_tet *start)
{
	char	*sq;
	int		len;
	int		i;

	len = 2;
	while (1)
	{
		i = len;
		if (!(sq = ft_strnew(len * (len + 1))))
			return (NULL);
		ft_memset(sq, '.', (len * (len + 1)));
		while (i < (len * (len + 1)))
		{
			sq[i] = '\n';
			i = i + len + 1;
		}
		if (fill_str(sq, start, len) == 0)
			return (sq);
		len++;
	}
}
