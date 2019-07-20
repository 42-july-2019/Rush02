/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabreui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 12:27:55 by alabreui          #+#    #+#             */
/*   Updated: 2019/07/20 14:23:20 by alabreui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

#include "utils.h"

int		main(int argc, char **argv)
{
	char	*dict_name;

	dict_name = "numbers.dict";
	if (argc > 1)
		printf("%s\n", argv[1]);
	read_dict(dict_name);
	printf("Hello !");
	return (0);
}
