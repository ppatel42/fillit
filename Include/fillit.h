/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:36:19 by ppatel            #+#    #+#             */
/*   Updated: 2016/12/08 17:38:51 by ppatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define BUF_SIZE 21

typedef struct	s_tet
{
	char			c;
	int				pos[4];
	struct s_tet	*next;
}				t_tet;

void			fillit(char **tab);
void			fillit_data(char **tab);
char			*sol_fillit(t_tet *start);
void			print_fillit(char *s);

#endif
