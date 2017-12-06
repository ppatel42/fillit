/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:37:07 by ppatel            #+#    #+#             */
/*   Updated: 2016/12/08 17:39:25 by ppatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static int		tabsize(char **tab)
{
	int		i;

	i = 0;
	if (tab)
		while (tab[i])
			i++;
	return (i);
}

static char		**ft_tab(char **tab, char *str)
{
	int		i;
	char	**new;

	i = 0;
	if (!(new = (char **)malloc(sizeof(char **) * (tabsize(tab) + 2))))
		return (NULL);
	while (tab && tab[i])
	{
		new[i] = ft_strdup(tab[i]);
		i++;
	}
	new[i] = ft_strdup(str);
	new[i + 1] = 0;
	return (new);
}

int				main(int ac, char **av)
{
	int		ret;
	int		fd;
	char	buf[BUF_SIZE + 1];
	char	**tab;

	fd = open(av[1], O_RDWR);
	if (ac != 2 || fd == -1)
	{
		write(1, "usage: ./fillit [use 1 valid file]\n", 35);
		return (0);
	}
	tab = NULL;
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tab = ft_tab(tab, buf);
	}
	close(fd);
	fillit(tab);
	return (0);
}
