/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fillit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:35:48 by ppatel            #+#    #+#             */
/*   Updated: 2016/12/08 16:41:37 by ppatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static int		block(char *s, int i, char c)
{
	int		p;

	p = 0;
	if (i >= 0 && i < 19 && s[i] == '#')
	{
		p++;
		s[i] = c;
		p = p + block(s, i + 1, c) + block(s, i + 5, c) \
			+ block(s, i - 1, c) + block(s, i - 5, c);
	}
	return (p);
}

static int		tetris(char *str, char c)
{
	int		i;
	int		p;

	i = 0;
	p = 0;
	while (str && str[i])
	{
		if (str[i] == '#')
		{
			p++;
			if (block(str, i, c) != 4)
				return (1);
		}
		i++;
	}
	if (p != 1)
		return (1);
	return (0);
}

static int		check_fillit(char *str, char c)
{
	int		i;

	i = 0;
	if (ft_strlen(str) < 20 && ft_strlen(str) > 21)
		return (1);
	while (str[i])
	{
		if (i == 4 || i == 9 || i == 14 || i == 19)
		{
			if (str[i] != '\n')
				return (1);
		}
		else if (i == 20)
		{
			if (str[i] != '\n')
				return (1);
		}
		else if (str[i] != '.' && str[i] != '#')
			return (1);
		i++;
	}
	return (tetris(str, c));
}

void			fillit(char **tab)
{
	int		i;

	i = 0;
	if (!tab)
	{
		write(1, "error\n", 6);
		return ;
	}
	while (tab && tab[i])
	{
		if (check_fillit(tab[i], i + 'A') == 1)
		{
			write(1, "error\n", 6);
			return ;
		}
		i++;
	}
	if (ft_strlen(tab[i - 1]) != 20)
	{
		write(1, "error\n", 6);
		return ;
	}
	fillit_data(tab);
}
