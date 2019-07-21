/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabreui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 12:27:55 by alabreui          #+#    #+#             */
/*   Updated: 2019/07/21 18:33:03 by sbouatto         ###   ########.fr       */
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
	t_dict_entry	*array;

	dict_name = "numbers.dict";
	if (argc < 2 || argc > 3)
	{
		ft_error();
		return(0);
	}
	else if (argc == 2)
	{
		given_number = argv[1];
		if (*given_number == '0')
		{
			ft_error();
			return (0);
		}
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
	else if (argc == 3)
	{
		given_number = argv[2];
		while(*given_number)
		{
			if (*given_number < '0' || *given_number> '9')
			{
				ft_error();
				return(0);
			}
			given_number++;
		}
		dict_name = argv[1];
	}
	array = read_dict(dict_name);
//	printf("%s", read_dict(dict_name)->str);
	if (array == 0)
	{
		ft_error_dict();
		return(0);
	}

	return (0);
}
