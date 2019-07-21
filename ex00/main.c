/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabreui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 12:27:55 by alabreui          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/07/21 15:38:31 by asambron         ###   ########.fr       */
=======
/*   Updated: 2019/07/21 18:23:55 by alabreui         ###   ########.fr       */
>>>>>>> 287d161b4da9d10fbe0b544ed66009c532f8466f
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include "utils.h"

void	ft_error(void)
{
	write(1, "ERROR\n", 6);
}

void	ft_error_dict(void)
{
	write(1, "DICT ERROR\n", 11);
}

int		main(int argc, char **argv)
{
	char			*dict_name;
	char			*given_number;
//t_dict_entry	*array;

	dict_name = "numbers.dict";
<<<<<<< HEAD
	read_dict(dict_name);
	if (argc == 1)
=======
	if (argc < 2 || argc > 3)
	{
>>>>>>> 287d161b4da9d10fbe0b544ed66009c532f8466f
		ft_error();
		return(0);
	}
	else if (argc == 2)
	{
		given_number = argv[1];
		while (*given_number)
		{
			if (*given_number < '0' || *given_number > '9')
			{
				ft_error();
				return (0);
			}
			given_number++;
		}
	}
	return (0);
}
