/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:35:47 by amanasse          #+#    #+#             */
/*   Updated: 2022/05/23 15:42:29 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// #define BUFFER_SIZE 1

char	*stock_save(char *dest, char *exline, char *exsave)
{
	int		i;
	char	*save;
	int		j;

	j = ft_strlen(exsave) - ft_strlen(exline);
	save = malloc(sizeof(char) * (j + 1));
	i = 0;
	while (j > 0)
	{
		save[i] = dest[i];
		i++;
		j--;
	}
	save[i] = '\0';
	return (save);
}

char	*stock_line(char *dest, int octet)
{
	int		i;
	char	*line;

	i = 0;
	while (dest[i] != '\0')
	{
		if (dest[i] == '\n')
			break ;
		i++;
	}
	line = malloc(sizeof(char) * (i + 2));
	i = 0;
	while (dest[i] != '\0' && octet > 0)
	{
		line[i] = dest[i];
		if (dest[i] == '\n')
			break ;
		i++;
		octet--;
	}
	line[i + 1] = '\0';
	return (line);
}

int	ft_join(char *dest, char **save, int fd)
{
	char	*tmp;
	int		nb_octet;

	nb_octet = 1;
	while (check_sep(*save) == 0 && nb_octet != 0)
	{	
		nb_octet = read(fd, dest, BUFFER_SIZE);
		dest[nb_octet] = '\0';
		if (dest[0] == '\0' && *save[0] == '\0')
			return (0);
		if (nb_octet > 0)
		{
			tmp = *save;
			*save = ft_strjoin(*save, dest);
			free(tmp);
			tmp = NULL;
		}
	}
	return (1);
}

char	*free_stock_save(char **save, char **line)
{
	char	*tmp;

	tmp = *save;
	*save = stock_save(*save + ft_strlen(*line), *line, *save);
	free(tmp);
	tmp = NULL;
	return (*line);
}

char	*get_next_line(int fd)
{
	static char	dest[BUFFER_SIZE + 1];
	static char	*save;
	char		*line;

	if (save == NULL)
		save = ft_strdup("");
	if (fd == -1 || BUFFER_SIZE <= 0 || read(fd, dest, 0) < 0)
		return (NULL);
	if (ft_join(dest, &save, fd) == 0)
		return (NULL);
	if (save && check_sep(save) == 1)
	{
		line = stock_line(save, ft_strlen(save));
		return (free_stock_save(&save, &line));
	}
	if (save[0] == '\0')
	{
		free (save);
		return (NULL);
	}	
	line = stock_line_last(save);
	return (free_stock_save(&save, &line));
}

/*
int	main() 
{
	int	fichier;
	char *tmp;


	if ((fichier = open("test.txt", O_RDONLY)) == -1) 
	{
		perror("Impossible d'ouvrir le fichier en lecture\n"); 
		exit(1);
	}

	printf("--------------------------------------------\n");
	tmp = get_next_line(fichier);
	printf("line = [%s]\n", tmp);
	free (tmp);
	printf("--------------------------------------------\n");
	tmp = get_next_line(fichier);
	printf("line = [%s]\n", tmp);
	free (tmp);
	printf("--------------------------------------------\n");
	tmp = get_next_line(fichier);
	printf("line = [%s]\n", tmp);
	free (tmp);
	printf("--------------------------------------------\n");
	tmp = get_next_line(fichier);
	printf("line = [%s]\n", tmp);
	free (tmp);
	printf("--------------------------------------------\n");
	tmp = get_next_line(fichier);
	printf("line = [%s]\n", tmp);
	free (tmp);


	close(fichier);
 
 	// nb_octet = read(fd, dest, BUFFER_SIZE);
	// if (nb_octet > 0)
	// {
	// 	if(nb_octet < BUFFER_SIZE)
	// 		dest[nb_octet] = '\0';
	// 	save = ft_strjoin(save, dest, nb_octet, BUFFER_SIZE);
	// }
}
*/