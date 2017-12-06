/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:36:51 by ppatel            #+#    #+#             */
/*   Updated: 2016/12/08 16:36:54 by ppatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>

void			*ft_memset(void *b, int c, size_t len);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
void			*ft_memalloc(size_t size);
char			*ft_strnew(size_t size);

#endif
