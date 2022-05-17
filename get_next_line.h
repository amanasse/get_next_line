/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:32:34 by amanasse          #+#    #+#             */
/*   Updated: 2022/05/17 19:10:55 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <ctype.h>
# include <unistd.h>
# include <fcntl.h>

void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);



#endif