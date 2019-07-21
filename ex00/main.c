/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabreui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 12:27:55 by alabreui          #+#    #+#             */
/*   Updated: 2019/07/21 21:36:18 by alabreui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"

int		ft_error(void)
{
	write(1, "ERROR\n", 6);
	return (0);
}

int		ft_error_dict(void)
{
	write(1, "DICT ERROR\n", 11);
	return (0);
}

int		check_given_number(char *given_number)
{
	if (*given_number == '0')
	{
		return (ft_error());
	}
	while (*given_number)
	{
		if (*given_number < '0' || *given_number > '9')
			return (ft_error());
		given_number++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	char			*dict_name;
	char			*given_number;
	t_dict_entry	*array;

	dict_name = "numbers.dict";
	if (argc < 2 || argc > 3)
		return (ft_error());
	else if (argc == 2)
	{
		given_number = argv[1];
		if (!check_given_number(given_number))
			return (0);
	}
	else if (argc == 3)
	{
		given_number = argv[2];
		if (!check_given_number(given_number))
			return (0);
		dict_name = argv[1];
	}
	array = read_dict(dict_name);
	if (array == 0)
		return (ft_error_dict());
	return (0);
}
