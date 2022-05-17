/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:35:47 by amanasse          #+#    #+#             */
/*   Updated: 2022/05/17 19:10:54 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int	main() 
{
	int	fichier;
	int nb_octet;
	int count;
	char dest[BUFFER_SIZE + 1];

	nb_octet = 1;
	count = nb_octet;
	if ((fichier = open("test.txt", O_RDONLY)) == -1) 
	{
		perror("Impossible d'ouvrir le fichier en lecture\n"); 
		exit(1);
	}

	puts("Traitement...");
	while (nb_octet != 0)
	{
		nb_octet = read(fichier, dest, BUFFER_SIZE);
		// ft_putnbr(nb_octet);
		puts ("\n");
		dest[nb_octet] = '\0';
		ft_putstr(dest);
		puts ("\n");
		count = nb_octet + count;
	}
	ft_putnbr(nb_octet);
	ft_putnbr(count);
	close(fichier);
	puts("FIN"); 
}
