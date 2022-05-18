/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:35:47 by amanasse          #+#    #+#             */
/*   Updated: 2022/05/18 16:24:05 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 10

char *stock_save(char *dest, int octet)
{
	int	i;
	int j;
	char	*save;
		
	i = 0;
	while (dest[i] != '\0' && octet > 0)
	{
		if (dest[i] == '\n')
			break ;
		i++;
		octet--;
	}

	save = malloc(sizeof(char) * (octet + 2));
	j = 0;
	while (dest[i + j] != '\0' || octet > 0)
	{
		save[j - 1] = dest[i + j];
		j++;
		octet--;
	}
	save[j + 1] = '\0';

	return(save);
}

char *stock_line(char *dest, int octet)
{

	int	i;
	char	*line;
	
	i = 0;
	line = malloc(sizeof(char) * (octet + 2));
	while (dest[i] != '\0' && octet > 0)
	{
		line[i] = dest[i];
		if (dest[i] == '\n')
			break ;
		i++;
		octet--;
	}
	line[i + 1] = '\0';
	return(line);
}

char	*get_next_line(int fd)
{
	char		dest[BUFFER_SIZE];
	char		*line;
	int			nb_octet;
	static char	*save;
	
	printf("save du debut = [%s]\n", save);
	nb_octet = 1;
	if(fd == -1 || BUFFER_SIZE <= 0 || read(fd, dest, 0) < 0)
		return(0);	
	nb_octet = read(fd, dest, BUFFER_SIZE);
	printf("dest = [%s]\n", dest);
	if (nb_octet == 0)
		return(NULL);
	if (save)
		line = stock_line(save, nb_octet);
	else
		line = stock_line(dest, nb_octet);
		
	save = stock_save(dest, nb_octet);

	printf("save de fin = [%s]\n", save);
	return(line);
}

int	main() 
{
	int	fichier;


	if ((fichier = open("test.txt", O_RDONLY)) == -1) 
	{
		perror("Impossible d'ouvrir le fichier en lecture\n"); 
		exit(1);
	}

	printf("--------------------------------------------\n");
	printf("gnl = [%s]\n", get_next_line(fichier));
	printf("--------------------------------------------\n");
	printf("gnl = [%s]\n", get_next_line(fichier));
	printf("--------------------------------------------\n");
	printf("gnl = [%s]\n", get_next_line(fichier));
	printf("--------------------------------------------\n");
	printf("gnl = [%s]\n", get_next_line(fichier));


	// get_next_line(fichier);

	
	

	close(fichier);
	// printf("\n");
	// puts("FIN"); 
}
