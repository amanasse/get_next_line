/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:35:47 by amanasse          #+#    #+#             */
/*   Updated: 2022/05/18 13:14:13 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 10

char *stock_save(char *dest, int octet)
{

	int	i;
	int j;
	char	*save;
	char	*line;
	
	i = 0;
	save = malloc(sizeof(char) * (octet + 2));
	line = malloc(sizeof(char) * (octet + 2));
	while (dest[i] != '\0' && octet > 0)
	{
		save[i] = dest[i];
		line[i] = save[i];
		if (save[i] == '\n')
			break ;
		i++;
		octet--;
	}
	line[i] = '\0';
	free(save);
	save = malloc(sizeof(char) * (octet + 2));
	j = 0;
	while (dest[i + j] != '\0' || octet > 0)
	{
		save[j] = dest[i + j];
		j++;
		octet--;
	}
	save[j] = '\0';
	ft_putstr(line);
	puts ("\n");
	ft_putstr(save);
	puts ("\n");
	return(line);
	


}

char	*get_next_line(int fd)
{
	char		*dest;
	char		*line;
	int			nb_octet;
	static char	*save;
	


	nb_octet = 1;
	if(fd == -1 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return(0);	
	dest = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	nb_octet = read(fd, dest, BUFFER_SIZE);
	line = stock_save(dest, nb_octet);

	free(dest);
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
	ft_putnbr(fichier);
	puts("Traitement...");

	get_next_line(fichier);

	

	close(fichier);
	puts("FIN"); 
}
