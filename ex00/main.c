/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabreui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 12:27:55 by alabreui          #+#    #+#             */
/*   Updated: 2019/07/21 14:33:23 by alabreui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_error(void)
{
	ft_putchar('E');
	ft_putchar('R');
	ft_putchar('R');
	ft_putchar('O');
	ft_putchar('R');
	ft_putchar('\n');
}

int		main(int argc, char **argv)
{
	char	*dict_name;

	dict_name = "numbers.dict";
	if (argc == 1)
		ft_error();
	if (argc == 2)
	{
		if (argv[2] < 0)
			ft_error();
	}
	if (argc > 3)
		ft_error();
}
